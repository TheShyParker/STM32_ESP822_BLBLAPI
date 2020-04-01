/**
  ******************************************************************************
  * @file    led.c
  * @author  author
  * @version V1.0.0
  * @date    2018-8-25
  * @brief   led function.
  ******************************************************************************
  * @attention
  *
	*		There is no
  * 
  ******************************************************************************
* */

/* Includes ------------------------------------------------------------------*/
#include "led.h"
#include "../allincludes.h"


/* Define ------------------------------------------------------------------*/

u8 test = 0;


/** Exported_Functions		*/

/** @defgroup void LED_Init(void)��������
							void Infrared_Init(void)
  * @{
  */

/**
  * @brief  LED�˿ڳ�ʼ��        
  * @param  none
	* @return none
  * @retval none
  */
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStr;//GPIO_Init���� �ڶ���������ṹ��
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA,ENABLE);//ʼ��ʱ��GPIOA,B
	
	
	GPIO_InitStr.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStr.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStr.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStr);  
	GPIO_SetBits(GPIOB,GPIO_Pin_12);	
	
	GPIO_InitStr.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStr.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStr.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStr);  //��ʼ��GPIOA
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);	//��ʼ��GPIOA Pin0�ߵ�ƽ
}


