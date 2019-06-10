#include "connection.h"



void setup()
{
   Serial.begin(9600);
   setupWifiConnection();

  
}

void loop()
{ 
  getConnection();
}
