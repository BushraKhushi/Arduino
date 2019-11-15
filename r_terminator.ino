String rx_byte="";

void setup() {
  
  Serial.begin(9600);
  Serial.setTimeout(10);
  Serial.println("Input Data");
}
void loop(){
  
  if (Serial.available()>0){ 
  rx_byte=Serial.readStringUntil('#');
  Serial.println();
  Serial.println(rx_byte);
  Serial.print("Input Data");
  rx_byte = "";
  Serial.end();
  }
  Serial.begin(9600);
  Serial.print(".");
  delay(1000);
}
  
