#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include <WiFi.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// const char *ssid = "Freebox-A05C1B";
// const char *password = "kzvzbq2tdbq6rttrqh6f35";
// const char *ssid = "Ynryo's Private Network";
// const char *password = "SecurePassword";
const char *ssid = "TP-Link_FC6C";
const char *password = "03798966";

// int led = 2;
const int luminositySensor = 34;
const int windSpeedSensor = 12;
const int windDirectionSensor = 14;
const int temperatureSensor = 33; //temperature and humidity in the same sensor

int windVitesse;
int windDirectionInt = 0;
String windDirectionText = "none";

DHT dht(temperatureSensor, DHT22);

AsyncWebServer server(80);

void setup()
{
    //--------------------Serial
    Serial.begin(115200);
    while (!Serial)
    {
        Serial.println("\n");
    }

    //--------------------GPIO
    pinMode(luminositySensor, INPUT);
    pinMode(windSpeedSensor, INPUT);
    pinMode(windDirectionSensor, INPUT);
    dht.begin();

    //--------------------SPIFFS
    if (!SPIFFS.begin(true))
    {
        Serial.println("SPIFFS error");
        return;
    }

    File root = SPIFFS.open("/");
    File file = root.openNextFile();

    while (file)
    {
        Serial.print("File: ");
        Serial.println(file.name());
        file.close();
        file = root.openNextFile();
    }

    //--------------------WIFI
    WiFi.begin(ssid, password);
    Serial.print("Waiting for connection...");

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(100);
    }

    Serial.print("\n");
    Serial.println("Connected");
    Serial.print("IP adress: ");
    Serial.println(WiFi.localIP());

    //--------------------SERVER
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(SPIFFS, "/index.html", "text/html"); });
    server.on("/index.html", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(SPIFFS, "/index.html", "text/html"); });
    server.on("/old.html", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(SPIFFS, "/old.html", "text/html"); });

    server.on("/w3.css", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(SPIFFS, "/w3.css", "text/css"); });
    server.on("/styles.css", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(SPIFFS, "/styles.css", "text/css"); });

    server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(SPIFFS, "/script.js", "text/javascript"); });

    server.on("/getDatas", HTTP_GET, [](AsyncWebServerRequest *request)
              {
        String datas = "{\"brightness\":" + String(analogRead(luminositySensor)) + 
        ",\"windSpeed\":" + windVitesse + 
        ",\"windDirectionText\":\"" + windDirectionText + 
        "\",\"windDirectionInt\":" + String(windDirectionInt) + 
        ",\"temperature\":" + float(dht.readTemperature()) + 
        ",\"humidity\":" + float(dht.readHumidity()) + 
        "}";
        // String datas = "{\"brightness\":" + String(random(100000)) + 
        // ",\"windSpeed\":" + String(random(150)) + 
        // ",\"windDirectionText\":\"" + windDirectionText + 
        // "\",\"windDirectionInt\":" + windDirectionInt + 
        // ",\"temperature\":" + String(random(30)) + 
        // ",\"humidity\":" + String(random(100)) + 
        // "}";
       request->send(200, "application/json", datas); });

    server.begin();
    Serial.println("Server on");
}

void loop()
{
    float tauxHumidite = dht.readHumidity();            // Lecture du taux d'humidité (en %)
    float temperatureEnCelsius = dht.readTemperature(); // Lecture de la température, exprimée en degrés Celsius
    windVitesse = random(30, 70);
    windDirectionInt = random(0, 360);
    delay(1000);

    windVitesse = windVitesse + random(-2, 3);
    windDirectionInt = windDirectionInt + random(-2, 3);
    delay(1000);
    if (windVitesse < 10) //simulateur vitesse
    {
        windVitesse = windVitesse + 3;
    }
    if (windVitesse > 90)
    {
        windVitesse = windVitesse - 3;
    }
    if (windDirectionInt < 10)
    {
        windVitesse = windVitesse + 3;
    }
    if (windVitesse > 90)
    {
        windVitesse = windVitesse - 3;
    }

    if (windDirectionInt > 337.5 && windDirectionInt < 360) //convertisseur angle en ° en text
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