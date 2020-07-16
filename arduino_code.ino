
// defining the variables

const int trigPin = 7;
const int echoPin = 8;

long int duration;
long int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

  // Setting up connection with Serial Monitor
  Serial.begin(9600);

  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // To ensure that trigPin is at LOW
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  
  // Calculating duration and distance
  duration = pulseIn(echoPin,HIGH);
  distance = (duration*0.034)/2;

  // Writing on the Serial 'Play/Pause' on the basis of distance
  if(distance<26 && distance>0){
    Serial.println("Play/Pause\n");
    delay(500);
  }
  delay(500);
  distance=-1;
}
