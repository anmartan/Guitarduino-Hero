#define NUM_BITS_IN_BYTE 8

struct Shift_Register_595N
{
  byte SER;
  byte RCLK;
  byte SCLK;
};

inline uint32_t bit_set_to(uint32_t number, uint32_t n, bool x) 
{
  return (number & ~((uint32_t)1 << n)) | ((uint32_t)x << n);
}

class LEDGrid{
  public:
  uint32_t _state = 0x00000000;
  void clear(){
    _state=0x00000000;
  };
  void paint(){
    SR595N_writeVal(_state);
  };
  void turnLed(int color, int index, int on=1){
    _state=bit_set_to(_state,(color*8)+index,on);
  };
};

Shift_Register_595N sr = 
{
  .SER = 4,
  .RCLK = 5,
  .SCLK = 6
};

void SR595N_init()
{
  pinMode( sr.SER, OUTPUT);
  pinMode( sr.RCLK, OUTPUT);
  pinMode( sr.SCLK, OUTPUT);
}

void SR595N_writeVal ( uint32_t val )
{
  uint8_t counter;
  uint32_t shiftVal;

  for ( counter = 0; counter < NUM_BITS_IN_BYTE * 4 ; counter++ )
  {
    shiftVal = ( val & 0x01 );
    digitalWrite ( sr.SER, shiftVal );
    digitalWrite ( sr.SCLK, HIGH);
    digitalWrite ( sr.SCLK, LOW);
    val = val >> 1;
  }
  digitalWrite ( sr.RCLK, HIGH);
  digitalWrite ( sr.RCLK, LOW);
}

LEDGrid grid;

void shiftPattern() 
{
  uint32_t val = 0x0001;
  uint8_t counter;

  for(int i =0;i<4;i++){
    for(int j =0;j<8;j++){
      grid.clear();
      grid.turnLed(i,j);
      grid.paint();
      delay(100);
    }
  }
}