#include<ESP8266WiFi.h>


//Wifi.status(); --> WL_CONNECTED, WL_IDLE_STATUS, WL_CONNECT_FAILED

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin("wifi_name", "WifiPassword");
  while(WiFi.status()!= WL_CONNECTED)
  {
    Serial.print("..");
    delay(200);
  }
  Serial.println();
  Serial.println("Node MCU is connected ! ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
