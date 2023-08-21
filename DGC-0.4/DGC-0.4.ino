#include <AFMotor.h>
#include <MPU6050_light.h>
//#include <Wire.h>
#include <SoftwareWire.h>

MPU6050 mpu(Wire); //Inicialização do MPU6050

//                       (SDA,SCL)
SoftwareWire Hitechnic_1 (A8, A9); //Sensor Hitech Esquerdo
SoftwareWire Hitechnic_2 (A10, A11); //Sensor Hitech Direito

//  Declaração dos motores
AF_DCMotor motorD(2); //Motor Direito
AF_DCMotor motorE(3); //Motor Esquerdo

//  Pinos do seguidor de linha
#define pin_sensor1 22 //Ponta Direita
#define pin_sensor2 24 //Meio Direita
#define pin_sensor3 26 //Meio Esquerda
#define pin_sensor4 28 //Ponta Esquerda 

//  Definir Todos os sensores IR como 0
bool sensor1, sensor2, sensor3, sensor4 = 0;

//  Zerar a leitura dos HitechNic
byte cor1 = 0;
byte cor2 = 0;

void setup() {
  
  /*Wire.begin(); //Verificação ON/OFF do MPU6050 
  if (mpu.begin() != 0) {
    Serial.println("Sensor MPU6050 desconectado!");
  }
  else {
    Serial.println("Calculando offsets, não mova o MPU6050.");
    mpu.calcOffsets(); // Calibra o sensor MPU6050
    Serial.println("Calibração finalizada em: " + String(millis()) + "ms");
  }*/
  Hitechnic_1.begin();
  Hitechnic_2.begin();
  Serial.begin(9600);
  
  //  *Sensor seguidor de linha*
  pinMode(pin_sensor1, INPUT); // Branco = LOW; PRETO = HIGH
  pinMode(pin_sensor2, INPUT);
  pinMode(pin_sensor3, INPUT);
  pinMode(pin_sensor4, INPUT);
}

void loop() {

  //  *Leitura do verde*
  //  *Leitura HitechNic*
  leitura_verde();
  leitura_verde2();

  //  *Condicional Verde*
  condicional_verde2 ();      //Verde direito
  condicional_verde1 ();      //Verde esquerdo
  
  //  *Seguidor De Linha*
  //  *Leitura dos Sensores*
  sensor1 = digitalRead(pin_sensor1); //Ponta direita
  sensor2 = digitalRead(pin_sensor2); //Meio direita
  sensor3 = digitalRead(pin_sensor3); //Meio esquerda
  sensor4 = digitalRead(pin_sensor4); //Ponta esquerda

  //  *Condicional Seguidor De Linha*
  seguidorlinha ();
}
