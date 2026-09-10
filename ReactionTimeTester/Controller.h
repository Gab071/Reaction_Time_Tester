#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Arduino.h>

enum State {TestingState, RestingState};

class Controller{

  const int *ledPins;
  const uint8_t *buttonPins;
  const uint8_t startButton;
  LiquidCrystal &lcd;

  const int numInputs;

  State state;
  int randNum;
  int prevRandNum;
  int randNumInARow;
  int score;
  bool pressedOnTime;

  /// Function displays start message on LCD
  void ShowStartMessage();

  /// Function restarts all needed variables and waits to
  /// change state from resting to testing when button is pressed
  void RestartReactionTest();

  /// Function guesses which of the 4 LED's will be light up
  /// and which button will be needed to be pressed respectively
  void GuessRandomNumber();

  /// Just 3 second countdown on LCD 
  void BeginCountdown();

  /// Function that tests reaction (3 seconds to press the button or person fails)
  void TestReaction();

  /// Displays results on LCD
  void DisplayResults();

  public:

  Controller(const int Leds[], const uint8_t Buttons[], uint8_t StartButton, uint8_t numInputs, LiquidCrystal &lcdRef);

  void InitializePins();
  void Update();
};

#endif