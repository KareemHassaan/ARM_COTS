/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						13 FEB,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: UART Driver                                                        							                      *
* ! File Name	: UART_program.c                                                       							                      *
* ! Description : This file has the implementation of Basic of UART functions        							                      *
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
#include"../../include/MCAL/09-UART/UART_interface.h"  
#include"../../include/MCAL/09-UART/UART_private.h"
#include"../../include/MCAL/09-UART/UART_config.h"

/***************************************************** Global Variables **************************************************************/

/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MUART_voidInit																			                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Iniit UART Configrations	 					          					  						  *
**************************************************************************************************************************************/
void MUART_voidInit()
{ 
	/*Select BaudRate*/
	UART1 -> USART_BRR = BRR_VALUE;
	
	UART1 -> USART_CR1 = (USART_ENABLE								 << UE_BIT)| 													
	                     (WORD_LENGTH                                << M_BIT)|	
	                     (WAKEUP_METHOD                              << WAKE_BIT)| 	
	                     (PARITY_CONTROL_ENABLE                      << PCE_BIT)|		
	                     (PARITY_SELECTION                           << PS_BIT)|	
	                     (PE_INTERRUPT_ENABLE                        << PEIE_BIT)|	
	                     (TXE_INTERRUPT_ENABLE                       << TXEIE_BIT)|	
	                     (TRANSMISSION_COMPLETE_INTERRUPT_ENABLE     << TCIE_BIT)| 	
	                     (RXNE_INTERRUPT_ENABLE                      << RXNEIE_BIT)| 	
	                     (IDLE_INTERRUPT_ENABLE                      << IDLEIE_BIT)| 	
	                     (TRANSMITTER_ENABLE                         << TE_BIT)|		
	                     (RECEIVER_ENABLE                            << RE_BIT)| 		
	                     (RECEIVER_WAKEUP                            << RWU_BIT)|		
	                     (SEND_BREAK 								 << SBK_BIT);
						 
	UART1 -> USART_CR2 = (STOP_BITS_NUM								 << STOP_BIT)| 													
	                     (CLOCK_ENABLE                               << CLKEN_BIT)|	
	                     (CLOCK_POLARITY                             << CPOL_BIT)| 	
	                     (CLOCK_PHASE                      			 << CPHA_BIT);	
}

/**************************************************************************************************************************************
* Function Name		: MUART_voidSendByte																		                      *
* Parameters (in)	: uint8 Copy_uint8Data																			                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Send a Byte	 								          					  						  *
**************************************************************************************************************************************/
void MUART_voidSendByte(uint8 Copy_uint8Data)
{
	UART1 ->  USART_DR = Copy_uint8Data;
	
	while(GET_BIT(UART1 ->  USART_SR, USART_TC) == 0)
	{
		/*Busy Waiting For Sending Message*/
	}
	
	CLR_BIT(UART1 -> USART_SR, USART_TC);
}

/**************************************************************************************************************************************
* Function Name		: MUART_voidReceiveByte																		                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: uint8							  															    	              *
* Description		: Function To Receive a Byte	 							          					  						  *
**************************************************************************************************************************************/
uint8 MUART_voidReceiveByte()
{
	while(GET_BIT(UART1 ->  USART_SR, USART_RXNE) == 0)
	{
		/*Busy Waiting For Receiving Message*/
	}
	
	return UART1 -> USART_DR;
}

/**************************************************************************************************************************************
* Function Name		: MUART_voidReceiveByte																		                      *
* Parameters (in)	: None																							                  *
* Parameters (out)	: None																						                      *
* Return value		: uint8							  															    	              *
* Description		: Function To Receive a Byte	 (Interrupt)							          					  		      *
**************************************************************************************************************************************/
uint8 MUART_voidReceiveByteAsync()
{
	/*Get Data from Data Register*/
	return  UART1 -> USART_DR;
}

/**************************************************************************************************************************************
* Function Name		: MUART_voidSendString																		                      *
* Parameters (in)	: char str[]																					                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Send a string				 					          					  						  *
**************************************************************************************************************************************/
void MUART_voidSendString(char str[])
{
	while(*str != '\0')
	{
		MUART_voidSendByte(*str);
		str++;
	}

}

/**************************************************************************************************************************************
* Function Name		: MUART_voidSendString																		                      *
* Parameters (in)	: char str[]																					                  *
* Parameters (out)	: None																						                      *
* Return value		: None							  															    	              *
* Description		: Function To Receive a string				 				          					  						  *
**************************************************************************************************************************************/
void MUART_voidReceiveString(char str[])
{
	while(*str != '\0')
	{
		MUART_voidReceiveByte(*str);
		str++;
	}
}

/**************************************************************************************************************************************
* Function Name		: MUART_voidSendString																		                      *
* Parameters (in)	: None																				                              *
* Parameters (out)	: void (*ptr) (void)																					          *
* Return value		: None							  															    	              *
* Description		: Function To call back function of user to exectue ISR				 				        					  *
**************************************************************************************************************************************/
void MUSART1_VidSetCallBack( void (*ptr) (void) )
{
	/*Set user funtion to global call back pointer to function*/
	MUSART1_CallBack = ptr ;

}
/*************************************************************************************************************************************/
/***************************************************** Interrupt Handler *************************************************************/
/*************************************************************************************************************************************/
void USART1_IRQHandler(void)
{
	/*execute user function if there is an interrupt occured*/
	MUSART1_CallBack();
	UART1 ->  USART_SR = 0;
}













