# Contr-ler-des-servomoteurs-avec-un-Raspberry-Pi-Pico
Tutoriel pour contrôler des servomoteurs avec un Raspberry Pi Pico
L’idée est de faire bouger quatre servomoteurs à la suite, chacun passant de 0 degré à 180 degrés puis revenant à 0.
Le tout sera contrôlé par un Raspberry Pi Pico programmé via l’Arduino IDE.
Ce genre de montage est parfait pour apprendre à contrôler plusieurs moteurs en même temps, et comprendre comment fonctionne le signal PWM (Pulse Width Modulation) utilisé pour piloter des servos.


Composants et Cablage
Tu auras besoin d’un Raspberry Pi Pico, bien sûr, c’est le cerveau du montage.
Ensuite, il te faut quatre servomoteurs (les modèles SG90 ou MG90S conviennent très bien).
Ces petits moteurs fonctionnent en 5 volts et se commandent facilement.

Pour l’alimentation, il est fortement conseillé d’utiliser une source de 5 volts externe, comme un petit bloc d’alimentation, un pack de piles ou un chargeur USB coupé.
Le Raspberry Pi Pico ne peut pas fournir assez de courant pour quatre servos : sinon, la carte risque de redémarrer ou les servos de trembler.

Prends aussi quelques fils Dupont (mâle-femelle) pour les connexions, et éventuellement une breadboard pour organiser ton montage proprement.
