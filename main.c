#define Trig_pin A4
#define Echo_pin A5
#define buzzer 9


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Trig_pin,OUTPUT);
  pinMode(Echo_pin, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  long duration;
  int distance;


  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);


  duration=pulseIn(Echo_pin,HIGH);
  //Calculate the distance in cm (duration in microseconds, speed of sound is ~34300 cm/s)
  distance = duration * 0.034 / 2;

  if(distance<400){
    digitalWrite(buzzer, HIGH);
  }
  else{
    digitalWrite(buzzer, LOW);
  }
  delay(50);
  Serial.println(distance);

}
