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
