#ifndef SEGUIDOR_LINHA_H
#define SEGUIDOR_LINHA_H
#include <Arduino.h>
#include "Motores.h"
#include "ValoresMotor.h"

void seguidor_de_linha(AF_DCMotor motorE,
		       AF_DCMotor motorD,
		       bool sensor1,
		       bool sensor2,
		       bool sensor3,
		       bool sensor4);

#endif
