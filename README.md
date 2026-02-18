# Contrôle de 4 servomoteurs avec un Raspberry Pi Pico

Ce projet montre comment contrôler quatre servomoteurs à l’aide d’un **Raspberry Pi Pico** programmé dans l’**Arduino IDE**.  
Chaque servo va tourner de 0 à 180 degrés, puis revenir à 0, les uns après les autres.  
C’est un bon exercice pour comprendre comment fonctionne le signal PWM et comment piloter plusieurs moteurs.

---

## Matériel utilisé

- Raspberry Pi Pico  
- 4 servomoteurs  
- Alimentation 5V externe (pour ne pas surcharger la carte)  
- Fils Dupont  
- Breadboard (facultative)

Les servos doivent être alimentés par une source 5V séparée.  

---

## Branchement

Chaque servo a trois fils :  
- rouge → 5V (alimentation externe)  
- marron/noir → GND  
- orange/jaune → signal

Les signaux sont connectés aux broches GPIO suivantes du Pico :  
- Servo 1 → GP2  
- Servo 2 → GP3  
- Servo 3 → GP4  
- Servo 4 → GP5
  
  <img width="1025" height="1151" alt="Capture d&#39;écran 2026-02-18 210742" src="https://github.com/user-attachments/assets/9688203e-39bd-4d40-9ea1-607653298b90" />

---

## Préparation de l’environnement

1. Installe le support **Raspberry Pi RP2040** dans l’Arduino IDE (si non installé, voir https://github.com/earlephilhower/arduino-pico) :  
   - Menu *Outils → Type de carte → Gérer les cartes*  
   - Recherche “Raspberry Pi RP2040 by Earle Philhower” et installe-le  
2. Sélectionne **Raspberry Pi Pico** comme carte  
3. Branche le Pico et choisis le bon port dans *Outils → Port*

---

## Code Arduino

```cpp
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

```
---
## Explication rapide

Le code utilise la bibliothèque Servo.h pour générer le signal PWM.
Chaque servo est attaché à une broche différente du Pico (GPIO 2 à 5).
La boucle for fait passer le servo de 0 à 180°, puis de 180 à 0°, avec un petit délai à chaque pas pour un mouvement fluide.
Les messages envoyés sur le moniteur série permettent de suivre quel servo bouge.

## Résultat 

Les quatre servos bougent à tour de rôle, chacun effectuant un aller-retour complet.
Quand le dernier a fini, le programme recommence depuis le début.

## Problèmes fréquents

Si les servos tremblent, c’est souvent à cause d’une alimentation insuffisante.
Essaye avec une alimentation 5V plus stable ou plus puissante.

