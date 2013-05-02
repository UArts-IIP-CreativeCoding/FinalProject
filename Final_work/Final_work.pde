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

void setup(){
  
  background(0);
  frameRate(20);
  size(1300, 500,P3D);
  smooth();
  minim = new Minim(this);
  in = minim.getLineIn(Minim.STEREO, 512);
  fft = new FFT(in.bufferSize(), in.sampleRate());
  fft.logAverages(60, 7);
  wid = width/fft.avgSize();
  fade = get(0,0, width, height);
  
  rWidth = width * 0.99;
  rHeight = height * 0.99;
  hValue = 0;
  
  ellipseMode(CENTER);
  
  l = new Ball();
  m = new Ball();
  n = new Ball();
  o = new Ball();
  p = new Ball();
  q = new Ball();
  r = new Ball();
  s = new Ball();
  t = new Ball();
  u = new Ball();
  v = new Ball();
  w = new Ball();
  x = new Ball();
  y = new Ball();
  z = new Ball();
  
}

void draw(){
  
  background(0);
  
  tint(255,255,255,254);
  image(fade, (width - rWidth)/2, (height - rHeight)/2, rWidth, rHeight);
  noTint();
  
  fft.forward(in.mix);
  
  l.drawBall(-560, 0, 0.2, 10, -10);
  m.drawBall(-480, 0, 0.5, 0, -10);
  n.drawBall(-400, 0, 1, 0, -10);
  o.drawBall(-320, 0, 1.8, -10, -10);
  p.drawBall(-240, 0, 2.4, -20, -10);
  q.drawBall(-160, 0, 3.2, -30, -10);
  r.drawBall(-80, 0, 4, -40, -10);
  s.drawBall(0, 0, 3.2, -30, -10);
  t.drawBall(80, 0, 2.8, -20, -10);
  u.drawBall(160, 0, 2.1, -10, -10);
  v.drawBall(240, 0, 1.7, 0, -10);
  w.drawBall(320, 0, 1.2, 10, -10);
  x.drawBall(400, 0, 0.8, 20, -10);
  y.drawBall(480, 0, 0.5, 30, -10);
  z.drawBall(560, 0, 0.2, 40, -10);
  
  fade = get(0,0, width, height);
  
  println("wid");
}
