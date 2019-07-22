#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
const char* ssid = "EE-WLAN";
const char* password = "";


 
void setup () {
 
Serial.begin(9600);
WiFi.begin(ssid, password);
 
while (WiFi.status() != WL_CONNECTED) {
 
delay(1000);
Serial.println("Connecting..");
 
}


if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
HTTPClient http;  //Declare an object of class HTTPClient
 
http.begin("http://172.20.25.175:8080/doorstatus");  //Specify request destination
//int httpCode = http.POST("{\"hardwarecode\":\"111\",\"password\":\"123456\"}");   //Send the request
int httpCode =  http.POST("{\"hardwarecode\":\"655fd79e-704f-4bd2-b105-c7a804d8d844\"}");
Serial.println(httpCode);
//http.end();
if (httpCode > 0) { //Check the returning code
 
String payload = http.getString();   //Get the request response payload
Serial.println(payload); 
 
http.end(); 
 
}
 
delay(30000);   

}
}
 
void loop() {
 
                 //Print the response payload
 

   //Close connection
   //Send a request every 30 seconds
 
}
