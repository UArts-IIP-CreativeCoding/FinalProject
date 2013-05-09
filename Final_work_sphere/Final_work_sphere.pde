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
  frameRate(60); //frame rate
  size(1300, 500, P3D); //size with better render engine
 // smooth(); //enables sooth
  minim = new Minim(this); //calls minim
  in = minim.getLineIn(Minim.STEREO, 1024); //sets the sensitivity of mic
  fft = new FFT(in.bufferSize(), in.sampleRate()); //calls fft from minim
  fft.logAverages(60, 7); //average 
  wid = width/fft.avgSize(); //width divided by the audio
  //fade = get(0, 0, width, height); //enables things to fade into the back
  ellipseMode (CENTER);
  
  rWidth = width * 0.5; //row
  rHeight = height * 0.5; //row
  hValue = 0; //begining hue value





  s = new Ball();
  


}

void draw() {

  background(0); 

  //tint(255, 255, 255, 254);
  //image(fade, (width - rWidth)/2, (height - rHeight)/2, rWidth, rHeight);
  //noTint();

  fft.forward(in.mix);



  s.drawBall(0, 0, 20.0, -30, -10);

 

  //fade = get(0, 0, width, height);
}


//some code was submited from https://vimeo.com/7596987 
