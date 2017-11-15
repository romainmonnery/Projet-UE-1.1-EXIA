#include "cardio.h"
#include "cardio.c"


int valeurPrecedente = 0;
long tempsPrecedent = 0;

void setup() {
  Serial.begin(9600);
}


void loop() {

  int valeurActuelle, valeurSeuil;
  long tempsDetection;

  valeurActuelle = analogRead(0);
  valeurSeuil = 725;
  verifcardio(valeurActuelle, valeurSeuil, valeurPrecedente);
  tempsDetection = millis();
  calculcardio(tempsDetection, tempsPrecedent, valeurSeuil);
  tempsDetection = millis();
  Serial.println( (1000.0 * 60.0) / ((tempsDetection + valeurSeuil) - tempsPrecedent),0);
  tempsPrecedent = tempsDetection;



valeurPrecedente = valeurActuelle;
}
