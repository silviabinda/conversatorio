/*
SPDX-FileCopyrightText: © 2023 Silvia Binda Heiserova silviaheiserova@gmail.com

SPDX-License-Identifier: MIT

Conversatorio, pieza 5
por Silvia Binda Heiserova, 2023

   __________  _   ___    ____________ _____ ___  __________  ____  ________ 
  / ____/ __ \/ | / | |  / / ____/ __ / ___//   |/_  __/ __ \/ __ \/  _/ __ \
 / /   / / / /  |/ /| | / / __/ / /_/ \__ \/ /| | / / / / / / /_/ // // / / /
/ /___/ /_/ / /|  / | |/ / /___/ _, ____/ / ___ |/ / / /_/ / _, __/ // /_/ / 
\____/\____/_/ |_/  |___/_____/_/ |_/____/_/  |_/_/  \____/_/ |_/___/\____/  

 __                                 __      ______    
/\ \                               /\ \    /\  ___\   
\ \ \____    ___      __     _ __  \_\ \   \ \ \__/   
 \ \ '__`\  / __`\  /'__`\  /\`'__\/'_` \   \ \___``\ 
  \ \ \L\ \/\ \L\ \/\ \L\.\_\ \ \//\ \L\ \   \/\ \L\ \
   \ \_,__/\ \____/\ \__/.\_\\ \_\\ \___,_\   \ \____/
    \/___/  \/___/  \/__/\/_/ \/_/ \/__,_ /    \/___/ 
                                                                                                                                                            
Conversatorio, board 5
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

About board 5:
To represent the number 78, board 5 uses a laser module pointing on a perperdicular white wall. 
The microcontroller of the boards is coded so that the laser blinks 78 times, 
which is visually reflected as a small red dot blinking on the white wall.
When the cycle ends, tha pink-red backlight turns blue and the laser stops for 12 seconds until it starts the next cycle.

________________________________________________________________________________________________________________
This code is part of the physical electronic and digital artwork.

Complete list of board 5 components:
1) 19cm x 19cm custom designed perforated board, 3D printed with black PLA fillament
2) Custom designed holder for ESP32 microcontroller, 3D printed with black PLA fillament
3) ESP32 WROOM microcontroller
4) KY-008 laser module
5) RGB LED module with common anode
6) 3M self adhesive wire clip, black color (attached to the board to hold the wires)
7) Black micro USB to USB cable 3m long (powering the ESP3 microcontroller)
8) Custom made wires with dupont connectors of different colors and lengths
9) M3 screws and nuts, black and aluminium color 
10) Code
________________________________________________________________________________________________________________

This code is run on ESP32 WROOM microcontroller connected to the laser module and the RGB LED module.

GPIOs for connections:
  Laser module:
    Signal(S) -> GPIO15 (yellow wire) 
    + -> 3V3 PIN (blue wire) 
    - -> GND PIN (white wire)

  RGB LED module:
    + -> VIN (red wire) 
    R -> GPIO 21 (blue wire) 
    G -> GPIO 23 (violet wire)
    B -> GPIO 22 (green wire) 
________________________________________________________________________________________________________________

ACKNOWLEDGMENTS: 
Thanks to patorjk.com for sharing the TAAG. 
Fonts used for the ASCII art texts are Slant, Larry 3D (larry3d.flf by Larry Gelberg larryg@avs.com) and Doh.

*/

#define LASER 15 //GPIO15

#define PIN_GREEN   23 // GPIO23
#define PIN_BLUE 22 // GPIO22
#define PIN_RED   21  // GPIO21

#define BUILT_IN_LED 2 //GPIO2 is the blue built in LED on ESP32


// Function to set the RGB color
void setColor(int R, int G, int B) {
  analogWrite(PIN_GREEN, G);
  analogWrite(PIN_BLUE, B);
  analogWrite(PIN_RED, R);
}

void setup() {
  
  Serial.begin(9600); // open the serial port at 9600 bps:
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
  pinMode(PIN_RED, OUTPUT);
  pinMode (LASER, OUTPUT);
  pinMode (BUILT_IN_LED, OUTPUT);

  digitalWrite(BUILT_IN_LED, HIGH);
}

void laserBlink (){
  for (int i = 0; i <= 78; i++){
    Serial.println(i);
    digitalWrite(LASER, HIGH);
    delay(300);
    digitalWrite(LASER, LOW);
    delay(300);
  }
}

void loop() {
  setColor((78*3), 0, 0);
  laserBlink ();
  setColor(0, 0, (78*3));
  delay(12000);
}

//last time this code was edited on Arduino IDE 2.2.1 on November 20, 2023
