/*******************************************************************************
* File Name: Vhi.h  
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

#if !defined(CY_PINS_Vhi_H) /* Pins Vhi_H */
#define CY_PINS_Vhi_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Vhi_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Vhi_Write(uint8 value) ;
void    Vhi_SetDriveMode(uint8 mode) ;
uint8   Vhi_ReadDataReg(void) ;
uint8   Vhi_Read(void) ;
uint8   Vhi_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Vhi_DRIVE_MODE_BITS        (3)
#define Vhi_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Vhi_DRIVE_MODE_BITS))
#define Vhi_DRIVE_MODE_SHIFT       (0x00u)
#define Vhi_DRIVE_MODE_MASK        (0x07u << Vhi_DRIVE_MODE_SHIFT)

#define Vhi_DM_ALG_HIZ         (0x00u << Vhi_DRIVE_MODE_SHIFT)
#define Vhi_DM_DIG_HIZ         (0x01u << Vhi_DRIVE_MODE_SHIFT)
#define Vhi_DM_RES_UP          (0x02u << Vhi_DRIVE_MODE_SHIFT)
#define Vhi_DM_RES_DWN         (0x03u << Vhi_DRIVE_MODE_SHIFT)
#define Vhi_DM_OD_LO           (0x04u << Vhi_DRIVE_MODE_SHIFT)
#define Vhi_DM_OD_HI           (0x05u << Vhi_DRIVE_MODE_SHIFT)
#define Vhi_DM_STRONG          (0x06u << Vhi_DRIVE_MODE_SHIFT)
#define Vhi_DM_RES_UPDWN       (0x07u << Vhi_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define Vhi_MASK               Vhi__MASK
#define Vhi_SHIFT              Vhi__SHIFT
#define Vhi_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Vhi_PS                     (* (reg32 *) Vhi__PS)
/* Port Configuration */
#define Vhi_PC                     (* (reg32 *) Vhi__PC)
/* Data Register */
#define Vhi_DR                     (* (reg32 *) Vhi__DR)
/* Input Buffer Disable Override */
#define Vhi_INP_DIS                (* (reg32 *) Vhi__PC2)


#if defined(Vhi__INTSTAT)  /* Interrupt Registers */

    #define Vhi_INTSTAT                (* (reg32 *) Vhi__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins Vhi_H */


/* [] END OF FILE */
