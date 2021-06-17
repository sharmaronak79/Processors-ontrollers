#include<ESP8266WiFi.h>    
// Now, make NODE controller s a SERVER and our device as a client , How to read request on NODE MCU
WiFiClient client; // here client is a variable
WiFiServer server(80); //server ia a variable ,  port 80 is the port that the server "listens to"

//Wifi.status(); --> WL_CONNECTED, WL_IDLE_STATUS, WL_CONNECT_FAILED

#define led D5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin("wifi_name", "WifiPassword");
  while(WiFi.status()!= WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
   
  }
  Serial.println();
  Serial.println("Node MCU is connected ! ");
  Serial.println(WiFi.localIP());
  server.begin(); // to start NODE MCU is a server
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  client = server.available();//Gets a client that is connected to the r=server and has dta available for reading
  if (client == 1)
  {
    String request = client.readStringUntil('\n');
    Serial.println(request);
    request.trim(); //to remove garbage value from request

    if(request == "GET /ledon HTTP/1.1") // if you request ledon it will turn on led
    {
      digitalWrite(led,HIGH);
    }

    
    if(request == "GET /ledoff HTTP/1.1")  // if you request ledoff it will turn off led
    {
      digitalWrite(led,LOW);
    }
  }

}
