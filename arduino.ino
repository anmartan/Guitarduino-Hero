// struct Shift_Register_595N
// {
//   byte SER;
//   byte RCLK;
//   byte SCLK;
// };
// #define NUM_BITS_IN_BYTE 8

// Shift_Register_595N sr1 = 
// {
//     .SER = 4,
//     .RCLK = 5,
//     .SCLK = 6
// };

// /*
//  * setup() - this function runs once when you turn your Arduino on
//  * We initialize the serial connection with the computer
//  */
// void setup() 
// {
//   // Set all the pins of 74HC595 as OUTPUT
//     pinMode( sr1.SER, OUTPUT);
//     pinMode( sr1.RCLK, OUTPUT);
//     pinMode( sr1.SCLK, OUTPUT);
// }

// /*
//  * loop() - this function runs over and over again
//  */


// void writeVal ( const Shift_Register_595N * const sr , uint16_t val )
// {
//     uint8_t counter;
//     byte shiftVal;

//     for ( counter = 0; counter < NUM_BITS_IN_BYTE*2 ; counter++ )
//     {
//         shiftVal = ( val & 0x01 );
//         digitalWrite ( sr->SER, shiftVal );
//         digitalWrite ( sr->SCLK, HIGH);
//         digitalWrite ( sr->SCLK, LOW);
//         val = val >> 1;
//     }
//     digitalWrite ( sr->RCLK, HIGH);
//     digitalWrite ( sr->RCLK, LOW);
// }

// void loop() 
// {
//  //writeVal(&sr1, 0x0000000001000000);
//  writeVal(&sr1, 0x8000);
// }