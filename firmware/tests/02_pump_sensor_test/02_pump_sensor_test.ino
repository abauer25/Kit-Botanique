int sensors[] = {1, 2, 3, 4};      // moisture sensors
int pumps[]   = {17, 18, 21};      // pumps

int nbSensors = 4;
int nbPumps = 3;

void setup() {
  Serial.begin(115200);

  // Sensor setup (input)
  for (int i = 0; i < nbSensors; i++) {
    pinMode(sensors[i], INPUT);
  }

  // Pump setup (output)
  for (int i = 0; i < nbPumps; i++) {
    pinMode(pumps[i], OUTPUT);
    digitalWrite(pumps[i], LOW); // pumps off at startup
  }
}

void loop() {
  Serial.println("---- Reading sensors ----");

  // Read sensors
  for (int i = 0; i < nbSensors; i++) {
    int value = analogRead(sensors[i]); // analog reading
    Serial.print("Sensor ");
    Serial.print(i);
    Serial.print(" (GPIO ");
    Serial.print(sensors[i]);
    Serial.print(") = ");
    Serial.println(value);
  }

  Serial.println("Pumps ON");

  // Turn pumps on
  for (int i = 0; i < nbPumps; i++) {
    digitalWrite(pumps[i], HIGH);
  }

  delay(3000); // 3 seconds ON

  Serial.println("Pumps OFF");

  // Turn pumps off
  for (int i = 0; i < nbPumps; i++) {
    digitalWrite(pumps[i], LOW);
  }

  delay(3000); // 3 seconds OFF
}