/******************************************************************

                        J s o n   T e s t 

                                                  қuran nov 2024
******************************************************************/
#include <Arduino.h>
#include <ArduinoJson.h>


void setup() {
  Serial.begin(115200);

  // Beispiel-JSON als String
  const char* jsonString = "{\"temperatur\":25.3,\"feuchtigkeit\":60}";

  // JSON-Dokument erstellen
  StaticJsonDocument<200> doc;

  // JSON-String parsen
  // jsonString -> doc
  DeserializationError error = deserializeJson(doc, jsonString);

  if (error) {
    Serial.print("Fehler beim Parsen: ");
    Serial.println(error.c_str());
    return;
  }

  // Werte auslesen
  float temperatur = doc["temperatur"];
  int feuchtigkeit = doc["feuchtigkeit"];

  // Ausgabe
  Serial.print("Temperatur: ");
  Serial.println(temperatur);
  Serial.print("Feuchtigkeit: ");
  Serial.println(feuchtigkeit);

  // neue Daten vorbereiten

  doc["temp"] = 22.3;
  doc["feu"] = 50;

  String jsonString2; 
  // doc -> jsonString2
  serializeJson(doc, jsonString2);
  
  Serial.println(jsonString2);

}

void loop() {
  // Hier ist nichts zu tun
}

