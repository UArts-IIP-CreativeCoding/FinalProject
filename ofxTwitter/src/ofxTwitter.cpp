#include "ofxTwitter.h"

ofxTwitter::ofxTwitter(){
    verbose					= false;
	xmlLoaded				= false;
	mode					= OFX_TWITTER_DIRECT;
    timeout					= 100;
	realtimeRefreshTimeout	= 10000;
}
ofxTwitter::~ofxTwitter(){
	// Stop the  thread if it's still running
	if(isThreadRunning()) stop();
}

// ----------------------------------------------------------------------

// Add new Searches in the search list. This is the threaded version
void ofxTwitter::addSearch(string query, int limit){
	searches.push_back(ofxTwitterSearch(query, limit));
	start();
}

// ----------------------------------------------------------------------

// Search for tweets. The blocking version
vector<ofxTweet> ofxTwitter::search(string query, int limit){
	vector<ofxTweet> tweets;

	// Create url
	string url = "http://search.twitter.com/search.atom?q="+query;
	bool	morePages = true;
	int		page = 0;

	while(morePages && page<limit){
		
		// Try to load xml from url
		if(xml.loadUrl(url)){

			// Push root
			xml.pushTag("feed", 0);	
			
			// Parse entries
			int numEntries = xml.getNumTags("entry");
			for(int i=0; i<numEntries; i++){
				xml.pushTag("entry", i);

					ofxTweet tweet;
					tweet.setTitle(xml.getValue("title", "", 0));
					tweet.setText(xml.getValue("content", "", 0));
					tweet.setPublished(xml.getValue("published", "", 0));
					tweet.setUpdated(xml.getValue("updated", "", 0));

					std::string id = xml.getValue("id", "", 0);
					int start = id.find(":",4)+1;
					int end = id.length();
					id = (std::string) id.substr(start, end); 
			
					tweet.setId(id);
					tweet.setProfileImage(xml.getAttribute("link", "href", "", 0)); // pas correct
					tweet.setSource(xml.getValue("twitter:source", "", 0));

					xml.pushTag("author");
						tweet.setAuthor(xml.getValue("name", "", 0));
						tweet.setAuthorUri(xml.getValue("uri", "", 0));
					xml.popTag();

					tweets.push_back(tweet);

				xml.popTag();
			}

			// Check for next page
			morePages = false;
			int numLinks = xml.getNumTags("link");
			for(int i=0; i<numLinks; i++){
				if(xml.attributeExists("link", "rel", i) && xml.getAttribute("link", "rel", "", i) == "next"){
					url = xml.getAttribute("link", "href", "", i);
					morePages = true;
					page++;
				}
			}

		}
	}

	return tweets;
}

// Search for tweets. This is the threaded continuous version
void ofxTwitter::search(){
	// Push into root
	xml.pushTag("feed", 0);	

		// Parse current entry
		xml.pushTag("entry", tweetLoaded);

			// for now, don't take tweets without content
			if(xml.tagExists("content")){

				ofxTweet tweet;
				tweet.setTitle(xml.getValue("title", "", 0));
				tweet.setText(xml.getValue("content", "", 0));
				tweet.setPublished(xml.getValue("published", "", 0));
				tweet.setUpdated(xml.getValue("updated", "", 0));

				std::string id = xml.getValue("id", "", 0);
				int start = id.find(":",4)+1;
				int end = id.length();
				id = (std::string) id.substr(start, end); 
			
				tweet.setId(id);
				tweet.setProfileImage(xml.getAttribute("link", "href", "", 0)); // pas correct
				tweet.setSource(xml.getValue("twitter:source", "", 0));

				xml.pushTag("author");
				tweet.setAuthor(xml.getValue("name", "", 0));
				tweet.setAuthorUri(xml.getValue("uri", "", 0));
				xml.popTag();

				// Notify new tweet to the event manager
				ofxTwitterEvents.notifyNewTweet(tweet);
			}
		
		xml.popTag();
	xml.popTag();

	tweetLoaded++;
}

