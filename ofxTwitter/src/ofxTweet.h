#ifndef OFX_TWEET_H
#define OFX_TWEET_H



#include "ofMain.h"

class ofxTweet
{

    public:
		// Getters
		string	getTitle();
		string	getText();
		string	getId();

		string	getPublished();
		string	getUpdated();

		string	getAuthor();
		string	getAuthorUri();

		string  getSource();
		string	getProfileImage();

		// Setters
		void	setTitle(string s);
		void	setText(string s);
		void	setId(string s);

		void	setPublished(string s);
		void	setUpdated(string s);

		void	setAuthor(string s);
		void	setAuthorUri(string s);

		void	setSource(string s);
		void	setProfileImage(string s);

	private:
		string	title;
		string	text;
		string	id;

		string	published;
		string	updated;

		string	author;
		string	authorUri;

		string	source;
		string	profileImage;
};

#endif 
