Arduino Embedded C/C++ Program:
const int trigPin = 5;
const int echoPin = 18;

const int buzzerPin = 25;
const int greenLED = 26;
const int redLED = 27;

void setup() {
  Serial.begin(115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzerPin, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  digitalWrite(trigPin, LOW);

  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);
  digitalWrite(buzzerPin, LOW);
}

float getDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0)
    return 400;

  return duration * 0.0343 / 2.0;
}

void loop() {

  float distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 20.0) {

    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);

    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(100);

    Serial.println("Obstacle Detected!");

  } else {

    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);

    digitalWrite(buzzerPin, LOW);
  }

  delay(100);

}
