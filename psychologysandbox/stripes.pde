int movecounter = 0;
class Stripes {
  
  Stripes(){
  }
  
  void stripe(){
    //makes stripes diagonal
    background(255, 218, 42);
    rotate(PI/4);
translate(0, -800);
  for(int i = 0; i < 1300; i += 40){    
    if(i%80 == 0){
      noStroke();
      fill(255, 133, 132, 100);
      rect(0, i+movecounter, 1300, 40);
      fill(255, 218, 42);
      rect(0, i+40+movecounter, 1300, 40); 
    }

  } 
 if (movecounter <= 80){
  movecounter+=2;
 //makes for movement of stripes, infinite stripes 
}
else{
  movecounter=1;
}
 
    }
}
