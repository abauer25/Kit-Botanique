#include <string>
using namespace std;

const int moistureSensorNumber = 6;//pump number and moisture sensor number have to be equal and in the same order in the array
const int pumpNumber = 6;

// PIN configuration
int pumpPowerPin[] = {32,33,26,27,14,5}; //Pins of the pump from top to bottom: P32, P33, P26, P27, P14, P5
int moistureSensorPowerPin = 16; // moisture sensor power pin : P16
int moistureSensorSignalPin[] = {12,13,15,2,34,4}; //moisture sensor signal pin from top to bottom: P12, P13, P15, P2, P34, P4

// Thresholds for soil moisture (you'll need to adjust these based on your requirements)
int drySoilThreshold[moistureSensorNumber] = {600, 600, 600, 600, 600, 600}; // Example thresholds for dry soil
int wetSoilThreshold[moistureSensorNumber] = {400, 400, 400, 400, 400, 400}; // Example thresholds for wet soil (pump turns off)

void setup() {
  // put your setup code here, to run once:
   Serial.begin(115200);
  // initialisation des ports
  for (int i(0);i<pumpNumber;i++){
    pinMode(pumpPowerPin[i], OUTPUT);
    digitalWrite(pumpPowerPin[i], LOW);
  }
  for (int i(0);i<moistureSensorNumber;i++){
    pinMode(moistureSensorSignalPin[i], INPUT);
  }
  pinMode(moistureSensorPowerPin, OUTPUT);
  digitalWrite(moistureSensorPowerPin, LOW);
}

void loop() {
  digitalWrite(moistureSensorPowerPin, HIGH);
  for (int i = 0; i < moistureSensorNumber; i++) {
    int moistureLevel = analogRead(moistureSensorSignalPin[i]);
    Serial.print("Moisture Level at Sensor ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(moistureLevel);
    
    // Check if soil is too dry and needs watering
    if (moistureLevel > drySoilThreshold[i]) {
      // Soil is dry, turn the pump on
      digitalWrite(pumpPowerPin[i], HIGH);
      Serial.print("Activating Pump ");
      Serial.println(i);
    } else if (moistureLevel < wetSoilThreshold[i]) {
      // Soil is wet enough, turn the pump off
      digitalWrite(pumpPowerPin[i], LOW);
      Serial.print("Deactivating Pump ");
      Serial.println(i);
    }
  }
  Serial.print("-------------------------- \n");
  digitalWrite(moistureSensorPowerPin, LOW); // Optionally, turn off moisture sensor power to save energy
  delay(1000); // Adjust delay based on your watering and reading frequency needs
}
