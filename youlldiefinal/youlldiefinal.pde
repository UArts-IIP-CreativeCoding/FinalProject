//by adam samson
//sound is my own material
//timer class contributed by Daniel Schiffman http://www.learningprocessing.com/examples/chapter-10/example-10-5/
//REQUIRES THE SHAPETWEEN LIBRARY
import ddf.minim.*;
import processing.opengl.*;
import megamu.shapetween.*;
int rightshape;
int wrongshape;
int alsowrongshape;
int shapetrigger = 1;
int eventcounter = 1;
int countdown = 10;
int howfast = 100;
//int game1loses = 0;
int ratecounter = 1;
int winquery = 0;
int losequery = 0;
int rightXjump = 0;
int wrongXjump = 0;
int alsowrongXjump = 0;
int rightYjump = 0;
int wrongYjump = 0;
int alsowrongYjump = 0;
int jumpstate = 0;
boolean clickcorrect = false;
boolean clickwrong = false;
PFont bariol;
PShape helloworld, titlescreen, clicktobegin, game1brief, callpyramid, callsphere, callcube, clockback, deadscreen, checkmark, xmark;
AudioPlayer player;
AudioSnippet bass, chimes, piano, soft, womp, wrongsound;
Minim minim;
Stripes bg;
Tween tweentest, logotween, clickanywhere, firstgamecall, calltween, marktween;
Shapecontrol right, wrong, alsowrong;
Timer fasttimer, normtimer, slowtimer;
//Relocate rightone, wrongone, alsowrongone;
void setup() {
  size(1024, 768, OPENGL);
  background(255, 218, 42);
minim = new Minim(this);
player = minim.loadFile("lucky.mp3");
bass = minim.loadSnippet("BASS.mp3");
chimes = minim.loadSnippet("CHIMES.mp3");
piano = minim.loadSnippet("PIANO.mp3");
womp = minim.loadSnippet("WOMP.mp3");
soft = minim.loadSnippet("SOFT.mp3");
wrongsound = minim.loadSnippet("WRONG.mp3");
player.play();

  helloworld = loadShape("helloworld.svg");
  titlescreen = loadShape("GONNADIE.svg");
  clicktobegin = loadShape("clicktobegin.svg");
  game1brief = loadShape("game1brief.svg");
  callpyramid = loadShape("pyramid.svg");
  callsphere = loadShape("sphere.svg");
  callcube = loadShape("cube.svg");
  clockback = loadShape("clockbacker.svg");
  bariol = createFont("Bariol_Regular.otf", 170);
  deadscreen = loadShape("deadscreen.svg");
  checkmark = loadShape("checkmark.svg");
  xmark = loadShape("xmark.svg");
  //loads the svg
  //blur = loadShader("blur.glsl");
  tweentest = new Tween(this, 160, Tween.FRAMES, Tween.COSINE);
  //lovely library for easing and tweens!
 // tweentest.setEasing(Tween.COSINE);  
  logotween = new Tween(this, 60, Tween.FRAMES, Tween.COSINE);
  clickanywhere = new Tween(this, 60, Tween.FRAMES, Tween.COSINE);
  calltween = new Tween(this, 30, Tween.FRAMES, Tween.COSINE);
  marktween = new Tween(this, 30, Tween.FRAMES, Tween.COSINE);
  fasttimer = new Timer(250);
  fasttimer.start();
  normtimer = new Timer(400);
  normtimer.start();
  slowtimer = new Timer(600);
  slowtimer.start();
}

