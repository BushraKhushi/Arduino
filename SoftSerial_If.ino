char rx_byte;

void setup() {
  
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()>0){
    
    rx_byte=Serial.read();
    
    if(rx_byte=='1')
    Serial.println("One");
    
    else if (rx_byte=='2')
    Serial.println("Two");
    
    else if (rx_byte=='3')
    Serial.println("Three");
    
    else
    Serial.println("Greater than 1, 2, 3");
    }
}
