void gyroZ(int angulo) { //Leitura relativa do sensor de gyro
  mpu.update();
  float gyroTemp = mpu.getAngleZ(); 
  
  while (mpu.getAngleZ() < (gyroTemp + angulo)) {
    mpu.update();    
    //Serial.println("Angulo Z : " + String(mpu.getAngleZ() - gyroTemp));
  }  
  //Serial.println("Gyro de " + String(angulo) + "º concluído.");  
  //Serial.println("----------------------------------------------------");
}

void gyroZ_I(int angulo) { //Leitura relativa do sensor de gyro Giro Com Valor Negativo
  mpu.update();
  float gyroTemp = mpu.getAngleZ(); 
  
  while (mpu.getAngleZ() > (gyroTemp + angulo)) {
    mpu.update();    
    //Serial.println("Angulo Z : " + String(mpu.getAngleZ() - gyroTemp));
  }  
  //Serial.println("Gyro de " + String(angulo) + "º concluído.");  
  //Serial.println("----------------------------------------------------");
}
