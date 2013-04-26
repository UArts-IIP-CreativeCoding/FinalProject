Ball p, q, r, s, t, u, v, w, x, y, z;

void setup(){
  
  size(800, 200);
  smooth();
  ellipseMode(CENTER);
  
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
  
  p.drawBall(0, 0);
  q.drawBall(40, 0);
  r.drawBall(-40, 0);
  s.drawBall(80, 0);
  t.drawBall(-80, 0);
  u.drawBall(120, 0);
  v.drawBall(-120, 0);
  w.drawBall(160, 0);
  x.drawBall(-160, 0);
  y.drawBall(200, 0);
  z.drawBall(-200, 0);
  
}
