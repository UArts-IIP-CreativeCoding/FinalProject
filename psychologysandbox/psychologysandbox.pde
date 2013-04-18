//a graphics sandbox!
//demonstration of graphic direction, svg rendering, affects of translations accross classes
int spherepusher = 0;
int sphererotator = 0;
PShape helloworld;
Stripes bg;
void setup(){
  size(1024, 768, OPENGL);
  //Renders smoother than P3D or default renderer!
  background(255, 218, 42);
  smooth();
  frameRate(60);
  helloworld = loadShape("helloworld.svg");
  //loads the svg
}

void draw(){
//background stripes
bg = new Stripes();
bg.stripe();

//rotate(-PI/4);
//translate(0, 800);
//these ^^ reverse the translation under stripes class in order to put "hello world" back on the map, but pull the 3d object off as a result.

shape(helloworld, -800, 10);
// ^^ tests with this determine that processing lacks support for scalable vectors with: ellipse types, gaussian blurs, embedded text.  page size is irrelevant.  also shows that svg's are recognized as 3d objects, and that i will have to figure out how to independently translate assets.


directionalLight(50, 50, 50, 0, 0, -.5);
ambientLight(200, 200, 200);

//lights();
//translate(width/2+spherepusher,height/2+spherepusher);
//^^ these lines are irrelevant at the moment

fill(255, 133, 132);
rotateX(radians(sphererotator));
sphereDetail(0);
sphere(40);
//^^makes the spinning 3d object.

if(sphererotator <= 360){
  sphererotator+=5;
}
else{
  sphererotator = 0;
}



}
