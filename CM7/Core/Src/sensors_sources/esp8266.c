/*
 * esp8266.c
 *
 *  Created on: 3 Sep 2020
 *      Author: piotrcieslik
 */


#include "sensors_headers/esp8266.h"

char* esp8266_init(UART_HandleTypeDef* usart, uint8_t* mode, char*response, char* message){
	char *fault;
	response = (char*)realloc(response, 2*sizeof(char));
	message = (char*)realloc(message, 16*sizeof(char));
	fault = (char*)malloc(16*sizeof(char));
	uint8_t timeout = 0;
	for (int i=0; i<4; i++){
		switch(i){
		case 0:
			sprintf(message,"%s", &AT);
			sprintf(fault,"%s","NO RESPONSE");
		case 1:
			sprintf(message,"%s",&RST);
			sprintf(fault,"%s","ERROR RESETING");
		case 2:
			sprintf(message, "%s%u", &MODE, *mode);
			sprintf(fault,"%s","ERROR MODE");
		case 3:
			sprintf(message, "%s%s", &MULT_CON, "1");
			sprintf(fault,"%s","ERROR MULTICONN");
		}
		timeout = 0;
		while(strcmp(response, "OK") && timeout<1000){
			HAL_UART_Transmit(usart, (uint8_t*)message, sizeof(message), 1000);
			HAL_UART_Receive(usart, (uint8_t*)response, 2, 1000);
			timeout++;
		}
		if (timeout>=999){
			return fault;
		}
	}
	return response;
}
char* esp8266_join_network(UART_HandleTypeDef* usart, char* ssid, char* password, char*response, char* message){
	uint8_t timeout = 0, mode_station = 1;
	while(!strcmp(esp8266_init(usart, &mode_station, response, message),"OK") && timeout<1000);
	if(timeout>=999){
		return "NO RESPONSE";
	}
	response = (char*)realloc(response, 2*sizeof(char));
	message = (char*)realloc(message, 16*sizeof(char));
	sprintf(message, "%s%s%s%s", &JOIN_AP, ssid, ",", password);
	while(!strcmp(response, "OK") && timeout<1000){
		HAL_UART_Transmit(usart, (uint8_t*)message, sizeof(message), 1000);
		HAL_UART_Receive(usart, (uint8_t*)response, 2, 1000);
		timeout++;
	}
	if (timeout>=999){
		return "CONNECTION FAILED";
	}
	return response;
}

char* esp8266_create_network(UART_HandleTypeDef* usart, char* network_name, char* password, uint8_t* port_number, uint8_t* security, char* response, char* message){

}
char* esp8266_join_tcp(UART_HandleTypeDef* usart, uint8_t* channel, char* master_ip_address, uint8_t* master_port, char*response, char* message);
char* esp8266_create_tcp(UART_HandleTypeDef* usart, uint8_t* port, char* ip_address, char* response, char* message);
char* esp8266_send_message(UART_HandleTypeDef* usart, uint8_t* channel, char*response, char* message);
char* esp8266_listen_message(UART_HandleTypeDef* usart, uint8_t* channel, char*response, char* message);
