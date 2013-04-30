//added shapetween functionality, event control, UI elements, classes.
//REQUIRES THE SHAPETWEEN LIBRARY
import processing.opengl.*;
import megamu.shapetween.*;

int eventcounter = 1;

PShape helloworld, titlescreen, clicktobegin, game1brief, callpyramid, callsphere, callcube, clockback;
Stripes bg;
GAMEONE firstgame;
Tween tweentest, logotween, clickanywhere, firstgamecall, calltween;
Shapecontrol right, wrong, alsowrong;
void setup() {
  size(1024, 768, OPENGL);
  background(255, 218, 42);

 helloworld = loadShape("helloworld.svg");
 titlescreen = loadShape("GONNADIE.svg");
 clicktobegin = loadShape("clicktobegin.svg");
 game1brief = loadShape("game1brief.svg");
 callpyramid = loadShape("pyramid.svg");
 callsphere = loadShape("sphere.svg");
 callcube = loadShape("cube.svg");
 clockback = loadShape("clockbacker.svg");
  //loads the svg
  //blur = loadShader("blur.glsl");
 tweentest = new Tween(this, 60, Tween.FRAMES, Tween.COSINE);
//lovely library for easing and tweens!
tweentest.setEasing(Tween.COSINE);  
logotween = new Tween(this, 60, Tween.FRAMES, Tween.COSINE);
clickanywhere = new Tween(this, 60, Tween.FRAMES, Tween.COSINE);
calltween = new Tween(this, 30, Tween.FRAMES, Tween.COSINE);

}

void draw() {

  bg = new Stripes();
  bg.stripe();

 
perspective();
tweentest.setEasingMode(Tween.OUT);
logotween.setEasingMode(Tween.OUT);
calltween.setEasingMode(Tween.IN_OUT);
calltween.pause();
logotween.setPlayMode(Tween.REVERSE_REPEAT);
clickanywhere.setPlayMode(Tween.REVERSE_REPEAT);


  if(eventcounter == 1){//titlescreen
  shape(titlescreen, 0, height/((3*logotween.position())+.5));
   //rotateY(radians((clickanywhere.position()-1)*90));
  shape(clicktobegin, (500*(clickanywhere.position()))-500, width/2);
  if(logotween.position()==1){
    logotween.pause();
    clickanywhere.pause();
  }
}
  if (eventcounter == 1 && mousePressed){
    eventcounter = 2;
  }
  if (eventcounter == 2){//transition into brief
   fill(0,0,0,abs(logotween.position()-1)*255);
   rect(0,0,width,height);
    if(logotween.position()==1){
     logotween.resume();
     clickanywhere.resume();
   }
    shape(titlescreen, 0, height/((3*logotween.position())+.5));
    //rotateY(radians((clickanywhere.position()-1)*90));
    shape(clicktobegin, (500*(clickanywhere.position()))-500, width/2);
   if(logotween.position()<=.02){
     logotween.pause();
     clickanywhere.pause();
     eventcounter = 3;
   }
    //alphafade-2;
  }
  if(eventcounter == 3){//brief for game 1
  fill(0);
    rect(0,0,width,height);
    shape(game1brief, 0, height/((3*clickanywhere.position())+.5)-200);
    shape(clicktobegin, (500*(clickanywhere.position()))-500, height-150);
    if(clickanywhere.position()<=.02){
      clickanywhere.resume();
    }
    if(clickanywhere.position()==1){
    clickanywhere.pause();
    }
   if(mousePressed){
     eventcounter = 4;
  }
  }
  if (eventcounter == 4){//transition into game 1
   
    fill(0,(clickanywhere.position())*255);
    rect(0,0,width,height);
    shape(game1brief, 0, height/((3*clickanywhere.position())+.5)-200);
    shape(clicktobegin, (500*(clickanywhere.position()))-500, height-150);
  if(clickanywhere.position()==1){
    clickanywhere.resume();
  }
  if(clickanywhere.position()<=0.02){
    clickanywhere.pause();
    eventcounter = 5;
  }
  }
if(eventcounter == 5){//game 1, still under development
  shapeMode(CENTER);
  shape(clockback, width/2, height/2);
  calltween.resume();
  shape(callpyramid, width/2, 800-(calltween.position()*100));
  lights();
 Shapecontrol right = new Shapecontrol(1, width/2, height/2);
 right.shapechoice();
 Shapecontrol wrong = new Shapecontrol(2, (2*width)/3, height/3);
 wrong.shapechoice();
 Shapecontrol alsowrong = new Shapecontrol(3, width/3, height/3);
 alsowrong.shapechoice();




}
  
  print(eventcounter);
}
