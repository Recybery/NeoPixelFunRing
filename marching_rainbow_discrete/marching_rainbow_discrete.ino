#include <Adafruit_NeoPixel.h>

#define neoPix 6
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
int sensorValue = 0;        // value read from the pot


int pushButton = 2;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, neoPix, NEO_GRB + NEO_KHZ800);

int arr=0;
int rep_org=0;
int ring_size=12;

void setup(){
  strip.begin();
  strip.setBrightness(50);
  strip.show();
  Serial.begin(9600);

}


void loop(){

  int buttonState = digitalRead(pushButton);
//  Serial.println(buttonState);
  sensorValue = analogRead(analogInPin);
  int outputValue = map(sensorValue, 0, 700, 1, 1000);  
//  Serial.println(sensorValue);
  Serial.println(buttonState);
  Serial.println();

  rainbowMarch(rep_org, buttonState);
  rep_org += 1-2*buttonState;
// delay(sensorValue);
 delay(outputValue);
}

void rainbowMarch(int origin, int state){
 uint32_t red = strip.Color(255,0,0);
 uint32_t orng = strip.Color(255,75,0);
 uint32_t ylw = strip.Color(255,216,0);
 uint32_t grn = strip.Color(0,255,0);
 uint32_t blu = strip.Color(0,0,255); 
 uint32_t vio = strip.Color(255,0,216);
 uint32_t blk = strip.Color(0,0,0);
 uint32_t wht = strip.Color(255,255,255);
 
// strip.setPixelColor((origin-1)%ring_size,blk);
//  uint32_t blank = strip.Color(255,255,255); 
uint32_t blank = strip.Color(0,0,0); 

if (state > 0){
  blank = strip.Color(0,0,0); 
}



for (int i=0; i <= ring_size; i++){
 strip.setPixelColor(i,blank);}


 
 strip.setPixelColor((origin)%ring_size,red);
 strip.setPixelColor((origin-1)%ring_size,orng);
 strip.setPixelColor((origin-2)%ring_size,ylw);
 strip.setPixelColor((origin-3)%ring_size,grn);
 strip.setPixelColor((origin-4)%ring_size,blu);
 strip.setPixelColor((origin-5)%ring_size,vio);
 strip.show();
 
}



