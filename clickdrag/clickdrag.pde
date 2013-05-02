// Click and Drag an object
// Daniel Shiffman <http://www.shiffman.net>

Draggable d;

void setup() {
  size(1300,500,P3D);
  smooth();
  d = new Draggable(50,50,200,100);
  
}

void draw() {
  background(255);
  d.rollover(mouseX,mouseY);
  d.drag(mouseX,mouseY);
  d.display();
}

void mousePressed() {
  d.clicked(mouseX,mouseY);
}

void mouseReleased() {
  d.stopDragging();
}
