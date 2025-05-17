#include <Arduino.h>
#include <BleKeyboard.h>

#define LED_PIN 22
#define BUTTON_ONE_PIN 15
#define BUTTON_TWO_PIN 18
#define BUTTON_THREE_PIN 19

BleKeyboard bleKeyboard;

void blinkLed();
bool lastButtonOneState = HIGH; 
bool lastButtonTwoState = HIGH; 
bool lastButtonThreeState = HIGH; 

void setup() 
{
  pinMode(LED_PIN, OUTPUT);    
  pinMode(BUTTON_ONE_PIN, INPUT_PULLUP); 
  pinMode(BUTTON_TWO_PIN, INPUT_PULLUP); 
  pinMode(BUTTON_THREE_PIN, INPUT_PULLUP); 

  Serial.begin(115200);
  bleKeyboard.begin();
}

void loop() 
{
  bool currentButtonOneState = digitalRead(BUTTON_ONE_PIN);
  bool currentButtonTwoState = digitalRead(BUTTON_TWO_PIN);
  bool currentButtonThreeState = digitalRead(BUTTON_THREE_PIN);

  if (bleKeyboard.isConnected()) {
    if (lastButtonOneState == HIGH && currentButtonOneState == LOW) 
    {
      bleKeyboard.write(KEY_NUM_1);
      blinkLed();
    }
    if (lastButtonTwoState == HIGH && currentButtonTwoState == LOW) 
    {
      bleKeyboard.write(KEY_NUM_2);
      blinkLed();
    }
    if (lastButtonThreeState == HIGH && currentButtonThreeState == LOW) 
    {
      bleKeyboard.write(KEY_NUM_3);
      blinkLed();
    }
  }

  lastButtonOneState = currentButtonOneState; 
  lastButtonTwoState = currentButtonTwoState; 
  lastButtonThreeState = currentButtonThreeState; 
  delay(10);
}

void blinkLed()
{
  digitalWrite(LED_PIN, HIGH);
  delay(100);
  digitalWrite(LED_PIN, LOW);
}