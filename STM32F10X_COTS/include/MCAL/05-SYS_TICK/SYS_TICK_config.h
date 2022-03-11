/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						28 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: SYS_TICK Driver                                     							                                      *
* ! File Name	: SYS_TICK_config.h                                                      							                  *
* ! Description : This file has the Configrations needed		     		        	 						                      *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef SYS_TICK_CONFIG_H
#define SYS_TICK_CONFIG_H

/**************************************************************************************************************************************
* MACRO		: 	To Enable Or Disable Interrupt																		         		  *
* options	:	ENABLE		/	 DISABLE		/																					  *
**************************************************************************************************************************************/
#define SYS_TICK_INT_ENABLE				ENABLE
/**************************************************************************************************************************************
* MACRO		: 	To Configure Sys_Tick Prescaller																	         		  *
* options	:	AHB			/	 CLK_AHB_DIVIDE_8		/																			  *
**************************************************************************************************************************************/
#define SYS_TICK_PRESCALLER				CLK_AHB_DIVIDE_8




#endif /*SYS_TICK_CONFIG_H*/  
