/* 

SPDX-FileCopyrightText: © 2023 Silvia Binda Heiserova silviaheiserova@gmail.com

SPDX-License-Identifier: MIT

Conversatorio, pieza 3
por Silvia Binda Heiserova, 2023

   __________  _   ___    ____________ _____ ___  __________  ____  ________ 
  / ____/ __ \/ | / | |  / / ____/ __ / ___//   |/_  __/ __ \/ __ \/  _/ __ \
 / /   / / / /  |/ /| | / / __/ / /_/ \__ \/ /| | / / / / / / /_/ // // / / /
/ /___/ /_/ / /|  / | |/ / /___/ _, ____/ / ___ |/ / / /_/ / _, __/ // /_/ / 
\____/\____/_/ |_/  |___/_____/_/ |_/____/_/  |_/_/  \____/_/ |_/___/\____/  
                                                                             
 __                                 __         __     
/\ \                               /\ \      /'__`\   
\ \ \____    ___      __     _ __  \_\ \    /\_\L\ \  
 \ \ '__`\  / __`\  /'__`\  /\`'__\/'_` \   \/_/_\_<_ 
  \ \ \L\ \/\ \L\ \/\ \L\.\_\ \ \//\ \L\ \    /\ \L\ \
   \ \_,__/\ \____/\ \__/.\_\\ \_\\ \___,_\   \ \____/
    \/___/  \/___/  \/__/\/_/ \/_/ \/__,_ /    \/___/ 

                                                       
Conversatorio, board 3
by Silvia Binda Heiserova, 2023                                             

About Conversatorio: 
Conversatorio is a series of feminist electronic and digital artworks, using various components, microcontrollers, modules and code.
It includes a series of 8 boards, conceptualized as open hardware artistic feminist devices, 
designed and assembled in such manner so they uncover what usually is hidden. 
These boards are open source and transparent, all its components are visible so everybody can see what these technologies consists of. 
Beside calling for openism and transparency, the boards from Conservatorio series are determined by the number 78:

                                                                           
77777777777777777777     888888888     
7::::::::::::::::::7   88:::::::::88   
7::::::::::::::::::7 88:::::::::::::88 
777777777777:::::::78::::::88888::::::8
           7::::::7 8:::::8     8:::::8
          7::::::7  8:::::8     8:::::8
         7::::::7    8:::::88888:::::8 
        7::::::7      8:::::::::::::8  
       7::::::7      8:::::88888:::::8 
      7::::::7      8:::::8     8:::::8
     7::::::7       8:::::8     8:::::8
    7::::::7        8:::::8     8:::::8
   7::::::7         8::::::88888::::::8
  7::::::7           88:::::::::::::88 
 7::::::7              88:::::::::88   
77777777                 888888888     
                                       

In 2023, up until today, September 15th, 78 women were assassinated in Spain for mysoginistic and sexist motives (data source: feminicidio.net). 
Every board from Conversatorio is coded so that it visually or sonically represents the number of these hate crimes, 
which in Spanish language are called "feminicidios". 
Alltogether, when entering the space of the open hardware boards ensamblage, visitors find themselves encircled 
by seemingly unpredictable soundscapes that are predetermined by data representing gender violance in its worst consequences. 
Simultaneously, the number 78 is visualised in subtle and almost invisible way, just like gender violance is persisting 
in our day to day lived societies throughout the year.

About board 3:
In the code written for board 3, the number 78 reappears as sonic representation in 8-bit retro game style. The number 78 is used repetitively for the creation of a sound sequence whose parameters -such as the frequency and duration - are pseudo-randomized in the limits of the number 78 and its variants (7.8, 7, 8, 780 etc.)

________________________________________________________________________________________________________________
This code is part of the physical electronic and digital artwork.

Complete list of board 3 components:
1) 19cm x 19cm custom designed perforated board, 3D printed with black PLA fillament
2) custom designed holder for LM386 Amplifier, 3D printed with black PLA fillament
3) custom designed holder for Mini Speaker 4Ω (3W), 3D printed with black PLA fillament
4) custom designed holder for breadboard (M), 3D printed with black PLA fillament
5) Arduino UNO R3 microcontroller
6) LM386 Amplifier
7) Mini Speaker 4Ω (3W) with dimensions: 40x40x20mm
8) Solderless mini breadboard with 55 pins, black color
9) 3x red color LED diodes
10) 3x resistor (220Ω)
11) Maxbotic MB1000 LV-MaxSonar-EZ0 ultrasonic range finder 
12) Black and aluminium color M3 screws, nuts and hexagonal standoff spacers
13) Black USB type A to USB type B cable, 3m long (powering the ESP32 microcontroller)
14) Custom made wires with dupont connectors of different colors and lengths
15) Code
________________________________________________________________________________________________________________

This code is run on Arduino UNO microcontroller connected to the amplifier and speaker, 3 LED diodes and the ultrasound sensor.

LM386 Amplifier module has assigned following Arduino pins:
VCC (orange wire) = Arduino 3.3V pin 
IN (yellow wire) = Arduino GPIO 6
GND (grey wire) = Arduino GND pin
The Speaker is connected via wires to the LM386 Amplifier.

3x LED diodes and 3x 220Ω resistors are connected to the 55 pin breadboard mounted on the board:
negatives of the LED diodes are conected to Arduino GND PIN via breadboard (white wire)
+ diode 1 = Arduino GPIO 9
+ diode 2 = Arduino GPIO 10
+ diode 3 = Arduino GPIO 11

Ultrasonic range finder has assigned following Arduino pins:
TX (orange wire) = Arduino GPIO D3
RX (yellow wire) = Arduino GPIO D4
VCC (red wire) = Arduino GPIO VIN
GND (brown wire) = Arduino GND pin

________________________________________________________________________________________________________________

ACKNOWLEDGMENTS: 
Thanks to patorjk.com for sharing the TAAG. 
Fonts used for the ASCII art texts are Slant, Larry 3D (larry3d.flf by Larry Gelberg larryg@avs.com) and Doh.
This code uses code snippets of Multiple tone player by Tom Igoe that is based on a snippet from Greg Borenstein.
*/

