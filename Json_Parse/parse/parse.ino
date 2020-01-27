#include <ArduinoJson.h>

void setup() {
  // Initialize serial port
  Serial.begin(115200);
  while (!Serial) continue;

  StaticJsonDocument<200> doc;
}

void loop() {
  
  StaticJsonDocument<200> doc;
  char json[] =
      "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";
  deserializeJson(doc, json);
  const char* sensor = doc["sensor"];
  Serial.println(sensor);
}
