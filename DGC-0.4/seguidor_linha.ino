void seguidorlinha () { //  *Condicional do seguidor de linha*

  if (sensor2 == HIGH && sensor3 == HIGH) {     // sensor 3 e sensor 2 no preto SIGA
    forcamotor(140, 140);
  }

  else if (sensor2 == LOW && sensor3 == LOW) {  // sensor 3 e sensor 2 no branco SIGA
    forcamotor(140, 140);
  }

  else if (sensor2 == LOW && sensor3 == HIGH) {  // Virar para a esquerda
    forcamotor (-140, 180);
  }

  else if (sensor2 == HIGH && sensor3 == LOW) {  //Virar para a direita
    forcamotor (180, -140);
  }

  if (sensor1 == LOW && sensor4 == HIGH) {  //90° à esqurda com o 4 no preto
    forcamotor (140, 140);
    delay (260);
    forcamotor (180, -160);
    delay (290);
    paradaBrusca(2);
    forcamotor (140, 140);
    delay (190);

    //paradaBrusca(2);
    //forcamotor (-200, 200);
    //delay(100);

    sensor2 = 0;        //Zerar Leitura do Sensor 2

    while (sensor2 == 0) { //Girar ilimitado até o sensor2 ver preto
      forcamotor (-200, 200);
      sensor2 = digitalRead(24); //Leia
    }
    paradaBrusca(2);
    forcamotor (160, -130);
    delay (160);
    forcamotor (-140, -140);
    delay (120);
  }

  if (sensor4 == LOW && sensor1 == HIGH) {  //90° à direita com o 1 no preto
    forcamotor (140, 140);
    delay (260);
    forcamotor (-190, 190);
    delay (370);
    paradaBrusca(2);
    forcamotor (140, 140);
    delay (190);

    //paradaBrusca(2);
    //forcamotor (200, -200);
    //delay(60);

    sensor3 = 0;        //Zerar Leitura do Sensor 3

    while (sensor3 == 0) { //Girar ilimitado até o sensor2 ver preto
      forcamotor (200, -200);    
      sensor3 = digitalRead(26); //Leia
    }
    paradaBrusca(2);
    forcamotor (-130, 160);
    delay (200);
    forcamotor (-140, -140);
    delay (120);
  }

  else if (sensor1 == LOW && sensor2 == LOW && sensor3 == LOW && sensor4 == LOW) {  // todos os sensores no branco SIGA
    forcamotor(140, 140);
  }
  else if (sensor1 == HIGH && sensor2 == HIGH && sensor3 == HIGH && sensor4 == HIGH) {  // todos os sensores no preto SIGA
    forcamotor(140, 140);
  }
}
