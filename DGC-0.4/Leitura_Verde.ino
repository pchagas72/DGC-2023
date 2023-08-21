void leitura_verde () { //  *Sensor Hitechnic Esquerdo (verde1)*
  Hitechnic_1.beginTransmission(1);
  Hitechnic_1.write(66);
  Hitechnic_1.endTransmission();

  Hitechnic_1.requestFrom(1, 1);
  if (Hitechnic_1.available()) {
    cor1 = Hitechnic_1.read();
    //Serial.println("sensor 1 detectado");
  }
  else {
    //Serial.println ("Hitechnic 01 não conectado");
  }
}

void leitura_verde2 () {  // *Sensor Hitechnich Direito (verde2)*
  Hitechnic_2.beginTransmission(1);
  Hitechnic_2.write(66);
  Hitechnic_2.endTransmission();

  Hitechnic_2.requestFrom(1, 1);
  if (Hitechnic_2.available()) {
    cor2 = Hitechnic_2.read();
    //Serial.println("sensor 2 detectado");
  }
  else {
    //Serial.println("Hitechnic 02 não conectado");
  }
}
