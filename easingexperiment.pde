//application implementing "ease in" temporal interpolation of movement.  object decelerates in accordance with proximity to destination.f
float xellipse = 512;
float yellipse = 384;
float xprogress;
float yprogress;
float destinationx;
float destinationy;
int movestate = 0;
int xNegorPos;
int yNegorPos;

void setup(){
  background(255);
  size(768, 768);
  smooth();
  
}

void draw(){
  ellipseMode(CENTER);
  fill(0);
  ellipse(xellipse, yellipse, 5, 5);
  //destinationx = random(1024);
  //destinationy = random(768);
  if (mousePressed){
    movestate = 1;
  }
if (movestate == 1){
  destinationx = random(768);
  destinationy = random(768);
}

if (movestate == 1 && mousePressed != true){
  movestate = 2;
}


//make if then for neg positive with greater than statement.

if (xellipse <= destinationx){
  xNegorPos = -1;
}
else{
  xNegorPos = 1;
}

if (yellipse <= destinationy){
  yNegorPos = -1;
}
else{
  yNegorPos = 1;
}

//it's doing some weird, cool stuff.
if (movestate == 2){
  xellipse += (xNegorPos*(((xellipse - destinationx)/200)*((xellipse - destinationx)/200)));
  yellipse += (yNegorPos*(((yellipse - destinationy)/200)*((yellipse - destinationy)/200)));
}


}
