#include <Arduino.h>
#include <BleKeyboard.h>

#define LED_PIN 22
#define BUTTON_PIN 15

BleKeyboard bleKeyboard;

void blinkLed();

void setup() 
{
  pinMode(LED_PIN, OUTPUT);    
  pinMode(BUTTON_PIN, INPUT_PULLUP); 

  Serial.begin(115200);
  bleKeyboard.begin();
}

void loop() 
{
  static bool lastButtonState = HIGH; 
  bool currentButtonState = digitalRead(BUTTON_PIN);

  if (bleKeyboard.isConnected()) {
    if (lastButtonState == HIGH && currentButtonState == LOW) 
    {
      bleKeyboard.write(KEY_NUM_0);
      blinkLed();
    }
  }

  lastButtonState = currentButtonState; 
  delay(10);
}

void blinkLed()
{
  digitalWrite(LED_PIN, HIGH);
  delay(100);
  digitalWrite(LED_PIN, LOW);
}