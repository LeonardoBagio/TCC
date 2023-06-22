float obterPercentualUmidade(int pinoSensor);
float formatarValor(float valor);

float obterPercentualUmidade(int pinoSensor){
	float valorTotal = 0;

	for (int indice = 0; indice < AMOSTRA; indice++){
		valorTotal = valorTotal + analogRead(pinoSensor);
	}

	return formatarValor(map((valorTotal/AMOSTRA), VALORuMINIMOuLEITURA, VALORuMAXIMOuLEITURA, 100, 0));
}

float formatarValor(float valor){
	if (valor > 100){
		valor = 100;
	}

	if (valor < 0){
		valor = 0;
	}

	return valor;
}