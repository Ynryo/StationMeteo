#include <Arduino.h>
int windSpeedPhase;
int windSpeed;
int windDirectionInt;
char *windDirectionText;
void setup()
{
  Serial.begin(9600);
}

void windDirectionIntToText()
{
  windDirectionInt = random(0, 360);
  if (windDirectionInt < 2)
  {
    windDirectionInt = windDirectionInt + 3;
  }
  if (windDirectionInt > 358)
  {
    windDirectionInt = windDirectionInt - 3;
  }
  if (windDirectionInt > 337.5 && windDirectionInt < 360) // convertisseur angle en ° en text
  {
    windDirectionText = "Nord";
  }
  else if (windDirectionInt > 0 && windDirectionInt < 22.5)
  {
    windDirectionText = "Nord";
  }
  else if (windDirectionInt > 22.5 && windDirectionInt < 67.5)
  {
    windDirectionText = "Nord-Est";
  }
  else if (windDirectionInt > 67.5 && windDirectionInt < 112.5)
  {
    windDirectionText = "Est";
  }
  else if (windDirectionInt > 112.5 && windDirectionInt < 157.5)
  {
    windDirectionText = "Sud-Est";
  }
  else if (windDirectionInt > 157.5 && windDirectionInt < 202.5)
  {
    windDirectionText = "Sud";
  }
  else if (windDirectionInt > 202.5 && windDirectionInt < 247.5)
  {
    windDirectionText = "Sud-Ouest";
  }
  else if (windDirectionInt > 247.5 && windDirectionInt < 292.5)
  {
    windDirectionText = "Ouest";
  }
  else if (windDirectionInt > 292.5 && windDirectionInt < 337.5)
  {
    windDirectionText = "Nord-Ouest";
  }
}

void loop()
{
    windSpeedPhase = random(1, 4);
    Serial.print("Phase : ");
    Serial.println(windSpeedPhase);
    if (windSpeedPhase == 1) // vent calme
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
            Serial.println(windSpeed);
            windDirectionIntToText();
            delay(1000);
        }
    }
    else if (windSpeedPhase == 2) // vent agité
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
            Serial.println(windSpeed);
            windDirectionIntToText();
            delay(1000);
        }
    }
    else if (windSpeedPhase == 3) // tempète
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
            Serial.println(windSpeed);
            windDirectionIntToText();
            delay(1000);
        }
    }
    else if (windSpeedPhase == 4)
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
            Serial.println(windSpeed);
            windDirectionIntToText();
            delay(1000);
        }
    }
}
