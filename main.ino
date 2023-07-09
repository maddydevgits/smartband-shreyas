#include <WiFi.h>
#include <ThingSpeak.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_ADDR   0x3C
#define SCROLL_DELAY 500
#define SCROLL_OFFSET 1
#define startB 2
#define stopB 5
#define buzzer 23
#define red 32
#define green 33
#define sensor 34
#define lo1 18
#define lo2 19

Adafruit_SSD1306 display(-1);

char* ssid="Smart Band";
char* password="1234567890";

char* apikey="3AMGXO1YIBDBQI8I";
unsigned int channelid=2215158;

WiFiClient client;

int count=0;
long sample=0;

void beep() {
  digitalWrite(buzzer,1);
  delay(3000);
  digitalWrite(buzzer,0);
}

void beep1() {
  digitalWrite(buzzer,1);
  delay(500);
  digitalWrite(buzzer,0);
  delay(500);
}

void connectWIFI() {
  Serial.println("Connecting...");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Connected");
  ThingSpeak.begin(client);
}

void setup() {
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(sensor,INPUT);
  pinMode(startB,INPUT_PULLUP);
  pinMode(stopB,INPUT_PULLUP);
  pinMode(lo1,INPUT);
  pinMode(lo2,INPUT);
  pinMode(buzzer,OUTPUT);
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Smart Band!");
  display.setCursor(0,16);
  display.println("Press Start");
  display.display();
  connectWIFI();
}


void loop() {
  if(digitalRead(startB)==0) {
    Serial.println("Start Button Pressed");
    beep();
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("Smart Band!");
    display.setCursor(0,16);
    display.println("Calibrating...");
    display.display();
    for(int i=0;i<2;i++) {
      beep1();
    }
    while(1) {
      if(digitalRead(stopB)==1) {
        if((digitalRead(lo1) == 1)||(digitalRead(lo2) == 1)){
          Serial.println('!');
        } else {
          int dummy=analogRead(sensor);
          Serial.println(dummy);
          sample+=dummy;
          count++;
        }
      } else {
        beep();
        int averageValue=sample/count;
        averageValue=averageValue/4;
        sample=0;
        count=0; 
        display.clearDisplay();
        display.setTextColor(WHITE);
        display.setTextSize(1);
        display.setCursor(0, 0);
        display.println("Smart Band!");
        display.setCursor(0,16);
        display.println("Stopping...");
        display.display();
        delay(1000);
        beep1();
        display.clearDisplay();
        display.setTextColor(WHITE);
        display.setTextSize(1);
        display.setCursor(0, 0);
        display.println("Smart Band!");
        display.setCursor(0,16);
        display.print("Value: ");
        display.println(averageValue);
        display.display();
        delay(1000);
        beep1();
        display.clearDisplay();
        display.setTextColor(WHITE);
        display.setTextSize(1);
        display.setCursor(0, 0);
        display.println("Smart Band!");
        display.setCursor(0,16);
        display.println("Uploading to Cloud... ");
        display.display();
        delay(1000);
        beep1();
        
        ThingSpeak.setField(1,averageValue);
        int statusCode=ThingSpeak.writeFields(channelid,apikey);
        if(statusCode==200) {
          display.clearDisplay();
          display.setTextColor(WHITE);
          display.setTextSize(1);
          display.setCursor(0, 0);
          display.println("Smart Band!");
          display.setCursor(0,16);
          display.println("Data Uploaded");
          display.display();
          delay(1000);
        }
        if(averageValue>400 && averageValue<500) {
          digitalWrite(green,1);
          digitalWrite(red,0);
        } else {
          digitalWrite(green,0);
          digitalWrite(red,1);
        }
        break;
      }
    }
  }
}
