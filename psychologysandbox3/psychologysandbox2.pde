//this past week I studied shaders, opengl basics, and the shapetween library.  The code you see is an amalgamation of my experiments.
//a graphics sandbox!
//demonstration of graphic direction, svg rendering, affects of translations accross classes
import processing.opengl.*;
import megamu.shapetween.*;
int spherepusher = 0;
int sphererotator = 0;
PShape helloworld;
//PShader blur;
Stripes bg;
Tween tweentest;
//Shapecontrol tri cube sphere; 
void setup() {
  size(1024, 768, OPENGL);
  background(255, 218, 42);
  //smooth();
  //frameRate(60);
 helloworld = loadShape("helloworld.svg");
  //loads the svg
  //blur = loadShader("blur.glsl");
 tweentest = new Tween(this, 60, Tween.FRAMES, Tween.COSINE);
//lovely library for easing and tweens!
tweentest.setEasing(Tween.COSINE);  


}

void draw() {
  //background stripes
  //blur.set("blurSize", 9);
// blur.set("sigma", 10.0f);  
  bg = new Stripes();
  bg.stripe();
  //tri = new Shapecontrol();
 // cube = new Shapecontrol();
  //sphere = new Shapecontrol();
perspective();
tweentest.setEasingMode(Tween.OUT);
//tweentest.reverse();

  
  shape(helloworld, 0, height/4);
 
  
  //tests with this determine processing lacks support for: ellipse vectors, gaussian blurs, embedded text.  page size is irrelevant.  also shows that svg's are recognized as 3d objects, and that i will have to figure out how to independently translate assets.
  directionalLight(50, 50, 50, 0, 0, -.5);
  ambientLight(200, 200, 200);
  //these lines are irrelevant at the moment
  //lights();
 

  
   //these reverse the translation under stripes class in order to put "hello world" back on the map, but pull the 3d object off as a result.
  
 //makes t9he spinning 3d object.
  translate((width/2)+tweentest.position()*(width/2),(height/2)+tweentest.position()*(height/2), 50);
  fill(255, 133, 132);
  rotateX(radians(sphererotator));
  sphereDetail(0);
  sphere(40);
if(mousePressed && abs((width/2)-mouseX) <=30 && abs((height/2)-mouseY) <= 30){
tweentest.start();
}
  if (sphererotator <= 360) {
    sphererotator+=5;
  }
  else {
    sphererotator = 0;
  }
}
/*
void mousePressed(){
  //tweentest.start();
}
*/
