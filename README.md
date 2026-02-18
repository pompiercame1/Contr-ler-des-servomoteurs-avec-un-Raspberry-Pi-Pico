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
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int servoPins[] = {2, 3, 4, 5};
Servo servos[4];

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    servos[i].attach(servoPins[i]);
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    Serial.print("Servo ");
    Serial.print(i + 1);
    Serial.println(" -> 0 à 180");

    for (int angle = 0; angle <= 180; angle += 5) {
      servos[i].write(angle);
      delay(20);
    }
    delay(500);

    Serial.print("Servo ");
    Serial.print(i + 1);
    Serial.println(" -> 180 à 0");

    for (int angle = 180; angle >= 0; angle -= 5) {
      servos[i].write(angle);
      delay(20);
    }
    delay(500);
  }
}


Explication rapide

Le code utilise la bibliothèque Servo.h pour générer le signal PWM.
Chaque servo est attaché à une broche différente du Pico (GPIO 2 à 5).
La boucle for fait passer le servo de 0 à 180°, puis de 180 à 0°, avec un petit délai à chaque pas pour un mouvement fluide.
Les messages envoyés sur le moniteur série permettent de suivre quel servo bouge.

Résultat attendu

Les quatre servos bougent à tour de rôle, chacun effectuant un aller-retour complet.
Quand le dernier a fini, le programme recommence depuis le début.

Si les servos tremblent, c’est souvent à cause d’une alimentation insuffisante.
Essaye avec une alimentation 5V plus stable ou plus puissante.

