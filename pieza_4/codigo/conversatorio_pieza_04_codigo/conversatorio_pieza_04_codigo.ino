/* 
SPDX-FileCopyrightText: © 2023 Silvia Binda Heiserova silviaheiserova@gmail.com

SPDX-License-Identifier: MIT

Conversatorio, pieza 4
por Silvia Binda Heiserova, 2023

   __________  _   ___    ____________ _____ ___  __________  ____  ________ 
  / ____/ __ \/ | / | |  / / ____/ __ / ___//   |/_  __/ __ \/ __ \/  _/ __ \
 / /   / / / /  |/ /| | / / __/ / /_/ \__ \/ /| | / / / / / / /_/ // // / / /
/ /___/ /_/ / /|  / | |/ / /___/ _, ____/ / ___ |/ / / /_/ / _, __/ // /_/ / 
\____/\____/_/ |_/  |___/_____/_/ |_/____/_/  |_/_/  \____/_/ |_/___/\____/  

 __                                 __      __ __      
/\ \                               /\ \    /\ \\ \     
\ \ \____    ___      __     _ __  \_\ \   \ \ \\ \    
 \ \ '__`\  / __`\  /'__`\  /\`'__\/'_` \   \ \ \\ \_  
  \ \ \L\ \/\ \L\ \/\ \L\.\_\ \ \//\ \L\ \   \ \__ ,__\
   \ \_,__/\ \____/\ \__/.\_\\ \_\\ \___,_\   \/_/\_\_/
    \/___/  \/___/  \/__/\/_/ \/_/ \/__,_ /      \/_/  
                                                       
                                                                             
Conversatorio, board 4
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
Every board from Conversatorio is coded so that it visually or sonically represents the number of these hate crimes, 
which in Spanish language are called "feminicidios". 
Alltogether, when entering the space of the open hardware boards ensamblage, visitors find themselves encircled 
by seemingly unpredictable soundscapes that are predetermined by data representing gender violance in its worst consequences. 
Simultaneously, the number 78 is visualised in subtle and almost invisible way, just like gender violance is persisting 
in our day to day lived societies throughout the year.

About board 4:
This board uses an OLED display as a visual component to explain the context of the numnber 78 which is constituting this artwork series. 
On the display we can read following text in English language:
"The enactment of the Spanish Constitution, on 6 December '78, represents the legal affirmation of equality between women and men and the desire to eradicate discrimination 
based on race, sex or religion, as well as their recognition as the main inspiration for Spain's legal system.
As of September 2023, 78 femicides have been registered in Spain throughout this year. Despite Spain's gender equality rate standing at about 78%, 
progress is still necessary to achieve gender parity."
________________________________________________________________________________________________________________
This code is part of the physical electronic and digital artwork.

Complete list of board 4 components:
1) 19cm x 19cm custom designed perforated board, 3D printed with black PLA fillament
2) 2x Custom designed holder for OLED display, 3D printed with black PLA fillament
3) 1x Custom designed holder for ESP32 microcontroller, 3D printed with black PLA fillament
4) ESP32 WROOM microcontroller
5) 0.91inch blue OLED display module (128x32 pixels) with I2C interface and SSD1306 driver
6) RGB LED module with common cathode
7) Black micro USB to USB cable 3m long (powering the ESP3 microcontroller)
8) Custom made wires with dupont connectors of different colors and lengths
9) M3 screws and nuts, black color 
10) Code
________________________________________________________________________________________________________________

This code is run on ESP32 WROOM microcontroller connected to the 0.91inch OLED display and the RGB LED module.

GPIOs for connections:
  OLED display:
    SCL -> GPIO 22
    SDA -> GPIO 21
    VCC -> 3.3V
    GND -> GND

  RGB LED module:
    - -> GND
    R -> GPIO 13
    G -> GPIO 27
    B -> GPIO 26
   (NOTE: In the code we are assigning the "G" the pin 33, which is made intentionally because we decided not to use the green color in the final setting.)
________________________________________________________________________________________________________________

ACKNOWLEDGMENTS: 
Thanks to patorjk.com for sharing the TAAG. 
Fonts used for the ASCII art texts are Slant, Larry 3D (larry3d.flf by Larry Gelberg larryg@avs.com) and Doh.

*/

