#include "pitches.h"

const int PIN = 12;

const int BIEN=7;
const int MAL=8;
const int IN_3=A3;
const int IN_2=A2;
const int IN_1=A1;
const int IN_0=A0;

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

const hit cancion3[]={ // tempo 240
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

const hit cancion4[] = {
  
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

const hit cancion_larga[]={
  {NOTE_D4, 4,2},
  {NOTE_D4, 4,2},
  {NOTE_D4, 8,2},
  {NOTE_D4, 8,2},
  {NOTE_B3, 2,0},
  {NOTE_B3, 8,0},
  {NOTE_D4, 4,2},
  {NOTE_D4, 4,2},
  {NOTE_D4, 8,2},
  {NOTE_D4, 8,2},
  {NOTE_B3, 2,0},
  {NOTE_B3, 8,0},
  {NOTE_CS4, 4,1},
  {NOTE_CS4, 4,1},
  {NOTE_CS4, 8,1},
  {NOTE_CS4, 8,1},
  {NOTE_AS3, 2,3},
  {NOTE_AS3, 8,3},
  {NOTE_CS4, 4,1},
  {NOTE_CS4, 4,1},
  {NOTE_CS4, 8,1},
  {NOTE_CS4, 8,1},
  {NOTE_AS3, 2,3},
  {NOTE_B3, 8,0},
  {NOTE_D4, 4,2},
  {NOTE_D4, 4,2},
  {NOTE_D4, 8,2},
  {NOTE_D4, 8,2},
  {NOTE_B3, 2,0},
  {NOTE_B3, 8,0},
  {NOTE_D4, 4,2},
  {NOTE_D4, 4,2},
  {NOTE_D4, 8,2},
  {NOTE_D4, 8,2},
  {NOTE_B3, 2,0},
  {NOTE_B3, 8,0},
  {NOTE_CS4, 4,1},
  {NOTE_CS4, 4,1},
  {NOTE_CS4, 8,1},
  {NOTE_CS4, 8,1},
  {NOTE_AS3, 2,2},
  {NOTE_AS3, 8,2},
  {NOTE_CS4, 4,2},
  {NOTE_CS4, 4,2},
  {NOTE_CS4, 8,2},
  {NOTE_CS4, 8,2},
  {NOTE_AS3, 2,2},
  {NOTE_B4, 2,3},
  {NOTE_A4, 2,3},
  {NOTE_G4, 2,2},
  {NOTE_D4, 4,2},
  {NOTE_FS4, 1,2},
  {NOTE_E4, 1,2},
  {NOTE_B4, 8,3},
  {NOTE_B4, 2,3},
  {NOTE_A4, 2,3},
  {NOTE_G4, 2,2},
  {NOTE_D4, 4,2},
  {NOTE_FS4, 1,2},
  {NOTE_AS4, 1,3},
  {REST, 2,-1},
  {NOTE_E4, 2,2},
  {NOTE_FS4, 8,2},
  {NOTE_E4, 8,2},
  {NOTE_D4, 8,2},
  {NOTE_B3, 2,2},
  {NOTE_D4, 8,2},
  {NOTE_E4, 8,2},
  {NOTE_D4, 8,2},
  {NOTE_E4, 8,2},
  {NOTE_D4, 8,2},
  {NOTE_E4, 8,2},
  {NOTE_D4, 8,2},
  {NOTE_E4, 8,2},
  {NOTE_D4, 8,2},
  {NOTE_E4, 8,2},
  {NOTE_B4, 2,3},
  {REST, 2,-1},
  {NOTE_E4, 2,2},
  {NOTE_FS4, 8,2},
  {NOTE_E4, 8,2},
  {NOTE_D4, 8,2},
  {NOTE_B3, 2,2},
  {NOTE_D4, 8,2},
  {NOTE_E4, 8,2},
  {NOTE_D4, 8,2},
  {NOTE_E4, 8,2},
  {NOTE_D4, 8,2},
  {NOTE_E4, 8,2},
  {NOTE_B4, 2,3},
  {REST, 2,-1},
  {NOTE_B3, 8,2},
  {NOTE_B3, 8,2},
  {NOTE_B3, 8,2},
  {NOTE_D4, 2,2},
  {NOTE_CS4, 2,2},
  {NOTE_B3, 2,2},
  {NOTE_FS3, 8,2},
  {NOTE_E3, 4,2},
  {NOTE_FS3, 4,2},
  {NOTE_FS4, 8,2},
  {NOTE_B4, 4,3},
  {NOTE_FS4, 8,2},
  {NOTE_E4, 2,2},
  {REST, 2,-1},
  {NOTE_B3, 8,2},
  {NOTE_B3, 8,2},
  {NOTE_B3, 8,2},
  {NOTE_D4, 2,2},
  {NOTE_CS4, 2,2},
  {NOTE_B3, 2,2},
  {NOTE_FS3, 8,2},
  {NOTE_E3, 4,2},
  {NOTE_FS3, 4,2},
  {NOTE_FS4, 8,2},
  {NOTE_B4, 4,3},
  {NOTE_FS4, 8,2},
  {NOTE_E4, 2,2},
  {REST, 1,-1}
};

const hit* cancion = cancion_larga;


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
  SR595N_init();
  
  pinMode(PIN, OUTPUT);
  pinMode(BIEN, OUTPUT);
  pinMode(MAL, OUTPUT);
  pinMode(IN_3, INPUT);
  pinMode(IN_2, INPUT);
  pinMode(IN_1, INPUT);
  pinMode(IN_0, INPUT);

  for(int i= 0; i < sizeof(carriles)/sizeof(carriles[0]); i++)
  {
    for(int j = 0; j < 5; j++)
    {
      pinMode(carriles[i][j], OUTPUT);
    }
  }
  
  lastTime = millis();
  hitTimestamp = lastTime;
  //setupSR();
}

int _state = 0;
void turnLED(int color, int index, int ON = 1){
  //writeVal(0xfffffffffffffffffffff);
  grid.turnLed(color,index,ON);
}

void clearLEDs(){
  grid.clear();
  grid.paint();
}

void paintLEDs(float nextTransition){
  float step = calculateDuration(16);
  float offset = calculateDuration(16);

  for(int futureCount=0;futureCount<8;futureCount++){
    float destination = lastTime + futureCount*step;
    int* color = nullptr;
    float diff = lastTime - hitTimestamp;
    if(futureCount == 0){
      if(diff < offset)
      {
        turnLED(cancion[currentHit].canal,0, cancion[currentHit].nota != REST);
      }
    }
    else if(abs(destination-nextTransition)<=offset/2 )
    {
      turnLED(cancion[currentHit + 1].canal,futureCount, cancion[currentHit+1].nota != REST);
    }

  }
  grid.paint();
}

void ledsReset()
{
  currentHit = 0;
  lastTransition = 0;
  
  lastTime = millis();
  hitTimestamp = lastTime;
}

void checkInput(){
  digitalWrite(MAL,0);
  digitalWrite(BIEN,0);

  // if(digitalRead(IN_0)==HIGH){}
  // return;
  switch(cancion[currentHit].canal){
    case 0:{
      if(digitalRead(IN_0)){
        digitalWrite(BIEN,1);
      }else{
        digitalWrite(BIEN,0);
        digitalWrite(MAL,1);
      }
      break;
    }
    case 1:{
      if(digitalRead(IN_1)){
        digitalWrite(BIEN,1);
      }else{
        digitalWrite(BIEN,0);
        digitalWrite(MAL,1);
      }
      break;
    }
    case 2:{
      if(digitalRead(IN_2)){
        digitalWrite(MAL,0);
        digitalWrite(BIEN,1);
      }else{
        digitalWrite(BIEN,0);
        digitalWrite(MAL,1);
      }
      break;
    }
    case 3:{
      if(digitalRead(IN_3)){
        digitalWrite(MAL,0);
        digitalWrite(BIEN,1);
      }else{
        digitalWrite(BIEN,0);
        digitalWrite(MAL,1);
      }
      break;
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

  checkInput();


  paintLEDs(nextTransition);
  return true;
}
