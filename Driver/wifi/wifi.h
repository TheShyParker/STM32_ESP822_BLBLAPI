/**
  ******************************************************************************
  * @file    wifi.h
	* @author	 author
  * @version V1.0
  * @date    20xx-xx-xx
  * @brief   ����˵��
  ******************************************************************************
  * @attention ע��/��ע����
  *
  *
  ******************************************************************************
  */ 
	
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _wifi_H
#define _wifi_H

/* Includes ------------------------------------------------------------------*/

#include "string.h"
#include <stdio.h>
#include "sys.h"

/* Define  ------------------------------------------------------------------*/
typedef struct
{
	char *fans;
	char *view;
	char *bv;
}_BLBLAPI;
typedef struct
{
	char *fans;
	char *view;
}_BLBLOrder;
typedef struct
{
	char fans[12];
	char view[12];
}_BLBLValue;

typedef struct
{
	unsigned char get; //0x00 | 0000 0000 
							//0bit:��λ��1 ��ȡup��˿�����ܲ�����
							//����λ ��ȡ����API ���������
	char uid[12]; //up uid
	char bv[12]; 
	_BLBLAPI   api;
	_BLBLOrder order;
	_BLBLValue value;
}_BLBL;
extern _BLBL BLBL;
extern uint8_t msgfre;


/** @defgroup ģ�鶨��/��������
  * @{
  */

/**  wifi_Exported_Functions ---------------------------------------------------*/


char * MatchOrder(char *str,char *order);
char* strstri(char * inBuffer, char * inSearchStr);
void get_wifi(void);
void wifi_Init(void);
void send_message(void);

u8 AT_SetWifi(u8 error);
u8 AT_Return(char *str);
_bool AT_RST(u8 mode);
u8 AT_BlblConnect(u8 error);
void BlblConnect(void);
void While_Setwifi(void);
#endif /*__wifi_H */
