/*
** Rotary Encoder Example Application
** Two rotary encoders with output to the Serial monitor
*/

#include <RotaryEncoder.h>

const byte ENCODER1_PINA= 2;
const byte ENCODER1_PINB= 3;
const byte ENCODER2_PINA= 4;
const byte ENCODER2_PINB= 5;

ROTARY_ENCODER r_encoder1(ENCODER1_PINA, ENCODER1_PINB, 5);
ROTARY_ENCODER r_encoder2(ENCODER2_PINA, ENCODER2_PINB, 5);

// setup ********************************************
void setup() {
  Serial.begin(9600);
}

void loop() {
  r_encoder1.update();
  r_encoder2.update();
  
  if (r_encoder1.newVal){
    Serial.print("Dial 1: ");
    Serial.println(r_encoder1.value);
    r_encoder1.newVal=false;
  }
  
  if (r_encoder2.newVal){
    Serial.print("Dial 2: ");
    Serial.println(r_encoder2.value);
    r_encoder2.newVal=false;
  }
} 



