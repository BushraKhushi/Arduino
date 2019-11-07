String rx_byte="";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(10);
  Serial.println("Input Data");
}

void loop() {

   while (Serial.available()==0){}
   rx_byte=Serial.readString();
   Serial.println(rx_byte);
  // put your main code here, to run repeatedly:
}
