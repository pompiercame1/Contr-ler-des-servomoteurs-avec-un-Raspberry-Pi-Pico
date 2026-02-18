# Contrôler 4 servomoteurs avec un Raspberry Pi Pico

## 🎯 Objectif

Faire bouger **quatre servomoteurs** à la suite (de 0° à 180°, puis retour à 0°), à l’aide d’un **:contentReference[oaicite:1]{index=1}** programmé dans l’**:contentReference[oaicite:2]{index=2}**.  
Ce projet est idéal pour apprendre à manipuler le signal PWM et contrôler plusieurs moteurs.

---

## 🧰 Matériel nécessaire

- Un **Raspberry Pi Pico**
- Quatre **servomoteurs** (SG90 ou MG90S)
- Une **alimentation externe 5V** (piles, adaptateur, powerbank…)
- Des **fils Dupont** (mâle-femelle)
- Une **breadboard** (optionnelle, pour organiser les connexions)

💡 **Important :** Les servos doivent être alimentés par une source **5V externe**.  
Le Pico ne peut pas fournir assez de courant pour 4 moteurs.

---

## ⚙️ Branchement des servos

Chaque servo possède **3 fils** :
- **Rouge** → 5V (alimentation)
- **Marron ou noir** → GND (masse)
- **Orange ou jaune** → signal de commande

Branche les signaux sur les broches **GP2, GP3, GP4 et GP5** du Pico.  
Assure-toi que **toutes les masses (GND)** soient reliées entre elles :  
celle du Pico, celle de ton alimentation externe et celles des servos.

---

## 💻 Configuration de l’Arduino IDE

1. Ouvre l’**Arduino IDE**.  
2. Va dans **Outils → Type de carte → Gérer les cartes**.  
3. Recherche : `Raspberry Pi RP2040 by Earle Philhower` et installe-le.  
4. Sélectionne la carte **Raspberry Pi Pico**.  
5. Branche le Pico en USB et sélectionne le bon **Port** dans le menu Outils.

---

## 🧩 Le code complet

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
    Serial.println(" → de 0° à 180°");

    for (int angle = 0; angle <= 180; angle += 5) {
      servos[i].write(angle);
      delay(20);
    }
    delay(500);

    Serial.print("Servo ");
    Serial.print(i + 1);
    Serial.println(" → de 180° à 0°");

    for (int angle = 180; angle >= 0; angle -= 5) {
      servos[i].write(angle);
      delay(20);
    }
    delay(500);
  }
}
```

---

## 🧠 Explication du code

- `#include <Servo.h>` : charge la bibliothèque qui simplifie le contrôle des servos.  
- `servo.attach(pin)` : lie chaque servo à une broche GPIO.  
- `servo.write(angle)` : envoie un angle entre 0° et 180°.  
- Les boucles `for` font bouger chaque servo progressivement.  
- Les `delay()` ajoutent de petites pauses pour rendre le mouvement fluide.  
- `Serial.print()` affiche les étapes dans le moniteur série.

---

## 🚀 Résultat

Chaque servo bouge à son tour de 0° à 180° puis revient à 0°.  
Quand les quatre servos ont terminé, le programme recommence indéfiniment.

💡 Si tes servos tremblent ou ne bougent pas bien, vérifie ton alimentation 5V et les masses communes.

---

## 🧩 Aller plus loin

Tu peux modifier ce code pour :
- faire bouger **les 4 servos en même temps**,  
- changer la vitesse (en réduisant `delay(20)`),  
- ou inverser le sens de rotation d’un servo.

---
✨ Auteur : *TonNom*  
📅 Date : *février 2026*
