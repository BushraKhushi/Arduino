int pre=0;
int cur =0;
int button = 16;
int count =0;
int current_state=0;
int last_state=0;

void setup() {
  Serial.begin(9600);
  pre = millis();
  pinMode(button,INPUT);
}

void loop() {
  cur =millis();
  
  if(digitalRead(button)==HIGH){
    current_state=1;}
  else
    current_state=0;
    
  if(cur-pre>10*1000||!(current_state=last_state)){
  
  Serial.println("In Loop");
  pre = millis();
  current_state=last_state;
  }
  
  Serial.println("Out of Loop");
  delay(1000);
  Serial.println(count++);
}
