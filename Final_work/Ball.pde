class Ball {
  
  public float x, y;
  
  void drawBall(float pX, float pY) {
    
    x = pX;
    y = pY;
    
    fill(0 ,0 ,0);
    strokeWeight(0);
    ellipse(width/2+x, height/2+y, 20, 20);
    
  }
  
}
