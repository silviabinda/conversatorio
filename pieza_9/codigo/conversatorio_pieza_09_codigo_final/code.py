#SPDX-FileCopyrightText: © 2023 Silvia Binda Heiserova silviaheiserova@gmail.com

#SPDX-License-Identifier: MIT

'''

Conversatorio, pieza 9
por Silvia Binda Heiserova, 2023

   __________  _   ___    ____________ _____ ___  __________  ____  ________
  / ____/ __ \/ | / | |  / / ____/ __ / ___//   |/_  __/ __ \/ __ \/  _/ __ \
 / /   / / / /  |/ /| | / / __/ / /_/ \__ \/ /| | / / / / / / /_/ // // / / /
/ /___/ /_/ / /|  / | |/ / /___/ _, ____/ / ___ |/ / / /_/ / _, __/ // /_/ /
\____/\____/_/ |_/  |___/_____/_/ |_/____/_/  |_/_/  \____/_/ |_/___/\____/


Conversatorio, artwork 9
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

About artwork 9:
The last artwork from Conversatorio derives from our concern about the relation between feminism, gender and technology. After being overwhelmed and saturated with passing by the electronic, sonic and visual interpretation of gender violence statistics, we end up on exploring the human - machine relation through an impossible conversation about feminism.
This artwork is an ensamblage of 6 RGB LED Matrices that visualize a human - machine conversation about the current state of feminism. The composition of the LED Matrices as well as the behaviour of the text make its reading impossible. The text written in natural language is being constantly overlapped by the text written in programming language, specifically the same code written here that was used to visualize the natural language text.

# This code is based on an example by Jeff Epler that implements a simple two line scroller using
# Adafruit_CircuitPython_Display_Text.
# SPDX-FileCopyrightText: 2020 Jeff Epler for Adafruit Industries
# SPDX-License-Identifier: MIT
'''

import adafruit_display_text.label
import board
import displayio
import framebufferio
import rgbmatrix
import terminalio
import time
from math import sin
import adafruit_imageload
from adafruit_display_text.label import Label
import os
import random

#to change the font:
from adafruit_bitmap_font import bitmap_font

font_file = "fonts/LeagueSpartan-Bold-16.bdf"

#font = bitmap_font.load_font(font_file)

displayio.release_displays()

matrix = rgbmatrix.RGBMatrix(
    width=160, height=32, bit_depth=3,
    rgb_pins=[board.R0, board.G0, board.B0, board.R1, board.G1, board.B1],
    addr_pins=[board.ROW_A, board.ROW_B, board.ROW_C, board.ROW_D],
    clock_pin=board.CLK, latch_pin=board.LAT, output_enable_pin=board.OE)

display = framebufferio.FramebufferDisplay(matrix, auto_refresh=False)


def read_text_from_file(filename):
    with open(filename, 'r') as file:
        return file.read()
# Read text from the file
text_to_display = read_text_from_file("text.txt")

# Create labels with text from the files
text_file1 = "text.txt"
text_file2 = "text1.txt"

line1_text = read_text_from_file(text_file1)
line2_text = read_text_from_file(text_file2)


line1 = adafruit_display_text.label.Label(
    #terminalio.FONT,
    font = bitmap_font.load_font("/LeagueSpartan-Bold-16.bdf"),
    color=0xe965fc,
    text=line1_text)
line1.x = display.width
line1.y = 16

line2 = adafruit_display_text.label.Label(
    #terminalio.FONT,
    font = bitmap_font.load_font("/LeagueSpartan-Bold-16.bdf"),
    color=0x65fcf4,
    text=line2_text)
line2.x = display.width
line2.y = 16

# Put each line of text into a Group, then show that group.
g = displayio.Group()
g.append(line1)
g.append(line2)
display.show(g)


# This function will scoot one label a pixel to the left and send it back to
# the far right if it's gone all the way off screen. This goes in a function
# because we'll do exactly the same thing with line1 and line2 below.
def scroll(line):
    line.x = line.x - 1
    line_width = line.bounding_box[2]
    if line.x < -line_width:
        line.x = display.width
    

# This function scrolls lines backwards.  Try switching which function is
# called for line2 below!
def reverse_scroll(line):
    
    line.x = line.x + 1
    line_width = line.bounding_box[2]

    if line.x >= display.width:
        line.x = -line_width
    
    line.y = line.y + 1  # Move down by one pixel vertically
    line_height = 0  # Adjust this value to match your text height
    if line.y >= display.height - line_height:
        line.y = 0


# Function to display alternating columns of colors
def display_alternating_columns():
    cyan = (0, 255, 255)
    pink = (255, 105, 180)

    # Create a bitmap and palette for the display
    bitmap = displayio.Bitmap(matrix.width, matrix.height, 2)
    palette = displayio.Palette(2)
    palette[0] = cyan  # Color for cyan columns
    palette[1] = pink  # Color for pink columns

    column_width = 7  # Number of pixels in the cyan column

    for column in range(matrix.width):
        # Determine the color index based on the column width
        color_index = 0 if column % (column_width + 8) < column_width else 1
        for row in range(matrix.height):
            bitmap[column, row] = color_index
        
    tile_grid = displayio.TileGrid(bitmap, pixel_shader=palette)
    group = displayio.Group()
    group.append(tile_grid)
    display.show(group)
    time.sleep(10)  # Display alternating columns for 10 seconds
    # Stop displaying the columns
    display.show(None)
    display.show(g)
    scroll(line1)
    reverse_scroll(line2)

# You can add more effects in this loop. For instance, maybe you want to set the
# color of each label to a different value.
while True:
    read_text_from_file("text1.txt")
    start_time = time.monotonic()
    while time.monotonic() - start_time < (random.randint(7, 78)):

        scroll(line1)
        reverse_scroll(line2)
        display.refresh(minimum_frames_per_second=0)
   
    display_alternating_columns()
