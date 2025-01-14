/* 

SPDX-FileCopyrightText: © 2023 Silvia Binda Heiserova silviaheiserova@gmail.com

SPDX-License-Identifier: MIT

Conversatorio, pieza 6
por Silvia Binda Heiserova, 2023

   __________  _   ___    ____________ _____ ___  __________  ____  ________ 
  / ____/ __ \/ | / | |  / / ____/ __ / ___//   |/_  __/ __ \/ __ \/  _/ __ \
 / /   / / / /  |/ /| | / / __/ / /_/ \__ \/ /| | / / / / / / /_/ // // / / /
/ /___/ /_/ / /|  / | |/ / /___/ _, ____/ / ___ |/ / / /_/ / _, __/ // /_/ / 
\____/\____/_/ |_/  |___/_____/_/ |_/____/_/  |_/_/  \____/_/ |_/___/\____/  
                                                                             
 __                                 __        ____    
/\ \                               /\ \      /'___\   
\ \ \____    ___      __     _ __  \_\ \    /\ \__/   
 \ \ '__`\  / __`\  /'__`\  /\`'__\/'_` \   \ \  _``\ 
  \ \ \L\ \/\ \L\ \/\ \L\.\_\ \ \//\ \L\ \   \ \ \L\ \
   \ \_,__/\ \____/\ \__/.\_\\ \_\\ \___,_\   \ \____/
    \/___/  \/___/  \/__/\/_/ \/_/ \/__,_ /    \/___/ 
                                                      
                                                       
Conversatorio, board 6
by Silvia Binda Heiserova, 2023                                             

About Conversatorio: 
Conversatorio is a series of feminist electronic and digital artworks, using various components, microcontrollers, modules and code.
It includes a series of 8 boards, conceptualized as open hardware artistic feminist devices, designed and assembled in such manner so they uncover what usually is hidden. 
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
Every board from Conversatorio is coded so that it visually or sonically represents the number of these hate crimes, which in Spanish language are called "feminicidios". 
Alltogether, when entering the space of the open hardware boards ensamblage, visitors find themselves encircled by seemingly unpredictable soundscapes that are predetermined by data representing gender violance in its worst consequences. 
Simultaneously, the number 78 is visualised in subtle and almost invisible way, just like gender violance is persisting in our day to day lived societies throughout the year.

About board 6:
This board contains a numeric 7-segment display build out of 21 blue led diodes. It only can show one number at a time. 
The number 78 is shown in intervals, where the bumber 7 appears for a half of second, followed by the number 8 appearing for half of a second and a 5 second break until the cycle begins from start.
________________________________________________________________________________________________________________
This code is part of the physical electronic and digital artwork.

Complete list of board 6 components:
1) 19cm x 19cm custom designed perforated board, 3D printed with black PLA fillament
2) Custom designed holder for ESP32 microcontroller, 3D printed with black PLA fillament
3) 7x Custom designed holder for breadboard, size M, 3D printed with black PLA fillament
4) 1x Custom designed holder for breadboard, size S, 3D printed with black PLA fillament
5) ESP32 WROOM microcontroller
6) 21x blue LED diodes
7) 21x resistor (220Ω)
8) 7x Solderless mini breadboard with 55 pins, black color
9) 1x Solderless mini breadboard with 25 pins, black color
10) 2x 3M self adhesive wire clips, black color (attached to the board to hold wires)
11) Black microUSB to USB type B cable, 3m long (powering the ESP32 microcontroller)
12) Custom made wires with dupont connectors of different lengths in blue, white and green colors.
13) Code
________________________________________________________________________________________________________________

The code is run on an ESP32 microcontroller which is connected to the 21 led diodes.
The blue LED diodes are designed and coded to form a 7 segment numeric display.
In each segment, there are 3 LED diodes connected to one pin of the ESP32 WROOM as follows:  

      GPIO23  
        _
GPIO27 |_| GPIO22
GPIO26 |_| GPIO19
      GPIO25
(the cental fragment corresponds to GPIO18)

LED diode cathodes (-) are connected to the GND pin on ESP32 via the breadboard with 25 pins.

There is a color pattern applied to the wiring:
Connections from LED diode anodes (+) => green color wires 
Connections from LED diode cathodes (-) and connection to GND pin of the ESP32 => white color wires
Connection from breadboards size M to respective GPIOs of the ESP32 => blue color wires
________________________________________________________________________________________________________________

ACKNOWLEDGMENTS: 
Thanks to patorjk.com for sharing the TAAG. 
Fonts used for the ASCII art texts are Slant, Larry 3D (larry3d.flf by Larry Gelberg larryg@avs.com) and Doh.

*/

//Define the pins:

int pin_led1 = 23;
int pin_led2 = 22;
int pin_led3 = 19;
int pin_led4 = 18;
int pin_led5 = 27;
int pin_led6 = 26;
int pin_led7 = 25;

