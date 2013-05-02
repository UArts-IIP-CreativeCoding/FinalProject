import ddf.minim.analysis.*;
import ddf.minim.*;

Minim minim;
AudioInput in;
FFT fft;
int wid;
PImage fade;
int hValue;
int yValue;
float rWidth, rHeight;
float yV;

boolean dragging = false; // Is the object being dragged?
boolean rollover = false; // Is the mouse over the ellipse?

float x, y, z, g;          // Location and size
float offsetX, offsetY; // Mouseclick offset

Ball l;

void setup(){
  
  background(0);
  //frameRate(20);
  size(1300, 500,P3D);
  smooth();
  minim = new Minim(this);
  in = minim.getLineIn(Minim.STEREO, 512);
  fft = new FFT(in.bufferSize(), in.sampleRate());
  fft.logAverages(60, 7);
  wid = width/fft.avgSize();
  
  
  l = new Ball(50,50,5);
  
}

void draw(){
  
  background(0);
  
  l.drag(mouseX,mouseY);
  l.display();
  
}

void mousePressed() {
  l.clicked(mouseX,mouseY);
}

void mouseReleased() {
  l.stopDragging();
}
