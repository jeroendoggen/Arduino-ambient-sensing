#include <AmbientSensing.h>

//--------------------------------
//Required for the linking process of nested libraries
#include "TemperatureTMP.h"
#include "HumidityHIH4030.h"
#include "SignalFilter.h"
//--------------------------------

AmbientSensing Ambient;
uint8_t temperature;
uint8_t humidity;

void setup()
{
  Serial.begin(115200);
  Ambient.begin();
}

void loop()
{
  humidity = Ambient.getHumidity();
  temperature = Ambient.getTemperature();

  Serial.print("Hum: ");
  Serial.print(humidity,0);

  Serial.print("% -- Temp: ");
  Serial.print(temperature,0);
  Serial.println("C");
  delay(1000);

//  Ambient.printAmbientSensors(); // only posssible if debug mode enabled in "defines.h"

  delay(100);
}
