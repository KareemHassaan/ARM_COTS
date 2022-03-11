/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						04 MAR,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: WIFI Driver	    		                                                							              *
* ! File Name	: WIFI_private.h                                   		                  							                  *
* ! Description : This file has the Private definitions needed				       							                          *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL                  						                                         							      *
**************************************************************************************************************************************/
#ifndef WIFI_PRIVATE_H
#define WIFI_PRIVATE_H


#define OK 										1
#define NOT_OK 									0

#define WIFI_CONNECT_CMD_P1 					"AT+CWJAP=\""
#define WIFI_CONNECT_CMD_P2 					"\",\""
#define WIFI_CONNECT_CMD_P3			 			"\"\r\n"

#define SERVER_CONNECT_CMD_P1 					"AT+CIPSTART=\"TCP\",\""
#define SERVER_CONNECT_CMD_P2 					"\","
#define SERVER_CONNECT_CMD_P3 					"\r\n"

#define HTTP_REQUEST_SEND_CMD_P1 				"AT+CIPSEND="
#define HTTP_REQUEST_SEND_CMD_P2 				"\r\n"

/*************************************************************************************************************************************/
/********************************************** Static Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: HWIFI_CommandValidation																		                  *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Validate the Sent Command                 									                      *
**************************************************************************************************************************************/
static uint8 HWIFI_CommandValidation();
/**************************************************************************************************************************************
* Function Name		: HWIFI_CLearDataBuffer																			                  *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Clear the Global Buffer of Received Data  									                      *
**************************************************************************************************************************************/
static void HWIFI_CLearDataBuffer();

#endif /*WIFI_PRIVATE_H*/
