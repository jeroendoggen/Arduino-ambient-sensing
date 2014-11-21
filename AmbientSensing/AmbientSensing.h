// AmbientSensing.h - Arduino library to get data from multiple ambient sensors
// Copyright 2012 Jeroen Doggen (jeroendoggen@gmail.com)
//
// Version History:
//  Version 0.1: Temperature & humidity
//  Version 0.2: Filtered data
//
// Roadmap:
//  Version 0.3:
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

#ifndef AmbientSensing_h
#define AmbientSensing_h

#include "defines.h"
#include "../TemperatureTMP/TemperatureTMP.h"
#include "../HumidityHIH4030/HumidityHIH4030.h"
#include "../SignalFilter/SignalFilter.h"

/// class AmbientSensing
class AmbientSensing
{
  public:
    AmbientSensing();                             // Constructor
    ~AmbientSensing();                            // Destructor

    void begin();                                 // Begin all sensors

    uint8_t getHumidity();                        // Read humidity sensor value
    uint8_t getTemperature();                     // Read temperature sensor value

    uint8_t getFilteredHumidity();                // Humidity values filtered with median Filter
    uint8_t getFilteredTemperature();             // Temperature values filtered with median Filter

#ifdef DEBUG_AMBIENT
    void printAmbientSensors();
#endif
  private:
    HumidityHIH4030 _Humidity;                    // Humidity sensor object
    TemperatureTMP _Temperature;                  // Temperature sensor object
    SignalFilter _HumidityFilter;                 // Humidity sensor Filter object
    SignalFilter _TemperatureFilter;              // Temperature sensor Filter object
};
#endif