// Include following libraries
#include "pitches.h" //library for playing specific tones
#include <SoftwareSerial.h> //for the maxbotix sensor

int melody[] = {
  NOTE_DS2, NOTE_DS2, NOTE_DS2
};

// note durations logic: 4 = quarter note, 8 = eighth note, etc.
int noteDurations[] = {
  78
};

SoftwareSerial mySerial(3, 4,true); // TX (orange) on pin D3, RX (yellow) on pin D4
int BW=4;
char *buffer;
byte x;
char array[3];
int counter=0;

#define LED_PIN 9
#define LED_PIN_1 10
#define LED_PIN_2 11

int PIN_speaker = 6; //on Arduino UNO it can be any digital PIN (connected via the amplifier)

long frequency;
long duration;

void realRandomFreq() 
{
  frequency = random(78, 780);
}

void realRandomDuration() 
{
  duration = random(7.8, 78);
}

void setup() 
{
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(BW,OUTPUT);
  digitalWrite(BW,LOW);
  delay(250);
  Serial.println("Calibrartion Cycle ");
  delay(150);
  
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);

  Serial.begin(9600);
  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0));
  
}

void playsound() {

  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 78*3; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    //int noteDuration = 7800 / noteDurations[thisNote]; //other good options are 780, 7800
    int noteDuration = noteDurations[thisNote]*1.78; //other good options are 780, 7800
    tone(PIN_speaker, melody[thisNote], noteDuration); //number of PIN speaker

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.78;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(78);
  }
}

void reading()
{
  mySerial.println(1);
  while (mySerial.available())
  {
   x= mySerial.readBytes(buffer,1);
   if(*buffer==0x52)
    { 
      x= mySerial.readBytes(buffer,1);
      array[0]=*buffer; 
      x= mySerial.readBytes(buffer,1);
      array[1]=*buffer; 
      x= mySerial.readBytes(buffer,1);
      array[2]=*buffer;
    }
  }
}
void loop()
{ 
  reading();
  int Final_inch=(array[0]-48)*100 + (array[1]-48)*10 +(array[2]-48) ;
  float Final_cm=Final_inch*2.54;
  Serial.print(Final_cm);
  Serial.println(" cm ");
  delay(200);
  if (Final_cm < 80)
  {
    digitalWrite(LED_PIN, HIGH);  // turn the LED on (HIGH is the voltage level)                  
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);  
    delay(78); 
    digitalWrite(LED_PIN, LOW);  // turn the LED on (HIGH is the voltage level)                  
    digitalWrite(LED_PIN_1, LOW);  
    digitalWrite(LED_PIN_2, LOW);  
    delay(78); 
    digitalWrite(LED_PIN, HIGH);  // turn the LED on (HIGH is the voltage level)                  
    digitalWrite(LED_PIN_1, HIGH);  
    digitalWrite(LED_PIN_2, HIGH); 
    delay(78); 
    digitalWrite(LED_PIN, LOW);  // turn the LED on (HIGH is the voltage level)                  
    digitalWrite(LED_PIN_1, LOW);  
    digitalWrite(LED_PIN_2, LOW);  
    delay(78); 
    digitalWrite(LED_PIN, HIGH);  // turn the LED on (HIGH is the voltage level)                  
    digitalWrite(LED_PIN_1, HIGH);  
    digitalWrite(LED_PIN_2, HIGH); 
    delay(78); 
    digitalWrite(LED_PIN, LOW);  // turn the LED on (HIGH is the voltage level)                  
    digitalWrite(LED_PIN_1, LOW);
    digitalWrite(LED_PIN_2, LOW);  
    delay(78); 
    digitalWrite(LED_PIN, HIGH);  // turn the LED on (HIGH is the voltage level)                  
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH); 

   // play a note on pin 8 for 78 ms:
    playsound();

    digitalWrite(LED_PIN_1, LOW);  // turn the LED on (HIGH is the voltage level)
    digitalWrite(LED_PIN, LOW);   // turn the LED off by making the voltage LOW
    digitalWrite(LED_PIN_2, LOW);
  }

  else

  {
    digitalWrite(LED_PIN_1, LOW);  // turn the LED on (HIGH is the voltage level)
    digitalWrite(LED_PIN, LOW);   // turn the LED off by making the voltage LOW
    digitalWrite(LED_PIN_2, LOW);
  }
}

//last time this code was edited with Arduino IDE 2.2.1 on November 20, 2023