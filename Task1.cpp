const int buttonPin = 2;  
volatile int buttonCount = 0;  
unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50;  
int buttonState;  
int lastButtonState = LOW;  

void setup() {  
  Serial.begin(9600);  
  pinMode(buttonPin, INPUT);  
  attachInterrupt(digitalPinToInterrupt(buttonPin), countButtonPress, RISING);  
}  

void loop() {  
  Serial.println(buttonCount);  
  delay(1000);  
}  

void countButtonPress() {  
  int reading = digitalRead(buttonPin);  
  if (reading != lastButtonState) {  
    lastDebounceTime = millis();  
  }  
  if ((millis() - lastDebounceTime) > debounceDelay) {  
    if (reading != buttonState) {  
      buttonState = reading;  
      if (buttonState == HIGH) {  
        buttonCount++;  
      }  
    }  
  }  
  lastButtonState = reading;  
}