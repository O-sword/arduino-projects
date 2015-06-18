# arduino-projects
// Include the DIY Gamer library
#include <Gamer.h>

// Make a copy of the library
Gamer gamer;

// Animation code copied from our Animation Generator app.
#define NUMFRAMESIMAGES 4
byte images[NUMFRAMESIMAGES][8] = {
  {
    B00000000,
    B00011000,
    B00011000,
    B00111100,
    B00111100,
    B01111110,
    B01111110,
    B00000000  }
  ,

  {
    B00000000,
    B00000110,
    B00011110,
    B01111110,
    B01111110,
    B00011110,
    B00000110,
    B00000000  }
  ,

  {
    B00000000,
    B01100000,
    B01111000,
    B01111110,
    B01111110,
    B01111000,
    B01100000,
    B00000000  }
  ,

  {
    B00000000,
    B01111110,
    B01111110,
    B00111100,
    B00111100,
    B00011000,
    B00011000,
    B00000000  }
};

byte go[8] = {
  B10101010,
  B10101010,
  B01010101,
  B01010101,
  B10101010,
  B10101010,
  B01010101,
  B01010101
};

byte right[8] = {
  B00000001,
  B00000011,
  B00000111,
  B00001110,
  B11011100,
  B11111000,
  B01110000,
  B00100000
};

byte wrong[8] = {
  B11000011,
  B01100110,
  B00111100,
  B00011000,
  B00011000,
  B00111100,
  B01100110,
  B11000011
};

void setup() {
  // Start Gamer!
  gamer.begin();
}

void loop() {
  if(gamer.isPressed(UP)) {
    gamer.printImage(images[0]);
    delay(200);
  }
  else if(gamer.isPressed(LEFT)) {
    gamer.printImage(images[1]);
    delay(200);
  } 
  else if(gamer.isPressed(RIGHT)) {
    gamer.printImage(images[2]);
    delay(200);
  } 
  else if(gamer.isPressed(DOWN)) {
    gamer.printImage(images[3]);
    delay(200);
  }
  
  gamer.clear();
}
