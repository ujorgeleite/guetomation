#include <ESP8266WiFi.h>
#include <WiFiServer.h>


WiFiServer servidor(80);
WiFiClient cliente;


void setupWifiConnection(){
  WiFi.mode(WIFI_STA);
  WiFi.begin("networkUser", "networkPassword"); 
  servidor.begin();
  delay(10000);
}

void getConnection(){
  if(WiFi.status() != WL_CONNECTED) {
      Serial.println("No wifi");
      setupWifiConnection();
  } else {
      Serial.println("WiFi connected");
      Serial.print("IP address: ");
      Serial.println(WiFi.localIP());
  }

 }
