bool rodarSegundoSistema();
bool validarSegundaTarefa(const char* chave);

bool rodarSegundoSistema(){	
	if (validarSegundaTarefa(NOVEuHORAS) == true){
		controlarPorTempo(PINOuBOMBAu2, TEMPOuPADRAO);
		escreverBool(NOVEuHORAS, true);
        return true;
	}

	if (validarSegundaTarefa(DOZEuHORAS) == true){
		controlarPorTempo(PINOuBOMBAu2, TEMPOuPADRAO);
		escreverBool(DOZEuHORAS, true);
        return true;
	}

	if (validarSegundaTarefa(QUINZEuHORAS) == true){
		controlarPorTempo(PINOuBOMBAu2, TEMPOuPADRAO);
		escreverBool(QUINZEuHORAS, true);
        return true;
	}

	return true;
}

bool validarSegundaTarefa(const char* chave){
	if (lerBool(chave) == true){
		return false;
	}

	if (obterHora() < chave){
		return false;
	}

	return true;
}