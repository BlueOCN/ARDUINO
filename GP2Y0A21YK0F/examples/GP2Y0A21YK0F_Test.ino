//-----------------------------------------------------//
//--------------------- Libraries ---------------------//
#include "Arduino.h"
#include "GP2Y0A21YK0F.h"
//-----------------------------------------------------//
//-------------------- Definitions ------------------- //
#define IR_pin A0
//---------------------- LAYOUT ---------------------- //
//                      ---------
//                     |   Tx    |
//               ------|         |
// To Micro     |  Vo  | GP2Y0A  | -0.3 to Vcc+0.3
// To ground    | GND  | 21YK0F  | 0V Typ
// -0.3V to +7V | VCC  |         | 5V Typ
//               ------|         |
//                     |   Rx    |
//                      ---------
//-----------------------------------------------------//
//--------------------- Objects -----------------------//
GP2Y0A21YK0F IR (  IR_pin  );
//-----------------------------------------------------//
//---------------------- Setup ------------------------//
void setup() {
  // put your setup code here, to run once:

}
//-----------------------------------------------------//
//---------------------- Loop -------------------------//
void loop() {
  IR.GP2Y0A21YK0F_test_();
}
//-----------------------------------------------------//
//--------------------- Methods -----------------------//
