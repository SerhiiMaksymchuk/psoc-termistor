/*******************************************************************************
* File Name: Thermistor_1.c
* Version 1.20
*
* Description:
*  This file provides the source code to the API for the ThermistorCalc
*  Component.
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Thermistor_1.h"


/*******************************************************************************
* Function Name: Thermistor_1_GetResistance
********************************************************************************
*
* Summary:
*  The digital values of the voltages across the reference resistor and the
*  thermistor are passed to this function as parameters. The function returns
*  the resistance, based on the voltage values.
*
* Parameters:
*  vReference: the voltage across the reference resistor;
*  vThermistor: the voltage across the thermistor.
*  The ratio of these two voltages is used by this function. Therefore, the
*  units for both parameters must be the same.
*
* Return:
*  The return value is the resistance across the thermistor. The value returned
*  is the resistance in Ohms.
*
*******************************************************************************/
uint32 Thermistor_1_GetResistance(int16 vReference, int16 vThermistor)
                                      
{
    int32 resT;
    int16 temp;

    /* Calculate thermistor resistance from the voltages */
    resT = Thermistor_1_REF_RESISTOR * ((int32)vThermistor);
    if (vReference < 0)
    {
        temp = -vReference;
        temp = (int16)((uint16)((uint16)temp >> 1u));
        temp = -temp;
    }
    else
    {
        temp = (int16)((uint16)((uint16)vReference >> 1u));
    }
    resT += temp;
    resT /= vReference;

    /* The ordering of Reference resistor value is specifically designed to keep the result from overflowing */
    return ((uint32)((uint32)resT << Thermistor_1_REF_RES_SHIFT));
}


