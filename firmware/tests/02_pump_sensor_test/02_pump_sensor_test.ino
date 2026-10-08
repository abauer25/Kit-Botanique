int capteurs[] = {1, 2, 3, 4};      // capteurs humidité
int pompes[]   = {17, 18, 21};      // pompes

int nbCapteurs = 4;
int nbPompes = 3;

void setup() {
  Serial.begin(115200);

  // Config capteurs (entrée)
  for (int i = 0; i < nbCapteurs; i++) {
    pinMode(capteurs[i], INPUT);
  }

  // Config pompes (sortie)
  for (int i = 0; i < nbPompes; i++) {
    pinMode(pompes[i], OUTPUT);
    digitalWrite(pompes[i], LOW); // pompes éteintes au début
  }
}

void loop() {
  Serial.println("---- Lecture capteurs ----");

  // Lire capteurs
  for (int i = 0; i < nbCapteurs; i++) {
    int valeur = analogRead(capteurs[i]); // lecture analogique
    Serial.print("Capteur ");
    Serial.print(i);
    Serial.print(" (GPIO ");
    Serial.print(capteurs[i]);
    Serial.print(") = ");
    Serial.println(valeur);
  }

  Serial.println("Pompes ON");
  
  // Allumer pompes
  for (int i = 0; i < nbPompes; i++) {
    digitalWrite(pompes[i], HIGH);
  }

  delay(3000); // 3 secondes ON

  Serial.println("Pompes OFF");

  // Éteindre pompes
  for (int i = 0; i < nbPompes; i++) {
    digitalWrite(pompes[i], LOW);
  }

  delay(3000); // 3 secondes OFF
}