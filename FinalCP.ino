//#include <ESP8266WiFi.h>
//#include <SPI.h>
//#include <Wire.h>
//
//
//int air_quality;
//int num_Measure = 128 ; // Set the number of measurements   
//int pinSignal = A0; // pin connected to pin O module sound sensor  
//long Sound_signal;    // Store the value read Sound Sensor   
//long sum = 0 ; // Store the total value of n measurements   
//long level = 0 ; // Store the average value   
//int soundlow = 100;
//int soundmedium = 500;
////int error = 33;
//int LED=D2;
//int swt = 1;
//bool swt1,swt2;
//int swtpin = D7;
//
//String apiKey = "AA6XEKCEUYJ3M6HE"; // Enter your Write API key from ThingSpeak
//const char *ssid =  "SB";     // replace with your wifi ssid and wpa2 key
//const char *pass =  "12345678a";
//const char* server = "api.thingspeak.com";
//WiFiClient client;
//
//void setup() {
//  
//  // put your setup code here, to run once:
//  
//  pinMode (pinSignal, INPUT); // Set the signal pin as input   
//  Serial.begin (9600);  
//  pinMode(LED,OUTPUT);
//  pinMode (swtpin, INPUT);
// ////////////////////////////////////
//   delay(10);
// 
//  Serial.println("Connecting to ");
//  Serial.println(ssid);
//  
// 
//  
//  WiFi.begin(ssid, pass);
// 
//  while (WiFi.status() != WL_CONNECTED)
//  {
//    delay(50);
//    Serial.print(".");
//  }
//    Serial.println("");
//    Serial.println("WiFi connected");
//    
//    
//    delay(2000);
//    ////////////////////////////////////
////  delay(10);
// }
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  swt1 = analogRead(D7);
//  swt2 = analogRead(D8);
//  
////  Serial.print(swt1);
//  if(swt1 == 1 && swt2 == 0){
//    for ( int i = 0 ; i <num_Measure; i ++)  
//      {   
//        Sound_signal = analogRead (pinSignal);  
//        sum =sum + Sound_signal; 
//      } 
//    Serial.print("Sound Level: ");
//    Serial.println (level); 
// 
//    level = sum / num_Measure; // Calculate the average value 
//    if( (level) < soundlow)
//    {
//      digitalWrite(LED,LOW);
//      Serial.println("Intensity= Low");
//      
//    }
//    if( ( (level) > soundlow ) && ( (level) < soundmedium )  )
//    {
//      digitalWrite(LED,HIGH);
//      Serial.println("Intensity=Medium"); 
//      
//    }
//    if( (level) > soundmedium )
//    {
//      digitalWrite(LED,HIGH);
//      Serial.println("Intensity= High");   
//    }
//    sum = 0 ; // Reset the sum of the measurement values  
//  }
//  else if(swt1 == 0 && swt2 == 1){
//    air_quality = ((analogRead(A0)/1024.0)*100.0);
//    
//    Serial.print("Air pollution Level: ");
//    Serial.println(air_quality);
//  }
//  else{
//    Serial.println("Nothing is on");
//  }
//
//    if (client.connect(server, 80)) // "184.106.153.149" or api.thingspeak.com
//  {
//    apiKey = "https://api.thingspeak.com/update?api_key=AA6XEKCEUYJ3M6HE";
//    String postStr = apiKey;
//    postStr += "&field1=";
//    postStr += String(level);
//    postStr += "\r\n";
//    
//    client.print("POST /update HTTP/1.1\n");
//    client.print("Host: api.thingspeak.com\n");
//    client.print("Connection: close\n");
//    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
//    client.print("Content-Type: application/x-www-form-urlencoded\n");
//    client.print("Content-Length: ");
//    client.print(postStr.length());
//    client.print("\n\n");
//    client.print(postStr);
//   
//  }
//    client.stop();
//  
//  delay(10000);
// 
//
//}


