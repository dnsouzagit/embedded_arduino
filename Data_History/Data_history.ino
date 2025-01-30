// Exemplo de código para historizar um sensor de temperatura via arduino enviando dados na porta serial rs232

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// Defina o tipo de sensor e o pino onde ele está conectado
#define DHTPIN 2
#define DHTTYPE DHT11   // DHT 11

DHT_Unified dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("Data logging iniciado");
}

void loop() {
  // Delay entre as leituras dos dados
  delay(2000);

  // Obtenha a leitura do sensor
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println("Falha ao ler do sensor de temperatura!");
  } else {
    Serial.print("Temperatura: ");
    Serial.print(event.temperature);
    Serial.println(" °C");
    
    // Escreve os dados no formato CSV
    Serial.print(millis());
    Serial.print(",");
    Serial.println(event.temperature);
  }
}
