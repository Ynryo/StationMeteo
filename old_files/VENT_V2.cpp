#include <Arduino.h>
int vitesse;
int orientation;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  vitesse = random(30, 70);
  orientation = random(0, 360);
  delay(1000);
  while (true)
  {
    vitesse = vitesse + random(-2, 3);
    orientation = orientation + random(-2, 3);
    Serial.print(vitesse);
    Serial.println("km/h");
    Serial.print(" ");
    delay(1000);
    if (vitesse < 10)
    {
      vitesse = vitesse + 3;
    }
    if (vitesse > 90)
    {
      vitesse = vitesse - 3;
    }
    if (orientation < 10)
    {
      vitesse = vitesse + 3;
    }
    if (vitesse > 90)
    {
      vitesse = vitesse - 3;
    }
    if (orientation > 337.5 && orientation < 360)
    {
      Serial.print(orientation);
      Serial.print("°");
      Serial.print(" ");
      Serial.println("Nord");
    }
    if (orientation > 0 && orientation < 22.5)
    {
      Serial.print(orientation);
      Serial.print("°");
      Serial.print(" ");
      Serial.println("Nord");
    }
    if (orientation > 22.5 && orientation < 67.5)
    {
      Serial.print(orientation);
      Serial.print("°");
      Serial.print(" ");
      Serial.println("Nord-Est");
    }
    if (orientation > 67.5 && orientation < 112.5)
    {
      Serial.print(orientation);
      Serial.print("°");
      Serial.print(" ");
      Serial.println("Est");
    }
    if (orientation > 112.5 && orientation < 157.5)
    {
      Serial.print(orientation);
      Serial.print("°");
      Serial.print(" ");
      Serial.println("Sud-Est");
    }
    if (orientation > 157.5 && orientation < 202.5)
    {
      Serial.print(orientation);
      Serial.print("°");
      Serial.print(" ");
      Serial.println("Sud");
    }
    if (orientation > 202.5 && orientation < 247.5)
    {
      Serial.print(orientation);
      Serial.print("°");
      Serial.print(" ");
      Serial.println("Sud-Ouest");
    }
    if (orientation > 247.5 && orientation < 292.5)
    {
      Serial.print(orientation);
      Serial.print("°");
      Serial.print(" ");
      Serial.println("Ouest");
    }
    if (orientation > 292.5 && orientation < 337.5)
    {
      Serial.print(orientation);
      Serial.print("°");
      Serial.print(" ");
      Serial.println("Nord-Ouest");
    }
  }
}
