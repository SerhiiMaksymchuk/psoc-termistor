/*******************************************************************************
* File Name: Vtherm.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Vtherm_H) /* Pins Vtherm_H */
#define CY_PINS_Vtherm_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Vtherm_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Vtherm_Write(uint8 value) ;
void    Vtherm_SetDriveMode(uint8 mode) ;
uint8   Vtherm_ReadDataReg(void) ;
uint8   Vtherm_Read(void) ;
uint8   Vtherm_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Vtherm_DRIVE_MODE_BITS        (3)
#define Vtherm_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Vtherm_DRIVE_MODE_BITS))
#define Vtherm_DRIVE_MODE_SHIFT       (0x00u)
#define Vtherm_DRIVE_MODE_MASK        (0x07u << Vtherm_DRIVE_MODE_SHIFT)

#define Vtherm_DM_ALG_HIZ         (0x00u << Vtherm_DRIVE_MODE_SHIFT)
#define Vtherm_DM_DIG_HIZ         (0x01u << Vtherm_DRIVE_MODE_SHIFT)
#define Vtherm_DM_RES_UP          (0x02u << Vtherm_DRIVE_MODE_SHIFT)
#define Vtherm_DM_RES_DWN         (0x03u << Vtherm_DRIVE_MODE_SHIFT)
#define Vtherm_DM_OD_LO           (0x04u << Vtherm_DRIVE_MODE_SHIFT)
#define Vtherm_DM_OD_HI           (0x05u << Vtherm_DRIVE_MODE_SHIFT)
#define Vtherm_DM_STRONG          (0x06u << Vtherm_DRIVE_MODE_SHIFT)
#define Vtherm_DM_RES_UPDWN       (0x07u << Vtherm_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define Vtherm_MASK               Vtherm__MASK
#define Vtherm_SHIFT              Vtherm__SHIFT
#define Vtherm_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Vtherm_PS                     (* (reg32 *) Vtherm__PS)
/* Port Configuration */
#define Vtherm_PC                     (* (reg32 *) Vtherm__PC)
/* Data Register */
#define Vtherm_DR                     (* (reg32 *) Vtherm__DR)
/* Input Buffer Disable Override */
#define Vtherm_INP_DIS                (* (reg32 *) Vtherm__PC2)


#if defined(Vtherm__INTSTAT)  /* Interrupt Registers */

    #define Vtherm_INTSTAT                (* (reg32 *) Vtherm__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins Vtherm_H */


/* [] END OF FILE */
