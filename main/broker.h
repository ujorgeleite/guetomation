const static char pubkey[]  = "pub-c-3343b65e-d72a-4f0f-a8df-d3d19e062753";
const static char subkey[]  = "sub-c-be793f12-1b58-11e8-97e5-2e7e45341bc1";
const static char channel[] = "casa";
const static String devicesPattern = "/00100000"; 

void byInternetMessage(){
  {
        PubSubClient* sclient = PubNub.subscribe(channel); // Subscribe.
        if (0 == sclient) { 
            Serial.println("Error subscribing to channel.");
            delay(1000);
            return;
        }
        while (sclient->wait_for_data() //&& alguma condicao false) { // Print messages.
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
  //{
    //    WiFiClient* client = PubNub.publish(channel, msg); // Publish message.
      //  if (0 == client) {
        //    Serial.println("Error publishing message.");
          //  delay(1000);
            //return;
        //}
        //client->stop();
   // }
  
}


void receiveMessage(){
  
  byHomeMessage();

}
