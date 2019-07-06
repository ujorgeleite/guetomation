const static String devicesPattern = "/00100000"; 

void byInternetMessage(){
  {
        PubSubClient* sclient = PubNub.subscribe(pubNubChannel);
        if (0 == sclient) { 
            Serial.println("Error subscribing to channel.");
            delay(1000);
            return;
        }
        while (sclient->wait_for_data()) {
           int result = sclient->read();
            if (devicesPattern.indexOf(result) > -1)
            {
               digitalWrite(D6, !digitalRead(D6));
            }
            Serial.write(result);
        }
        sclient->stop();
    }


}

void byHomeMessage()
{
   cliente = servidor.available();

   if (cliente == true)
   {
      String req = cliente.readStringUntil('\r');
      Serial.println(req);
      if (req.indexOf(devicesPattern) > -1)
      {
         digitalWrite(D6, !digitalRead(D6));
      
      }
      
   }else{
    byInternetMessage();
   }
}




void publish(char msg)
{ 
  {
        //WiFiClient* client = PubNub.publish(pubNubChannel, msg); 
        //if (0 == client) {
          //  Serial.println("Error publishing message.");
            //delay(1000);
            //return;
        //}
        //client->stop();
    }
  
}


void receiveMessage(){
  byInternetMessage();
}
