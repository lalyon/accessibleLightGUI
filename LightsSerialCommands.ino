#include <Adafruit_NeoPixel.h>
#define NUM_LEDS 150
#define PIN 6

char receivedChar;
boolean newData = true;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(150, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
 Serial.begin(9600);
 Serial.println("<Arduino is ready>");
  strip.begin();
  strip.setBrightness(30); //adjust brightness here
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
 recvOneChar();
  //if a new color was selected
  if (newData) 
  {
    //reset check
    newData=false;

// Turn them off
 uint32_t low = strip.Color(0, 0, 0);
 
 uint32_t high;
 if (receivedChar == 'r')
 {
  high = strip.Color(255, 0, 0);
 }
 else if (receivedChar == 'b') {
  high = strip.Color(0, 0, 255);
  }
  
  else if (receivedChar == 'g') {
  high = strip.Color(0, 255, 0);
  }
  
    else if (receivedChar == 'y') {
  high = strip.Color(255, 255, 0);
  }
  
    else if (receivedChar == 'o') {
  high = strip.Color(255, 128, 0);
  }
  
    else if (receivedChar == 'n') {
  high = strip.Color(0, 0, 102);
  }
  
    else if (receivedChar == 'p') {
  high = strip.Color(205, 0, 102);
  }
  
    else if (receivedChar == 'f') {
  high = strip.Color(0, 51, 0);
  }
  
    else if (receivedChar == 'l') {
  high = strip.Color(102, 178, 255);
  }
  
    else if (receivedChar == 's') {
  high = strip.Color(255, 153, 153);
  }
  
    else if (receivedChar == 'h') {
  high = strip.Color(255, 102, 178);
  }
  
    else if (receivedChar == 'm') {
  high = strip.Color(0, 255, 255);
  }
  
  

  
  else { high=low;}
 for( int i = 0; i<NUM_LEDS; i++){
  strip.setPixelColor(i, low);
  strip.show();
  }   
  delay(1000);
  
 for( int i = 0; i<NUM_LEDS; i++){
  strip.setPixelColor(i, high);
  strip.show();
  }   
  
 delay(1000);
  }  


}

void recvOneChar() {
 if (Serial.available() > 0) {
 receivedChar = Serial.read();
 Serial.println(receivedChar);
 newData = true;
 }
}

