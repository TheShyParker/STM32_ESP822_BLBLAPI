#include "allincludes.h"

u8 key_state = 0; 
//������ʼ������
void KEY_Init(void) //IO��ʼ��
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB,ENABLE);//ʹ��PORTA,PORTEʱ��

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_3;//KEY0-KEY2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOE2,3,4

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������  
	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOA.0

}
//����������
//���ذ���ֵ
//mode:0,��֧��������;1,֧��������;
//0��û���κΰ�������
//1��KEY1����
//2��KEY2����

//ע��˺�������Ӧ���ȼ�,KEY0>KEY1>KEY2>KEY3!!
u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//�������ɿ���־
	if(mode)key_up=1;  //֧������	
	if(key_up&&(KEY1==0||KEY2==0))
	{
		delay_ms(10);//ȥ���� 
		key_state++;
		//if(state==0){state++;return 0;}
		key_up=0;
		if(KEY1==0)return KEY1_PRES;
		else if(KEY2==0)return KEY2_PRES;
	}else if(KEY1==1&&KEY2==1){key_up=1;key_state=0;}	    
 	return 0;// �ް�������
}

u8 get_key(void)
{
	u8 flash = 0;
	if(key_state>=10)
	{
			AT_RST(1);
			While_Setwifi();
			OLED_CLS();
			OLED_Show((_OLED){16,2,2},"Waiting for WiFi link");
			while(1)
			{
				
				if(AT_Return("GOT")) {OLED_Show((_OLED){88,6,2},"TRUE ");break;}
				else{OLED_Show((_OLED){88,6,2},"FALSE");}
				if(systemtime.msec1000flag == 1)//1s
				{
					systemtime.msec1000flag = 0;
					ESP8266_SendTime++;
					PBout(12) = flash;
					flash=!flash;
					if(ESP8266_SendTime==10) 
					{
						AT_RST(1);
						ESP8266_SendTime = 0;
					}
				}
			}
			BlblConnect();
			ESP8266_SendTime = 5;
			ImgInit();
			return 1;
	}
	return 0;
}
