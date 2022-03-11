/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						21 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: NVIC Driver                                                        							                      *
* ! File Name	: NVIC_program.c                                                       							                      *
* ! Description : This file has the implementation of Basic of NVIC functions        							                      *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/

/**************************************************** Library Inclusions *************************************************************/
#include "../../include/LIB/STD_TYPES.h"
#include "../../include/LIB/BIT_MATH.h"
/************************************************** Lower Layer Inclusions ***********************************************************/

/************************************************** Self Layer Inclusions ************************************************************/

/************************************************** Self Files Inclusions ************************************************************/
/*Must be with that order maybe change Private with config only*/
#include"../../include/MCAL/03-NVIC/NVIC_interface.h"  
#include"../../include/MCAL/03-NVIC/NVIC_private.h"
#include"../../include/MCAL/03-NVIC/NVIC_config.h"

/***************************************************** Global Variables **************************************************************/


/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MNVIC_voidInit																			                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Set Specific Bit To Enable Interrupt 										          				  *
**************************************************************************************************************************************/
void MNVIC_voidInit()
{
	/*configure NVIC Grouping and Subgrouping*/
	SCB_AIRCR =  NVIC_GROUP_POLICY;
}

/**************************************************************************************************************************************
* Function Name		: MNVIC_voidEnableInterrupt																	                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Set Specific Bit To Enable Interrupt 										          				  *
**************************************************************************************************************************************/
void MNVIC_voidEnableInterrupt(uint8 Copy_uint8InterruptNumber)
{
	NVIC -> ISER[Copy_uint8InterruptNumber / 32] = (1 << (Copy_uint8InterruptNumber % 32));
}

/**************************************************************************************************************************************
* Function Name		: MNVIC_voidDisableInterrupt																                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Set Specific Bit To Disable Interrupt 										          			  *
**************************************************************************************************************************************/
void MNVIC_voidDisableInterrupt(uint8 Copy_uint8InterruptNumber)
{
	NVIC -> ICER[Copy_uint8InterruptNumber / 32] = (1 << (Copy_uint8InterruptNumber % 32));
}

/**************************************************************************************************************************************
* Function Name		: MNVIC_voidSetPendingFlag																	                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Set the Pending Flag Used in Testing The ISR 							          					  *
**************************************************************************************************************************************/
void MNVIC_voidSetPendingFlag(uint8 Copy_uint8InterruptNumber)
{
	NVIC -> ISPR[Copy_uint8InterruptNumber / 32] = (1 << (Copy_uint8InterruptNumber % 32));
}

/**************************************************************************************************************************************
* Function Name		: MNVIC_voidClearPendingFlag																                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Clear the Pending Flag Used in Testing The ISR 						          					  *
**************************************************************************************************************************************/
void MNVIC_voidClearPendingFlag(uint8 Copy_uint8InterruptNumber)
{
	NVIC -> ICPR[Copy_uint8InterruptNumber / 32] = (1 << (Copy_uint8InterruptNumber % 32));
}

/**************************************************************************************************************************************
* Function Name		: MNVIC_uint8GetActiveInterrupt																                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Get the Interrupt Status		 										          					  *
**************************************************************************************************************************************/
uint8 MNVIC_uint8GetActiveInterrupt(uint8 Copy_uint8InterruptNumber)
{
	uint8 Local_uint8ReturnValue;
	
	Local_uint8ReturnValue = GET_BIT(NVIC -> IABR[Copy_uint8InterruptNumber / 32], (Copy_uint8InterruptNumber % 32));
	
	return Local_uint8ReturnValue;
}

/**************************************************************************************************************************************
* Function Name		: NVIC_voidSetPriority																		                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Set Priority of specific Interrupt ID									        					  *
**************************************************************************************************************************************/
void NVIC_voidSetPriority(uint8 cpy_uint8IntID, uint8 cpy_uint8Priority)
{
	/* Check that Interrupt ID is within Range */
	if(cpy_uint8IntID < 60)
	{
		/* Check that Priority is within Range (only 4-bits) */
		if(cpy_uint8Priority < 16)
		{
			/*Setting the Priority*/
			NVIC -> IPR[cpy_uint8IntID] = (cpy_uint8Priority << 4);
		}
	}
}