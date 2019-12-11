double current;
//double amp;
void setup() {

  Serial.begin(9600);
  pinMode(current, INPUT);
  // put your setup code here, to run once:
  analogReference(INTERNAL1V1);
}

void loop() {

  //current=analogRead(A8);
  //amp=current*1000;
  Serial.print("CURRENT : ");
  //Serial.println(current);
  double long sum=0;
  int i;
  double output=0;
  for(i=0;i<200;i++){
    
    current=analogRead(A8);
    sum=sum+current;
    }
    output=sum/200;
    output = 0.053*output;
    output = output+ 0.271;
    Serial.println(output);
  delay(1000);
  
  // put your main code here, to run repeatedly:

}
