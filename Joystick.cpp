#include "Arduino.h"
#include "Joystick.h"

void Joystick::ReadYaxis()
{
  yValue = analogRead(A1); 
  if(yValue < 100)
  {
    keyPressedY = 'U';
  }
  else if(yValue > 900)
  {
    keyPressedY = 'D';
  }else
  {
    keyPressedY = ' ';
  }
}

void Joystick::ReadXaxis()
{
  xValue = analogRead(A0); 
  if(xValue < 100)
  {
    keyPressedX = 'L';
  }
  else if(xValue > 900)
  {
    keyPressedX = 'R';
  }else
  {
    keyPressedX = ' ';
  }
}