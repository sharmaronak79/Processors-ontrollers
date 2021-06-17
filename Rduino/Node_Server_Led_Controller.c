#include<ESP8266WiFi.h>    
// Now, make NODE controller s a SERVER and our device as a client , How to read request on NODE MCU
WiFiClient client; // here client is a variable
WiFiServer server(80); //server ia a variable ,  port 80 is the port that the server "listens to"

//Wifi.status(); --> WL_CONNECTED, WL_IDLE_STATUS, WL_CONNECT_FAILED

#define led D5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //to print data on serial monitor
  WiFi.softAP("NodeMCU", "123456789"); // to make NODE as a own wifi or network, Access Point, to make it as a hotspot like mobile hotspot
  Serial.println();
  Serial.println("NodeMCU Started");
  Serial.println(WiFi.softAPIP()); // this will print its own IP
  server.begin(); //NODE MCU will start as a server
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
