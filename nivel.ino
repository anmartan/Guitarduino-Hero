const int PIN = 11;

const int BIEN=13;
const int MAL=12;
const int IN_3=A3;
const int IN_2=A2;
const int IN_1=A1;
const int IN_0=A0;

int currentScore = 0;
float multiplierAcrossNotes = 1;
float multiplierCurrentNote = 1;

uint32_t lastTime;
float deltaTime;
int currentHit = 0;
uint32_t hitTimestamp;
float lastTransition = 0;
int tempo = 240;

const level* level;
const melody* cancion;


float calculateDuration(float duration)
{
  return ((60000 * 4) / tempo) / duration;
}

void nextHit(){
  currentHit++;
  tone(PIN, cancion[currentHit].nota, calculateDuration(cancion[currentHit].duracion));
  
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
  
  lastTime = millis();
  hitTimestamp = lastTime;
  //setupSR();
}

int _state = 0;
void turnLED(int color, int index, int ON = 1){
  grid.turnLed(color, index, ON);
}

void clearLEDs()
{
  grid.clear();
  grid.paint();
}

void paintLEDs(float nextTransition)
{
  float step = calculateDuration(16);
  float offset = calculateDuration(16);

  for(int futureCount=0;futureCount<8;futureCount++){
    float destination = lastTime + futureCount*step;
    int* color = nullptr;
    float diff = lastTime - hitTimestamp;
    if(futureCount == 0){
      turnLED(cancion[currentHit].canal,0, cancion[currentHit].nota != REST);
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
  level = &pipopipo;
  cancion = level->song;
  tempo = level->tempo;
  currentHit = 0;
  lastTransition = 0;
  currentScore = 0;
  multiplierAcrossNotes = 1;
  multiplierCurrentNote = 1;
  
  lastTime = millis();
  hitTimestamp = lastTime;
}

void setScore(int input)
{
  // The more time the input is correct, the more rewarding it is
  if(cancion[currentHit].canal == input)
  {
    currentScore += 1 * multiplierCurrentNote * multiplierAcrossNotes;

    multiplierCurrentNote += 0.1f;
    
    digitalWrite(BIEN,1);
    digitalWrite(MAL,0);
  }

  // If failing, the multipliers are reset
  else
  {
    multiplierCurrentNote = 1;
    multiplierAcrossNotes = 1;

    digitalWrite(BIEN,0);
    digitalWrite(MAL,1);
  }
}
/*
int currentScore = 0;
float multiplierAcrossNotes = 1;
float multiplierCurrentNote = 1;
*/
void checkInput(){
  digitalWrite(MAL,0);
  digitalWrite(BIEN,0);

  if(digitalRead(IN_0)) setScore(0);
  if(digitalRead(IN_1)) setScore(1);
  if(digitalRead(IN_2)) setScore(2);
  if(digitalRead(IN_3)) setScore(3);
}

bool ledsLoop() {
  bool songIsOver = currentHit+1 == prueba.duration;
  
  deltaTime = (millis() - lastTime) / 1000;
  lastTime = millis();
  float nextTransition= hitTimestamp + calculateDuration(cancion[currentHit].duracion);
  bool nextIsSilence = songIsOver || cancion[currentHit + 1].nota == 0;
  bool currentIsSilence = cancion[currentHit].nota == 0;

  clearLEDs();
  
  if(nextTransition < lastTime)
  {
    if(songIsOver){
      noTone(PIN);
      clearLEDs();
      return false;
    } 
    nextHit();
  }

  checkInput();


  paintLEDs(nextTransition);
  return true;
}
