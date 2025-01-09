#pragma once
#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,7,8,9,10);
int joystickYAxis = A4;
int joystickButton = A5;

class Menu 
{
public:


  songInfo songs[5];  // poner aqui las que sean

  int sizeOfArray;    // solo para no estar haciendo sizeof todo el rato    
  int songDisplayed;  // indice de la que se esta mostrando 

  Menu()
  {
    songs[0] = { "primera", 50 };
    songs[1] = { "segunda", 150 };
    songs[2] = { "tercera", 250 };
    songs[3] = { "cuarta", 520 };
    songs[4] = { "quinta", 350 };
    
    lcd.begin(16,2);
    songDisplayed = 0;
    sizeOfArray = sizeof(songs) / sizeof(songInfo);
  }

  void move(bool next)
  {
    if (next) songDisplayed = (songDisplayed + 1) % sizeOfArray;
    else 
    {
      if (songDisplayed <= 0) songDisplayed = sizeOfArray;
      songDisplayed--;
    }
  }

  void show()
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(songs[songDisplayed].name);

    lcd.setCursor(0,1);
    lcd.print(songs[songDisplayed].highScore);
  }

  void update(int score)
  {
    if (score > songs[songDisplayed].highScore)
      songs[songDisplayed].highScore = score;
  }

  songInfo select() 
  {
    return songs[songDisplayed];
  }

  void clear()
  {
    lcd.clear();
  }
};

Menu menu;

void menuSetup()
{
  Serial.begin(9600);
  pinMode(joystickButton , INPUT_PULLUP);
  menu.show();
}

bool menuLoop()
{
  int Yvalue = 0;
  int buttonValue = 0;

  Yvalue = analogRead(joystickYAxis);
  Serial.println(Yvalue);
  if(Yvalue < 100) 
  {
    menu.move(false);
    menu.show();
    delay(250);
    return true;
  }
  else if (Yvalue > 850) 
  {
    menu.move(true);
    menu.show();
    delay(250);
    return true;
  }

  buttonValue = digitalRead(joystickButton);
  if(!buttonValue)
  {
    menu.select();
    return false;
  }
  menu.show();
  delay(100);
  return true;
}
