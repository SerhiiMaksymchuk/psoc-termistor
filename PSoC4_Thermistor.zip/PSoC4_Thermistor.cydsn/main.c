
#include <device.h>
#include "removeOffsetNoise.h"
#include "measurement.h"
	
void main()
{
	/* Voltages across reference resistor and thermistor*/
	int16 iVref, iVtherm;
	
	/* Resistance of Thermistor*/
	uint32 iRes;
	
	/* Temperature value in 100ths of a degree C*/
	int32 iTemp; 

	/*Start all the hardware components required*/
	ADC_Start();
	AMux_Start();
	UART_Start();
	
	/*Enable Global Interrupts*/
	CyGlobalIntEnable;
    
	for(;;)
    {
		/* Measure Voltage Across Thermistor*/
    	iVtherm = MeasureResistorVoltage(AMUX_1_VT); 
		
		/* Measure Voltage Across Reference Resistor*/
    	iVref = MeasureResistorVoltage(AMUX_1_VREF);
        
	   	/* Use the thermistor component API function call to obtain the temperature corresponding to the voltages measured*/	
    	iRes = Thermistor_1_GetResistance(iVref, iVtherm);
    	iTemp = Thermistor_1_GetTemperature(iRes);

	  	/* Communicate results out over UART, send a header of 0x55 first followed
		by a tail of 0xAA*/
		
		/* Header*/
	  	UART_UartPutChar (0x55);
		/* Data*/
        UART_UartPutChar((uint8)(iTemp>>8));
		UART_UartPutChar((uint8)(iTemp));
		/*Tail*/
		UART_UartPutChar (0xAA);
		
		CyDelayUs(10);
    }
}

/* [] END OF FILE */