// Include following libraries
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Initialize the SSD1306 display
Adafruit_SSD1306 display(4);

// Define two messages to be displayed on the screen
char message1[] = "The enactment of the Spanish Constitution, on 6 December '78, represents the legal affirmation of equality between women and men and the desire to eradicate discrimination based on race, sex or religion, as well as their recognition as the main inspiration for Spain's legal system.";

char message2[] = "As of September 2023, 78 femicides have been registered in Spain throughout this year. Despite Spain's gender equality rate standing at about 78%, progress is still necessary to achieve gender parity.";

// Define variables for the x-coordinates of the messages and their minimum values
int x1, x2, minX1, minX2;

// Define a boolean variable to determine which message to display
bool showMessage1 = true;

// Define the pins for the RGB LED
const int redPin = 13;    // Red LED connected to digital pin 13
const int greenPin = 33; // Green LED assigned to digital pin 33 but actually connected to pin 27
const int bluePin = 26;  // Blue LED connected to digital pin 26

// Define a variable to keep track of the last time the messages were updated
unsigned long previousMillis = 0;

// Define the interval for updating the messages
const long interval = 50; // Adjust this interval for the scrolling speed

void setup() {
   // Set the RGB LED pins as output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Start the serial communication
  Serial.begin(9600);

  // Initialize the display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  // Set the text size, color, and wrap mode
  display.setTextSize(2);
  display.setTextColor(SSD1306_BLACK); // Set text color to black
  display.fillScreen(SSD1306_WHITE); // Set background to white
  display.setTextWrap(false);

  // Set the initial x-coordinates of the messages
  x1 = x2 = display.width();

  // Calculate the minimum x-coordinates of the messages
  minX1 = -12 * strlen(message1);  // 12 = 6 pixels/character * text size 2
  minX2 = -12 * strlen(message2);
}

// Function to display the first message
void run_message1(uint16_t textColor, uint16_t bgColor) {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.setTextSize(2);
  display.setTextColor(textColor);
  display.fillScreen(bgColor);
  display.setCursor(x1, 10);
  display.print(message1);
  display.display();
}

// Function to display the second message
void run_message2(uint16_t textColor, uint16_t bgColor) {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.setTextSize(2);
  display.setTextColor(textColor);
  display.fillScreen(bgColor);
  display.setCursor(x2, 10);
  display.print(message2);
  display.display();
}

// Function to control the fading of the RGB LED
void rgb_led_dim() {
  static int brightness = 0;
  static bool fadingIn = true;

  if (fadingIn) {
    brightness++;
    if (brightness >= 255) {
      fadingIn = false;
    }
  } else {
    brightness--;
    if (brightness <= 0) {
      fadingIn = true;
    }
  }

  analogWrite(redPin, brightness);
  analogWrite(greenPin, brightness);
  analogWrite(bluePin, brightness);
}

void loop() {
  unsigned long currentMillis = millis();

  // Change the messages every interval milliseconds

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // If showMessage1 is true, display the first messag
    if (showMessage1) {
      run_message1(SSD1306_BLACK, SSD1306_WHITE);
      x1 = x1 - 5;
      if (x1 < minX1) {
        x1 = display.width();
        showMessage1 = false;
      }
    } else {
      // If showMessage1 is false, display the second message
      run_message2(SSD1306_WHITE, SSD1306_BLACK);
      x2 = x2 - 5;
      if (x2 < minX2) {
        x2 = display.width();
        showMessage1 = true;
      }
    }
  }

  // Call the function to control the dimming of the RGB LED
  rgb_led_dim();
}

//last time this code was edited with Arduino IDE 2.2.1 on November 20, 2023