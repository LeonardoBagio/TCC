#include <WiFi.h>

void conectarWifi();
bool desconectar();
bool verificarConexaoWifi();

void conectarWifi(){
    int indice = 0;

    WiFi.setHostname(hostName);
    WiFi.setAutoReconnect(true);
    WiFi.begin(redeWifi, senhaWifi);

    Serial.printf("Conectando wifi...");
    while (verificarConexaoWifi() != true){
        Serial.printf(".");
        
        indice++;
        if (indice > 10){
            break;
        }

        vTaskDelay(1000);
    }
}

bool desconectarWifi(){
    WiFi.disconnect(true);
    
    if (verificarConexaoWifi() == true){
        return false;
    }

    return true;
}

bool verificarConexaoWifi(){
    if (WiFi.status() != WL_CONNECTED){
        return false;
    }

    Serial.println("Conectado");
    return true;
}