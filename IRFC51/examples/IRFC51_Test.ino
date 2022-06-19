//-----------------------------------------------------//
//--------------------- Libraries ---------------------//
#include "Arduino.h"
#include "IRFC51.h"
//-----------------------------------------------------//
//-------------------- Definitions ------------------- //
#define SIGNAL_pin A0
//---------------------- LAYOUT ---------------------- //
//                      -----------------------------
// Digital pin    OUT  |                        | TX |
// Micro GND      GND  |        IR FC-51        | ---
// Micro VCC      VCC  |                        | RX |
//                      -----------------------------
//-----------------------------------------------------//
//--------------------- Objects -----------------------//
IRFC51 IR_Sensor (  SIGNAL_pin  );
//-----------------------------------------------------//
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  Serial.begin(9600);
  IR_Sensor.detect_object();
  Serial.println(IR_Sensor.get_object());
  Serial.end();
}
