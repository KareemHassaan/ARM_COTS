/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						02 MAR,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: FLASH Driver   			                                                 							              *
* ! File Name	: FLASH_intrface.h                        	                             							                  *
* ! Description : This file has the Definitions needed		         		        							                      *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL	                  						                                         							  *
**************************************************************************************************************************************/

#ifndef MCAL_10_FLASH_FLASH_INTERFACE_H_
#define MCAL_10_FLASH_FLASH_INTERFACE_H_

/*************************************************************************************************************************************/
/***************************************************** Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MFLASH_voidAreaErase																				              *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Erase app area of flash									                                          *
**************************************************************************************************************************************/
void MFLASH_voidAreaErase(void);
/**************************************************************************************************************************************
* Function Name		: MFLASH_voidPageErase																				              *
* Parameters (in)	: Page number																						              *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Erase Selected page of flash									                                      *
**************************************************************************************************************************************/
void MFLASH_voidPageErase(uint8 Copy_uint8PageNum );
/**************************************************************************************************************************************
* Function Name		: MFLASH_voidWrite																				                  *
* Parameters (in)	: Adress to write on, data, length 									                                              *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Write on flash								                                                      *
**************************************************************************************************************************************/
void MFLASH_voidWrite(uint32 Copy_uint32Address, uint16 * Copy_uint16Data, uint8 Copy_uint8Length);


#endif /* MCAL_10_FLASH_FLASH_INTERFACE_H_ */
