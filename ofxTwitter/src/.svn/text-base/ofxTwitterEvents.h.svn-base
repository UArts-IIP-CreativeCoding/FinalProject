#ifndef OFX_TWITTEREVENTS_H
#define OFX_TWITTEREVENTS_H

#include "Poco/BasicEvent.h"

class ofxTwitter;

#include "ofxTwitter.h"
#include "ofxTweet.h"

class ofxTwitterSearch {
	public :
		ofxTwitterSearch(string u, int l){
			url = u;
			limit = l;
		}

		string	url;
		int		limit;
};

class ofxTwitterEventListener{
	public:
		virtual void newTweet(ofxTweet & tweet){};
		void newTweet(const void * sender, ofxTweet & tweet){
			newTweet(tweet);
		}

		virtual void newTweets(vector<ofxTweet> & search){};
		void newTweets(const void * sender, vector<ofxTweet> & search){
			newTweets(search);
		}
};

class ofxTwitterEventManager{
	public:

		ofxTwitterEventManager(){
			this->sender=NULL;
		}
		ofxTwitterEventManager(ofxTwitter * sender){
			this->sender=sender;
		}
		void addListener(ofxTwitterEventListener * listener){
			searchEvent += Poco::Delegate<ofxTwitterEventListener,vector<ofxTweet>>(listener,&ofxTwitterEventListener::newTweets);
			tweetEvent	+= Poco::Delegate<ofxTwitterEventListener,ofxTweet>(listener,&ofxTwitterEventListener::newTweet);
		}

		void removeListener(ofxTwitterEventListener * listener){
			searchEvent -= Poco::Delegate<ofxTwitterEventListener,vector<ofxTweet>>(listener,&ofxTwitterEventListener::newTweets);
			tweetEvent  -= Poco::Delegate<ofxTwitterEventListener,ofxTweet>(listener,&ofxTwitterEventListener::newTweet);
		}

		void notifyNewSearch(vector<ofxTweet> search){
			searchEvent.notify(sender,search);
		}
		
		void notifyNewTweet(ofxTweet tweet){
			tweetEvent.notify(sender,tweet);
		}

	protected:
		Poco::BasicEvent <vector<ofxTweet>> searchEvent;
		Poco::BasicEvent <ofxTweet> tweetEvent;
		ofxTwitter * sender;
};

extern ofxTwitterEventManager ofxTwitterEvents;
extern ofxTwitter ofxTwitterAPI;

#endif 
