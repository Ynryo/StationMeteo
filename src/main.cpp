#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

const char* ssid = "Station Météo";
const char* password = "YnryoMétéoStation";

const int led = 2;
const int capteurLuminosite = 34;

AsyncWebServer server(80);

void setup() {
    //--------------------Serial
    Serial.begin(115200);
    while(!Serial){
        Serial.println("\n");
    }
    //--------------------GPIO
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
    pinMode(capteurLuminosite, INPUT);
    //--------------------SPIFFS
    if(!SPIFFS.begin()) {
        Serial.println("Erreur SPIFFS");
        return;
    }

    File root = SPIFFS.open("/");
    File file = root.openNextFile();

    while(file) {
        Serial.print("Fichier : ");
        Serial.println(file.name());
        file.close();
        file = root.openNextFile();
    }

    //--------------------WIFI
    Serial.begin(115200);
	delay(1000);
	Serial.println("\n");
	
	Serial.println("Création du point d'accès...");
	WiFi.softAP(ssid, password);
	
	Serial.print("Adresse IP: ");
	Serial.println(WiFi.softAPIP());

    //--------------------SERVER
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SPIFFS, "/index.html", "text/html");
    });

    server.on("/w3.css", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SPIFFS, "/w3.css", "text/css");
    });

    server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SPIFFS, "/script.js", "text/javascript");
    });

    server.on("/lireMuminosite", HTTP_GET, [](AsyncWebServerRequest *request){
        int val = analogRead(capteurLuminosite);
        String luminosite = String(val);
        request->send(200, "text/plain", luminosite);
    });

    server.on("/on", HTTP_GET, [](AsyncWebServerRequest *request){
        digitalWrite(led, HIGH);
        request->send(200);
    });

    server.on("/off", HTTP_GET, [](AsyncWebServerRequest *request){
        digitalWrite(led, LOW);
        request->send(200);
    });

    server.begin();
    Serial.println("Serveur activé");
}

void loop() {

}