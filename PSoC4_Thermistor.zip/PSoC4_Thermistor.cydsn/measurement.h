
*******************************************************************************/
#if !defined(measurement_H)
#define measurement_H

#include "device.h"

/*AMUX channel selections*/
#define AMUX_1_VT 1
#define AMUX_1_VREF 0
#define AMUX_1_CDS 2

/* Function prototype to measure the voltage across resistance */
int32 MeasureResistorVoltage(uint8 channel);

#endif 