bool rodarPrimeiroSistema();

bool rodarPrimeiroSistema(){
	if (obterPercentualUmidade(PINOuSENSORu1) <= PERCENTUALuSOLOuSECO){
		controlarPorTempo(PINOuBOMBAu1, TEMPOuPADRAO);
	}
	
    return true;
}