/*******************************************************************************
* File Name: Vlow.h  
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

#if !defined(CY_PINS_Vlow_H) /* Pins Vlow_H */
#define CY_PINS_Vlow_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Vlow_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Vlow_Write(uint8 value) ;
void    Vlow_SetDriveMode(uint8 mode) ;
uint8   Vlow_ReadDataReg(void) ;
uint8   Vlow_Read(void) ;
uint8   Vlow_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Vlow_DRIVE_MODE_BITS        (3)
#define Vlow_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Vlow_DRIVE_MODE_BITS))
#define Vlow_DRIVE_MODE_SHIFT       (0x00u)
#define Vlow_DRIVE_MODE_MASK        (0x07u << Vlow_DRIVE_MODE_SHIFT)

#define Vlow_DM_ALG_HIZ         (0x00u << Vlow_DRIVE_MODE_SHIFT)
#define Vlow_DM_DIG_HIZ         (0x01u << Vlow_DRIVE_MODE_SHIFT)
#define Vlow_DM_RES_UP          (0x02u << Vlow_DRIVE_MODE_SHIFT)
#define Vlow_DM_RES_DWN         (0x03u << Vlow_DRIVE_MODE_SHIFT)
#define Vlow_DM_OD_LO           (0x04u << Vlow_DRIVE_MODE_SHIFT)
#define Vlow_DM_OD_HI           (0x05u << Vlow_DRIVE_MODE_SHIFT)
#define Vlow_DM_STRONG          (0x06u << Vlow_DRIVE_MODE_SHIFT)
#define Vlow_DM_RES_UPDWN       (0x07u << Vlow_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define Vlow_MASK               Vlow__MASK
#define Vlow_SHIFT              Vlow__SHIFT
#define Vlow_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Vlow_PS                     (* (reg32 *) Vlow__PS)
/* Port Configuration */
#define Vlow_PC                     (* (reg32 *) Vlow__PC)
/* Data Register */
#define Vlow_DR                     (* (reg32 *) Vlow__DR)
/* Input Buffer Disable Override */
#define Vlow_INP_DIS                (* (reg32 *) Vlow__PC2)


#if defined(Vlow__INTSTAT)  /* Interrupt Registers */

    #define Vlow_INTSTAT                (* (reg32 *) Vlow__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins Vlow_H */


/* [] END OF FILE */
