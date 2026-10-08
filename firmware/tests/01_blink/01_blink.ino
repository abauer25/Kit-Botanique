int led_pin = 17;

void setup() {
  pinMode(led_pin, OUTPUT); // set the pin as an output
}

void loop() {
  digitalWrite(led_pin, HIGH); // turn the LED on
  delay(1000);                 // wait 1 second
  digitalWrite(led_pin, LOW);  // turn the LED off
  delay(1000);                 // wait 1 second
}