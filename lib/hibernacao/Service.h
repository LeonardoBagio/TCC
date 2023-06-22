void iniciarHibernacao(float tempoHibernacao);

void iniciarHibernacao(int tempo){
	Serial.println(obterHora());
	Serial.println("Hibernação");

	float tempoHibernacao = (TEMPOuHIBERNACAO * tempo);

	esp_sleep_enable_timer_wakeup(tempoHibernacao * MULTIPLICADORuHIBERNACAO);
	esp_deep_sleep_start();
}