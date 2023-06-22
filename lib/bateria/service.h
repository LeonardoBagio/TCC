float obterPercentualBateria(int pino);
bool validarTensaoMinima(int pino);

float obterPercentualBateria(int pino){
	return ((analogReadMilliVolts(pino) * 5.00) / 1023.00);
}

bool validarTensaoMinima(int pino){
	if (obterPercentualBateria(pino) <= TENSAOuMINIMA){
		return true;
	}

	return false;
}