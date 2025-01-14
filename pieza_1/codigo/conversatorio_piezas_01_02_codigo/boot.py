'''
SPDX-FileCopyrightText: © 2023 Silvia Binda Heiserova silviaheiserova@gmail.com

SPDX-License-Identifier: MIT

Conversatorio, pieza 1 y pieza 2
por Silvia Binda Heiserova, 2023

   __________  _   ___    ____________ _____ ___  __________  ____  ________ 
  / ____/ __ \/ | / | |  / / ____/ __ / ___//   |/_  __/ __ \/ __ \/  _/ __ \
 / /   / / / /  |/ /| | / / __/ / /_/ \__ \/ /| | / / / / / / /_/ // // / / /
/ /___/ /_/ / /|  / | |/ / /___/ _, ____/ / ___ |/ / / /_/ / _, __/ // /_/ / 
\____/\____/_/ |_/  |___/_____/_/ |_/____/_/  |_/_/  \____/_/ |_/___/\____/  
                                                                             
 __                                 __         _         ____        __                                 __          ___     
/\ \                               /\ \      /' \      /|  _ \      /\ \                               /\ \       /'___`\   
\ \ \____    ___      __     _ __  \_\ \    /\_, \     |/\   |      \ \ \____    ___      __     _ __  \_\ \     /\_\ /\ \  
 \ \ '__`\  / __`\  /'__`\  /\`'__\/'_` \   \/_/\ \     \// __`\/\   \ \ '__`\  / __`\  /'__`\  /\`'__\/'_` \    \/_/// /__ 
  \ \ \L\ \/\ \L\ \/\ \L\.\_\ \ \//\ \L\ \     \ \ \    /|  \L>  <_   \ \ \L\ \/\ \L\ \/\ \L\.\_\ \ \//\ \L\ \      // /_\ \
   \ \_,__/\ \____/\ \__/.\_\\ \_\\ \___,_\     \ \_\   | \_____/\/    \ \_,__/\ \____/\ \__/.\_\\ \_\\ \___,_\    /\______/
    \/___/  \/___/  \/__/\/_/ \/_/ \/__,_ /      \/_/    \/____/\/      \/___/  \/___/  \/__/\/_/ \/_/ \/__,_ /    \/_____/ 


Conversatorio, board 1 and board 2
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

About board 1 and board 2:
In the code written for boards 1 and 2, the number 78 is being visualized on the LCD display as a repetitive count up from zero to 78, 
blinking in intervals of 0.78 seconds once the count up reaches the number 78.
The sonic part of the board (reproduced by a mini speaker), is activated only if the bodily presence is detected by the PIR module.
If so, the sonic representation of following data launches: the number of 78 feminicides and the year 2023 - reflected by the sound frequency
which is coded to be (pseudo)randomly selected from values between 78 and 2023 Hz; duration of each note is coded to be (pseudo)randomly  
assigned to values in range between 7 and 78 ms.
________________________________________________________________________________________________________________
This code is part of the physical electronic and digital artwork.

Board 1 and board 2 are run by only one ESP32 microcontroller, which is mounted on board 1 and on which this code is run. 

Electronic components of these two boards are connected with wires and should be always side by side,
boards 1 and board 2 should not be separated.

Complete list of board 1 components:
1) 19cm x 19cm custom designed perforated board, 3D printed with black PLA fillament
2) custom designed holder for ESP32 microcontroler, 3D printed with black PLA fillament
3) custom designed holder for LM386 Amplifier, 3D printed with black PLA fillament
4) custom designed holder for Mini Speaker 4Ω (3W), 3D printed with black PLA fillament
5) custom designed holder for breadboard (S), 3D printed with black PLA fillament
6) ESP32 WROOM microcontroller
7) LM386 Amplifier
8) Mini Speaker 4Ω (3W) with dimensions: 40x40x20mm
9) Solderless mini breadboard with 25 pins, black color
10) Black micro USB to USB cable 3m long (powering the ESP32 microcontroller)
11) Custom made wires with dupont connectors of different colors and lengths
12) Black and aluminium color M3 screws and nuts
13) MicroPython Code
________________________________________________________________________________________________________________

Complete list of board 2 components:
1) 19cm x 19cm custom designed perforated board, 3D printed with black PLA fillament
2) Custom designed holder for breadboard (M), 3D printed with black PLA fillament
3) LCD 1602 display with integrated i2C module, blue underlight
4) SR602 PIR module
5) Solderless mini breadboard with 25 pins, black color
6) Black micro USB to USB cable 2m long (powering the LCD 1602 display)
7) Custom made wires with dupont connectors of different colors and lengths
8) Black color M3 screws, nuts and hexagonal standoff spacers
9) 3M self adhesive wire clip, black color (attached to the board to hold the usb cable)
10) Two WAGO 221-413 splicing connectors
11) WAGO 221-500 DIN rail mount
________________________________________________________________________________________________________________

This code is run on ESP32 WROOM microcontroller conected to the amplifier, speaker, I2C LCD display and PIR module.
Description of connections:

I2C LCD display has assigned following esp32 pins:
SDA (yellow wire) = (esp32 GPIO21)
SCL (green wire) = (esp32 GPIO22)
GND (white wire) = (connected to external power via wago splicing connector) 
VCC (red wire) = (connected to external power via wago splicing connector)

!!!!! When externally powered, I2C LCD display and ESP32 need to have a common Ground for correct communication !!!

PIR module has assigned following esp32 PINS:
OUT (violet wire) = esp32 GPIO26
+ (red wire) = esp32 VIN pin (5V output)
- (grey wire) = connected to esp32 GND pin via breadboard mounted on board 1

LM386 Amplifier module has assigned following esp32 PINS:
VCC (orange wire) = esp32 3.3V pin 
IN (blue wire) = esp32 GPIO25
GND (white wire) = connected to esp32 GND pin via breadboard mounted on board 1

The Speaker is connected via wires directly to the LM386 Amplifier.

________________________________________________________________________________________________________________

ACKNOWLEDGMENTS: 
Thanks to patorjk.com for sharing the TAAG. 
Fonts used for the ASCII art texts are Slant, Larry 3D (larry3d.flf by Larry Gelberg larryg@avs.com) and Doh.

'''

