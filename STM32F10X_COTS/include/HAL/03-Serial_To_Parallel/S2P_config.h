/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						02 FEB,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: Serial To Parallel Driver                                							                                  *
* ! File Name	: S2P_config.h                                                      							                  	  *
* ! Description : This file has the Configrations needed		     		        	 						                      *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL	                  						                                         							  *
**************************************************************************************************************************************/
#ifndef S2P_CONFIG_H
#define S2P_CONFIG_H

/**************************************************************************************************************************************
* MACRO		: 	To Configure The Serial To Parallel Port															         		  *
* options	:	GPIO_PORTA		/		GPIO_PORTB		/		GPIO_PORTC		/													  *
**************************************************************************************************************************************/
#define S2P_PORT										GPIO_PORTA
/**************************************************************************************************************************************
* MACRO		: 	To Configure The Serial To Parallel OtuPut Pin Data													         		  *
* options	:	GPIO_PORTA	(PIN0 -> PIN15)		/		GPIO_PORTB	(PIN0 -> PIN15) 	/		GPIO_PORTC	(PIN13 -> PIN15) 	/	  *
**************************************************************************************************************************************/
#define S2P_SERIAL_OUTPUT_PIN							GPIO_PIN0
/**************************************************************************************************************************************
* MACRO		: 	To Configure The Serial To Parallel Clock Pin														         		  *
* options	:	GPIO_PORTA	(PIN0 -> PIN15)		/		GPIO_PORTB	(PIN0 -> PIN15) 	/		GPIO_PORTC	(PIN13 -> PIN15) 	/	  *
**************************************************************************************************************************************/
#define S2P_CLK_OUTPUT_PIN								GPIO_PIN1
/**************************************************************************************************************************************
* MACRO		: 	To Configure The Serial To Parallel Latch Pin														         		  *
* options	:	GPIO_PORTA	(PIN0 -> PIN15)		/		GPIO_PORTB	(PIN0 -> PIN15) 	/		GPIO_PORTC	(PIN13 -> PIN15) 	/	  *
**************************************************************************************************************************************/
#define S2P_LATCH_OUTPUT_PIN							GPIO_PIN2
/**************************************************************************************************************************************
* MACRO		: To Configure Number Of The Register Of The S2P														         		  *
* options	:																														  *
**************************************************************************************************************************************/
#define S2P_REGS_NUM									2
/**************************************************************************************************************************************
* MACRO		: To Configure Size Of The Register Of The S2P															         		  *
* options	:																														  *
**************************************************************************************************************************************/
#define S2P_REGS_SIZE									8
/**************************************************************************************************************************************
* MACRO		: To Configure Pulse Time																				         		  *
* options	: Number In Micro Sec																									  *
**************************************************************************************************************************************/
#define S2P_PULSE_TIME									10  
 
#endif /*S2P_CONFIG_H*/  
