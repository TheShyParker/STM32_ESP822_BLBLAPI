#ifndef __USART3_H
#define __USART3_H	 
#include "sys.h"  


#define USART3_REC_LEN  200  	//�����������ֽ��� 200
#define USART3_MAX_SEND_LEN		800					//����ͻ����ֽ���
extern u8  USART3_RX_BUF[USART3_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�
extern u8  USART3_TX_BUF[USART3_MAX_SEND_LEN]; 		//���ͻ���,���USART3_MAX_SEND_LEN�ֽ�
extern u16 USART3_RX_STA;         		//����״̬���	 0-14λΪ�����ֽ�����15λ������ɱ�־λ

void usart3_init(u32 pclk1,u32 bound);	//����3��ʼ�� 
void u3_printf(char* fmt,...);
#endif


