#include <DHT.h>
#define brocheDeBranchementDHT 6    // La ligne de communication du DHT22 sera donc branchée sur la pin D6 de l'Arduino
#define typeDeDHT DHT22             // Ici, le type de DHT utilisé est un DHT22 (que vous pouvez changer en DHT11, DHT21, ou autre, le cas échéant)
int capteur_lum = 0; // capteur branché sur le port 0
int analog_lum; // valeur analogique envoyé par le capteur
// Instanciation de la librairie DHT
DHT dht(brocheDeBranchementDHT, typeDeDHT);


// ========================
// Initialisation programme
// ========================
void setup () {
  
  // Initialisation de la liaison série (pour retourner les infos au moniteur série de l'ordi)
  Serial.begin(9600);
  Serial.println("Programme de test du DHT22");
  Serial.println("==========================");
  Serial.println();

  // Initialisation du DHT22;
  dht.begin();
}
 
// =================
// Boucle principale
// =================
void loop () {
   analog_lum = analogRead(capteur_lum); // lecture de la valeur analogique, qu'on enregistre dans analog_lum
  Serial.print("Valeur luminosité = ");
  Serial.print(analog_lum); 
  Serial.println("");   
  // Lecture des données
  float tauxHumidite = dht.readHumidity();              // Lecture du taux d'humidité (en %)
  float temperatureEnCelsius = dht.readTemperature();   // Lecture de la température, exprimée en degrés Celsius

  // Vérification si données bien reçues
  if (isnan(tauxHumidite) || isnan(temperatureEnCelsius)) {
    Serial.println("Aucune valeur retournée par le DHT22. Est-il bien branché ?");
    delay(2000);
    return;         // Si aucune valeur n'a été reçue par l'Arduino, on attend 2 secondes, puis on redémarre la fonction loop()
  }

  // Calcul de la température ressentie
  float temperatureRessentieEnCelsius = dht.computeHeatIndex(temperatureEnCelsius, tauxHumidite, false); // Le "false" est là pour dire qu'on travaille en °C, et non en °F
  
  // Affichage des valeurs
  Serial.print("Humidité = "); Serial.print(tauxHumidite); Serial.println(" %");
  Serial.print("Température = "); Serial.print(temperatureEnCelsius); Serial.println(" °C");
  Serial.print("Température ressentie = "); Serial.print(temperatureRessentieEnCelsius); Serial.println(" °C");
  Serial.println();

  // Temporisation de 2 secondes (pour rappel : il ne faut pas essayer de faire plus d'1 lecture toutes les 2 secondes, avec le DHT22, selon le fabricant)
  delay(2000);
}
