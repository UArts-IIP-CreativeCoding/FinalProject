#include "ofxTweet.h"

// GETTERS

string ofxTweet::getTitle(){
	return title;
}
string ofxTweet::getText(){
	return text;
}
string ofxTweet::getId(){
	return id;
}

string ofxTweet::getPublished(){
	return published;
}

string ofxTweet::getUpdated(){
	return updated;
}

string ofxTweet::getAuthor(){
	return author;
}
string	ofxTweet::getAuthorUri(){
	return authorUri;
}

string ofxTweet::getSource(){
	return source;
}
string ofxTweet::getProfileImage(){
	return profileImage;
}

// SETTERS
void ofxTweet::setTitle(string s){
	text = s;
}
void ofxTweet::setText(string s){
	text = s;
}
void ofxTweet::setId(string s){
	id = s;
}

void ofxTweet::setPublished(string s){
	published = s;
}
void ofxTweet::setUpdated(string s){
	updated = s;
}
void ofxTweet::setAuthor(string s){
	author = s;
}
void ofxTweet::setAuthorUri(string s){
	authorUri = s;
}

void ofxTweet::setSource(string s){
	source = s;
}
void ofxTweet::setProfileImage(string s){
	profileImage = s;
}

