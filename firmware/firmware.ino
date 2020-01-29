//{"mId":1,"t":"1579847135","watt":1234,"voltage":230,"current":12.3,"frequency":50.01,"kwh":2345,"status":0}

#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <ArduinoOTA.h>
#include <FS.h>

#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>  

//#ifndef STASSID
//#define STASSID "Infinix HOT 4"
//#define STAPSK  "bushra@3"
//#define STASSID "IX Basement-2.4G"
//#define STAPSK  "ixbasement@123"
//#endif

//const char* ssid     = STASSID;
//const char* password = STAPSK;

//const char* host = "192.168.0.209";
const char* host = "51.144.52.85";
const uint16_t port = 1122;

const char* filename="/samplefile.txt";
String object ="";
File fsUploadFile; 

int i =0;
int watt = 1234;
int voltage = 230;
int current = 12.3;
int frequency = 50.01;
int kwh = 2345;

const char* stored_data(int i);

StaticJsonDocument<256> doc;
JsonObject root = doc.to<JsonObject>();


void setup() {
  root["time"] = 1351824120;
  root["iteration"]= i;
  root["mId"] = 1;
  root["time"] = 1351824120;
  root["watt"]= watt;
  root["voltage"]= voltage;
  root["current"]= current;
  root["frequency"]= frequency;
  root["kwh"]= kwh;
  root["status"]= 0;
  if(SPIFFS.begin()) {  Serial.println("SPIFFS got Initialized successfully"); }
  else {  Serial.println("SPIFFS Initialization is failed");}
//  SPIFFS.format();
  
  Serial.begin(115200);
  Serial.print("Connecting to Interet");
//  Serial.println(ssid);
  WiFiManager wifiManager;
  wifiManager.resetSettings();
  wifiManager.setTimeout(1);
  while(!wifiManager.autoConnect("AutoConnectAP")) {
    Serial.println("failed to connect and hit timeout");
    delay(1000);
//    serializeJson(root, Serial);
    Serial.println("{\"mId\": 1,\"time\":1351824120, \"watt\": "+(String)watt+",\"volatge\":"+String(voltage)+",\"current\" :"+String(current)+", \"frequency\": "+(String)frequency+",\"kwh\":"+String(kwh)+",\"status\":0, \"iteration\":"+(String)i+"},");
    filename=stored_data(i); 
    i++;
  //reset and try again, or maybe put it to deep sleep
//    ESP.reset();
    delay(2000);
    }

  WiFi.mode(WIFI_STA);
  WiFi.begin();

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
    Serial.println("{\"mId\": 1,\"time\":1351824120, \"watt\": "+(String)watt+",\"volatge\":"+String(voltage)+",\"current\" :"+String(current)+", \"frequency\": "+(String)frequency+",\"kwh\":"+String(kwh)+",\"status\":0, \"iteration\":"+(String)i+"},");
    filename=stored_data(i);
    i++;  
} Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  while (!Serial) continue;

  root["sensor"] = "gps";
  root["time"] = 1351824120;
  root["iteration"]= i;
  root["mId"] = 1;
  root["time"] = 1351824120;
  root["watt"]= watt;
  root["voltage"]= voltage;
  root["current"]= current;
  root["frequency"]= frequency;
  root["kwh"]= kwh;
  root["status"]= 0;
}

void loop() {

  if (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("Connecting to Internet");
}
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
    filename=stored_data(i); 
    i++; }
  Serial.println("Connected to Internet");
  Serial.print("connecting to Server");
  Serial.print(host);
  Serial.print(':');
  Serial.println(port);
  
  WiFiClient client;
  if (!client.connect(host, port))
  Serial.println("Connection Failed with Server");
  while (!client.connect(host, port)) {
//    Serial.println("connection failed");
    filename=stored_data(i);
    Serial.println("{\"mId\": 1,\"time\":1351824120, \"watt\": "+(String)watt+",\"volatge\":"+String(voltage)+",\"current\" :"+String(current)+", \"frequency\": "+(String)frequency+",\"kwh\":"+String(kwh)+",\"status\":0, \"iteration\":"+(String)i+"},");
    delay(1000);
    i++;   
  }
  Serial.println("sending data to server");
  if (client.connected()) {
    File f=SPIFFS.open(filename,"r");
    if(!f)
    {
      Serial.println("file open failed");
    }
    else
    {
      Serial.println("Reading Data from file....");
      {
      client.print("[");
      for(int j=0;j<f.size()-1;j++)
      {
      client.print((char)f.read());      }
      //close file
      f.close();
      client.println("]");
      client.println("file Closed");
      }
    SPIFFS.format();
  }
  delay(1000);
  
  Serial.println("{\"mId\": 1,\"time\":1351824120, \"watt\": "+(String)watt+",\"volatge\":"+String(voltage)+",\"current\" :"+String(current)+", \"frequency\": "+(String)frequency+",\"kwh\":"+String(kwh)+",\"status\":0, \"iteration\":"+(String)i+"},");
  client.print("{\"mId\": 1,\"time\":1351824120, \"watt\": "+(String)watt+",\"volatge\":"+String(voltage)+",\"current\" :"+String(current)+", \"frequency\": "+(String)frequency+",\"kwh\":"+String(kwh)+",\"status\":0, \"iteration\":"+(String)i+"},"); 
  i++;
  }
  // wait for data to be available
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      delay(6000);
      return;
    }}
  Serial.println("receiving from remote server");
  while (client.available()) {
    char ch = static_cast<char>(client.read());
    Serial.print(ch);  }
    
  Serial.println();
  Serial.println("closing connection");
  client.stop();

  delay(3000); // execute once every 5 minutes, don't flood remote service

}
const char* stored_data( int i){
  
//  root.prettyPrintTo(Serial);
  
  File Log = SPIFFS.open("/samplefile.txt", "a");
  Log.print ("{\"mId\": 1,\"time\":1351824120, \"watt\": "+(String)watt+",\"volatge\":"+String(voltage)+",\"current\" :"+String(current)+", \"frequency\": "+(String)frequency+",\"kwh\":"+String(kwh)+",\"status\":0, \"iteration\":"+(String)i+"},"); 
  Log.close();
  return "/samplefile.txt";}
