#include <Arduino.h>
int windSpeedPhase;
int windSpeed;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  windSpeedPhase = random(1, 4);
  if (windSpeedPhase = 1)
  {
    windSpeed = random(3, 35);
    for (int loops = 1; loops < random(6, 16); loops++)
    {
      windSpeed = windSpeed + random(-2, 3);
      if (windSpeed < 2)
      {
        windSpeed = windSpeed + 3;
      }
      if (windSpeed > 36)
      {
        windSpeed = windSpeed - 3;
      }
      delay(1000);
    }
  }
  if (windSpeedPhase = 2)
  {
    windSpeed = random(35, 70);
    for (int loops = 1; loops < random(6, 16); loops++)
    {
      windSpeed = windSpeed + random(-2, 3);
      if (windSpeed < 34)
      {
        windSpeed = windSpeed + 3;
      }
      if (windSpeed > 71)
      {
        windSpeed = windSpeed - 3;
      }
      delay(1000);
    }
  }
  if (windSpeedPhase = 3)
  {
    windSpeed = random(70, 110);
    for (int loops = 1; loops < random(6, 16); loops++)
    {
      windSpeed = windSpeed + random(-2, 3);
      if (windSpeed < 69)
      {
        windSpeed = windSpeed + 3;
      }
      if (windSpeed > 111)
      {
        windSpeed = windSpeed - 3;
      }
      delay(1000);
    }
  }
  if (windSpeedPhase = 4)
  {
    windSpeed = random(110, 170);
    for (int loops = 1; loops < random(6, 16); loops++)
    {
      windSpeed = windSpeed + random(-2, 3);
      if (windSpeed < 109)
      {
        windSpeed = windSpeed + 3;
      }
      if (windSpeed > 171)
      {
        windSpeed = windSpeed - 3;
      }
      delay(1000);
    }
  }
}
