//work in progress
int rotator;
int shapestate;
  int xPosition;
  int yPosition;
class Shapecontrol{
 // public triggerstate();

  Shapecontrol(int state, int xPos, int yPos){
   shapestate = state;
  xPosition = xPos;
 yPosition = yPos; 
  
 }



void shapechoice(){
  if (shapestate == 1){
       pushMatrix();
  translate(xPosition, yPosition, 50);
  fill(255, 133, 132);
  rotateX(radians(rotator));
  rotateY(radians(rotator));
  rotateZ(radians(rotator));
  sphereDetail(0);
  sphere(40);
  popMatrix();
  }
  if (shapestate == 2){
    pushMatrix();
  translate(xPosition, yPosition, 50);
  fill(255, 133, 132);
  rotateX(radians(rotator));
  rotateY(radians(rotator));
  rotateZ(radians(rotator));
  sphereDetail(100);
  sphere(30);
  popMatrix();
  }
  if (shapestate == 3){
    pushMatrix();
  translate(xPosition, yPosition, 50);
  fill(255, 133, 132);
  rotateX(radians(rotator));
  rotateY(radians(rotator));
  rotateZ(radians(rotator));
  box(40);
  popMatrix();
  }
rotator++;
}
}


