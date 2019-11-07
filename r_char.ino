char rx_byte;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(10);
  Serial.println("Input Data");
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()==0){}

  rx_byte=Serial.read();
  Serial.println(rx_byte);
}
