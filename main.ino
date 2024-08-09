#include <Arduino.h>

const int triggerPin = 4; // GPIO4 (D4)
const int echoPin = 2;    // GPIO2 (D2)

const int maxDistance = 450; // Max distance for the sensor
const int minDistance = 20;  // Min distance for the sensor

const unsigned long timeout = 13200; // Timeout for pulseIn

const int fullDistance = 45;  
const int emptyDistance = 115; 

String tankStatus = "Unknown"; // Variable to store the tank status

void setup() {
  Serial.begin(115200); 
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT); 
}

void loop() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  long duration = pulseIn(echoPin, HIGH, timeout);

  int distance = 0;
  if (duration > 0) {
    distance = duration / 58.0; 
  }

  if (distance >= minDistance && distance <= maxDistance) {
    int waterLevelPercentage = 0;
    if (distance <= fullDistance) {
      waterLevelPercentage = 100;
    } else if (distance >= emptyDistance) {
      waterLevelPercentage = 0;
    } else {
      waterLevelPercentage = map(distance, fullDistance, emptyDistance, 100, 0);
    }

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm, Water Level: ");
    Serial.print(waterLevelPercentage);
    Serial.println("%");

    if (waterLevelPercentage == 100) {
      tankStatus = "Tanker Full";
    } else if (waterLevelPercentage == 0) {
      tankStatus = "Tanker Empty";
    } else {
      tankStatus = "In Between";
    }

    Serial.println(tankStatus);
  }

  delay(100); 
}
