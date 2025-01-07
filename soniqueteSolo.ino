#include "pitches.h"

const int aPIN = 12;


uint32_t alastTime;
float adeltaTime;
int acurrentHit = 0;
uint32_t ahitTimestamp;
float alastTransition = 0;
float atempo = 240;

const hit enemy[]= {
  {NOTE_D4, 4,1},
  {NOTE_D4, 4,1},
  {NOTE_D4, 8,1},
  {NOTE_D4, 8,1},
  {NOTE_B3, 2,0},
  {NOTE_B3, 8,0},
  {NOTE_D4, 4,1},
  {NOTE_D4, 4,1},
  {NOTE_D4, 8,1},
  {NOTE_D4, 8,1},
  {NOTE_B3, 2,0},
  {NOTE_B3, 8,0},
  {NOTE_CS4, 4,0},
  {NOTE_CS4, 4,0},
  {NOTE_CS4, 8,0},
  {NOTE_CS4, 8,0},
  {NOTE_AS3, 2,0},
  {NOTE_AS3, 8,0},
  {NOTE_CS4, 4,0},
  {NOTE_CS4, 4,0},
  {NOTE_CS4, 8,0},
  {NOTE_CS4, 8,0},
  {NOTE_AS3, 2,0},
  {NOTE_B3, 8,0},
  {NOTE_D4, 4,1},
  {NOTE_D4, 4,1},
  {NOTE_D4, 8,1},
  {NOTE_D4, 8,1},
  {NOTE_B3, 2,0},
  {NOTE_B3, 8,0},
  {NOTE_D4, 4,1},
  {NOTE_D4, 4,1},
  {NOTE_D4, 8,1},
  {NOTE_D4, 8,1},
  {NOTE_B3, 2,0},
  {NOTE_B3, 8,0},
  {NOTE_CS4, 4,0},
  {NOTE_CS4, 4,0},
  {NOTE_CS4, 8,0},
  {NOTE_CS4, 8,0},
  {NOTE_AS3, 2,0},
  {NOTE_AS3, 8,0},
  {NOTE_CS4, 4,0},
  {NOTE_CS4, 4,0},
  {NOTE_CS4, 8,0},
  {NOTE_CS4, 8,0},
  {NOTE_AS3, 2,0},
  {NOTE_B4, 2,1},
  {NOTE_A4, 2,1},
  {NOTE_G4, 2,1},
  {NOTE_D4, 4,1},
  {NOTE_FS4, 1,1},
  {NOTE_E4, 1,1},
  {NOTE_B4, 8,1},
  {NOTE_B4, 2,1},
  {NOTE_A4, 2,1},
  {NOTE_G4, 2,1},
  {NOTE_D4, 4,1},
  {NOTE_FS4, 1,1},
  {NOTE_AS4, 1,1},
  {REST, 2,-1},
  {NOTE_E4, 2,1},
  {NOTE_FS4, 8,1},
  {NOTE_E4, 8,1},
  {NOTE_D4, 8,1},
  {NOTE_B3, 2,0},
  {NOTE_D4, 8,1},
  {NOTE_E4, 8,1},
  {NOTE_D4, 8,1},
  {NOTE_E4, 8,1},
  {NOTE_D4, 8,1},
  {NOTE_E4, 8,1},
  {NOTE_D4, 8,1},
  {NOTE_E4, 8,1},
  {NOTE_D4, 8,1},
  {NOTE_E4, 8,1},
  {NOTE_B4, 2,1},
  {REST, 2,-1},
  {NOTE_E4, 2,1},
  {NOTE_FS4, 8,1},
  {NOTE_E4, 8,1},
  {NOTE_D4, 8,1},
  {NOTE_B3, 2,0},
  {NOTE_D4, 8,1},
  {NOTE_E4, 8,1},
  {NOTE_D4, 8,1},
  {NOTE_E4, 8,1},
  {NOTE_D4, 8,1},
  {NOTE_E4, 8,1},
  {NOTE_B4, 2,1},
  {REST, 2,-1},
  {NOTE_B3, 8,0},
  {NOTE_B3, 8,0},
  {NOTE_B3, 8,0},
  {NOTE_D4, 2,1},
  {NOTE_CS4, 2,0},
  {NOTE_B3, 2,0},
  {NOTE_FS3, 8,0},
  {NOTE_E3, 4,0},
  {NOTE_FS3, 4,0},
  {NOTE_FS4, 8,1},
  {NOTE_B4, 4,1},
  {NOTE_FS4, 8,1},
  {NOTE_E4, 2,1},
  {REST, 2,-1},
  {NOTE_B3, 8,0},
  {NOTE_B3, 8,0},
  {NOTE_B3, 8,0},
  {NOTE_D4, 2,1},
  {NOTE_CS4, 2,0},
  {NOTE_B3, 2,0},
  {NOTE_FS3, 8,0},
  {NOTE_E3, 4,0},
  {NOTE_FS3, 4,0},
  {NOTE_FS4, 8,1},
  {NOTE_B4, 4,1},
  {NOTE_FS4, 8,1},
  {NOTE_E4, 2,1},
  {REST, 1,-1}
};

