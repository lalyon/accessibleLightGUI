# Accessible IoT LED Light Strip Interface

The code here includes a webpage and backend functions to support an Adafruit NeoPixel 32-LED-per-meter strip controlled by an Arduino and Raspberry Pi Zero W.

## Getting Started

These instructions apply to an Arduino Uno, Raspberry Pi Zero W, and Adafruit NeoPixel strip. The setup requires that you've already hooked up your LEDs to power and the Arduino is ready to send data to the strip. See [AdaFruit's NeoPixel Uberguide](https://learn.adafruit.com/adafruit-neopixel-uberguide/the-magic-of-neopixels) if you are not there yet.

### Prerequisites

You'll need the following packages installed to get this working.

```
php
apache2
pyserial
Adafruit_NeoPixel.h
```

### Installing

First, flash [LightSerialCommands.ino](LightSerialCommands.ino) to your Arduino. I prefer to use the [Arduino Web Editor](https://create.arduino.cc/) for flashing. Feel free to customize the .ino file to your RGB liking.

Next, physically connect your Arduino and LED strip via data pin 6.

Clone this repo to your Raspberry Pi.

```
git clone https://github.com/lalyon/accessibleLightGUI.git
```

Move the following files to your /var/www/html folder on the Pi.

'''
ajax.php
index.html
lights.css
lights.js
all of the [color].py files
'''

Start the web server and php on your Pi.

'''
$ sudo service apache2 start
'''

In a browser, go to your Raspberry Pi's local IP address to check if the server is up.

'''
$ hostname -I
'''

Finally, be sure to physically connect your Rapsberry Pi and Arduino via a USB connection.

### Customizing the Interface

The webpage uses a CSS Grid layout to organize the colored circles. If you want to add more colors to the page, be sure to assign columns and rows to the new circles.

Each colored circle is a button. When pressed, the button's HTML value attribute is sent via an AJAX request to the ajax.php file.

To add a new color:

1. Add a new button to the index.html file
'''
<button class="circle mynewcolor" name="mynewcolor" value="mynewcolor" accesskey="z">
</button>
'''
2. Add custom styling to lights.css for both mobile and desktop viewing
'''
.mynewcolor {
  background: red;
  grid-row: 13;
}
'''
'''
.mynewcolor {
  background: red;
  grid-column: 1;
  grid-row: 4;
}
'''
3. Add a new case statement to the ajax.php file
'''
case 'mynewcolor':
    mynewcolor();
    break;
'''
4. Add a new function to the end of the ajax.php file
'''
function mynewcolor() {
  exec("python mynewcolor.py");
  exit;
}
'''
5. Create a new python script in the same directory as your index.html file (probably /var/www/html)
'''
import time
import serial
ser = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(1)
ser.write('c') #change this to whatever you want
'''
6. Amend your LightSerialCommands.ino file to include an if statement checking for your custom serial command from step 5.
'''
else if (receivedChar == 'c') {
high = strip.Color(255, 255, 255); //change these RGB values to whatever color you want
}
'''
7. Reflash your Arduino

## Author

* **Luke Lyon**

## Acknowledgments

* [Arduino and Raspberry Pi Serial Communication]
(http://codeandlife.com/2012/07/29/arduino-and-raspberry-pi-serial-communication/)
* [Adafruit NeoPixel Überguide](https://learn.adafruit.com/adafruit-neopixel-uberguide/the-magic-of-neopixels)
* [Run Python script from AJAX or JQuery](https://stackoverflow.com/questions/25336688/run-python-script-from-ajax-or-jquery)