void draw() {

  bg = new Stripes();
  bg.stripe();


  perspective();
  tweentest.setEasingMode(Tween.IN_OUT);
  logotween.setEasingMode(Tween.OUT);
  calltween.setEasingMode(Tween.IN_OUT);
  marktween.setEasingMode(Tween.IN_OUT);
  calltween.pause();
  logotween.setPlayMode(Tween.REVERSE_REPEAT);
  clickanywhere.setPlayMode(Tween.REVERSE_REPEAT);
  //calltween.setPlayMode(Tween.REPEAT);
  marktween.setPlayMode(Tween.REPEAT);
  tweentest.setPlayMode(Tween.REVERSE_REPEAT);


  if (eventcounter == 1) {//titlescreen
    shape(titlescreen, 0, height/((3*logotween.position())+.5));
    //rotateY(radians((clickanywhere.position()-1)*90));
    shape(clicktobegin, (500*(clickanywhere.position()))-500, width/2);
    if (logotween.position()==1) {
      logotween.pause();
      clickanywhere.pause();
    }
  }
  if (eventcounter == 1 && mousePressed) {
    womp.play();
    eventcounter = 2;
  }
  if (eventcounter == 2) {//transition into brief
    fill(0, 0, 0, abs(logotween.position()-1)*255);
    rect(0, 0, width, height);
    if (logotween.position()==1) {
      logotween.resume();
      clickanywhere.resume();
    }
    shape(titlescreen, 0, height/((3*logotween.position())+.5));
    //rotateY(radians((clickanywhere.position()-1)*90));
    shape(clicktobegin, (500*(clickanywhere.position()))-500, width/2);
    if (logotween.position()<=.02) {
      logotween.pause();
      clickanywhere.pause();
      eventcounter = 3;
    }
    //alphafade-2;
  }
  if (eventcounter == 3) {//brief for game 1
    fill(0);
    rect(0, 0, width, height);
    shape(game1brief, 0, height/((3*clickanywhere.position())+.5)-200);
    shape(clicktobegin, (500*(clickanywhere.position()))-500, height-150);
    if (clickanywhere.position()<=.02) {
      clickanywhere.resume();
    }
    if (clickanywhere.position()==1) {
      clickanywhere.pause();
    }
    if (mousePressed) {
      chimes.play();
      eventcounter = 4;
    }
  }
  if (eventcounter == 4) {//transition into game 1

    fill(0, (clickanywhere.position())*255);
    rect(0, 0, width, height);
    shape(game1brief, 0, height/((3*clickanywhere.position())+.5)-200);
    shape(clicktobegin, (500*(clickanywhere.position()))-500, height-150);
    if (clickanywhere.position()==1) {
      clickanywhere.resume();
    }

    if (clickanywhere.position()<=0.02) {
      clickanywhere.pause();
      eventcounter = 5;
      rightshape = int(random(1, 4));
    }
  }

  if (eventcounter == 5) {//game1
    fasttimer.start();
    normtimer.start();
    slowtimer.start();
    countdown = 10;
    eventcounter = 6;
    clickanywhere.position();
    calltween.start();
    calltween.pause();
    marktween.start();
    marktween.pause();
    tweentest.start();
    //tweentest.pause();
    winquery = 0;
    losequery = 0;
    jumpstate = 1;

  }
  if (eventcounter == 6) {//game 1, still under development
    if(jumpstate == 1){
      rightXjump=(int(1.5*(random(512)-256)));
      rightYjump=(int(1.5*(random(314)-192)));
      wrongXjump=(int(1.5*(random(512)-256)));
      wrongYjump=(int(1.5*(random(314)-192)));
      alsowrongXjump=(int(1.5*(random(512)-256)));
      alsowrongYjump=(int(1.5*(random(314)-192)));
      jumpstate = 0;
    }
    
   
    shapeMode(CENTER);
    shape(clockback, width/2, height/2);
    if (rightshape == 1) {
      calltween.resume();
      shape(callpyramid, width/2, 800-(calltween.position()*100));
    }
    if (rightshape == 2) {
      calltween.resume();
      shape(callsphere, width/2, 800-(calltween.position()*100));
    }
    if (rightshape == 3) {
      calltween.resume();
      shape(callcube, width/2, 800-(calltween.position()*100));
    }

    fill(255);
    textFont(bariol);
    textAlign(CENTER, CENTER);
    text(countdown, width/2, height/2);
    if (ratecounter==1) {
      if (fasttimer.isFinished()) {
        countdown--;
        fasttimer.start();
      }
    }
    if (ratecounter==2) {
      if (normtimer.isFinished()) {
        countdown--;
        normtimer.start();
      }
    }
    if (ratecounter==3) {
      if (slowtimer.isFinished()) {
        countdown--;
        slowtimer.start();
      }
    }
    if (fasttimer.isFinished()) {
      fasttimer.start();
    }
    if (normtimer.isFinished()) {
      normtimer.start();
    }
    if (slowtimer.isFinished()) {
      slowtimer.start();
    }
    if (countdown == 0) {
      eventcounter = 7;
      ratecounter = 2;
    }
    if (winquery == 0 && losequery == 0) {  
      shapeMode(CENTER);
      shape(checkmark, width/2, height-150);
      }
    
    if (winquery == 1) {  
      //losequery=0;
      if(piano.isPlaying()==false){
        piano.rewind();
        piano.pause();
      }
      shapeMode(CENTER);
      shape(checkmark, width/2+(170*marktween.position()), 150);
      if (marktween.position() >= .8) {
        marktween.pause();
      }
      else{
       // marktween.reset();
        marktween.resume();
      }
    }
      if (losequery == 1) {  
      //winquery = 0;
      shapeMode(CENTER);
      shape(checkmark, width/2-(170*marktween.position()), 150);
    if (wrongsound.isPlaying() == false){
    wrongsound.rewind();
    wrongsound.pause();
    }
      if (marktween.position() >= .8) {
        marktween.pause();
      }
        else{
          marktween.resume();
      }
    }
    
    lights();

    if (rightshape == 1) {
      wrongshape = 2;
      alsowrongshape = 3;
    }
    if (rightshape == 2) {
      wrongshape = 1;
      alsowrongshape = 3;
    }
    if (rightshape == 3) {
      wrongshape = 1;
      alsowrongshape = 2;
    }
    if (rightshape == 4) {
      rightshape = 1;
    }

    Shapecontrol right = new Shapecontrol(int(rightshape), int((width/2)+(tweentest.position()*rightXjump)+50), int((height/2)+(tweentest.position()*rightYjump)));
    right.shapechoice();
    Shapecontrol wrong = new Shapecontrol(int(wrongshape), int((width/2)+(tweentest.position()*wrongXjump)), int((height/2)+(tweentest.position()*wrongYjump)));
    wrong.shapechoice();
    Shapecontrol alsowrong = new Shapecontrol(int(alsowrongshape), int((width/2)+(tweentest.position()*alsowrongXjump)+50), int((height/2)+(tweentest.position()*alsowrongYjump))-30);
    alsowrong.shapechoice();

    if (mousePressed && abs(mouseX-wrong.xPosition) <= 30 && abs(mouseY-wrong.yPosition) <= 30) {
      // ratecounter= ratecounter-1;
        wrongsound.play();
        losequery=1;
        winquery = 0;
        marktween.start();
      tweentest.resume();
      jumpstate = 1;
      if (ratecounter ==3) {
        ratecounter = 2;
      }
      else {
        ratecounter = 1;
      }
       
     // tweentest.resume();
    }

    if (mousePressed && abs(mouseX-alsowrong.xPosition) <= 30 && abs(mouseY-alsowrong.yPosition) <= 30) {
      wrongsound.play(); 

      losequery=1;
       winquery = 0;
       marktween.start();
      tweentest.resume();
      jumpstate = 1;
      if (ratecounter ==3) {
        ratecounter = 2;
      }
      //   if (ratecounter ==2){
      //   ratecounter = 1;
      // }
      else {
        ratecounter = 1;
      }
     
    }
    if (mousePressed && abs(mouseX-right.xPosition) <= 30 && abs(mouseY-right.yPosition) <= 30) {
      //ratecounter= ratecounter+1;
       piano.play();
       winquery = 1;
       losequery=0;
       marktween.start();
      tweentest.resume();
      jumpstate = 1;
      if (ratecounter == 1) {
        ratecounter=2;
      }
      else {
        ratecounter = 3;
      }
      
      countdown++;
      clickcorrect = true;
     // tweentest.resume();
     
      rightshape = int(random(1, 4));
    }
  /*   if(tweentest.position()==1){
    tweentest.pause();
    }
  if(tweentest.position()==0){
  tweentest.pause();
  }  */
    if (countdown >= 15) {
      countdown = 15;
    }
    if (clickcorrect = true) {
      //winquery = 1;

    }
    
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  if (eventcounter == 7) {//death
    if(bass.isPlaying()==false){
      bass.rewind();
      bass.pause();
    }
    
    rightshape = int(random(1, 4));
    shapeMode(CORNER);
    shape(deadscreen);
    if (fasttimer.isFinished() || normtimer.isFinished()  || slowtimer.isFinished() ) {
      clickanywhere.resume();

      shape(clicktobegin, (500*(clickanywhere.position()))-500, height-150);  

      if (clickanywhere.position()==1) {
        clickanywhere.pause();
      }

      if (mousePressed) {
        eventcounter = 8;
      }
    }
  }
  if (eventcounter == 8) {
    bass.play();
    shapeMode(CORNER);
    shape(deadscreen);
    clickanywhere.resume();
    shape(clicktobegin, (500*(clickanywhere.position()))-500, height-150); 
    if (clickanywhere.position()<=.02) {
      clickanywhere.pause();

      eventcounter = 5;
    }
  }



  //print(eventcounter);
  //print(clickcorrect);
  println(winquery);
  print(losequery);
}

