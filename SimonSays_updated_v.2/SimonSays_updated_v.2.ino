// Include the DIY Gamer library
#include <Gamer.h>

// Make a copy of the library
Gamer gamer;

// Animation code copied from our Animation Generator app.
#define NUMFRAMESIMAGES 4

bool gameMode;
//int simonSays;
int simonSays[10];
// how many items does the user have to remember at the moment
int nSteps;
// while guessing, which item are they currently guessing
int userStep;
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

byte correct[8] = {
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
  gameMode = false;
  nSteps = 1;
  userStep = 0;
  gamer.begin();
}

void loop() {
  if (!gameMode) {
    // show what simon says
    // 1. pick a random number
    // loop up to the current number of steps, picking random numbers
    for (int i = 0; i < nSteps; i++) {
      // store each random number
      simonSays[i] = random(4);
    }
    // 2. show it to the user
    
    for (int j = 0; j < nSteps; j++) {
      gamer.printImage(images[j]);
      delay(200);
      gamer.clear();
      delay(200);
    }
    gameMode = true;
  } else {
    // the game is on - wait for them to pick the right button
    if(gamer.isPressed(UP)) {
      gamer.printImage(images[0]);
      delay(200);
      scoreGame(0, simonSays);
    }
    else if(gamer.isPressed(LEFT)) {
      gamer.printImage(images[1]);
      delay(200);
      scoreGame(1, simonSays);
    } 
    else if(gamer.isPressed(RIGHT)) {
      gamer.printImage(images[2]);
      delay(200);
      scoreGame(2, simonSays);
    } 
    else if(gamer.isPressed(DOWN)) {
      gamer.printImage(images[3]);
      delay(200);
      scoreGame(3, simonSays);
    }
  
    gamer.clear();
  }
}

void scoreGame(int input, int simonSays)
{
  if (input == simonSays) {
    gamer.printImage(correct);
    delay(1000);
  } else {
    gamer.printImage(wrong);
    delay(1000);
  }
  setup();
}
