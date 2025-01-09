#include "pitches.h"
#include "data.h"

bool inMenu = true;

void setup() 
{
Serial.begin(9600);
  menuSetup();
  ledsSetup();
}

void loop() 
{
  if(inMenu){
    while(menuLoop());
    inMenu = !inMenu;
  }
  else
  {
    ledsReset();
    while(ledsLoop());
    
    inMenu = true;
  }
}