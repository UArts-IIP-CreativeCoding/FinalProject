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



Ball l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

void setup() {

  //background(0);
  frameRate(20);
  size(1300, 500, P3D);
  smooth();
  minim = new Minim(this);
  in = minim.getLineIn(Minim.STEREO, 512);
  fft = new FFT(in.bufferSize(), in.sampleRate());
  fft.logAverages(60, 7);
  wid = width/fft.avgSize();
  fade = get(0, 0, width, height);

  rWidth = width * 0.99;
  rHeight = height * 0.99;
  hValue = 0;

  ellipseMode(CENTER);

  l = new Ball(-560, 0, 0.2, 10, -1);
  
}

void draw() {

  //background(0);

  tint(255, 255, 255, 254);
  image(fade, (width - rWidth)/2, (height - rHeight)/2, rWidth, rHeight);
  noTint();

  fft.forward(in.mix);

  l.display();
 

  l.drag(mouseX, mouseY);

  fade = get(0, 0, width, height);
}

void mousePressed() {
  l.clicked(mouseX, mouseY);
}

void mouseReleased() {
  l.stopDragging();
}

