#ifndef OFX_TWITTER_H
#define OFX_TWITTER_H


#include "ofxXmlSettings.h"
#include "ofxThread.h"
#include "ofxTwitterEvents.h"
#include "ofxTweet.h"

				
#define OFX_TWITTER_DIRECT		0	// The direct mode send directly all the tweets into a vector through the "newTweets" function.
#define OFX_TWITTER_PROGRESSIVE	1	// The progressive mode send progressively all the tweets, one by one through the "newTweet" function.
#define OFX_TWITTER_REALTIME	2

class ofxTwitter : public ofxThread {

	public:
		ofxTwitter();
		~ofxTwitter();
		
		void				addSearch(string query, int limit);		// Add new Searches in the search list. This is the threaded mode.

		vector<ofxTweet>	search(string query, int limit);		// Search for tweets. The blocking mode.
		
		// Search operators
		// http://search.twitter.com/operators

		// twitter search						containing both "twitter" and "search". This is the default operator.
		// "happy hour"							containing the exact phrase "happy hour".
		// love OR hate							containing either "love" or "hate" (or both).
		// beer -root							containing "beer" but not "root".
		// #haiku								containing the hashtag "haiku".
		// from:alexiskold						sent from person "alexiskold".
		// to:techcrunch						sent to person "techcrunch".
		// @mashable							referencing person "mashable".
		// "happy hour" near:"san francisco"	containing the exact phrase "happy hour" and sent near "san francisco".
		// near:NYC within:15mi					sent within 15 miles of "NYC".
		// superhero since:2009-10-09			containing "superhero" and sent since date "2009-10-09" (year-month-day).
		// ftw until:2009-10-09					containing "ftw" and sent up to date "2009-10-09".
		// movie -scary :)						containing "movie", but not "scary", and with a positive attitude.
		// flight :(							containing "flight" and with a negative attitude.
		// traffic ?							containing "traffic" and asking a question.
		// hilarious filter:links				containing "hilarious" and linking to URLs.
		// news source:twitterfeed				containing "news" and entered via TwitterFeed

		void				threadedFunction();

		void				setVerbose(bool v);
		void				setTimeout(int t);
		void				setRealtimeRefreshTimeout(int t);
		void				setMode(int m) ;

	private:

		void				search();								// Search for tweets. This is the threaded continuous version.

		void				start();
		void				stop();

		vector<ofxTwitterSearch> searches;							// Vector for the progressive mode
		vector<ofxTwitterSearch> rtSearches;						// Vector for the realtime mode

		bool			verbose;
		int				timeout;
		int				realtimeRefreshTimeout;

		int				mode;

		ofxXmlSettings  xml;
		bool			xmlLoaded;

		int				tweetLoaded;								// Variables for the progressive mode
		int				pageLoaded;
		int				tweetToLoad;

};


#endif 
