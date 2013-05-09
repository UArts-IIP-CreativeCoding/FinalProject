class Ball {

  public float w, v, x, y, z; //some floats

  /*
    fill(0 ,0 ,0);
   strokeWeight(0);
   ellipse(width/2+x, height/2+y, 20, 20);
   */


  void drawBall(float pX, float pY, float mP, float miHf, float miHs) {

    w = miHf;
    v = miHs;
    x = pX;
    y = pY;
    z = mP;

    colorMode(HSB); //changes the color mode from rgb to hsb

    fill(hValue+w, 255, 255);
    //stroke(hValue+v,255,255);
    noStroke();


    colorMode(RGB); //changes color mode back to rgb

    for (int i = 0; i < fft.avgSize(); i++) { //forloop with fft to make ball h & w expand and contrast

      float g;

      g = height/80 - fft.getAvg(i) * z;

      rect(width/2+x, height/2+y, g, g);
    }

    hValue += 1; //adds 1 to hvalue

    if (hValue > 255) { //when hvalue becomes 255 resets back to 0
      hValue = 0;
    }
  }
}

