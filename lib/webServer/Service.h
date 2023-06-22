#include <ArduinoWebsockets.h>

using namespace websockets;
WebsocketsClient client;

bool conectarServidor();
bool post();

bool conectarServidor(){
    bool connected = client.connect(servidor, porta, caminho);
    
    if (!connected){
        return false;
    }

    return true;
}

bool post(){
    if(!client.available()) {
        return false;
    }
    
    client.poll();
    client.send(obterJson());
    limparJson();
    
    return true;
}