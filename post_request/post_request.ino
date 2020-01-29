/*
    This sketch establishes a TCP connection to a "quote of the day" service.
    It sends a "hello" message, and then prints received data.
*/

#include <ESP8266WiFi.h>

#ifndef STASSID
//#define STASSID "Infinix HOT 4"
//#define STAPSK  "bushra@3"
#define STASSID "IX Basement-2.4G"
#define STAPSK  "ixbasement@123"
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;

const char* host = "192.168.0.209";
const uint16_t port = 1122;
int n =0;
int watt = 1234;
int voltage = 230;
int current = 12.3;
int frequency = 50.01;
int kwh = 2345;
int buttonState =0;
int Last_buttonState =0;
int s =0;
const int pin = 16;
long cur;
long pre;
int q=1;

void setup() {
  pre = millis();
  Serial.begin(115200);
  pinMode(pin,INPUT);
  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  cur = millis();
  Serial.print("connecting to ");
  Serial.print(host);
  Serial.print(':');
  Serial.println(port);
n=random(3000,4000);
  // Use WiFiClient class to create TCP connections


    
  // This will send a string to the server

      if(digitalRead(pin)==HIGH){
        Last_buttonState=1;
        s=1;}
      else{
       Last_buttonState=0;
        s=0;
        n=0;
      }
      if(cur-pre>1000*60*1 ||q==1)
      {q=0;
          WiFiClient client;
  if (!client.connect(host, port)) {
    Serial.println("connection failed");
    delay(5000);
    return;
  }
    if (client.connected()) {

        pre=millis();
//        n=random(3000,4000);
    Serial.println("Client Connected after one minute");
    client.print("{\"mId\": 1,\"t\":1351824120, \"watt\": "+(String)n+",\"voltage\":"+String(voltage)+",\"current\" :"+String(current)+", \"frequency\": "+(String)frequency+",\"kwh\":"+String(kwh)+",\"status\":"+String(s)+"}"); 
    delay(1000);
    client.stop();
    Serial.print("{\"mId\": 1,\"t\":1351824120, \"watt\": "+(String)n+",\"voltage\":"+String(voltage)+",\"current\" :"+String(current)+", \"frequency\": "+(String)frequency+",\"kwh\":"+String(kwh)+",\"status\":"+String(s)+"}"); 
      }}
    if (buttonState != Last_buttonState){
                WiFiClient client;
  if (!client.connect(host, port)) {
    Serial.println("connection failed");
    delay(5000);
    return;
  }

    
        if (client.connected()) {
Serial.println("button state change");

      client.print("{\"mId\": 1,\"t\":1351824120, \"watt\": "+(String)n+",\"voltage\":"+String(voltage)+",\"current\" :"+String(current)+", \"frequency\": "+(String)frequency+",\"kwh\":"+String(kwh)+",\"status\":"+String(s)+"}");
//      buttonState=1; 
buttonState=Last_buttonState; 
    }}
    else
    buttonState=Last_buttonState; 
    
      
//    unsigned long timeout = millis();

    
    /*client.print("{\"mId\": 1,\"t\":1351824120, \"watt\": "+(String)n+",\"voltage\":"+String(voltage)+",\"current\" :"+String(current)+", \"frequency\": "+(String)frequency+",\"kwh\":"+String(kwh)+",\"status\":"+String(s)+"}"); 
    Serial.print("{\"mId\": 1,\"t\":1351824120, \"watt\": "+(String)n+",\"voltage\":"+String(voltage)+",\"current\" :"+String(current)+", \"frequency\": "+(String)frequency+",\"kwh\":"+String(kwh)+",\"status\":"+String(s)+"}"); 
    while((millis()<<15*60*1000)&&s==1){
      Serial.println("WAITING S=1");}*/
    
      
//delay(5000);
//    delay(15*60*1000);



  // wait for data to be available
 // unsigned long timeout = millis();
 //// while (client.available() == 0) {
  //  if (millis() - timeout > 5000) {
   //   Serial.println(">>> Client Timeout !");
   //   client.stop();
    //  delay(60000);
    //  return;
   // }
 // }

  // Read all the lines of the reply from server and print them to Serial
  Serial.println("receiving from remote server");
  // not testing 'client.connected()' since we do not need to send data here
 // while (client.available()) {
 //   char ch = static_cast<char>(client.read());
  //  Serial.print(ch);
 // }

  // Close the connection
  Serial.println();
  Serial.println("closing connection");

  delay(3000); // execute once every 5 minutes, don't flood remote service
}
