#if !defined(removeOffsetNoise_H)
#define removeOffsetNoise_H

#include "device.h"

/* Filter coefficient for RTD sensor */
#define RTD_FILTER_COEFF_SHIFT          6
#define MAX_FILTER_COEFF_SHIFT			8

/* Number of sensors(readings) that require filtering */
#define NUM_SENSORS						2

/* Number of each sensor */
#define REF_RES							
#define THERMISTOR						1

/* Filter Feedforward. It is set equal to 100 ADC counts. It has been scaled by 256 to account for MAXIMUM_FITER_COEFF  */
#define FILTER_FEEDFORWARD 				50 * 256

/* Function prototype for IIR filter */
int32 FilterSignal(int32 ADCSample, uint8 sensor);

/* Function to measure voltage across RTD sensor at zero current */
int32 GetOffset(void);

#endif

//[] END OF FILE
