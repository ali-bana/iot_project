#include <stdlib.h>

void setup() {
  Serial.begin(9600);
  Serial.println("serial delimit test 11-12-13"); // so I can keep track of what is loaded
}

char* parser(String inputString){
  int ind1 = -1;
  int ind2 = 0;
  unsigned char * item;
  item = (char *) malloc (512 * sizeof(char));
  int i = 0;
  int j = 0;
  String str;
  while(i < 512){
    ind2 = inputString.indexOf(',', ind1 + 1);  //finds location of first ,
    str = inputString.substring(ind1 + 3, ind2);   //captures data String
    if(ind2 != -1)
    {
      char c = 0;
      if(str[1] >= '0' && str[1] <= '9')
        c += str[1] - '0';
      else
        c += 10 + str[1] - 'a';
      if(str[0] >= '0' && str[0] <= '9')
        c += 16 * (str[0] - '0');
      else
        c += 16 * (10 + str[0] - 'a');
      item[i] = (unsigned char) c; //assigns this number to ith item
      ind1 = ind2; //updates index
    }
    else
    {
      item[i] = 0;
    }
    i++; //iteration
  }
  return item;
}

void loop() {
  String inpStr = "0xff,0xa9,0x35,0xbc,0x6d,0x23"; //main captured String 
  unsigned char * itemp;
  //itemp = (char *) malloc (512 * sizeof(char));
  itemp = parser(inpStr);
  int j = 0;
  for(j = 0; j < 512; j++){
    Serial.print(itemp[j], HEX);
    Serial.print(" ");
  }
  delay(100000);
}


