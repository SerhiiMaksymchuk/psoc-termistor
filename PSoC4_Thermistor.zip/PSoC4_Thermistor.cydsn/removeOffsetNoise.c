#include "removeOffsetNoise.h"
#include "measurement.h"

/*******************************************************************************

*  This is IIR filter to process the sampled ADC data. For first sample passed 
*  the function simply returns the passed ADC sample. for second sample onwards,
*  Fraction of input signal based upon the filter coefficient, is calculated and 
*  added to the previously stored filtered value.

*******************************************************************************/
int32 FilterSignal(int32 ADCSample, uint8 sensor)
{
	/* Running filtered value accumulator */
	static int32 filteredValue[NUM_SENSORS] = {0,0};
	
	/* Filtered value rounded-off to 20-bits */
	int32 filValueRounded;
	
	/* Left shift input by MAX_FILTER_COEFF_SHIFT to allow divisions up to MAX_FILTER_COEFF_SHIFT */
	ADCSample <<= MAX_FILTER_COEFF_SHIFT;
	   
	/* Pass the filter input as it is for fast changes in input */
    if ( (ADCSample > (filteredValue[sensor] + FILTER_FEEDFORWARD)) || (ADCSample < (filteredValue[sensor] - FILTER_FEEDFORWARD)) )
    {
        filteredValue[sensor] = ADCSample;
    }
    
    /* If not the first sample then based on filter coefficient, filter the 
     * input signal */
    else
    {
		/* IIR filter */
		filteredValue[sensor] = filteredValue[sensor] + ((ADCSample - filteredValue[sensor]) >> RTD_FILTER_COEFF_SHIFT);			
	}
	
	/* Compensate filter result for  left shift of 8 and round off */
	filValueRounded = (filteredValue[sensor] >> MAX_FILTER_COEFF_SHIFT) + ((filteredValue[sensor] & 0x00000080) >> (MAX_FILTER_COEFF_SHIFT - 1));
	
    return filValueRounded;
}

/* This function shorts the inputs of the ADC together and reads the offset. */

int32 GetOffset(void)
{
	int32 result;

  	/*Select the MUX channel and Measure the offset voltage*/	
	AMux_FastSelect(AMUX_1_CDS);
    ADC_StartConvert();
	ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
	result = ADC_GetResult16(0);
	ADC_StopConvert();
	
    return result;
}

/* [] END OF FILE */
