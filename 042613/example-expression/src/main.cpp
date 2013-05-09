#include "testApp.h"
#include "ofAppGlutWindow.h"

int main() {
	ofAppGlutWindow window;
	ofSetupOpenGL(&window, 580, 90, OF_WINDOW);
	ofRunApp(new testApp());
}
