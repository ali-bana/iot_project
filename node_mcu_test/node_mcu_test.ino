#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
const char* ssid = "Ali";
const char* password = "09301332495";
 
void setup () {
 
Serial.begin(9600);
WiFi.begin(ssid, password);
 
while (WiFi.status() != WL_CONNECTED) {
 
delay(1000);
Serial.println("Connecting..");
 
}
 
}
 
void loop() {
 
if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
HTTPClient http;  //Declare an object of class HTTPClient
 
http.begin("http://172.20.10.2:8080/signin");  //Specify request destination
int httpCode = http.POST("{\"username\":\"user2\",\"password\":\"password2\"}");                                                                  //Send the request
 
if (httpCode > 0) { //Check the returning code
 
String payload = http.getString();   //Get the request response payload
Serial.println(payload);                     //Print the response payload
 
}
 
http.end();   //Close connection
 
}
 
delay(30000);    //Send a request every 30 seconds
 
}