# This file is executed on every boot (including wake-boot from deepsleep)

import machine
import _thread
import time
import random # for random numbers for the frequency and duration of sounds
from machine import Pin, SoftI2C
from i2c_lcd import I2cLcd

# Define speaker pin
SPEAKER_PIN = 25

# Onboard led
ledPin = machine.Pin(2, machine.Pin.OUT) 

# Set up PWM for the speaker
speaker = machine.PWM(machine.Pin(SPEAKER_PIN))

# Initialize random seed
random.seed(int(time.time()))

#define Pin for PIR sensor
inputPin = Pin(26, Pin.IN)      # choose the input pin (for PIR sensor)
pirState = False                # we start, assuming no motion detected
val = 0                         # variable for reading the pin status

#define the I2C LCD display address, number of raws and columns
I2C_ADDR = 0x27
totalRows = 2
totalColumns = 16

i2c = SoftI2C(scl=Pin(22), sda=Pin(21), freq=10000) #initializing the I2C method for ESP32
#i2c = I2C(scl=Pin(5), sda=Pin(4), freq=10000)       #initializing the I2C method for ESP8266

lcd = I2cLcd(i2c, I2C_ADDR, totalRows, totalColumns)
backlight = True #turns on the red backlight of the LCD

n_espana = bytearray ([0x09, 0x06, 0x11, 0x19, 0x19, 0x15, 0x13, 0x00])

lcd.custom_char(0, n_espana)

# Define a global flag to indicate when TextNumInfo() is done
text_num_info_done = True

# Define global flags to indicate when threads should stop
stop_blink_thread = False
stop_text_info_thread = False
stop_data_sonification_thread = False


