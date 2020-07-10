
#include "measurement.h"
#include "removeOffsetNoise.h"

/* This functions returns the voltage across the resistor. Either Thermistor or Reference */

int32 MeasureResistorVoltage(uint8 channel)
{
	/* Voltage across resistor*/
	int32 result;
	
	/* Offset Voltage*/
	int32 offset;

	/* Select correct AMUX channel*/	
	AMux_FastSelect(channel);
	
	/* Read voltage across  resistor*/
    ADC_StartConvert();
	
	ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
	result = ADC_GetResult16(0);
	
	ADC_StopConvert();
	
	/* Get the offset voltage*/
	offset = GetOffset(); 
	
	/* Get CDS difference*/
	result = result - offset;
	
	/* Filter signal*/
	result = FilterSignal(result, channel);
	
	return result;
	
}
