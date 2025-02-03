#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11);

const int relayPin = 7;

void setup() {
    pinMode(relayPin, OUTPUT);
    digitalWrite(relayPin, LOW);
    BT.begin(9600);
    Serial.begin(9600);
}

void loop() {
    if (BT.available()) {
        char command = BT.read();
        
        if (command == '1') {
            digitalWrite(relayPin, HIGH);
            Serial.println("Device ON");
        } 
        else if (command == '0') {
            digitalWrite(relayPin, LOW);
            Serial.println("Device OFF");
        }
    }
}
