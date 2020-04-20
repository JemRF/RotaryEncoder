/*
* The MIT License (MIT)
*
* Copyright (c) JEMRF
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
********************************************************************************
*
* Module     : RotaryEncoder.cpp
* Author     : Jonathan Evans
* Description: Rotary Encoder Driver
*
* A rotary encoder converts the angular position (rotation) of a knob into an output signal that is 
* used to determine what direction the knob is being rotated. They have three pins, two for digital input 
* and one for GROUND. The outer pins are the digital inputs and the middle pin is ground. Some come with 
* labelled pins on breakout boards.  
*
* Library Description
*
*  - This library detects the clockwise or anti-clockwise motion of the rotary encoder and increments 
*    or decrements the value by 1  
*  - A debounce routine is used to smooth out fluctuation in signal. The debounce can be fine tuned with the 
*    parm_milles parameter and is set to 5ms by default
*  - The update method updates the new value of the dial in "value" and sets the newVal flag
*    that can be monitored 
*/

#include "RotaryEncoder.h"

ROTARY_ENCODER::ROTARY_ENCODER(int parm_pinA, int parm_pinB, unsigned int parm_millis)
{
  pinA = parm_pinA;
  pinB = parm_pinB;
  interval_millis = parm_millis;
  pinMode(pinA,INPUT_PULLUP);
  pinMode(pinB,INPUT_PULLUP);
  newVal=false;
}

void ROTARY_ENCODER::debounce(){
    int val;
    val = digitalRead(pinA);
    if ( val != valueA ) {
      if ( millis() - previous_millis_a >= interval_millis ) {
          valueA^=1;
          previous_millis_a = millis();
      }
      else {
        previous_millis_a = millis();
      }
    }

    val = digitalRead(pinB);
    if ( val != valueB ) {

      if ( millis() - previous_millis_a >= interval_millis ) {
          valueB^=1;
          previous_millis_b = millis();
      }
      else {
        previous_millis_b = millis();
      }
    }
}

void ROTARY_ENCODER::update()
{
  debounce();
  if (valueA && valueB && rotated ) 
  {
    if (clockwise)
    {
      value=value+1;
    }
    else 
    {
      value=value-1;
    }
    rotated = false;
    newVal=true;
  }
  if (valueA && !valueB && !rotated ) 
  {
    clockwise= true;
    rotated=true;
  }
  if (!valueA && valueB && !rotated ) 
  {
    clockwise= false;
    rotated=true;
  }
} 

