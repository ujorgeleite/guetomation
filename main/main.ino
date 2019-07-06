#include <ESP8266WiFi.h>
#include <WiFiServer.h>
#define PubNub_BASE_CLIENT WiFiClient
#include <PubNub.h>
#include "setup.h"
#include "connection.h"



void setup()
{
   Serial.begin(9600);
   PubNub.begin(pubNubPublishKey, pubNubSubscribeKey);
   setupWifiConnection();
   pinMode(D6, OUTPUT);
  
}

void loop()
{ 
  getConnection();
  
}
