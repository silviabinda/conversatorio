/*
SPDX-FileCopyrightText: © 2023 Silvia Binda Heiserova silviaheiserova@gmail.com

SPDX-License-Identifier: MIT

Conversatorio, pieza 7
por Silvia Binda Heiserova, 2023

   __________  _   ___    ____________ _____ ___  __________  ____  ________ 
  / ____/ __ \/ | / | |  / / ____/ __ / ___//   |/_  __/ __ \/ __ \/  _/ __ \
 / /   / / / /  |/ /| | / / __/ / /_/ \__ \/ /| | / / / / / / /_/ // // / / /
/ /___/ /_/ / /|  / | |/ / /___/ _, ____/ / ___ |/ / / /_/ / _, __/ // /_/ / 
\____/\____/_/ |_/  |___/_____/_/ |_/____/_/  |_/_/  \____/_/ |_/___/\____/  

  __                                 __         ________ 
/\ \                               /\ \       /\_____  \
\ \ \____    ___      __     _ __  \_\ \      \/___//'/'
 \ \ '__`\  / __`\  /'__`\  /\`'__\/'_` \         /' /' 
  \ \ \L\ \/\ \L\ \/\ \L\.\_\ \ \//\ \L\ \      /' /'   
   \ \_,__/\ \____/\ \__/.\_\\ \_\\ \___,_\    /\_/     
    \/___/  \/___/  \/__/\/_/ \/_/ \/__,_ /    \//       


Conversatorio, board 7
by Silvia Binda Heiserova, 2023

About Conversatorio: 
Conversatorio is a series of feminist electronic and digital artworks, using various components, microcontrollers, modules and code. It includes a series of 8 boars, conceptualized as open hardware artistic feminist devices, designed and assembled in such manner so they uncover what usually is hidden. These boards are open source and transparent, all its components are visible so everybody can see what these technologies consists of. 
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
Alltogether, when entering the space of the open hardware boards ensamblage, visitors find themselves encircled by seemingly unpredictable soundscapes that are predetermined by data representing gender violance in its worst consequences. Simultaneously, the number 78 is visualised in subtle and almost invisible way, just like gender violance is persisting in our day to day lived societies throughout the year.  

About board 7:
On this board, the number 78 is represented both visually and sonically by a sine wave. The sound of the sinusoid is generated in real time 
with a digital to analogue conversion using the number 78 as modulation amplitude of this sinusoidal wave. Parallelly, the sine wave is 
visualised on a mini display as an oscillating waveform whose, whereby the values 78 and -78 are used to map the output of the sine function to the height of the OLED display, so that after the mapping, the wave moves between 78 and -78.
________________________________________________________________________________________________________________
This code is part of the physical electronic and digital artwork.

Complete list of board 7 components:
1) 19cm x 19cm custom designed perforated board, 3D printed with black PLA fillament
2) custom designed holder for ESP32 microcontroler, 3D printed with black PLA fillament
3) custom designed holder for LM386 Amplifier, 3D printed with black PLA fillament
4) custom designed holder for Mini Speaker 4Ω (3W), 3D printed with black PLA fillament
5) custom designed holder for OLED display, 3D printed with black PLA fillament
6) ESP32 WROOM microcontroller
7) LM386 Amplifier
8) Mini Speaker 4Ω (3W) with dimensions: 40x40x20mm
9) 0.91inch blue OLED display module (128x32 pixels) with I2C interface and SSD1306 driver
10) Black micro USB to USB cable 2m long (powering the ESP32 microcontroller)
11) Custom made wires with dupont connectors of different colors and lengths
12) Black and aluminium color M3 screws and nuts
13) Code
________________________________________________________________________________________________________________

This code is run on ESP32 WROOM microcontroller conected to the amplifier, speaker and OLED display.

GPIOs for connections:
  OLED display
    SCL -> GPIO 22
    SDA -> GPIO 21
    VCC -> 3.3V
    GND -> GND

LM386 Amplifier module has assigned following esp32 PINS:
VCC = esp32 VIN pin 
IN = esp32 GPIO25
GND = connected to esp32 GND pin

The Speaker is connected via wires directly to the LM386 Amplifier.
________________________________________________________________________________________________________________

ACKNOWLEDGMENTS: 
Thanks to patorjk.com for sharing the TAAG. 
Fonts used for the ASCII art texts are Slant, Larry 3D (larry3d.flf by Larry Gelberg larryg@avs.com) and Doh.

*/

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Create an instance of the display
Adafruit_SSD1306 display(4); // The constructor of this class takes the port number at which the display could be reset

