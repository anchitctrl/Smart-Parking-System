#define trigPin1 9
#define echoPin1 10
#define trigPin2 6
#define echoPin2 7
#define ledRed 4
#define ledGreen 3
long duration, distance, TopSensor,FrontSensor;
void setup()
{
Serial.begin (9600);
 pinMode(trigPin1, OUTPUT);
 pinMode(echoPin1, INPUT);
 pinMode(trigPin2, OUTPUT);
 pinMode(echoPin2, INPUT);
}
void loop() {
 SonarSensor(trigPin1, echoPin1);
 TopSensor = distance;
 SonarSensor(trigPin2, echoPin2);
 FrontSensor = distance;12
 delay(1000);
 if(TopSensor < 100 && FrontSensor < 50) {
 digitalWrite(ledGreen, LOW);
 digitalWrite(ledRed, HIGH);
 delay(2000);
 } else {
 digitalWrite(ledGreen, HIGH);
 digitalWrite(ledRed, LOW);
 delay(2000);
 }
 Serial.print("Top: ");
 Serial.println(TopSensor);
 Serial.print("Front: ");
 Serial.println(FrontSensor);
 delay(1000);
}
void SonarSensor(int trigPin,int echoPin)
{
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 //distance = (duration/2) / 29.1;
 distance= duration*0.034/2;
}
