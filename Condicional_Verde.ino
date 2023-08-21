void condicional_verde2 () {  //  *Identificação Verde2 Direito*
  if (cor2 == 4) {
    paradaBrusca(2);
    delay (50);
    forcamotor (-120, -120);
    delay(30);
    paradaBrusca(2);

    leitura_verde (); //Verificar se o sensor1 está no verde
    if (cor1 == 4) {  //Verde duplo confirmado
      verde_duplo();
      cor1 = false;
      cor2 = false;
    }

    else {  //  Verde direito confirmado
      paradaBrusca(2);
      leitura_verde (); //Verificar se o sensor1 está no verde
      if (cor1 == 4) {  //Verde duplo confirmado
        verde_duplo();
        cor1 = false;
        cor2 = false;
      }

      while (cor2 == 4) { //  Andar ilimitado até ver uma cor ≠ de verde
        leitura_verde2();
        forcamotor (120, 120);
      }
      paradaBrusca(2);
      delay (150);

      leitura_verde2(); //  Verificacao verde verdadeiro ou falso
      if (cor2 != 14) { //  Verde Verdadeiro Direito/
        verde_direito ();
      }
      else if (cor2 == 14) { //Verde Falso Direito
        verde_direito_falso ();
      }
    }
  }
}

void condicional_verde1 () {  //  *Identificação Verde1 Esquerdo*
  if (cor1 == 4) {
    paradaBrusca(2);
    delay (2000);
    forcamotor (-120, -120);
    delay(30);
    paradaBrusca(2);
    delay(200);

    leitura_verde2 ();  //Verificar se o sensor2 está no verde
    if (cor2 == 4) {    //Verde duplo confirmado
      verde_duplo ();
      cor1 = false;
      cor2 = false;
    }

    else { //Verde esquerdo confirmado
      paradaBrusca(2);
      delay (100);
      leitura_verde2 ();  //Verificar se o sensor2 está no verde
      if (cor2 == 4) {    //Verde duplo confirmado
        verde_duplo ();
        cor1 = false;
        cor2 = false;
      }

      while (cor1 == 4) { //Andar ilimitado até ver uma cor diferente de verde
        leitura_verde();
        forcamotor (120, 110);
      }
      forcamotor (120, 110);
      delay(20);
      paradaBrusca(2);
      delay (200);

      leitura_verde();  //Verificacao verde verdadeiro ou falso
      if (cor1 != 14) { //Verde Verdadeiro Esquerdo
        verde_esquerdo ();
      }
      else if (cor1 == 14) { //Verde Falso Esquerdo
        verde_esquerdo_falso ();
      }
    }
  }
}
