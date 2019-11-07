int i;
long p;
long n=0;
void setup() {
  Serial.begin(9600);
  Serial.println("Enter any number to print");
  Serial.setTimeout(10);
}

void loop() {
  while(Serial.available()==0){}
  /*Serial.println("After parsed");
  p = Serial.parseInt();
  Serial.println(p);*/   //prints parsed, not seperately.
  
  i = Serial.read();
  Serial.println("In Decimal");
  Serial.println(i);  //prints decimal of inserted ASCII code.

  n = n*10+ (i-48);
  Serial.println("Input:\t");
  Serial.println(n);  //prints accurate number.
}
