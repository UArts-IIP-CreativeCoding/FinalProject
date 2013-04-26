#include "testApp.h"
#include "ofAppGlutWindow.h"
#include "config.make"

int main() {
	ofAppGlutWindow window;
	ofSetupOpenGL(&window, 1024, 768, OF_WINDOW);
	ofRunApp(new testApp());
}
