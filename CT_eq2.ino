double current=0;
double sum=0;

void setup() {

  Serial.begin(9600);
  pinMode(A8, INPUT);
  analogReference(INTERNAL1V1);
}

void loop() {

  Serial.print("CURRENT : ");
  
    int i;
    double output=0;
    for(i=0;i<400;i++){
      
      current=analogRead(A8);
      sum=sum+current;
     }
     output=sum/400;
     sum=0;
     output = (output - 15.636)/95.126;

     Serial.println(output);
  delay(500);
}
