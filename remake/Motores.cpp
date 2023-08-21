#include "Motores.h"

void forcamotor (AF_DCMotor motorE, AF_DCMotor motorD, int velocidade_esquerda, int velocidade_direita){
  
  if (velocidade_esquerda >= 0) {
    motorE.run(FORWARD);
    motorE.setSpeed(velocidade_esquerda);
  }
  else {
    motorE.run(BACKWARD);
    motorE.setSpeed(abs(velocidade_esquerda));
  }

  if (velocidade_direita >= 0) {
    motorD.run(FORWARD);
    motorD.setSpeed(velocidade_direita);
  }
  else {
    motorD.run(BACKWARD);
    motorD.setSpeed(abs(velocidade_direita));
  }
}

void paradaBrusca (AF_DCMotor motorE, AF_DCMotor motorD, bool p) {
  if (p == 1) { //Modo 1
    motorE.setSpeed (110);
    motorD.setSpeed (110);
    for (int i = 0; i < 50; i++) {
      motorE.run (BACKWARD);
      motorD.run (BACKWARD);
      delay(2);
      motorE.run(FORWARD);
      motorD.run(FORWARD);
      delay(1);
    }
    forcamotor (motorE, motorD, 0, 0);
  }
  else { //Modo 2
    motorE.run (BACKWARD);
    motorD.run (BACKWARD);
    for (int i = 110; i > 0; i--) {
      motorE.setSpeed(i);
      motorD.setSpeed(i);
      delay(2);
    }
  }
}
