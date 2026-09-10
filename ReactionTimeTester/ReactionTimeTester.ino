#include <LiquidCrystal.h>
#include <Arduino.h>
#include "Controller.h"

const int LED_PINS[] = {A0, A1, A2, 3};
const uint8_t BUTTON_PINS[] = {13, 12, 11, 4};
const int StartButton = 2;
const int numInputs = 4;

LiquidCrystal lcd(10, 9, 8, 7, 6, 5);

Controller test(LED_PINS, BUTTON_PINS, StartButton, numInputs, lcd);

void setup() 
{
  lcd.begin(16, 2);  
  randomSeed(analogRead(A3));

  test.InitializePins();
}

void loop() 
{
  test.Update();
}