#my function for pir sensor motion detection:
def PIRsensor():
    global pirState
    while True:
        val = inputPin.value()      # read input value
        if val == 1:                # check if the input is HIGH
            ledPin.on()             # turn LED ON
            if not pirState:
                pirState = True
                # we have just turned on
                print("Motion detected!")
                # We only want to print on the output change, not state
        else:
            ledPin.off()            # turn LED OFF
            if pirState:
                pirState = False
                # we have just turned off
                print("Motion ended!")
                # We only want to print on the output change, not state
        time.sleep(0.1)             # Small delay to debounce and reduce CPU load


def BlinkOnboardLed(): #my function for making the blue onboard LED of the ESP32 blinking all the time
    global stop_blink_thread
    while not stop_blink_thread: #we use this instead of while True, so we do not have an infinite cycle
        led.value(1)
        time.sleep(0.78)
        led.value(0)
        time.sleep(0.78)
        print("BlinkOnboardLed is running") # to check if the function is running

def TextNumInfo():
    global text_num_info_done
    
    global stop_text_info_thread
    while not stop_text_info_thread:
        print("TextNumInfo is running") # to check if the function is running
        
        lcd.move_to (4, 0)
        lcd.putstr("ESPA"+chr(0)+"A")
        lcd.move_to (5, 1)
        lcd.putstr("2023:")
        time.sleep(2)
        lcd.clear()
        
        for i in range(10):
            lcd.move_to (7, 0)
            lcd.putstr(str(i))
            time.sleep(0.2)
            lcd.clear()
        
        for i in range(10, 77):
            lcd.move_to (6, 0)
            lcd.putstr(str(i))
            time.sleep(0.2)
            lcd.clear()
            
        for i in range(5):
            lcd.move_to (6, 0)
            time.sleep(0.78)
            lcd.putstr(str(78))
            time.sleep(0.78)
            lcd.clear()
            time.sleep(0.78)

        # Signal that TextNumInfo() is done
        text_num_info_done = True
    
def DataSonification():
    global pirstate
    global text_num_info_done
    # Generate the sound (pseudo)randomly
    
    while True:
        # Wait for TextNumInfo() to finish before starting
        while not text_num_info_done:
            pass
        
        melody = []
        
        for _ in range(180):  # Change the range to the desired number of notes
            frequency = random.randint(78, 2023)  # Random frequency between 78 and 2023 Hz
            duration = random.randint(7, 78)   # Random duration between 7 and 78 ms
            melody.append((frequency, duration))
        
            # Add a deep, long note to the melody at the end
        deep_note_frequency = 78  # Adjust the frequency to your preference
        deep_note_duration = (780*2)  # Adjust the duration to your preference
        time.sleep(3)
            
        for _ in range(3):
            melody.append((deep_note_frequency, deep_note_duration))

        # Play the melody
        for frequency, duration in melody:
            speaker.freq(frequency)
            if pirState:
                speaker.duty(512)  # Adjust duty cycle as needed = from 0 up to 1023 (when on 0, there is no sound)
                time.sleep_ms(duration)
                speaker.duty(0)  # Turn off the speaker
                time.sleep_ms(78)  # Pause between notes
            else:
                speaker.duty(0)  # Adjust duty cycle as needed = from 0 up to 1023 (when on 0, there is no sound)
                time.sleep_ms(duration)
                speaker.duty(0)  # Turn off the speaker
                time.sleep_ms(78)  # Pause between notes
                
            # Reset the flag to False
        text_num_info_done = False
    
# def main():
#     global text_num_info_done
#     while True:
#         # Wait for TextNumInfo() to finish before starting
#         while not text_num_info_done:
#             pass
#         time.sleep(2)
#         DataSonification()
#         # Delay between melodies (5 seconds in this example)

_thread.start_new_thread(PIRsensor, ())
_thread.start_new_thread(TextNumInfo, ())
_thread.start_new_thread(BlinkOnboardLed, ())
_thread.start_new_thread(DataSonification, ())

# many thanks to the tutorial: https://microcontrollerslab.com/i2c-lcd-esp32-esp8266-micropython-tutorial/
# LCD custom character generator: https://maxpromer.github.io/LCD-Character-Creator/
# (choose the interfacing "I2C" and the Data Type "Hex")
