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
    for(i=0;i<200;i++){
      
      current=analogRead(A8);
      sum=sum+current;
     }
     output=sum/200;
     sum=0;
     output = 0.0081*output - 0.0164;

      Serial.println(output);
  delay(1000);
}
