class Ball {

  Ball(float tempX, float tempY, float tempZ) {

    x = tempX;
    y = tempY;
    z = tempZ;
  }

  // Method to display
  void display() {

    stroke(0);

    for (int i = 0; i < fft.avgSize(); i++) {

      g = height/50 - fft.getAvg(i) * z;

      rect(x, y, g, g);

      offsetX = 0;
      offsetY = 0;
    }
  }

  // Is a point inside the rectangle (for click)?
  void clicked(int mx, int my) {
    if (mx > x && mx < x + g && my > y && my < y + g) {
      dragging = true;
      // If so, keep track of relative location of click to corner of rectangle
      offsetX = x-mx;
      offsetY = y-my;
    }
  }

  // Is a point inside the rectangle (for rollover)


  // Stop dragging
  void stopDragging() {
    dragging = false;
  }

  // Drag the rectangle
  void drag(int mx, int my) {
    if (dragging) {
      x = mx + offsetX;
      y = my + offsetY;
    }
  }
}

