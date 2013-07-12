/*
  Shift Register Example
 for 74HC595 shift register

 This sketch turns reads serial input and uses it to set the pins
 of a 74HC595 shift register.

 Hardware:
 * 74HC595 shift register attached to pins 2, 3, and 4 of the Arduino,
 as detailed below.
 * LEDs attached to each of the outputs of the shift register

 Created 22 May 2009
 Created 23 Mar 2010
 by Tom Igoe

 */

//Pin connected to latch pin (ST_CP) of 74HC595
const int latchPin = 8;
//Pin connected to clock pin (SH_CP) of 74HC595
const int clockPin = 12;
////Pin connected to Data in (DS) of 74HC595
const int dataPin = 11;
int addButton = 4;
int decButton = 7;
int powerOut = 5;
int x = 0;
void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(addButton,INPUT);
  pinMode(decButton,INPUT);
  pinMode(powerOut,OUTPUT);

}

void loop() {
  //count up routine
  int addState = digitalRead(addButton);
  int decState = digitalRead(decButton);
  if (addState == HIGH && x < 9){
    x = x + 1;
    delay(200);
  }
  if (decState == HIGH && x > 0){
    x = x - 1;
    delay(200);
  }
    num(x);
    analogWrite(powerOut,x*28);
}

void num(int x) //num(x),显示数字x
{
switch(x)
{
default: //0
digitalWrite(latchPin,0);
shiftOut(dataPin,clockPin,MSBFIRST,3);
digitalWrite(latchPin,1);
break;
case 1: //1
digitalWrite(latchPin,0);
shiftOut(dataPin,clockPin,MSBFIRST,159);
digitalWrite(latchPin,1);
break;
case 2: //2
digitalWrite(latchPin,0);
shiftOut(dataPin,clockPin,MSBFIRST,37);
digitalWrite(latchPin,1);
break;
case 3: //3
digitalWrite(latchPin,0);
shiftOut(dataPin,clockPin,MSBFIRST,13);
digitalWrite(latchPin,1);
break;
case 4: //4
digitalWrite(latchPin,0);
shiftOut(dataPin,clockPin,MSBFIRST,153);
digitalWrite(latchPin,1);
break;
case 5: //5
digitalWrite(latchPin,0);
shiftOut(dataPin,clockPin,MSBFIRST,73);
digitalWrite(latchPin,1);
break;
case 6: //6
digitalWrite(latchPin,0);
shiftOut(dataPin,clockPin,MSBFIRST,65);
digitalWrite(latchPin,1);
break;
case 7: //7
digitalWrite(latchPin,0);
shiftOut(dataPin,clockPin,MSBFIRST,27);
digitalWrite(latchPin,1);
break;
case 8: //8
digitalWrite(latchPin,0);
shiftOut(dataPin,clockPin,MSBFIRST,1);
digitalWrite(latchPin,1);
break;
case 9: //9
digitalWrite(latchPin,0);
shiftOut(dataPin,clockPin,MSBFIRST,9);
digitalWrite(latchPin,1);
break;
}
}

void cls() //清屏
{
digitalWrite(latchPin,LOW);
shiftOut(dataPin,clockPin,MSBFIRST,255);
digitalWrite(latchPin,HIGH);
}