/*
int air_quality;
int num_Measure = 128 ; // Set the number of measurements   
int pinSignal = A0; // pin connected to pin O module sound sensor  
long Sound_signal;    // Store the value read Sound Sensor   
long sum = 0 ; // Store the total value of n measurements   
long level = 0 ; // Store the average value   
int soundlow = 100;
int soundmedium = 500;
//int error = 33;
int LED1=D2;
int LED2=D3; 

void setup() {
  
  // put your setup code here, to run once:
  
  pinMode (pinSignal, INPUT); // Set the signal pin as input   
  Serial.begin (115200);  
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(D6 , OUTPUT);

  delay(10);
 }

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(D6,LOW);
  
  
//  Serial.print(swt1);
  
{
    for ( int i = 0 ; i <num_Measure; i ++)  
      {   
        Sound_signal = analogRead (pinSignal);  
        sum =sum + Sound_signal; 
      } 
     level = sum / num_Measure;
    Serial.print("Sound Level: ");
    Serial.println (level); 
 
     // Calculate the average value 
    if( (level) < soundlow)
    {
      digitalWrite(LED1,LOW);
      Serial.println("Intensity= Low");
      
    }
    if( ( (level) > soundlow ) && ( (level) < soundmedium )  )
    {
      digitalWrite(LED1,HIGH);
      Serial.println("Intensity=Medium"); 
      
    }
    if( (level) > soundmedium )
    {
      digitalWrite(LED1,HIGH);
      Serial.println("Intensity= High");   
    }
    sum = 0 ; // Reset the sum of the measurement values  
  }
  
//  delay(5000000);
  delay(5000);
  digitalWrite(D6,HIGH);
  
  {
    air_quality = ((analogRead(A0)/1024.0)*100.0);
    
    Serial.print("Air pollution Level: ");
    Serial.println(air_quality);
    if(air_quality > 15){
      digitalWrite(LED2,HIGH);
    }
    else{
      digitalWrite(LED2,LOW);
    }
  }
  delay(5000);

}


*/
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPLRy0TcR6o"
#define BLYNK_DEVICE_NAME "Sound and Air Pollution Monitoring"

#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "MQ135.h"

int air_quality;
int num_Measure = 128 ; // Set the number of measurements   
int pinSignal = A0; // pin connected to pin O module sound sensor  
long Sound_signal;    // Store the value read Sound Sensor   
long sum = 0 ; // Store the total value of n measurements   
long level = 0 ; // Store the average value   
int soundlow = 150;
int soundmedium = 500;
int SoundError = 9;

int LED1=D2;
int LED2=D3; 


char auth[ ] = "DadoN-gUYk4NSE35yzMUfYvOjU2n5m10"; 
char ssid[ ] = "SN";
char pass[ ] = "sid12345678";
WiFiClient client;

void setup() {
  
  // put your setup code here, to run once:
  
  pinMode (pinSignal, INPUT); // Set the signal pin as input   
  Serial.begin(9600);
//  Serial1.begin (115200);  
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(D6 , OUTPUT);
  ////////////////
  WiFi.begin(ssid, pass);
 
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(50);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  ///////////
  Blynk.begin(auth, ssid, pass);
  delay(10);
 }

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  digitalWrite(D6,LOW);
  
  
//  Serial.print(swt1);
 
//  MQ135 gasSensor = MQ135(A0);
//  float ppm = gasSensor.getPPM(); 
{ 
    for ( int i = 0 ; i <num_Measure; i++)  
      {   
        Sound_signal = analogRead (pinSignal);  
        sum =sum + Sound_signal; 
      } 
     level = (sum / num_Measure)-SoundError;
    Serial.print("Sound Level: ");
    Serial.println (level); 
 
     // Calculate the average value 
    if( (level) < soundlow)
    {
      digitalWrite(LED1,LOW);
      Serial.println("Intensity= Low");
      
    }
    if( ( (level) > soundlow ) && ( (level) < soundmedium )  )
    {
      digitalWrite(LED1,HIGH);
      Serial.println("Intensity=Medium"); 
      
    }
    if( (level) > soundmedium )
    {
      digitalWrite(LED1,HIGH);
      Serial.println("Intensity= High");   
    }
    
    Blynk.virtualWrite(V4, level);
    
    sum = 0 ; // Reset the sum of the measurement values  
  }
//  delay(5000000);
  delay(2000);
  digitalWrite(D6,HIGH);
  {
    air_quality = ((analogRead(A0)/1024.0)*100.0);
//    air_quality=ppm;
    Serial.print("Air pollution Level: ");
    Serial.println(air_quality);
    if(air_quality > 80){
      digitalWrite(LED2,HIGH);
    }
    else{
      digitalWrite(LED2,LOW);
    }
  }
  delay(2000);
  
  Blynk.virtualWrite(V5, air_quality);

}
