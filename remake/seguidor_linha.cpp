#include "seguidor_linha.h"
#include "Motores.h"

void seguidor_de_linha(AF_DCMotor motorD,
		       AF_DCMotor motorE,
		       bool sensor1,
		       bool sensor2,
		       bool sensor3,
		       bool sensor4){

  if (sensor2 == HIGH && sensor3 == HIGH) {     // Sensores do meio no preto, SIGA
    forcamotor(motorD, motorE, VEL_FRENTE, VEL_FRENTE);
  }

  else if (sensor2 == LOW && sensor3 == LOW) {  // Sensores do meio no branco SIGA
    forcamotor(motorD, motorE, 140, 140);
  }

  else if (sensor2 == LOW && sensor3 == HIGH) {  // Sensores do meio diferentes, curva para esquerda.
    forcamotor(motorD, motorE, -140, 180);
  }

  else if (sensor2 == HIGH && sensor3 == LOW) {  // Sensores do meio diferentes, curva para direita.
    forcamotor(motorD, motorE, 180, -140);
  }

  if (sensor1 == LOW && sensor4 == HIGH) {  // Curva de 90° à esquerda com o 4 no preto
    forcamotor(motorD, motorE, 140, 140);
    delay (260);
    forcamotor(motorD, motorE, 180, -160);
    delay (290);
    paradaBrusca(motorE, motorD, 2);
    forcamotor(motorD, motorE, 140, 140);
    delay (190);

    sensor2 = 0;        // Zera valor no sensor 2 (meio direita)

    while (sensor2 == 0) { //Girar ilimitado até o sensor2 ver preto
      forcamotor(motorD, motorE, -200, 200);
      sensor2 = digitalRead(24); //Leia
    }
    paradaBrusca(motorE, motorD, 2);
    forcamotor(motorD, motorE, 160, -130);
    delay (160);
    forcamotor(motorD, motorE, -140, -140);
    delay (120);
  }

  if (sensor4 == LOW && sensor1 == HIGH) {  // Curva de 90° à direita com o 1 no preto
    forcamotor(motorD, motorE, 140, 140);
    delay (260);
    forcamotor(motorD, motorE, -190, 190);
    delay (370);
    paradaBrusca(motorE, motorD, 2);
    forcamotor(motorD, motorE, 140, 140);
    delay (190);

    sensor3 = 0;        // Zerar Leitura do Sensor 3 (meio esquerda)

    while (sensor3 == 0) { // Girar ilimitado até o sensor2 ver preto
      forcamotor(motorD, motorE, 200, -200);    
      sensor3 = digitalRead(26); // Leia
    }
    paradaBrusca(motorE, motorD, 2);
    forcamotor(motorD, motorE, -130, 160);
    delay (200);
    forcamotor(motorD, motorE, -140, -140);
    delay (120);
  }

  else if (sensor1 == LOW && sensor2 == LOW && sensor3 == LOW && sensor4 == LOW) {  // Todos os sensores no branco SIGA
    forcamotor(motorD, motorE, 140, 140);
  }
  else if (sensor1 == HIGH && sensor2 == HIGH && sensor3 == HIGH && sensor4 == HIGH) {  // Todos os sensores no preto SIGA
    forcamotor(motorD, motorE, 140, 140);
  }

}
