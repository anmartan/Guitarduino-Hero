bool inMenu = false;

void setup() {
  // put your setup code here, to run once:
  menuSetup();
  ledsSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(inMenu){
    while(menuLoop());
  }
  else
  {
    ledsReset();
    while(ledsLoop());
  }
  //inMenu = !inMenu;
}