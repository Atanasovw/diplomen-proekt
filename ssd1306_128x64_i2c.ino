/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/
#include <SharpIR.h>
int button=3;
int button2=4;
int buttonState = 0; 
int secondbuttonState=0;
int count = 0;//
int count2=0;
int plusValue=10;
int lastValue=0; 
#define ir A0
#define model 1080
// ir: the pin where your sensor is attached
// model: an int that determines your sensor:  1080 for GP2Y0A21Y
//                                            20150 for GP2Y0A02Y
//                                            (working distance range according to the datasheets)

SharpIR SharpIR(ir, model);

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  pinMode(button, INPUT);
    pinMode(button2, INPUT);
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
//  display.println("Hello, world!");
//  display.display(); 
}

void loop() {
// this returns the distance to the object you're measuring
 int dis=SharpIR.distance();
   delay(50);   
   
  display.setCursor(0, 10);
  buttonState = digitalRead(button);
  secondbuttonState=digitalRead(button2);
  
    
  if(buttonState==1)
  {
    count++;
    }

 if(secondbuttonState==1)
  {
    count2++;
    }
        Serial.println();

    Serial.print(count2);
    if(count==0)
    {
      display.print(dis);
     display.print(" cm"); 
   display.display();
   display.clearDisplay();
      }
    else if(count==1)
    {
      lastValue=dis;
      display.print(dis);
      }
        
      else
      {
      
        count=0;
        }

     
 Serial.print(count);

  unsigned long pepe1=millis();  // takes the time before the loop on the library begins



 
  //Serial.println(dis);
  
  unsigned long pepe2=millis()-pepe1;  // the following gives you the time taken to get the measurement
 
   

   delay(50);
}
