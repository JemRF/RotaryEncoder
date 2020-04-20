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
*********************************************************************************
*
* Module     : RotaryEncoder.h
* Author     : Jonathan Evans
* Description: Rotary Encoder
*
********************************************************************************
*/

#ifndef RotaryEncoder_h
#define RotaryEncoder_h

#include <Arduino.h>


class ROTARY_ENCODER
{
private:
  int pinA;
  int pinB;
  unsigned int previous_millis_a;
  unsigned int previous_millis_b;
  unsigned int interval_millis;
  int valueA;
  int valueB;
  int rotated;
  int clockwise;
  
public: 
  ROTARY_ENCODER(int parm_pinA, int parm_pinB, unsigned int parm_millis);
  void debounce();
  void update();
  int value;
  int newVal;

};

#endif