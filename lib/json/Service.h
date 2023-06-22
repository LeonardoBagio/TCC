#include <ArduinoJson.h>

DynamicJsonDocument json(2048);

void montarJsonString(String campo, String informacao);
void montarJsonFloat(String campo, String informacao);
void limparJson();
String obterJson();

void montarJsonString(String campo, String informacao){
	json[campo] = informacao;
}

void montarJsonFloat(String campo, float informacao){
	json[campo] = informacao;
}

void limparJson(){
	json.clear();
}

String obterJson(){
	String stringJson;

	serializeJson(json, stringJson);
	
	Serial.println(stringJson);

	return stringJson;
}

