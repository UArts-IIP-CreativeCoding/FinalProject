class Ball {
  
  public float w, v, x, y, z;
  
  void drawBall(float pX, float pY, float mP, float miHf, float miHs) {
    
    w = miHf;
    v = miHs;
    x = pX;
    y = pY;
    z = mP;
    
    /*
    fill(0 ,0 ,0);
    strokeWeight(0);
    ellipse(width/2+x, height/2+y, 20, 20);
    */
    
    colorMode(HSB);
  
    fill(hValue+w,255,255);
    //stroke(hValue+v,255,255);
    noStroke();
    
    colorMode(RGB);
    
    for (int i = 0; i < fft.avgSize(); i++){
    ellipse(width/2+x, height/2+y, height/80 - fft.getAvg(i) * z, height/80 - fft.getAvg(i) * z);
    }
    
    hValue += 1;
    
    if (hValue > 255) {
      hValue = 0;
    } 
  }  
}
