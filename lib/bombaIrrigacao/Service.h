void controlarPorSensor(int pinoSensor, int pinoBomba);
void controlarPorTempo(int pinoSensor, int pinoBomba);

void controlarPorSensor(int pinoSensor, int pinoBomba){
	if (obterPercentualUmidade(pinoSensor) <= PERCENTUALuSOLOuSECO){
		controlarPorTempo(pinoBomba, TEMPOuPADRAO);
	}
}

void controlarPorTempo(int pinoBomba, int tempo){
	digitalWrite(pinoBomba, LOW);
	vTaskDelay(tempo);
	digitalWrite(pinoBomba, HIGH);
}