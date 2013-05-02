class Ball {

  public float w, v, x, y, z;

  float g;
  float h;

  boolean dragging = false; // Is the object being dragged?
  boolean rollover = false; // Is the mouse over the ellipse?

  float offsetX, offsetY; // Mouseclick offset

  Ball (float pX, float pY, float mP, float miHf, float miHs) {

    w = miHf;
    v = miHs;
    x = pX;  //x
    y = pY;  //y
    z = mP;

    offsetX = 0;
    offsetY = 0;
  }

  /*
    fill(0 ,0 ,0);
   strokeWeight(0);
   ellipse(width/2+x, height/2+y, 20, 20);
   */


  void display() {



    colorMode(HSB);

    fill(hValue+w, 255, 255);
    //stroke(hValue+v,255,255);

    if (dragging) {

      noStroke();

      colorMode(RGB);

      for (int i = 0; i < fft.avgSize(); i++) {

        g = height/80 - fft.getAvg(i) * z;
        h = height/80 - fft.getAvg(i) * z;

        ellipse(width/2+x, height/2+y, g, h);
      }

      hValue += 1;

      if (hValue > 255) {
        hValue = 0;
      }
    }
  }

  void clicked (int mx, int my) {
    if (mx > x && mx < x + g && my > y && my < y + g) {
      dragging = true;
      offsetX = x-mx;
      offsetY = y-my;
    }
  } 

  void stopDragging() {
    dragging = false;
  }

  void drag(int mx, int my) {
    if (dragging) {
      x = mx + offsetX;
      y = my + offsetY;
    }
  }
}

