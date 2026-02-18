#include <Servo.h> // On importe la bibliothèque Servo pour contrôler les servomoteurs

// Création des objets Servo pour chacun des 4 servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// Tableau des broches GPIO sur lesquelles les servos sont connectés
int servoPins[] = {2, 3, 4, 5};

// Tableau d'objets Servo pour pouvoir boucler facilement
Servo servos[4];

void setup() {
  Serial.begin(9600); // On initialise la communication série pour afficher des messages

  // On relie chaque objet Servo à la broche correspondante
  for (int i = 0; i < 4; i++) {
    servos[i].attach(servoPins[i]); // attach() configure la broche pour générer le PWM
  }
}

void loop() {
  // On parcourt les 4 servos un par un
  for (int i = 0; i < 4; i++) {
    Serial.print("Servo ");       // Affiche "Servo "
    Serial.print(i + 1);          // Affiche le numéro du servo (1 à 4)
    Serial.println(" -> 0 à 180"); // Affiche l'action en cours

    // Mouvement progressif du servo de 0° à 180°
    for (int angle = 0; angle <= 180; angle += 5) { 
      servos[i].write(angle); // Envoie la position au servo
      delay(20);              // Pause pour que le servo ait le temps de bouger
    }
    delay(500); // Pause d'une demi-seconde à 180° pour stabiliser le servo

    Serial.print("Servo ");       
    Serial.print(i + 1);          
    Serial.println(" -> 180 à 0"); // Affiche l'action en cours

    // Mouvement progressif du servo de 180° à 0°
    for (int angle = 180; angle >= 0; angle -= 5) {
      servos[i].write(angle); // Envoie la position au servo
      delay(20);              // Pause pour un mouvement fluide
    }
    delay(500); // Pause d'une demi-seconde à 0° avant de passer au servo suivant
  }

  // Quand le dernier servo a fini, la boucle recommence automatiquement
}
