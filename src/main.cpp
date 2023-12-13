#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

const char* ssid = "TP-Link_FC6C";
const char* password = "03798966";

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
    WiFi.begin(ssid, password);
	Serial.print("Tentative de connexion...");
	
	while(WiFi.status() != WL_CONNECTED)
	{
		Serial.print(".");
		delay(100);
	}
	
	Serial.println("\n");
	Serial.println("Connexion etablie!");
	Serial.print("Adresse IP: ");
	Serial.println(WiFi.localIP());

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

    server.on("/getDatas", HTTP_GET, [](AsyncWebServerRequest *request){
        String datas = String(analogRead(capteurLuminosite));
        request->send(200, "text/plain", datas);
    });

    server.on("/getDatas", HTTP_GET, [](AsyncWebServerRequest *request){
        String datas = String(analogRead(capteurLuminosite));
        request->send(200, "text/plain", datas);
    });

    // server.on("/on", HTTP_GET, [](AsyncWebServerRequest *request){
    //     digitalWrite(led, HIGH);
    //     request->send(200);
    // });

    // server.on("/off", HTTP_GET, [](AsyncWebServerRequest *request){
    //     digitalWrite(led, LOW);
    //     request->send(200);
    // });

    server.begin();
    Serial.println("Serveur activé");
}

void loop() {

}