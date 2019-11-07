String rx_byte="";

void setup() {
  
  Serial.begin(9600);
  Serial.setTimeout(10);
  Serial.println("Input Data");
  
  while (Serial.available()==0){}
  rx_byte=Serial.readStringUntil('#');
  Serial.println(rx_byte);
}
void loop(){
  }
