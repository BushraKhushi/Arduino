#include <ArduinoJson.h>
StaticJsonDocument<200> doc;
JsonObject root = doc.to<JsonObject>();
int i;

void setup() {
  Serial.begin(115200);
  while (!Serial) continue;

  root["sensor"] = "gps";
  root["time"] = 1351824120;
}

void loop() {
delay(1000);
  serializeJson(root, Serial);
char  json [] = "{\"sensor\":\"gps\",\"time\":135}";
  Serial.println(json);
}
