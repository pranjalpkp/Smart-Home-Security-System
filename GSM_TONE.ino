#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);

const int buzzer = 3; 
const int sensor = 4;

int state; // 0 close - 1 open wwitch

void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600); 
  pinMode(sensor, INPUT_PULLUP);
}

void loop()
{
  state = digitalRead(sensor);
  
  if (state == HIGH && mySerial.available()>0 ){
//    Serial.println("The door is open");
      mySerial.println("AT+CMGF=1"); 
      delay(1000);
      mySerial.println("AT+CMGS=\"+916204390422\"\r"); // Replace x with mobile number
      delay(1000);
      mySerial.println("The door is open");// The SMS text you want to send
     delay(1000);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
     delay(1000);
    tone(buzzer, 400);
  }
  else{
//    Serial.println("The door is closed");

    mySerial.println("AT+CMGF=1"); 
      delay(1000);
      mySerial.println("AT+CMGS=\"+916204390422\"\r"); // Replace x with mobile number
      delay(1000);
      mySerial.println("The door is closed");// The SMS text you want to send
     delay(1000);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);
    noTone(buzzer);
  }
  delay(200);
  
}
