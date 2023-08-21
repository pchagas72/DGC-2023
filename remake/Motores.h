#ifndef MOTORES_H
#define MOTORES_H
#include <Arduino.h>
#include <AFMotor.h>

void forcamotor (AF_DCMotor motorE, AF_DCMotor motorD, int velocidade_esquerda, int velocidade_direita);
void paradaBrusca (AF_DCMotor motorE, AF_DCMotor motorD, bool p);

#endif