/*******************************************************************************
* Function Name: Thermistor_1_GetTemperature
********************************************************************************
*
* Summary:
*  The value of the thermistor resistance is passed to this function as a
*  parameter. The function returns the temperature, based on the resistance
*  value. The method used to calculate the temperature is dependent on whether
*  Equation or LUT was selected in the Customizer.
*
* Parameters:
*  resT: the resistance across the thermistor in Ohms.
*
* Return:
*  The return value is the temperature in 1/100ths of degrees C. For example,
*  the return value is 2345, when the actual temperature is 23.45 degrees C.
*
*******************************************************************************/
int16 Thermistor_1_GetTemperature(uint32 resT) 
{
    int16 tempTR;
    static const uint32 CYCODE Thermistor_1_LUT[] = { 32770u, 32602u, 32436u, 32270u, 32106u, 31942u, 31779u, 31617u,
 31456u, 31296u, 31137u, 30979u, 30822u, 30665u, 30510u, 30355u, 30201u, 30048u, 29896u, 29745u, 29595u, 29446u, 29297u,
 29149u, 29002u, 28856u, 28711u, 28567u, 28423u, 28280u, 28138u, 27997u, 27857u, 27717u, 27578u, 27440u, 27303u, 27167u,
 27031u, 26896u, 26762u, 26629u, 26496u, 26364u, 26233u, 26102u, 25973u, 25844u, 25715u, 25588u, 25461u, 25335u, 25209u,
 25085u, 24961u, 24837u, 24715u, 24593u, 24471u, 24351u, 24231u, 24111u, 23993u, 23875u, 23757u, 23641u, 23525u, 23409u,
 23295u, 23181u, 23067u, 22954u, 22842u, 22730u, 22619u, 22509u, 22399u, 22290u, 22181u, 22073u, 21966u, 21859u, 21753u,
 21647u, 21542u, 21438u, 21334u, 21231u, 21128u, 21026u, 20924u, 20823u, 20722u, 20622u, 20523u, 20424u, 20326u, 20228u,
 20130u, 20034u, 19937u, 19842u, 19746u, 19652u, 19558u, 19464u, 19371u, 19278u, 19186u, 19094u, 19003u, 18912u, 18822u,
 18732u, 18643u, 18554u, 18466u, 18378u, 18291u, 18204u, 18118u, 18032u, 17946u, 17861u, 17777u, 17693u, 17609u, 17526u,
 17443u, 17361u, 17279u, 17197u, 17116u, 17036u, 16956u, 16876u, 16797u, 16718u, 16639u, 16561u, 16484u, 16406u, 16330u,
 16253u, 16177u, 16102u, 16026u, 15952u, 15877u, 15803u, 15729u, 15656u, 15583u, 15511u, 15439u, 15367u, 15296u, 15225u,
 15154u, 15084u, 15014u, 14945u, 14876u, 14807u, 14738u, 14670u, 14603u, 14535u, 14468u, 14402u, 14335u, 14269u, 14204u,
 14139u, 14074u, 14009u, 13945u, 13881u, 13817u, 13754u, 13691u, 13629u, 13566u, 13504u, 13443u, 13381u, 13320u, 13260u,
 13199u, 13139u, 13080u, 13020u, 12961u, 12902u, 12844u, 12785u, 12728u, 12670u, 12613u, 12556u, 12499u, 12442u, 12386u,
 12330u, 12275u, 12219u, 12164u, 12110u, 12055u, 12001u, 11947u, 11893u, 11840u, 11787u, 11734u, 11682u, 11629u, 11577u,
 11525u, 11474u, 11423u, 11372u, 11321u, 11271u, 11220u, 11170u, 11121u, 11071u, 11022u, 10973u, 10924u, 10876u, 10828u,
 10780u, 10732u, 10685u, 10637u, 10590u, 10543u, 10497u, 10451u, 10405u, 10359u, 10313u, 10268u, 10222u, 10178u, 10133u,
 10088u, 10044u, 10000u, 9956u, 9913u, 9869u, 9826u, 9783u, 9740u, 9698u, 9655u, 9613u, 9571u, 9530u, 9488u, 9447u,
 9406u, 9365u, 9324u, 9284u, 9243u, 9203u, 9163u, 9124u, 9084u, 9045u, 9006u, 8967u, 8928u, 8890u, 8851u, 8813u, 8775u,
 8737u, 8700u, 8662u, 8625u, 8588u, 8551u, 8515u, 8478u, 8442u, 8406u, 8370u, 8334u, 8298u, 8263u, 8227u, 8192u, 8157u,
 8123u, 8088u, 8054u, 8019u, 7985u, 7951u, 7917u, 7884u, 7850u, 7817u, 7784u, 7751u, 7718u, 7686u, 7653u, 7621u, 7589u,
 7556u, 7525u, 7493u, 7461u, 7430u, 7399u, 7368u, 7337u, 7306u, 7275u, 7245u, 7214u, 7184u, 7154u, 7124u, 7094u, 7064u,
 7035u, 7006u, 6976u, 6947u, 6918u, 6889u, 6861u, 6832u, 6804u, 6775u, 6747u, 6719u, 6691u, 6664u, 6636u, 6609u, 6581u,
 6554u, 6527u, 6500u, 6473u, 6446u, 6420u, 6393u, 6367u, 6341u, 6315u, 6289u, 6263u, 6237u, 6211u, 6186u, 6161u, 6135u,
 6110u, 6085u, 6060u, 6035u, 6011u, 5986u, 5962u, 5938u, 5913u, 5889u, 5865u, 5841u, 5818u, 5794u, 5770u, 5747u, 5724u,
 5700u, 5677u, 5654u, 5631u, 5609u, 5586u, 5563u, 5541u, 5518u, 5496u, 5474u, 5452u, 5430u, 5408u, 5386u, 5365u, 5343u,
 5322u, 5300u, 5279u, 5258u, 5237u, 5216u, 5195u, 5174u, 5153u, 5133u, 5112u, 5092u, 5072u, 5051u, 5031u, 5011u, 4991u,
 4971u, 4952u, 4932u, 4912u, 4893u, 4874u, 4854u, 4835u, 4816u, 4797u, 4778u, 4759u, 4740u, 4721u, 4703u, 4684u, 4666u,
 4647u, 4629u, 4611u, 4593u, 4575u, 4557u, 4539u, 4521u, 4503u, 4486u, 4468u, 4451u, 4433u, 4416u, 4399u, 4381u, 4364u,
 4347u, 4330u, 4313u, 4297u, 4280u, 4263u, 4247u, 4230u, 4214u, 4197u, 4181u, 4165u, 4149u, 4133u, 4117u, 4101u, 4085u,
 4069u, 4053u, 4038u, 4022u, 4007u, 3991u, 3976u, 3960u, 3945u, 3930u, 3915u, 3900u, 3885u, 3870u, 3855u, 3840u, 3826u,
 3811u, 3797u, 3782u, 3768u, 3753u, 3739u, 3725u, 3710u, 3696u, 3682u, 3668u, 3654u, 3640u, 3626u, 3613u, 3599u };


    #if (Thermistor_1_IMPLEMENTATION == Thermistor_1_EQUATION_METHOD)

        float32 stEqn;
        float32 logrT;

        /* Calculate thermistor resistance from the voltages */
        #if(!CY_PSOC3)
            logrT = (float32)log((float64)resT);
        #else
            logrT = log((float32)resT);
        #endif  /* (!CY_PSOC3) */

        /* Calculate temperature from the resistance of thermistor using Steinhart-Hart Equation */
        #if(!CY_PSOC3)
            stEqn = (float32)(Thermistor_1_THA + (Thermistor_1_THB * logrT) + 
                             (Thermistor_1_THC * pow((float64)logrT, (float32)3)));
        #else
            stEqn = (float32)(Thermistor_1_THA + (Thermistor_1_THB * logrT) + 
                             (Thermistor_1_THC * pow(logrT, (float32)3)));
        #endif  /* (!CY_PSOC3) */

        tempTR = (int16)((float32)((((1.0 / stEqn) - Thermistor_1_K2C) * (float32)Thermistor_1_SCALE) + 0.5));

    #else /* Thermistor_1_IMPLEMENTATION == Thermistor_1_LUT_METHOD */

        uint16 mid;
        uint16 first = 0u;
        uint16 last = Thermistor_1_LUT_SIZE - 1u;

        /* Calculate temperature from the resistance of thermistor by using the LUT */
        while (first < last)
        {
            mid = (first + last) >> 1u;

            if ((0u == mid) || ((Thermistor_1_LUT_SIZE - 1u) == mid) || (resT == Thermistor_1_LUT[mid]))
            {
                last = mid;
                break;
            }
            else if (Thermistor_1_LUT[mid] > resT)
            {
                first = mid + 1u;
            }
            else /* (Thermistor_1_LUT[mid] < resT) */
            {
                last = mid - 1u;
            }
        }

        /* Calculation the closest entry in the LUT */
        if ((Thermistor_1_LUT[last] > resT) && (last < (Thermistor_1_LUT_SIZE - 1u)) &&
           ((Thermistor_1_LUT[last] - resT) > (resT - Thermistor_1_LUT[last + 1u])))
        {
            last++;
        }
        else if ((Thermistor_1_LUT[last] < resT) && (last > 0u) &&
                ((Thermistor_1_LUT[last - 1u] - resT) < (resT - Thermistor_1_LUT[last])))
        {
            last--;
        }
        else
        {
            /* Closest entry in the LUT already found */
        }

        tempTR = Thermistor_1_MIN_TEMP + (int16)((uint16)(last * Thermistor_1_ACCURACY));

    #endif /* (Thermistor_1_IMPLEMENTATION == Thermistor_1_EQUATION_METHOD) */

    return (tempTR);
}


/* [] END OF FILE */
