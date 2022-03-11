/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						04 MAR,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: WIFI Driver   			                                                 							              *                     
* ! File Name	: WIFI_intrface.h                        	                             							                  *
* ! Description : This file has the Definitions needed		         		        							                      *
* ! Compiler  	: GNU ARM cross Compiler                                            							                      *
* ! Target 	  	: STM32F103 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL	                  						                                         							  *
**************************************************************************************************************************************/
#ifndef WIFI_INTERFACE_H
#define WIFI_INTERFACE_H

/*************************************************************************************************************************************/
/***************************************************** Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: HWIFI_VoidInit																				                  *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Initialize All Config of the wifi module										                      *
**************************************************************************************************************************************/
void HWIFI_voidInit();
/**************************************************************************************************************************************
* Function Name		: HWIFI_voidConnectToWifi																		                  *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Connect to the router															                      *
**************************************************************************************************************************************/
void HWIFI_voidConnectToWifi();
/**************************************************************************************************************************************
* Function Name		: HWIFI_voidConnectToServer																				          *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Connect to server																                      *
**************************************************************************************************************************************/
void HWIFI_voidConnectToServer();
/**************************************************************************************************************************************
* Function Name		: HWIFI_VoidInit																				                  *
* Parameters (in)	: Copy_uint8ServerLink, Copy_uint8DataLenght				     							                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Send Http Request																                      *
**************************************************************************************************************************************/
void HWIFI_VoidSendHttpRequest(uint8 * Copy_uint8ServerLink, uint8 * Copy_uint8DataLenght);
/**************************************************************************************************************************************
* Function Name		: HWIFI_VoidReceiveRecord																		                  *
* Parameters (in)	: Copy_uint8NetData[]																		                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Recieve Extract the Data from the Record										                      *
**************************************************************************************************************************************/
void HWIFI_VoidReceiveRecord(uint8 Copy_uint8NetData[]);
/**************************************************************************************************************************************
* Function Name		: MUART_ReceiveCBK_Func																			                  *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function UART CallBack																	                      *
**************************************************************************************************************************************/
void MUART_ReceiveCBK_Func();


#endif /*WIFI_INTERFACE_H*/