//functions for writing numbers:

void num_off ()
{
  digitalWrite(pin_led1, LOW);
  digitalWrite(pin_led2, LOW);
  digitalWrite(pin_led3, LOW);
  digitalWrite(pin_led4, LOW);
  digitalWrite(pin_led5, LOW);
  digitalWrite(pin_led6, LOW);
  digitalWrite(pin_led7, LOW);
}

void num_zero ()
{
  digitalWrite(pin_led1, HIGH);
  digitalWrite(pin_led2, HIGH);
  digitalWrite(pin_led3, HIGH);
  digitalWrite(pin_led4, LOW);
  digitalWrite(pin_led5, HIGH);
  digitalWrite(pin_led6, HIGH);
  digitalWrite(pin_led7, HIGH);
}

void num_one ()
{
  digitalWrite(pin_led1, LOW);
  digitalWrite(pin_led2, HIGH);
  digitalWrite(pin_led3, HIGH);
  digitalWrite(pin_led4, LOW);
  digitalWrite(pin_led5, LOW);
  digitalWrite(pin_led6, LOW);
  digitalWrite(pin_led7, LOW);
}

void num_two ()
{
  digitalWrite(pin_led1, HIGH);
  digitalWrite(pin_led2, HIGH);
  digitalWrite(pin_led3, LOW);
  digitalWrite(pin_led4, HIGH);
  digitalWrite(pin_led5, LOW);
  digitalWrite(pin_led6, HIGH);
  digitalWrite(pin_led7, HIGH);
}

void num_three ()
{
  digitalWrite(pin_led1, HIGH);
  digitalWrite(pin_led2, HIGH);
  digitalWrite(pin_led3, HIGH);
  digitalWrite(pin_led4, HIGH);
  digitalWrite(pin_led5, LOW);
  digitalWrite(pin_led6, LOW);
  digitalWrite(pin_led7, HIGH);
}

void num_four ()
{
  digitalWrite(pin_led1, LOW);
  digitalWrite(pin_led2, HIGH);
  digitalWrite(pin_led3, HIGH);
  digitalWrite(pin_led4, HIGH);
  digitalWrite(pin_led5, HIGH);
  digitalWrite(pin_led6, LOW);
  digitalWrite(pin_led7, LOW);
}

void num_five ()
{
  digitalWrite(pin_led1, HIGH);
  digitalWrite(pin_led2, LOW);
  digitalWrite(pin_led3, HIGH);
  digitalWrite(pin_led4, HIGH);
  digitalWrite(pin_led5, HIGH);
  digitalWrite(pin_led6, LOW);
  digitalWrite(pin_led7, HIGH);
}

void num_six ()
{
  digitalWrite(pin_led1, HIGH);
  digitalWrite(pin_led2, LOW);
  digitalWrite(pin_led3, HIGH);
  digitalWrite(pin_led4, HIGH);
  digitalWrite(pin_led5, HIGH);
  digitalWrite(pin_led6, HIGH);
  digitalWrite(pin_led7, HIGH);
}

void num_seven ()
{
  digitalWrite(pin_led1, HIGH);
  digitalWrite(pin_led2, HIGH);
  digitalWrite(pin_led3, HIGH);
  digitalWrite(pin_led4, LOW);
  digitalWrite(pin_led5, LOW);
  digitalWrite(pin_led6, LOW);
  digitalWrite(pin_led7, LOW);
}

void num_eight ()
{
  digitalWrite(pin_led1, HIGH);
  digitalWrite(pin_led2, HIGH);
  digitalWrite(pin_led3, HIGH);
  digitalWrite(pin_led4, HIGH);
  digitalWrite(pin_led5, HIGH);
  digitalWrite(pin_led6, HIGH);
  digitalWrite(pin_led7, HIGH);
}

void num_nine ()
{
  digitalWrite(pin_led1, HIGH);
  digitalWrite(pin_led2, HIGH);
  digitalWrite(pin_led3, HIGH);
  digitalWrite(pin_led4, HIGH);
  digitalWrite(pin_led5, HIGH);
  digitalWrite(pin_led6, LOW);
  digitalWrite(pin_led7, HIGH);
}

void setup() {
pinMode(pin_led1, OUTPUT);
pinMode(pin_led2, OUTPUT);
pinMode(pin_led3, OUTPUT);
pinMode(pin_led4, OUTPUT);
pinMode(pin_led5, OUTPUT);
pinMode(pin_led6, OUTPUT);
pinMode(pin_led7, OUTPUT);
}

// loop cycle for showing the numbers 7 and 8 and then pause for 5 seconds
void loop() {
num_seven();
delay(500);
num_eight();
delay(500);
num_off();
delay(5000);
}

//last time this code was edited on Arduino IDE 2.2.1 on November 20, 2023