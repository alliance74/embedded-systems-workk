// Transmitter codes
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop(){
  
  if (mySerial.available()) {
    String receivedData = mySerial.readStringUntil('\n');
    Serial.print("Rx Msg: ");
    Serial.println(receivedData);
  }

 
  if (Serial.available()) {
    String userMessage = Serial.readStringUntil('\n');
    mySerial.println(userMessage);
  }

  delay(1000);
}
