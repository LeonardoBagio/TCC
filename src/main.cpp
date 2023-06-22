#include <Arduino.h>
#include <parametro/Configuracao.h>
#include <../lib/sensorUmidadeSolo/Service.h>
#include <../lib/bombaIrrigacao/Service.h>
#include <../lib/sensorTemperatura/Service.h>
#include <../lib/wifi/Service.h>
#include <../lib/time/Service.h>
#include <../lib/json/Service.h>
#include <../lib/webServer/Service.h>
#include <../lib/memoria/Service.h>
#include <../lib/bateria/Service.h>
#include <../lib/hibernacao/Service.h>
#include <subSistema/sistemaPorSensor.h>
#include <subSistema/sistemaPorTempo.h>

void tarefaSistemaPorSensor1(void *parametro);
void tarefaSistemaPorSensor2(void *parametro);
void tarefaEnviarInformacao(void *parametro);
void tarefaHibernacao(void *parametro);

void tarefaSistemaPorSensor1(void *parametro){
    primeiraTarefaConcluida = rodarPrimeiroSistema();
	vTaskDelete(NULL);
}

void tarefaSistemaPorSensor2(void *parametro){
	segundaTarefaConcluida = rodarSegundoSistema();
	vTaskDelete(NULL);
}

void tarefaEnviarInformacao(void *parametro){
	while (true){
		if ((primeiraTarefaConcluida == true) &&
			(segundaTarefaConcluida  == true)){
			
			if (verificarConexaoWifi() == true){
				conectarServidor();
				
				montarJsonFloat("temperatura", temperatura);
				montarJsonFloat("umidadeAr", umidadeAr);
				montarJsonString("sensorSolo", "SENSOR");
				montarJsonFloat("umidadeSolo", obterPercentualUmidade(PINOuSENSORu1));
				montarJsonFloat("bateria", obterPercentualBateria(PINOuBATERIA));
				post();
				vTaskDelay(500);
				montarJsonFloat("temperatura", temperatura);
				montarJsonFloat("umidadeAr", umidadeAr);
				montarJsonString("sensorSolo", "TEMPO");
				montarJsonFloat("umidadeSolo", obterPercentualUmidade(PINOuSENSORu2));
				montarJsonFloat("bateria", obterPercentualBateria(PINOuBATERIA));
				post();
				vTaskDelay(500);
			}

			terceiraTarefaConcluida = true;
			vTaskDelete(NULL);
		}

		vTaskDelay(5000);
	}

	vTaskDelete(NULL);
}

void tarefaHibernacao(void *parametro){
	while (true){
		if (atualizouTime() == true){
			if (obterHora() <= INICIOuSISTEMA){
				iniciarHibernacao(QUATROuHORAS);
			}

			if (obterHora() >= FINALuSISTEMA){
				iniciarHibernacao(QUATROuHORAS);
			}
		}
		
		if ((primeiraTarefaConcluida == true) &&
			(segundaTarefaConcluida  == true) &&
			(terceiraTarefaConcluida == true)){
			
			iniciarHibernacao(DEZuMINUTOS);
		}

		vTaskDelay(5000);
	}

	vTaskDelete(NULL);
}

void setup(){
	Serial.begin(9600);

	pinMode(PINOuENERGIA,	OUTPUT);
	pinMode(PINOuSENSORu1,	INPUT);
  	pinMode(PINOuSENSORu2,	INPUT);
	pinMode(PINOuDHTu11,	INPUT);
	pinMode(PINOuBOMBAu1,	OUTPUT);
	pinMode(PINOuBOMBAu2,	OUTPUT);
	pinMode(PINOuBATERIA,	INPUT);
	
	digitalWrite(PINOuENERGIA, LOW);
	digitalWrite(PINOuBOMBAu1, HIGH);
	digitalWrite(PINOuBOMBAu2, HIGH);

	primeiraTarefaConcluida = false;
	segundaTarefaConcluida  = false;
	terceiraTarefaConcluida = false;

	if (validarTensaoMinima(PINOuBATERIA) == true){
		iniciarHibernacao(TRINTAuMINUTOS);
	}
	
	digitalWrite(PINOuENERGIA, HIGH);
	conectarWifi();
	iniciarTime();
	atualizarTime();
	iniciarSensorTemperatura();
	iniciarMemoria();

	temperatura = obterTemperatura();
	umidadeAr	= obterUmidade();

	xTaskCreatePinnedToCore(
		tarefaHibernacao,
		"tarefaHibernacao",
		configMINIMAL_STACK_SIZE * 2,
		NULL,
		0,
		NULL, 
		primeiroCore);
	delay(500);
	
	xTaskCreatePinnedToCore(
		tarefaSistemaPorSensor1,
		"primeiraTarefa",
		configMINIMAL_STACK_SIZE * 2,
		NULL,
		0,
		NULL, 
		primeiroCore);
	delay(500);

	xTaskCreatePinnedToCore(
		tarefaSistemaPorSensor2,
		"segundaTarefa",
		configMINIMAL_STACK_SIZE * 2,
		NULL,
		0,
		NULL, 
		primeiroCore);
	delay(500);
	
	xTaskCreatePinnedToCore(
		tarefaEnviarInformacao,
		"enviarInformacao",
		configMINIMAL_STACK_SIZE * 4,
		NULL,
		1,
		NULL, 
		segundoCore);
	delay(500);
}

void loop(){}