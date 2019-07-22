#include <SoftwareSerial.h>

#define serialNumber "12345" //serial number length is 5
#define password "12345" //password length is 5
SoftwareSerial mcu(15, 14);


int* string_to_int_arr(char* s)
{
  
}


void setup() {
  // put your setup code here, to run once:
  mcu.begin(9600);
  int state = 0; 
  String to_mcu = "";
  String response = "";
  int * qrcode;
}

void loop() {
  
  switch(state)
  {
    case 1: \\this is idl state
      break;

    case 2: \\this is sending sign in request
      to_mcu = "signin" + serialNumber + password;
      mcu.print(to_mcu);
      while(mcu.available() = 0);
      response = "";
      while(mcu.available())
        response += mcu.read();
      if (response == "error")
        {
          break;
        }

      qrcode = string_to_int_array(response);
      state = 3;
      break;

    case 3:
      break;

    case 4:
      break;
  }

}
