#include <Arduino.h>
int statuts;
int vitesse;
int orientation;
void setup() {
  Serial.begin(9600);
}

void loop() {
  statuts = random(1, 4);
  if (statuts = 1) {
    vitesse = random(3, 35);
    orientation = random(0, 360);
    for (int loops = 1; loops < random(6, 16); loops++) {
      vitesse = vitesse + random(-2, 3);
      orientation = orientation + random(-2, 3);
      Serial.print(vitesse);
      Serial.println("km/h");
      Serial.print(" ");
      if (vitesse < 2) {
        vitesse = vitesse + 3;
      }
      if (vitesse > 36) {
        vitesse = vitesse - 3;
      }
      if (orientation < 2) {
        orientation = orientation + 3;
      }
      if (orientation > 358) {
        orientation = orientation - 3;
      }
      orientation = orientation + random(-2, 3);
      if (orientation > 337.5 && orientation < 360) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Nord");

      }
      if (orientation > 0 && orientation < 22.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Nord");

      }
      if (orientation > 22.5 && orientation < 67.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Nord-Est");

      }
      if (orientation > 67.5 && orientation < 112.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Est");

      }
      if (orientation > 112.5 && orientation < 157.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Sud-Est");

      }
      if (orientation > 157.5 && orientation < 202.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Sud");

      }
      if (orientation > 202.5 && orientation < 247.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Sud-Ouest");

      }
      if (orientation > 247.5 && orientation < 292.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Ouest");

      }
      if (orientation > 292.5 && orientation < 337.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Nord-Ouest");

      }
      delay(1000);
    }
  }
  if (statuts = 2) {
    vitesse = random(35, 70);
    orientation = random(0, 360);
    for (int loops = 1; loops < random(6, 16); loops++) {
      vitesse = vitesse + random(-2, 3);
      orientation = orientation + random(-2, 3);
      Serial.print(vitesse);
      Serial.println("km/h");
      Serial.print(" ");
      if (vitesse < 34) {
        vitesse = vitesse + 3;
      }
      if (vitesse > 71) {
        vitesse = vitesse - 3;
      }
      if (orientation < 2) {
        orientation = orientation + 3;
      }
      if (orientation > 358) {
        orientation = orientation - 3;
      }
      orientation = orientation + random(-2, 3);
      if (orientation > 337.5 && orientation < 360) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Nord");

      }
      if (orientation > 0 && orientation < 22.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Nord");

      }
      if (orientation > 22.5 && orientation < 67.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Nord-Est");

      }
      if (orientation > 67.5 && orientation < 112.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Est");

      }
      if (orientation > 112.5 && orientation < 157.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Sud-Est");

      }
      if (orientation > 157.5 && orientation < 202.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Sud");

      }
      if (orientation > 202.5 && orientation < 247.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Sud-Ouest");

      }
      if (orientation > 247.5 && orientation < 292.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Ouest");

      }
      if (orientation > 292.5 && orientation < 337.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Nord-Ouest");

      }
      delay(1000);
    }
  }
  if (statuts = 3) {
    vitesse = random(70, 110);
    orientation = random(0, 360);
    for (int loops = 1; loops < random(6, 16); loops++) {
      vitesse = vitesse + random(-2, 3);
      orientation = orientation + random(-2, 3);
      Serial.print(vitesse);
      Serial.println("km/h");
      Serial.print(" ");
      if (vitesse < 69) {
        vitesse = vitesse + 3;
      }
      if (vitesse > 111) {
        vitesse = vitesse - 3;
      }
      if (orientation < 2) {
        orientation = orientation + 3;
      }
      if (orientation > 358) {
        orientation = orientation - 3;
      }
      orientation = orientation + random(-2, 3);
      if (orientation > 337.5 && orientation < 360) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Nord");

      }
      if (orientation > 0 && orientation < 22.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Nord");

      }
      if (orientation > 22.5 && orientation < 67.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Nord-Est");

      }
      if (orientation > 67.5 && orientation < 112.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Est");

      }
      if (orientation > 112.5 && orientation < 157.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Sud-Est");

      }
      if (orientation > 157.5 && orientation < 202.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Sud");

      }
      if (orientation > 202.5 && orientation < 247.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Sud-Ouest");

      }
      if (orientation > 247.5 && orientation < 292.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Ouest");

      }
      if (orientation > 292.5 && orientation < 337.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Nord-Ouest");

      }
      delay(1000);
    }
  }
  if (statuts = 4) {
    vitesse = random(110, 170);
    orientation = random(0, 360);
    for (int loops = 1; loops < random(6, 16); loops++) {
      vitesse = vitesse + random(-2, 3);
      orientation = orientation + random(-2, 3);
      Serial.print(vitesse);
      Serial.println("km/h");
      Serial.print(" ");
      if (vitesse < 109) {
        vitesse = vitesse + 3;
      }
      if (vitesse > 171) {
        vitesse = vitesse - 3;
      }
      if (orientation < 2) {
        orientation = orientation + 3;
      }
      if (orientation > 358) {
        orientation = orientation - 3;
      }
      orientation = orientation + random(-2, 3);
      if (orientation > 337.5 && orientation < 360) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Nord");

      }
      if (orientation > 0 && orientation < 22.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Nord");

      }
      if (orientation > 22.5 && orientation < 67.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Nord-Est");

      }
      if (orientation > 67.5 && orientation < 112.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Est");

      }
      if (orientation > 112.5 && orientation < 157.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Sud-Est");

      }
      if (orientation > 157.5 && orientation < 202.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Sud");

      }
      if (orientation > 202.5 && orientation < 247.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Sud-Ouest");

      }
      if (orientation > 247.5 && orientation < 292.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Ouest");

      }
      if (orientation > 292.5 && orientation < 337.5) {
        Serial.print(orientation);
        Serial.print("°");
        Serial.print(" ");
        Serial.println("Nord-Ouest");

      }
      delay(1000);
    }
  }
}
