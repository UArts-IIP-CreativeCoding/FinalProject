
import ddf.minim.analysis.*;
import ddf.minim.*;

Minim minim;
AudioInput in;
FFT fft;
int w;
PImage fade;
int hValue;
float rWidth, rHeight;

void setup() {
  
  //frameRate(20);
  size(640, 480, P3D);
  minim = new Minim(this);
  in = minim.getLineIn(Minim.STEREO, 512);
  fft = new FFT(in.bufferSize(), in.sampleRate());
  fft.logAverages(60, 7);
  stroke(255);
  w = width/fft.avgSize();
  //strokeWeight(w);
  strokeCap(SQUARE);
  
  background(0);
  fade = get(0,0, width, height);
  
  rWidth = width * 0.99;
  rHeight = height * 0.99;
  hValue = 0;
  
}

void draw() {
  background(0);
  
  tint(255,255,255,254);
  image(fade, (width - rWidth)/2, (height - rHeight)/2, rWidth, rHeight);
  noTint();
  
  fft.forward(in.mix);
  
  
  /*
  for (int i = 0; i < fft.avgSize(); i++){
    line((i * w) + (w / 2), height, (i * w) + (w / 2), height - fft.getAvg(i) * 4);
  }
  */
  
  colorMode(HSB);
  
  //fill(hValue,255,255);
  //stroke(hValue,255,255);
  
  colorMode(RGB);
  
  for (int i = 0; i < fft.avgSize(); i++){
    ellipse(width/2, height/2, height/8 - fft.getAvg(i) * 5, height/8 - fft.getAvg(i) * 5);
  }
  
  fade = get(0,0, width, height);
  
  hValue += 2;
  if (hValue > 255) {
    hValue = 0;
  }
}
