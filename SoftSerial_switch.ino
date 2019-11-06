char rx_byte;

void setup() {
  Serial.begin(9600);
  Serial.println("Enter any number between 1,2,3");
  mySerial.begin(4800);
}

void loop() {
  
 if (mySerial.available()>0){
  
  rx_byte=mySerial.read();
  
  switch (rx_byte){
    case '1':{
    Serial.println("One");
    break;}
    
    case '2':
    Serial.println("Two");
    break;
    
    case '3':
    Serial.println("Three");
    break;
    
    default:
    Serial.println("Invalid");
    break;
    }
  }
}
