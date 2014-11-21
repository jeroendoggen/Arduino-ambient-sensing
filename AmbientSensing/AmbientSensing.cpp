// AmbientSensing.h - Arduino library for retrieving data from Ambient sensors
// Copyright 2012 Jeroen Doggen (jeroendoggen@gmail.com)
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#include <AmbientSensing.h>
#include "../SignalFilter/SignalFilter.h"

/// @todo: does this work correctly with "uint8_t" types for all sensor readings? (not tested on hardware)

/**
 * Constructor
 */
AmbientSensing::AmbientSensing()
{
}

/**
 * Destructor
 */
AmbientSensing::~AmbientSensing()
{
//do something here? (free(), delete()?)
}

/**
 * Begin Function: begin all sensors
 */
void AmbientSensing::begin(uint8_t temperature_pin, uint8_t humidity_pin)
{
  _Temperature.begin(temperature_pin);
  _Humidity.begin(humidity_pin);

//TODO: use a begin function with parameters for the filters
  _HumidityFilter.begin();
  _HumidityFilter.setFilter('m');
  _HumidityFilter.setOrder(1);

  _TemperatureFilter.begin();
  _TemperatureFilter.setFilter('m');
  _TemperatureFilter.setOrder(1);
}

/// getHumidity: measure the humidity (taking temperature into account)
uint8_t AmbientSensing::getHumidity()
{
  _Humidity.setTemperature(uint8_t(_Temperature.getTemperatureCelcius()));
/// @todo: check if this cast works correctly on the hardware
  return(uint8_t(_Humidity.getHumidityPercentage()));
}

/// getTemperature: measure the temperature
uint8_t AmbientSensing::getTemperature()
{
  return(_Temperature.getTemperatureCelcius());
}

/// getFilteredHumidity: measure the humidity (data filtered)
uint8_t AmbientSensing::getFilteredHumidity()
{
  return(_HumidityFilter.run(uint8_t(getHumidity())));
}

/// getFilteredTemperature: measure the temperature (data filtered)
uint8_t AmbientSensing::getFilteredTemperature()
{
  return(_TemperatureFilter.run(uint8_t(getTemperature())));
}

#ifdef DEBUG_AMBIENT
/// printAmbientSensors: print values over the serial port
void AmbientSensing::printAmbientSensors()
{
  Serial.print("Hum: ");
  Serial.print(getHumidity() , 0);
  Serial.print("% -- Temp: ");
  Serial.print(getTemperature() , 0);
  Serial.println("C");
}
#endif