const hit pachelbelcanonind100[] = {
  
  {NOTE_FS4,2}, {NOTE_E4,2},
  {NOTE_D4,2}, {NOTE_CS4,2},
  {NOTE_B3,2}, {NOTE_A3,2},
  {NOTE_B3,2}, {NOTE_CS4,2},
  {NOTE_FS4,2}, {NOTE_E4,2},
  {NOTE_D4,2}, {NOTE_CS4,2},
  {NOTE_B3,2}, {NOTE_A3,2},
  {NOTE_B3,2}, {NOTE_CS4,2},
  {NOTE_D4,2}, {NOTE_CS4,2},
  {NOTE_B3,2}, {NOTE_A3,2},
  {NOTE_G3,2}, {NOTE_FS3,2},
  {NOTE_G3,2}, {NOTE_A3,2},

  {NOTE_D4,4}, {NOTE_FS4,8}, {NOTE_G4,8}, {NOTE_A4,4}, {NOTE_FS4,8}, {NOTE_G4,8}, 
  {NOTE_A4,4}, {NOTE_B3,8}, {NOTE_CS4,8}, {NOTE_D4,8}, {NOTE_E4,8}, {NOTE_FS4,8}, {NOTE_G4,8}, 
  {NOTE_FS4,4}, {NOTE_D4,8}, {NOTE_E4,8}, {NOTE_FS4,4}, {NOTE_FS3,8}, {NOTE_G3,8},
  {NOTE_A3,8}, {NOTE_G3,8}, {NOTE_FS3,8}, {NOTE_G3,8}, {NOTE_A3,2},
  {NOTE_G3,4}, {NOTE_B3,8}, {NOTE_A3,8}, {NOTE_G3,4}, {NOTE_FS3,8}, {NOTE_E3,8}, 
  {NOTE_FS3,4}, {NOTE_D3,8}, {NOTE_E3,8}, {NOTE_FS3,8}, {NOTE_G3,8}, {NOTE_A3,8}, {NOTE_B3,8},

  {NOTE_G3,4}, {NOTE_B3,8}, {NOTE_A3,8}, {NOTE_B3,4}, {NOTE_CS4,8}, {NOTE_D4,8},
  {NOTE_A3,8}, {NOTE_B3,8}, {NOTE_CS4,8}, {NOTE_D4,8}, {NOTE_E4,8}, {NOTE_FS4,8}, {NOTE_G4,8}, {NOTE_A4,2},
  {NOTE_A4,4}, {NOTE_FS4,8}, {NOTE_G4,8}, {NOTE_A4,4},
  {NOTE_FS4,8}, {NOTE_G4,8}, {NOTE_A4,8}, {NOTE_A3,8}, {NOTE_B3,8}, {NOTE_CS4,8},
  {NOTE_D4,8}, {NOTE_E4,8}, {NOTE_FS4,8}, {NOTE_G4,8}, {NOTE_FS4,4}, {NOTE_D4,8}, {NOTE_E4,8},
  {NOTE_FS4,8}, {NOTE_CS4,8}, {NOTE_A3,8}, {NOTE_A3,8},

  {NOTE_CS4,4}, {NOTE_B3,4}, {NOTE_D4,8}, {NOTE_CS4,8}, {NOTE_B3,4},
  {NOTE_A3,8}, {NOTE_G3,8}, {NOTE_A3,4}, {NOTE_D3,8}, {NOTE_E3,8}, {NOTE_FS3,8}, {NOTE_G3,8},
  {NOTE_A3,8}, {NOTE_B3,4}, {NOTE_G3,4}, {NOTE_B3,8}, {NOTE_A3,8}, {NOTE_B3,4},
  {NOTE_CS4,8}, {NOTE_D4,8}, {NOTE_A3,8}, {NOTE_B3,8}, {NOTE_CS4,8}, {NOTE_D4,8}, {NOTE_E4,8},
  {NOTE_FS4,8}, {NOTE_G4,8}, {NOTE_A4,2},  
   
  
};

const hit micancion[] = {};

float acalculateDuration(float duration)
{
  return ((60000 * 4) / atempo)/duration;
}

void anextHit(){
  acurrentHit++;
  tone(aPIN, micancion[acurrentHit].nota, acalculateDuration(micancion[acurrentHit].duracion));
  //
  ahitTimestamp = alastTime;
  alastTransition = alastTime;
}

// void setup() {
//   pinMode(aPIN, OUTPUT);

//   alastTime = millis();
//   ahitTimestamp = alastTime;
// }


// void loop() {
//   bool songIsOver = acurrentHit+1 == sizeof(micancion)/sizeof(hit);
  
//   adeltaTime = (millis() - alastTime) / 1000;
//   alastTime = millis();
//   float nextTransition= ahitTimestamp + acalculateDuration(micancion[acurrentHit].duracion);
//   bool nextIsSilence = songIsOver || micancion[acurrentHit + 1].nota == 0;
//   bool currentIsSilence = micancion[acurrentHit].nota == 0;
  
//   if(nextTransition < alastTime)
//   {
//     if(songIsOver){
//       exit(0);
//     } 
//     anextHit();
//   }
// }
