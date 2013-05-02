class Ball {
  
    public float w, v, x, y, z;
    
    /*
    fill(0 ,0 ,0);
    strokeWeight(0);
    ellipse(width/2+x, height/2+y, 20, 20);
    */
    
    
    void drawBall(float pX, float pY, float mP, float miHf, float miHs){
      
    w = miHf;
    v = miHs;
    x = pX;
    y = pY;
    z = mP;
      
    colorMode(HSB);
  
    fill(hValue+w,255,255);
    //stroke(hValue+v,255,255);
    noStroke();
    rectMode(CENTER);
    
    colorMode(RGB);
    
    for (int i = 0; i < fft.avgSize(); i++){
      
      float g;
      
      g = height/80 - fft.getAvg(i) * z;
      
    rect(width/3+hValue, height/4+hValue, g , g);
    }
    
    hValue += 1;
    
    if (hValue > 255) {
      hValue = 0;
    } 
  }  
}
