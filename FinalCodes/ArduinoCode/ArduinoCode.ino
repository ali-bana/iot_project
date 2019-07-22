#include <SoftwareSerial.h>


SoftwareSerial mcu(15, 14); //rx, tx


int* string_to_int_arr(char* s)
{
  
}


void setup() {
  // put your setup code here, to run once:
  mcu.begin(9600);
  
}

void loop() {
  String qr = "";
  while(mcu.available() == 0);
  while(mcu.available())
    qr.concat(mcu.read());
  //display income String
  

}
