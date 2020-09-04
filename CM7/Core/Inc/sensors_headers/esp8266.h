/*
 * esp8266.h
 *
 *  Created on: 2 Sep 2020
 *      Author: piotrcieslik
 */

#ifndef INC_SENSORS_HEADERS_ESP8266_H_
#define INC_SENSORS_HEADERS_ESP8266_H_

#include "stm32h7xx_hal.h"
#include "gpio.h"
#include "usart.h"
#include "string.h"
//ESP8266 commands


static const char AT = 'AT';
static const char RST = 'AT+RST';
static const char FRIMWARE = 'AT+GMR';
static const char MODE = 'AT+CWMODE=';
static const char LIST_AP = 'AT+CWLAP';
static const char JOIN_AP = 'AT+CWJAP=';
static const char QUIT_AP = 'AT+CWQAP';
static const char GET_IP = 'AT+CIFSR';
static const char MULT_CON = 'AT+CIPMUX=';
static const char IP_START = 'AT+CIPSTART=';
static const char SEND_DATA = 'AT+CIPSEND=';
static const char STATUS = 'AT+CIPSTATUS';
static const char SERVER = 'AT+CIPSERVER=';
static const char NETWORK = 'AT+CWSAP=';
static const char GEN_IP_CLIENT = 'AT+CIPSTA=';
static const char GEN_IP_ROUTER = 'AT+CIPAP=';

char* esp8266_init(UART_HandleTypeDef* usart, uint8_t* mode, char*response, char* message);
char* esp8266_join_network(UART_HandleTypeDef* usart, char* ssid, char* password, char*response, char* message);
char* esp8266_create_network(UART_HandleTypeDef* usart, char* network_name, char* password, uint8_t* port_number, uint8_t* security, char* response, char* message);
char* esp8266_join_tcp(UART_HandleTypeDef* usart, uint8_t* channel, char* master_ip_address, uint8_t* master_port, char*response, char* message);
char* esp8266_create_tcp(UART_HandleTypeDef* usart, uint8_t* port, char* ip_address, char* response, char* message);
char* esp8266_send_message(UART_HandleTypeDef* usart, uint8_t* channel, char*response, char* message);
char* esp8266_listen_message(UART_HandleTypeDef* usart, uint8_t* channel, char*response, char* message);

#endif /* INC_SENSORS_HEADERS_ESP8266_H_ */
