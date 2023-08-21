void verde_direito () { //  *Desvio verde direito*
  forcamotor (180, 180); // Toque para a frente
  delay(250);
  paradaBrusca(2);
  forcamotor(190, -190); //Giro Direita
  delay(180);
  paradaBrusca(2);
  forcamotor (180, 180); // Toque para a frente
  delay(300);

  forcamotor(190, -190); //Giro Direita
  delay(1000);
  paradaBrusca(2);

  forcamotor (-170, 170); //Toque Esquerda
  delay (150);
  paradaBrusca(2);
  forcamotor (-120, -120); //Ré
  delay (210);
  paradaBrusca(2);
}

void verde_direito_falso () {  //  *Verde falso direito*
  forcamotor (160, 140);
  delay(250);
  paradaBrusca(2);
  delay (100);
  digitalWrite (52, LOW);
}

void verde_esquerdo () {  //  Desvio verde esquerdo

  forcamotor (190, 180); // Toque para a frente
  delay(210);
  paradaBrusca(2);
  forcamotor(-170, 170); //Giro Esquerda

  paradaBrusca(2);

  forcamotor (190, 180); // Toque para a frente
  delay(160);

  forcamotor(-170, 170); //Giro Esquerda

  paradaBrusca(2);
  forcamotor (170, -170);
  delay (220);
  paradaBrusca(2);
  forcamotor (-120, -120);
  delay (210);
  paradaBrusca(2);
}

void verde_esquerdo_falso () {  //  *Verde falso esquerdo*
  forcamotor (160, 140);
  delay(250);
  paradaBrusca(2);
  delay (100);
}

void verde_duplo () { //Desvio verde duplo
  digitalWrite (52, HIGH);
  digitalWrite (53, HIGH);
  paradaBrusca(2);
  //delay(150);

  while (cor2 == 4) { //  Andar ilimitado até ver diferente de verde
    leitura_verde2();
    forcamotor (150, 130);
  }

  forcamotor (170, 160);
  delay (120);
  forcamotor (200, -200);
  delay (660);
  paradaBrusca(2);
  forcamotor (120, 110);
  delay(215);
  paradaBrusca(2);
  forcamotor (200, -200);
  delay (100);

  sensor2 = 0;
  while (sensor2 == 0)  { //  Girar ilimitado  até o sensor3 ler preto
    forcamotor (170, -170);
    sensor2 = digitalRead(24); //Leia
  }
  paradaBrusca(2);
  delay(200);
  forcamotor (170, -170);
  delay(220);
  paradaBrusca(2);
  forcamotor (-120, -120);
  delay (165);
  digitalWrite(52, LOW);
  digitalWrite(53, LOW);
  cor1 = false;
  cor2 = false;
  paradaBrusca(2);
}
