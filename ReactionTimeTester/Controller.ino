#include "Controller.h"

Controller::Controller(const int Leds[], const uint8_t Buttons[], uint8_t 
StartButton, uint8_t numInputs, LiquidCrystal &lcdRef) : ledPins(Leds), buttonPins(Buttons), 
startButton(StartButton), numInputs(numInputs), lcd(lcdRef)
{
  state = RestingState;
  randNum = -1;
  prevRandNum = -1;
  randNumInARow = 0;
  score = 0;
  pressedOnTime = false;
}

void Controller::InitializePins()
{
  pinMode(startButton, INPUT_PULLUP);
  for(int i = 0; i < numInputs; i++)
  {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
}

void Controller::Update()
{
  ShowStartMessage();
  
  RestartReactionTest();

  GuessRandomNumber();

  if(state == TestingState)
  {
    BeginCountdown();
    TestReaction();
  }

  DisplayResults();

}

void Controller::ShowStartMessage()
{
  if(state == RestingState)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("To test reaction");
    lcd.setCursor(0, 1);
    lcd.print("Press START");
  }
}

void Controller::RestartReactionTest()
{
  randNum = -1;
  score = 0;
  pressedOnTime = false;
  while(state == RestingState)
  {
    if(digitalRead(startButton) == LOW)
    {
      state = TestingState;
      while(digitalRead(startButton) == LOW){delay(10);}
    }
  }
}

void Controller::GuessRandomNumber()
{
  randNum = random(numInputs);
  if(prevRandNum == randNum)
  {
    randNumInARow++;
    
    if(randNumInARow > 3)
    {
      while(randNum == prevRandNum)
      {
        randNum = random(numInputs);
      }
      randNumInARow = 0;
    }
  }
  else
  {
    randNumInARow = 0;
  }
  prevRandNum = randNum;
}

void Controller::BeginCountdown()
{ 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Test starts in");
  for(int i = 3; i > 0; i--)
  { 
    lcd.setCursor(0, 1);
    lcd.print(i);
    lcd.print(" seconds");
    delay(1000);
  }
}

void Controller::TestReaction()
{
  int startTime = millis();
  int currentTime = startTime;
  digitalWrite(ledPins[randNum], HIGH);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Press the");
  lcd.setCursor(0, 1);
  lcd.print("button");

  while(abs(currentTime - startTime) < 3000 && !pressedOnTime)
  {
    currentTime = millis();
    if(digitalRead(buttonPins[randNum]) == LOW)
    {
      pressedOnTime = true;
      score = currentTime - startTime;
    }
  }
  digitalWrite(ledPins[randNum], LOW);
  state = RestingState;
}

void Controller::DisplayResults()
{ 
  lcd.clear();
  lcd.setCursor(0, 0);
  if(pressedOnTime)
  {
    lcd.print("Your score:");
    lcd.setCursor(0, 1);
    lcd.print(score);
    lcd.print(" ms");
  }
  else
  {
    lcd.print("Too slow");
  }

  int startTime = millis();
  int currentTime = startTime;
  while(abs(currentTime - startTime) < 3000 && state == RestingState)
  {
    currentTime = millis();
    if(digitalRead(startButton) == LOW)
    {
      state = TestingState;
    }
  }
}
