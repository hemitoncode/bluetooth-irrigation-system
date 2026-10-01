#include <SoftwareSerial.h>

SoftwareSerial bt(10, 11); // RX, TX

const int motorPin = 4;

void setup() {
  Serial.begin(9600);
  bt.begin(9600);

  pinMode(motorPin, OUTPUT);
  digitalWrite(motorPin, HIGH);

  Serial.println("STARTED");
}

void loop() {
  if (bt.available()) {
    char c = bt.read();

    Serial.print("I RECEIVED: ");
    Serial.println(c);
 
    if (c == '1') {
      Serial.println("TURNING MOTOR ON");
      digitalWrite(motorPin, LOW);
    }

    if (c == '0') {
      Serial.println("TURNING MOTOR OFF");
      digitalWrite(motorPin, HIGH);
    }
  }
}
