/*******************************************************************************
* File Name: Vtherm.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Vtherm.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Vtherm_PC =   (Vtherm_PC & \
                                (uint32)(~(uint32)(Vtherm_DRIVE_MODE_IND_MASK << (Vtherm_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Vtherm_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Vtherm_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void Vtherm_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Vtherm_DR & (uint8)(~Vtherm_MASK));
    drVal = (drVal | ((uint8)(value << Vtherm_SHIFT) & Vtherm_MASK));
    Vtherm_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Vtherm_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void Vtherm_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Vtherm__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Vtherm_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Vtherm_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Vtherm_Read(void) 
{
    return (uint8)((Vtherm_PS & Vtherm_MASK) >> Vtherm_SHIFT);
}


/*******************************************************************************
* Function Name: Vtherm_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Vtherm_ReadDataReg(void) 
{
    return (uint8)((Vtherm_DR & Vtherm_MASK) >> Vtherm_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Vtherm_INTSTAT) 

    /*******************************************************************************
    * Function Name: Vtherm_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Vtherm_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Vtherm_INTSTAT & Vtherm_MASK);
		Vtherm_INTSTAT = maskedStatus;
        return maskedStatus >> Vtherm_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
