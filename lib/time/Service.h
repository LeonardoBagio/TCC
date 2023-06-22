#include <NTPClient.h>
#include <WiFiUDP.h>

WiFiUDP ntpUDP;
NTPClient ntp(ntpUDP);

void iniciarTime();
void atualizarTime();
bool atualizouTime();
int obterDia();
String obterHora();

void iniciarTime(){
	ntp.begin();
	ntp.setTimeOffset((-3 * 3600));
}

void atualizarTime(){
	if (verificarConexaoWifi() == true){
		ntp.update();
	}
}

bool atualizouTime(){
    return ntp.isTimeSet();
}

int obterDia(){
	return ntp.getDay();
}

String obterHora(){
	return ntp.getFormattedTime();
}