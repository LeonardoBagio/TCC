#include <Preferences.h>

Preferences preferences;

void iniciarMemoria();
void limparMemoria();
void limparChave(const char* chave);
void realizarLimpezaMemoria();
void escreverBool(const char* chave, bool valor);
void escreverInt(const char* chave, int valor);
void escreverFloat(const char* chave, float valor);
bool lerBool(const char* chave);
int lerInt(const char* chave);
float lerFloat(const char* chave);

void iniciarMemoria(){
    preferences.begin("memoria", false);
	realizarLimpezaMemoria();
}

void limparMemoria(){
	preferences.clear();
}

void limparChave(const char* chave){
	preferences.remove(chave);
}

void realizarLimpezaMemoria(){
	if (atualizouTime() == false){
		return;
	}
	
	if (lerInt(DIAuSEMANA) == obterDia()){
		return;
	}

	limparMemoria();
	escreverInt(DIAuSEMANA, obterDia());
}

void escreverBool(const char* chave, bool valor){
    preferences.putBool(chave, valor);
}

void escreverInt(const char* chave, int valor){
    preferences.putInt(chave, valor);
}

void escreverFloat(const char* chave, float valor){
	preferences.putFloat(chave, valor);
}

bool lerBool(const char* chave){
    return preferences.getBool(chave, false);
}

int lerInt(const char* chave){
    return preferences.getInt(chave, false);
}

float lerFloat(const char* chave){
	return preferences.getFloat(chave, false);
}

