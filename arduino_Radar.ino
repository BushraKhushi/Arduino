//Firebase
//WebServer
//Blynk
#include <Servo.h>

const int triger = 10;
const int echo = 11;
long distance;

Servo myServo;

void setup() {

  Serial.begin(9600);
  
  pinMode(OUTPUT,triger);
  pinMode(INPUT,echo);
  
  myServo.attach(12);

}

void loop() {

  for (int i =0;i<=359;i++){
    myServo.write(i);
    delay(30);
    distance = c_distance();
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" At Degree ");
    Serial.println(i);
    }

  for (int i = 359;i<=0;i--){
    myServo.write(i);
    delay(30);
    distance = c_distance();
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" At Degree ");
    Serial.println(i);
    }
}

  int c_distance (){
  digitalWrite(triger,LOW);
  delayMicroseconds(10);
  digitalWrite(triger,HIGH);
  delayMicroseconds(10);
  digitalWrite(triger,LOW);

  long duration=pulseIn(echo,HIGH);

  distance = ((duration*0.0342)/2);
  return distance;
  }