// ----------------------------------------------------------------------
void ofxTwitter::threadedFunction(){

	string sinceIdParam = "";

    // loop through this process whilst thread running
	while( isThreadRunning() == true ){
		
			switch(mode){ 
				// The OFX_TWITTER_DIRECT mode send directly all the tweets into a vector through the "newTweets" function
				case OFX_TWITTER_DIRECT : 
					
    				if(searches.size()>0){
						ofxTwitterEvents.notifyNewSearch(search(searches.front().url, searches.front().limit));
						searches.erase( searches.begin() );	
					}
					else {
    					stop();
    				}
					break;

				// The OFX_TWITTER_REALTIME mode send all the tweets, one by one, in realtime through the "newTweet" function
				// The OFX_TWITTER_PROGRESSIVE mode send progressively all the tweets, one by one through the "newTweet" function
				case OFX_TWITTER_REALTIME : 
				case OFX_TWITTER_PROGRESSIVE : 
					bool keepGoing = (tweetLoaded<tweetToLoad);

					// If searches not finished
					if(searches.size()>0 || keepGoing){
						if(xmlLoaded) {
							if(keepGoing){
								// Keep searching
								if(verbose) printf("searching\n");
								search();
								ofSleepMillis(timeout);
							}
							else {
								// Checking for next page
								if(verbose) printf("Checking for next page\n");
								xml.pushTag("feed", 0);	

									int numLinks	= xml.getNumTags("link");

									string nextPage = "";
									for(int i=0; i<numLinks; i++){
										if(xml.attributeExists("link", "rel", i) && xml.getAttribute("link", "rel", "", i) == "next"){
											nextPage = xml.getAttribute("link", "href", "", i);
										}
									}
								
								xml.popTag();
								
								// If next page then load next XML
								if(nextPage != "" && pageLoaded < searches.front().limit) {
									if(verbose) printf("next XML\n");

									xml.clear();
									xmlLoaded	= xml.loadUrl(nextPage);

									xml.pushTag("feed", 0);	
										tweetToLoad = xml.getNumTags("entry");
									xml.popTag();

									tweetLoaded = 0;
								}

								// Search finished
								else {
									if(verbose) printf("Search Finish\n");
									xmlLoaded = false;
									
									// If realtime check for last tweet id
									if(mode == OFX_TWITTER_REALTIME) {
										std::string id = "";
										if(xml.tagExists("feed")){
											xml.pushTag("feed", 0);	
											if(xml.tagExists("entry")){
												xml.pushTag("entry", 0);
													id = xml.getValue("id", "", 0);
												xml.popTag();
											}
											xml.popTag();
										}
										
										// If last tweet id, update search url
										if(id!=""){
											int start = id.find(":",4)+1;
											int end = id.length();
											id = (std::string) id.substr(start, end); 
										
											int end2 = searches.front().url.find("since_id");

											if(end2 == -1) searches.front().url+="&since_id="+id;
											else searches.front().url = searches.front().url.substr(0,end2+9) + id;
										}
										rtSearches.push_back(searches.front());
									}

									searches.erase(searches.begin());	
								}
								
								pageLoaded++;

							}

						}
						// Init first search
						else {
							if(verbose) cout<<"init search  +"<<"http://search.twitter.com/search.atom?q="+searches.front().url<<endl;

							xml.clear();
							xmlLoaded = xml.loadUrl("http://search.twitter.com/search.atom?q="+searches.front().url);
							xml.pushTag("feed", 0);	
							tweetToLoad = xml.getNumTags("entry");
							xml.popTag();

							if(verbose) cout<<"xml loaded : "<<xmlLoaded<<endl;

							tweetLoaded = 0;
							pageLoaded	= 1;

							
						}
					}
					// All searches finished stop the thread in progressive mode and sleep in realtime mode
					else {
						if(verbose) printf("Searches Finished\n");

						// Realtime refresh
						if(mode == OFX_TWITTER_REALTIME) {
							if(verbose) printf("Realtime Refresh\n");
							
							// Sleep
							ofSleepMillis(realtimeRefreshTimeout);

							if(rtSearches.size()>0){
								searches.clear();
								for(int i=0;i<rtSearches.size(); i++){
									searches.push_back(rtSearches[i]);
								}
	
								rtSearches.clear();

								/*xml.pushTag("feed", 0);	

								xml.pushTag("entry", 0);
	
								std::string id = xml.getValue("id", "", 0);

								xml.popTag();
								xml.popTag();

								int start = id.find(":",4)+1;
								int end = id.length();
								id = (std::string) id.substr(start, end); 

								sinceIdParam = "&since_id="+id;*/
							}
						}
    					else stop();
    				}

					break;
			}
		
	}

}
// ----------------------------------------------------------------------
void ofxTwitter::setVerbose(bool v){
	verbose = v;
}
void ofxTwitter::setTimeout(int t){
	timeout = t;
}

void ofxTwitter::setRealtimeRefreshTimeout(int t){
	realtimeRefreshTimeout = t;
}
void ofxTwitter::setMode(int m) {
	mode = m;
}

// ----------------------------------------------------------------------
void ofxTwitter::start() {
     if (isThreadRunning() == false){
        if(verbose) printf("starting twitter thread\n");
        startThread(true, verbose);
    }
}
// ----------------------------------------------------------------------
void ofxTwitter::stop() {
     if(verbose) printf("stopping twitter thread\n");
    stopThread();
}

// ----------------------------------------------------------------------
ofxTwitter ofxTwitterAPI;
ofxTwitterEventManager ofxTwitterEvents(&ofxTwitterAPI);