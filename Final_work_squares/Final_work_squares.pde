import ddf.minim.analysis.*; //imports sound analysis
import ddf.minim.*; //imports sound 

Minim minim; //sound
AudioInput in; //audio input 
FFT fft; //sound analysis 

PImage fade; //enables fade
int wid, hValue, yValue; //ints 
float rWidth, rHeight, yV; // float values

Ball l, m, n, o, p, q, r, s, t, u, v, w, x, y, z; //calls balls

void setup() {

  background(0); //background black
  frameRate(24); //frame rate
  size(1300, 500, P3D); //size with better render engine
  smooth(); //enables sooth
  minim = new Minim(this); //calls minim
  in = minim.getLineIn(Minim.STEREO, 1024); //sets the sensitivity of mic
  fft = new FFT(in.bufferSize(), in.sampleRate()); //calls fft from minim
  fft.logAverages(60, 7); //average 
  wid = width/fft.avgSize(); //width divided by the audio
  fade = get(0, 0, width, height); //enables things to fade into the back
  ellipseMode (CENTER);
  
  rWidth = width * 0.99; //row
  rHeight = height * 0.99; //row
  hValue = 0; //begining hue value


  l = new Ball(); //ball
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

void draw() {

  background(0); 

  tint(255, 255, 255, 254);
  image(fade, (width - rWidth)/2, (height - rHeight)/2, rWidth, rHeight);
  noTint();

  fft.forward(in.mix);

  l.drawBall(-560, 180, 0.5, 10, -10);
  m.drawBall(-480, 180, 1.0, 0, -10);
  n.drawBall(-400, 180, 1.5, 0, -10);
  o.drawBall(-320, 180, 2.0, -10, -10);
  p.drawBall(-240, 180, 2.5, -20, -10);
  q.drawBall(-160, 180, 3.0, -30, -10);
  r.drawBall(-80, 180, 3.5, -40, -10);
  s.drawBall(0, 180, 4.0, -30, -10);
  t.drawBall(80, 180, 3.5, -20, -10);
  u.drawBall(160, 180, 3.0, -10, -10);
  v.drawBall(240, 180, 2.5, 0, -10);
  w.drawBall(320, 180, 2.0, 10, -10);
  x.drawBall(400, 180, 1.5, 20, -10);
  y.drawBall(480, 180, 1.0, 30, -10);
  z.drawBall(560, 180, 0.5, 40, -10);

  fade = get(0, 0, width, height);
}


//some code was submited from https://vimeo.com/7596987 
