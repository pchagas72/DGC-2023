#include <SoftwareWire.h>
#include <Wire.h>
#include <MPU6050.h>
#include "Motores.h"
#include "seguidor_linha.h"

// Conexão giroscópio
MPU6050 mpu(Wire); // Inicialização do MPU6050 (giroscópio)

// Conexão Hitechnic (sensor de cores)
//                       (SDA,SLC) -> Data, Clock
SoftwareWire Hitechnic_1 (A8, A9); // Hitechnic Esquerdo
SoftwareWire Hitechnic_2 (A10,A11); // Hitechnic Esquerdo

// Define a leitura inicial das cores do Hitechnic como 0.
byte cor_esquerda, cor_direita = 0;

// Conexão dos motores
AF_DCMotor motorD(2); // Motor Direito
AF_DCMotor motorE(3); // Motor Esquerdo

// Conexão Seguidor de Linha (infravermelhos, IR)
#define pin_sensor1 22 // Ponta Direita
#define pin_sensor2 24 // Meio Direita
#define pin_sensor3 26 // Meio Esquerda
#define pin_sensor4 28 // Ponta Esquerda

// Define a leitura inicial dos sensores IR com 0
bool sensor1, sensor2, sensor3, sensor4 = 0;

void setup(){

	// Inicializa os sensores Hitechnic
	Hitechnic_1.begin();
	Hitechnic_2.begin();

	// Inicializa os sensores IR
	pinMode(pin_sensor1, INPUT);
	pinMode(pin_sensor2, INPUT);
	pinMode(pin_sensor3, INPUT);
	pinMode(pin_sensor4, INPUT);
}

void loop(){
	// Atualiza o estado das cores detectadas pelo Hitechnic
	//  cor_esquerda = leitura_verde();
	//  cor_direita = leitura_verde2();

  //  Ações a serem tomadas baseadas nas variáveis cor_esquerda e cor_direita
	//  condicional_verde_direita (); 
	//  condicional_verde_esquerda ();
  
	// Atualiza o estado dos sensores IR seguidores de linha
	//  sensor1 = digitalRead(pin_sensor1); //Ponta direita
	//  sensor2 = digitalRead(pin_sensor2); //Meio direita
	//  sensor3 = digitalRead(pin_sensor3); //Meio esquerda
	//  sensor4 = digitalRead(pin_sensor4); //Ponta esquerda

  //  Ações a serem tomadas baseadas nas variáveis cor_esquerda e cor_direita

	seguidor_de_linha(motorD, motorE, sensor1, sensor2, sensor3, sensor4);
}
