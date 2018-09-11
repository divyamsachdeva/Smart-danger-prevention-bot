#define trigPin 10
#define echoPin 11
#define led 9

void setup()
{ Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{ long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  if (distance < 10)
  { digitalWrite(led, HIGH);
    digitalWrite(8, LOW);
  }
  else {
    digitalWrite(led, LOW);
    digitalWrite(8, HIGH);
  }
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
}
