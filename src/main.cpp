#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include <WiFi.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LTR390.h>
#include <DHT.h>
#include <DHT_U.h>

const char *ssid = "Freebox-A05C1B";
const char *password = "kzvzbq2tdbq6rttrqh6f35";
// const char *ssid = "Ynryo's Private Network";
// const char *password = "SecurePassword";
// const char *ssid = "TP-Link_FC6C";
// const char *password = "03798966";

const int luminositySensor = 34;
const int temperatureSensor = 33; // temperature and humidity in the same sensor

int windSpeed;
int windSpeedPhase;
int windDirectionInt = 0;
String windDirectionText = "none";

DHT dht(temperatureSensor, DHT22);
Adafruit_LTR390 ltr = Adafruit_LTR390();

AsyncWebServer server(80); // démarrage du serveur sur la port 80

void setup()
{
    //--------------------Serial
    Serial.begin(115200);
    while (!Serial)
    {
        Serial.println("\n");
    }

    //--------------------GPIO
    dht.begin(); // démarrage de la lib DHT
    ltr.begin();

    //--------------------SPIFFS
    if (!SPIFFS.begin(true)) // Si les SPIFFS ne initialisent pas, écrire "SPIFFS error" dans la console
    {
        Serial.println("SPIFFS error");
        return;
    }

    File root = SPIFFS.open("/");
    File file = root.openNextFile();

    while (file) // Pour chaque fichier, écrire son nom dans la console
    {
        Serial.print("File: ");
        Serial.println(file.name());
        file.close();
        file = root.openNextFile();
    }

    //--------------------WIFI
    WiFi.begin(ssid, password); // démarrage WIFI avec le SSID et le MDP
    Serial.print("Waiting for connection...");

    while (WiFi.status() != WL_CONNECTED) // tant que la connexion WIFI n'est pas active, print "."
    {
        Serial.print(".");
        delay(100);
    }

    Serial.print("\n");
    Serial.println("Connected");
    Serial.print("IP adress: ");
    Serial.println(WiFi.localIP()); // print l'adresse IP

    //--------------------SERVER
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(SPIFFS, "/index.html", "text/html"); });
    server.on("/styles.css", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(SPIFFS, "/styles.css", "text/css"); });
    server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(SPIFFS, "/script.js", "text/javascript"); });
    server.on("/onclick.js", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(SPIFFS, "/onclick.js", "text/javascript"); });
    server.on("/getDatas", HTTP_GET, [](AsyncWebServerRequest *request)
              {
        String datas = "{\"windSpeed\":" + String(windSpeed) + 
        ",\"windDirectionText\":\"" + windDirectionText + 
        "\",\"windDirectionInt\":" + String(windDirectionInt) + 
        ",\"temperature\":" + String(dht.readTemperature()) + 
        ",\"humidity\":" + String(dht.readHumidity()) + 
        ",\"uvIndex\":" + String(ltr.readUVS()) + 
        "}";
    request->send(200, "application/json", datas); });
    server.begin();
    Serial.println("Server on");
}

void windDirectionIntToText()
{
    // simulateur direction vent
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
    float tauxHumidite = dht.readHumidity();            // Lecture du taux d'humidité (en %)
    float temperatureEnCelsius = dht.readTemperature(); // Lecture de la température, exprimée en degrés Celsius
    // simulateur vitesse vent
    windSpeedPhase = random(1, 4);
    // Serial.print("Phase : ");
    // Serial.println(windSpeedPhase);
    if (windSpeedPhase == 1) // vent calme
    {
        windSpeed = random(3, 50);
        for (int loops = 1; loops < random(6, 16); loops++)
        {
            windSpeed = windSpeed + random(-2, 3);
            if (windSpeed < 3)
            {
                windSpeed = windSpeed + 3;
            }
            if (windSpeed > 50)
            {
                windSpeed = windSpeed - 3;
            }
            // Serial.println(windSpeed);
            windDirectionIntToText();
            delay(1000);
        }
    }
    else if (windSpeedPhase == 2) // vent normal
    {
        windSpeed = random(35, 85);
        for (int loops = 1; loops < random(6, 16); loops++)
        {
            windSpeed = windSpeed + random(-5, 6);
            if (windSpeed < 35)
            {
                windSpeed = windSpeed + 3;
            }
            if (windSpeed > 85)
            {
                windSpeed = windSpeed - 3;
            }
            // Serial.println(windSpeed);
            windDirectionIntToText();
            delay(1000);
        }
    }
    else if (windSpeedPhase == 3) // vent agité
    {
        windSpeed = random(55, 125);
        for (int loops = 1; loops < random(6, 16); loops++)
        {
            windSpeed = windSpeed + random(-8, 9);
            if (windSpeed < 55)
            {
                windSpeed = windSpeed + 3;
            }
            if (windSpeed > 125)
            {
                windSpeed = windSpeed - 3;
            }
            // Serial.println(windSpeed);
            windDirectionIntToText();
            delay(1000);
        }
    }
    else if (windSpeedPhase == 4) // tempète
    {
        windSpeed = random(95, 185);
        for (int loops = 1; loops < random(6, 16); loops++)
        {
            windSpeed = windSpeed + random(-11, 12);
            if (windSpeed < 95)
            {
                windSpeed = windSpeed + 3;
            }
            if (windSpeed > 185)
            {
                windSpeed = windSpeed - 3;
            }
            // Serial.println(windSpeed);
            windDirectionIntToText();
            delay(1000);
        }
    }
}