#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#define username "111" //serial number length is 5
#define password "123456" //password length is 5
#define base_url "http://172.20.25.175:8080"
#define wifi_name "EE-WLAN"
#define wifi_pass ""

int state = 0;
int button = 4;
int ledpin = 5;
String qr = "";
String coockie_id = "";
String response = "";
int i = 0;
int timer = 0;
int checking led = 6; //only defined
int open_led = 7; //only defined



String signin()
{
    String url = "";
    HTTPClient http;
    url.concat(base_url);
    url.concat("/signupdoor");
    http.begin(url);  //Specify request destination
    String json = "{\"hardwarecode\":\"";
    json.concat(username);
    json.concat("\",\"password\":\"""\",\"password\":\"");
    json.concat(password);
    json.concat("\"}");
    int httpCode = http.POST(json);   //Send the request
    if (httpCode == 200) { //Check the returning code
    String payload = http.getString();   //Get the request response payload
    http.end();
    return payload;
    }
    else {
        return "error";
    }
    
}

String check_open(String coockie)
{
    String url = "";
    HTTPClient http;
    url.concat(base_url);
    url.concat("/doorstatus");
    http.begin(url);  //Specify request destination
    int httpCode = http.POST("{\"hardwarecode\":\"" + coockie + "\"}");   //Send the request
    if (httpCode == 200) { //Check the returning code
    String payload = http.getString();   //Get the request response payload
    http.end();
//    Serial.println(payload);
    if (payload == "1")
      return "1";
    return "0";
    }
    else {
        return "0";
    }
}

//String read_serial()
//{
//  while
//}

void setup() {
  // put your setup code here, to run once:
    pinMode(button, INPUT);
    pinMode(ledpin, OUTPUT);
    Serial.begin(9600);
    WiFi.begin(wifi_name, wifi_pass);
    
    while (WiFi.status() != WL_CONNECTED) {
    
        digitalWrite(ledpin, HIGH);
        delay(500);
        digitalWrite(ledpin, LOW); 
        delay(500);
//        Serial.println("Connecting..");
    }

    digitalWrite(ledpin, HIGH);
 
//    if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
//    
//        String res = signup();
//        Serial.println(res);
//
//    }

    
    
}

void loop() {
  ESP.wdtDisable();

 while (WiFi.status() != WL_CONNECTED) {
    
        digitalWrite(ledpin, HIGH);
        delay(500);
        digitalWrite(ledpin, LOW); 
        delay(500);
//        Serial.println("Connecting..");
  }

  digitalWrite(ledpin, HIGH);

  
  switch(state)
  {
    case 0: //this is idl state
      if (digitalRead(button))
        state = 1;
      break;

    case 1://signing in and display the barcode
      response = signin();
      if (response == "error")
      {
        Serial.println("error");
        state = 0;
      }
      else
      {
        i = response.indexOf('/');
        coockie_id = response.substring(0, i);
        qr = response.substring(i+1);
//        Serial.println(response);
//        Serial.println(coockie_id);
        Serial.println(qr);
        state = 2;
      }
      break;

      case 2: //checking to open the door
      timer = 0;
      while(timer < 20)
      {
        ESP.wdtDisable();
        response = check_open(coockie_id);
        if (response == "1")
        {
          Serial.println("OPEN");
          break;
        }
        timer += 1;
        delay(1000);
      }
      state = 0;
      break;
  }

}
