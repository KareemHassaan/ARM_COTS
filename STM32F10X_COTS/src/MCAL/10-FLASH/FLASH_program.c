/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						02 MAR,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: FLASH Driver                                           							                     		 	  *
* ! File Name	: FLASH_program.c                                   		                   						                  *
* ! Description : This file has the implementation of Basic of FLASH functions  					   						          *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL	                  						                                         							  *
**************************************************************************************************************************************/

/**************************************************** Library Inclusions *************************************************************/
#include "../../include/LIB/BIT_MATH.h"
#include "../../include/LIB/STD_TYPES.h"
/************************************************** Lower Layer Inclusions ***********************************************************/


/************************************************** Self Layer Inclusions ************************************************************/

/************************************************** Self Files Inclusions ************************************************************/
#include "../../include/MCAL/10-FLASH/FLASH_interface.h"
#include "../../include/MCAL/10-FLASH/FLASH_private.h"
#include "../../include/MCAL/10-FLASH/FLASH_config.h"

/***************************************************** Global Variables **************************************************************/

/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MFLASH_voidWrite																				                  *
* Parameters (in)	: Adress to write on, data, length 													                              *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Write on flash											                      					  *
**************************************************************************************************************************************/
void MFLASH_voidWrite(uint32 Copy_uint32Address, uint16 * Copy_uint16Data, uint8 Copy_uint8Length)
{
	uint8 Local_uint8LoopCounter;
	/* Wait Busy Flag */
	while(GET_BIT(FLASH-> FLASH_SR, BSY_BIT) == 1);
	/*unlock flash*/
	FlashUnlock();

	for (Local_uint8LoopCounter = 0; Local_uint8LoopCounter< Copy_uint8Length; Local_uint8LoopCounter++)
	{
		/* Write Flash Programming */
		SET_BIT(FLASH->FLASH_CR, PG_BIT);

		/* Half word operation */
		*((volatile uint16*)Copy_uint32Address) = Copy_uint16Data[Local_uint8LoopCounter];
		Copy_uint32Address += 2 ;

		/* Wait Busy Flag */
		while (GET_BIT(FLASH->FLASH_SR, BSY_BIT) == 1);

		/* EOP */
		SET_BIT(FLASH->FLASH_SR, EOP_BIT);
		CLR_BIT(FLASH->FLASH_CR, PG_BIT);
	}
}

/**************************************************************************************************************************************
* Function Name		: MFLASH_voidPageErase																				              *
* Parameters (in)	: Page number																						              *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Erase Selected page of flash									                                      *
**************************************************************************************************************************************/
void MFLASH_voidPageErase(uint8 Copy_uint8PageNum )
{
	/* Wait Busy Flag */
	while(GET_BIT(FLASH-> FLASH_SR, BSY_BIT) == 1);
	/*unlock flash*/
	FlashUnlock();
	/*select Page Erase Operation */
	SET_BIT(FLASH->FLASH_CR, PER_BIT);
	/* Write Page address */
	FLASH->FLASH_AR =  (FLASH_PAGE0_ADDRESS) + (uint32) (Copy_uint8PageNum * PageSize);
	/* Start operation */
	SET_BIT(FLASH->FLASH_CR, STRT_BIT);
	/* Wait Busy Flag */
	while(GET_BIT(FLASH-> FLASH_SR, BSY_BIT) == 1);
	/*End of operation*/
	SET_BIT(FLASH->FLASH_SR, EOP_BIT);
	/* Disable Page erase */
	CLR_BIT(FLASH->FLASH_CR, PER_BIT);
}

/**************************************************************************************************************************************
* Function Name		: MFLASH_voidAreaErase																				              *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Erase app area of flash										                      			   	  * 
**************************************************************************************************************************************/
void MFLASH_voidAreaErase(void)
{
	uint8 Local_uint8LoopCounter;

	for(Local_uint8LoopCounter = START_PAGE; Local_uint8LoopCounter < END_PAGE; Local_uint8LoopCounter++)
	{
		/*Erase Selected Page*/
		MFLASH_voidPageErase(Local_uint8LoopCounter);
	}
}

/**************************************************************************************************************************************
* Function Name		: FlashUnlock																					                  *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: function to unlock Flash							                      										  *
**************************************************************************************************************************************/
static void FlashUnlock(void)
{
	/* Check if FPEC is locked or not */
	if(GET_BIT(FLASH->FLASH_CR, LOCK_BIT) == 1)
		{
			/* Write KEY1 */
			FLASH->FLASH_KEYR = KEY1;
			/* Write KEY2 */
			FLASH->FLASH_KEYR = KEY2;
		}
}