// Define the width and height of the OLED display
int SCREEN_WIDTH = 128;
int SCREEN_HEIGHT = 32;

float phase = 0;          // Declare phase as a global variable for OLED
float phaseIncrement = 0.2; // Adjust this value to control the speed of movement for OLED

// Define DAC pins
#define DAC_CH1 25
#define DAC_CH2 26

// Variables to keep track of the time of the last OLED update and sound generation
unsigned long previousOLEDMillis = 0;
unsigned long previousSoundMillis = 0;

// Define the interval between OLED updates and sound generations
const unsigned long oledInterval = 10;    // 10 milliseconds per frame for OLED
const unsigned long soundInterval = 7000; // 8 seconds pause - adjust for longer or smaller pause for sound
boolean playSound = true;

void setup() {
  // Initialize Serial communication
  Serial.begin(115200);

  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  // Set the text color to white
  display.setTextColor(SSD1306_WHITE);
  // Clear the display
  display.clearDisplay();

  // Initialize the DAC with a value of 128. This is setting the DAC value on the ESP32.
  // The ESP32 DAC is 8-bit, which means it can output 256 different values (from 0 to 255). Each of these values corresponds to a different voltage level.
  dacWrite(DAC_CH1, 128); // The number 128 in this context is an 8-bit value that corresponds to a voltage level on the DAC output.
}

// Function to update the OLED display
void oledTask(void *parameter) {
  while (true) {
    unsigned long currentMillis = millis();

    // Check if it's time to update the OLED display
    if (currentMillis - previousOLEDMillis >= oledInterval) {
      previousOLEDMillis = currentMillis;

      // Clear the display
      display.clearDisplay();

      // Draw the sine wave from left to right on the OLED display
      for (int x = 0; x < SCREEN_WIDTH; x++) {
        // Calculate the y-coordinate of the sine wave based on the phase
        int y = map(sin(phase + x * phaseIncrement) * 78, -78, 78, 0, SCREEN_HEIGHT);

        // Draw a single pixel at (x, y)
        display.drawPixel(x, y, SSD1306_WHITE);
      }

      // Update the display
      display.display();

      // Increment the phase to move the sine wave
      phase += phaseIncrement;

      // Reset the phase when it reaches a threshold for continuous movement
      if (phase >= TWO_PI) {
        phase = 0;
      }
    }
    delay(1); // A small delay to avoid excessive CPU usage
  }
}

// Function to generate sound
void dacTask(void *parameter) {
  while (true) {
    unsigned long currentMillis = millis();

    // Check if it's time to generate sound
    if (currentMillis - previousSoundMillis >= soundInterval) {
      previousSoundMillis = currentMillis;

      if (playSound) {
        float modulationFrequency = 1.0;
        float modulationAmplitude = 78;

        // Generate the sine wave for a longer duration (x * 360 degrees of the sine wave)
        for (int deg = 0; deg < 2880; deg = deg + 1) { // Longer duration (x * 360 degrees of the sine wave)
          float modulation = modulationAmplitude * sin(modulationFrequency * deg * PI / 180);
          int dacValue = int(128 + modulation + 78 * sin(deg * PI / 180));
          dacWrite(DAC_CH1, dacValue);
          delayMicroseconds(1000);
        }
      } else {
        // Stop generating sound (set DAC to neutral value)
        dacWrite(DAC_CH1, 128);
      }
    }
    delay(1); // A small delay to avoid excessive CPU usage
  }
}

void loop() {
  // Create tasks for OLED display and DAC output
  xTaskCreatePinnedToCore(oledTask, "oledTask", 4096, NULL, 1, NULL, 1);
  xTaskCreatePinnedToCore(dacTask, "dacTask", 4096, NULL, 1, NULL, 0);
  delay(5000);
  // Delay to prevent the main loop from running
  while (true) {
    delay(1000);
  }
}

//last time this code was edited on Arduino IDE 2.2.1 on November 20, 2023