void forcamotor (int vel_E, int vel_D) {  // *Velocidades dos motores*
  if (vel_E >= 0) {
    motorE.run(FORWARD);
    motorE.setSpeed(vel_E);
  }
  else {
    motorE.run(BACKWARD);
    motorE.setSpeed(abs(vel_E));
  }

  if (vel_D >= 0) {
    motorD.run(FORWARD);
    motorD.setSpeed(vel_D);
  }
  else {
    motorD.run(BACKWARD);
    motorD.setSpeed(abs(vel_D));
  }
}

void paradaBrusca (bool p) {
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
    forcamotor (0, 0);
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
