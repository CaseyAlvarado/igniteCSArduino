import controlP5.*;
import processing.serial.*;
 
final int CYAN = color(0,255,255);
final int ORANGE = color(255,165,0);
final int YELLOW = color(255,255,0);
final int PURPLE = color(160,32,240);
final int BLUE = color(0,0,255);
final int RED = color(255,0,0);
final int GREEN = color(0,255,0);
 
ControlP5 controlP5;
Grid board, preview;
Tetromino tetronimo;
Shape next;
Shape[] shapes = new Shape[7];
int timer = 10;
int currentTime = 0;
int score = 0;
int lines = 0;
int level = 1;
int angle = 0;
final int SPEED_DECREASE = 2;
boolean game_over = false;
Serial inPort;

boolean game; 

void setup() {
  size(500, 690, P2D);
  textSize(25);
  controlP5 = new ControlP5(this);
  controlP5.addButton("play", 1, width/2 + 35, height/2, 70, 20).setLabel("play again");
  shapes[0] = new Shape(4, new int[] {8,9,10,11}, CYAN);  // I
  shapes[1] = new Shape(3, new int[] {0,3,4,5}, BLUE);  // J
  shapes[2] = new Shape(3, new int[] {2,3,4,5}, ORANGE);  // L
  shapes[3] = new Shape(2, new int[] {0,1,2,3}, YELLOW);  // O
  shapes[4] = new Shape(4, new int[] {5,6,8,9}, GREEN);  // S
  shapes[5] = new Shape(3, new int[] {1,3,4,5,}, PURPLE);  // T
  shapes[6] = new Shape(4, new int[] {4,5,9,10}, RED);  // Z
  board = new Grid(20, 20, 321, 642, 20, 10);
  preview = new Grid(355, 20, 116, 58, 2, 4);
  next = shapes[(int)random(7)];
  //inPort = new Serial(this,Serial.list()[0],9600);
  delay(500); 
  loadNext();
}
 
void draw() {
  background(0);
  if (game_over) {
    text("GAME OVER\nSCORE: " + score, width/2 - 70, height/2 - 50);
    controlP5.draw(); // show the play again button
    return;
  }
  currentTime++;
  if (currentTime >= timer && board.animateCount == -1)
    tetronimo.stepDown();
  preview.draw();
  board.draw();
  if (tetronimo != null)
    tetronimo.draw();
  next.preview();
  fill(255);
  text("LEVEL\n" + level, width - 150, 120);
  text("LINES\n" + lines, width - 150, 200);
  text("SCORE\n" + score, width - 150, 280);
}
 
void loadNext() {
  tetronimo = new Tetromino(next);
  next = shapes[(int)random(7)];
  currentTime = 0;
}
 
void serialEvent(Serial port) {
   //This is a comment. The computer will not see lines that start with two forward slashes //
   game = true;
   //when we are playing the game, it will run the code below 
   while(game){
      try{
        //This is the try block. 
        //Inside this try block, we are telling the computer to try doing the things below 
        
        //write your code below!  
        
        //BELOW: your code to read the from port and save it to a variable  
        
        //BELOW: code to print you like cheeseburgers 
        println("I like cheeseburgers"); 
        
        game = false;
      } 
      catch(Exception e) { 
        //This is the catch block. 
        //if the computer cannot do what we told it to do in the try block, it will jump into the 
        //catch block 
        println("The computer cannot do what you asked it do in the try block"); 
      } 
  }       
}

//void serialEvent(Serial port) { 
//  game = true;
//  while(game){
//    try{ 
//      int letter = port.read(); 
//      println(letter);
//      if (letter== 108) {
//        tetronimo.left();
//      }
//        if (letter == 114) {
//        tetronimo.right();
//      }
//      else {
//        angle = letter;
//        //println(angle);
//        //current.getShape().changeColor((inChar+155)%255,(inChar+25)%255,inChar);
//        //timer = (inChar / 25) + 5;
//      } 
//     game = false;
//    }
//    catch(Exception e) { 
//      println("in the catch"); 
//      println(e); 
//    } 
//  }
//} 

void keyPressed() {
  println(108); 
  if (tetronimo == null || game_over)
    return;
  //println(inPort.available()); 
  //if (inPort.available() >0) {
  //  int inByte = inPort.read();
  //  println("in key pressed");
  //  println(inByte);
  //  if (inByte == 108) {
  //    current.left();
  //  }
  //}
  switch(keyCode) {
    case LEFT : tetronimo.left(); break;
    case RIGHT : tetronimo.right(); break;
    case UP : tetronimo.rotate(); break;
    case DOWN : tetronimo.rotateCCW(); break;
    case ' ' : tetronimo.hardDown(); break;
  }
}
 
void play(int value) {
  board.clear();
  loadNext();
}