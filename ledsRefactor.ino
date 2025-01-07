#include "pitches.h"

const int PIN = 12;

const int carriles[][5] = {
  /*
  {3,5,7,9,11}, //carril 0
  {2,4,6,8,10}  //carril 1
  // otros del futuro
  */
  {11,9,7,5,3}, //carril 0
  {10,8,6,4,2}  //carril 1
};

uint32_t lastTime;
float deltaTime;
int currentHit = 0;
uint32_t hitTimestamp;
float lastTransition = 0;
int tempo = 240;

// cada una de los "pasos" de la cancion
struct hit
{
    int nota;
    int duracion;
    int canal;
};

const hit cancion2[] = {
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

const hit cancion[]={ // tempo 240
  {REST,1,1},
  {NOTE_D4,1,1},
  {NOTE_A4,1,0},
  {NOTE_D4,1,1},
  {NOTE_A4,1,0},
  {NOTE_A4,1,0},
  {NOTE_A4,1,0},
  {NOTE_A4,1,0},
  {NOTE_A4,1,0},
  {NOTE_A4,1,0},
  {NOTE_A4,1,0},
  {NOTE_A4,1,0},
  {NOTE_D4,1,1},
  {NOTE_D4,1,1},
  {NOTE_D4,1,1},
  {NOTE_D4,1,1},
  {NOTE_A4,1,0},
  {NOTE_D4,1,1},
  {NOTE_A4,1,0},
  {NOTE_D4,1,1},
  {NOTE_A4,1,0},
  {NOTE_D4,1,1},
  {NOTE_A4,1,0},
  {NOTE_D4,1,1},
  {NOTE_A4,1,0},
  {NOTE_D4,1,1},
  {NOTE_A4,1,0}
};

float calculateDuration(float duration)
{
  return ((60000 * 4) / tempo) / duration;
}

void nextHit(){
  currentHit++;
  tone(PIN, cancion[currentHit].nota, calculateDuration(cancion[currentHit].duracion));
  //
  hitTimestamp = lastTime;
  lastTransition = lastTime;
}

void ledsSetup() {
  pinMode(PIN, OUTPUT);

  for(int i= 0; i < sizeof(carriles)/sizeof(carriles[0]); i++)
  {
    for(int j = 0; j < 5; j++)
    {
      pinMode(carriles[i][j], OUTPUT);
    }
  }
  
  lastTime = millis();
  hitTimestamp = lastTime;
}


void clearLEDs(){
  for(int i= 0; i < sizeof(carriles)/sizeof(carriles[0]); i++)
  {
    for(int j = 0; j < 5; j++)
    {
      digitalWrite(carriles[i][j], 0);
    }
  }

}
void paintLEDs(float nextTransition){
  float step = calculateDuration(16);
  float offset = calculateDuration(16);
  

  for(int futureCount=0;futureCount<5;futureCount++){
    float destination = lastTime + futureCount*step;
    int* color = nullptr;
    float diff = lastTime - hitTimestamp;
    if(futureCount == 0){
      if(diff < offset)
      {
        color = carriles[cancion[currentHit].canal];
        digitalWrite(color[0], cancion[currentHit].nota != REST);
      }
    }
    else if(abs(destination-nextTransition)<=offset/2 )
    {
      color = carriles[cancion[currentHit + 1].canal];
      digitalWrite(color[futureCount], cancion[currentHit+1].nota != REST);
    }

  }
}

bool ledsLoop() {
  bool songIsOver = currentHit+1 == sizeof(cancion)/sizeof(hit);
  
  deltaTime = (millis() - lastTime) / 1000;
  lastTime = millis();
  float nextTransition= hitTimestamp + calculateDuration(cancion[currentHit].duracion);
  bool nextIsSilence = songIsOver || cancion[currentHit + 1].nota == 0;
  bool currentIsSilence = cancion[currentHit].nota == 0;

  clearLEDs();
  
  if(nextTransition < lastTime)
  {
    if(songIsOver){
      return false;
    } 
    nextHit();
  }


  paintLEDs(nextTransition);
  return true;
}
