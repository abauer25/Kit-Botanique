int led_pin = 17;

void setup() {
  pinMode(led_pin, OUTPUT); // configure le pin comme sortie
}

void loop() {
  digitalWrite(led_pin, HIGH); // allume la LED
  delay(1000);                 // attend 1 seconde
  digitalWrite(led_pin, LOW);  // éteint la LED
  delay(1000);                 // attend 1 seconde
}