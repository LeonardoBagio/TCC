void controlarPorTempo(int pinoSensor, int pinoBomba);

void controlarPorTempo(int pinoBomba, int tempo){
	digitalWrite(pinoBomba, LOW);
	vTaskDelay(tempo);
	digitalWrite(pinoBomba, HIGH);
}