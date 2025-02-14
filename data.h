struct songInfo
{
  String name;
  int highScore;
};
  
struct melody
{
  int nota;
  int duracion;
  int canal;
};

struct level
{
  songInfo information;
  int tempo;
  int duration;
  melody song[];
};

const level prueba = {
  { "Prueba", 20 }, 240,
  14, {
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
    {REST, 1,-1}
  }
};

const level pipopipo = {
  {"pipopipo", 10}, 100,
  14, {
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
  }
};

const melody otracancion[] = {
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
  {REST, 1,-1}
};

const melody cancion3[]={ // tempo 240
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

const melody cancion4[] = {
  
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

const melody cancion_larga[]={
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

const melody enemy[]= {
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

const melody micancion[] = {
  
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
