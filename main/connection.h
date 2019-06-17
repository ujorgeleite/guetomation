WiFiServer servidor(80);
WiFiClient cliente;

#include "broker.h"



void setupWifiConnection(){
  WiFi.mode(WIFI_STA);
  WiFi.begin("JORGE", "995192978"); 
  servidor.begin();
  delay(10000);
}

 

void getConnection(){
  if(WiFi.status() != WL_CONNECTED) {
      Serial.println("No wifi");
      setupWifiConnection();
  } else {
      //Serial.println("WiFi connected");
      //Serial.print("IP address: ");
      //Serial.println(WiFi.localIP());
      receiveMessage();
  }

 }
