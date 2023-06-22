#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

DHT_Unified dht(PINOuDHTu11, DHT11);
sensors_event_t event;

void iniciarSensorTemperatura();
float obterTemperatura();
float obterUmidade();

void iniciarSensorTemperatura(){
    dht.begin();
}

float obterTemperatura(){
	dht.temperature().getEvent(&event);

	if (isnan(event.temperature)){
		return 0;
	}

	return event.temperature;
}

float obterUmidade(){
    dht.humidity().getEvent(&event);

    if (isnan(event.relative_humidity)){
        return 0;
    }

    return event.relative_humidity;
}