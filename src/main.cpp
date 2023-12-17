#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include <WiFi.h>

const char *ssid = "Freebox-A05C1B";
const char *password = "kzvzbq2tdbq6rttrqh6f35";
// const char *ssid = "TP-Link_FC6C";
// const char *password = "03798966";

// const int led = 2;
const int luminositySensor = 13;
const int windSpeedSensor = 12;
const int windDirectionSensor = 14;
const int temperatureSensor = 27;
const int humiditySensor = 26;

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
    // pinMode(led, OUTPUT);
    // digitalWrite(led, LOW);
    pinMode(luminositySensor, INPUT);
    pinMode(windSpeedSensor, INPUT);
    pinMode(windDirectionSensor, INPUT);
    pinMode(temperatureSensor, INPUT);
    pinMode(humiditySensor, INPUT);

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

    server.on("/w3.css", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(SPIFFS, "/w3.css", "text/css"); });

    server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(SPIFFS, "/script.js", "text/javascript"); });

    server.on("/getDatas", HTTP_GET, [](AsyncWebServerRequest *request)
              {
        String datas = "{\"brightness\":" + String(digitalRead(luminositySensor)) + 
        ",\"windSpeed\":" + String(digitalRead(windSpeedSensor)) + 
        ",\"windDirection\":" + String(digitalRead(windDirectionSensor)) + 
        ",\"temperature\":" + String(digitalRead(temperatureSensor)) + 
        ",\"humidity\":" + String(digitalRead(humiditySensor)) + 
        "}";
       request->send(200, "application/json", datas); });

    // server.on("/on", HTTP_GET, [](AsyncWebServerRequest *request){
    //     digitalWrite(led, HIGH);
    //     request->send(200);
    // });

    // server.on("/off", HTTP_GET, [](AsyncWebServerRequest *request){
    //     digitalWrite(led, LOW);
    //     request->send(200);
    // });

    server.begin();
    Serial.println("Server on");
}

void loop()
{
}