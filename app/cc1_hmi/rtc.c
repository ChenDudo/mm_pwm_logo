////////////////////////////////////////////////////////////////////////////////
#define _RTC_C_
////////////////////////////////////////////////////////////////////////////////
#include <string.h>
#include "types.h"

#include "hal_nvic.h"
#include "hal_rtc.h"
#include "hal_bkp.h"
#include "hal_rcc.h"
#include "hal_pwr.h"

#include "datetime.h"
#include "rtc.h"

////////////////////////////////////////////////////////////////////////////////
void NVIC_RTC()
{
    NVIC_InitTypeDef NVIC_InitStructure;

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

    NVIC_InitStructure.NVIC_IRQChannel = RTC_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

////////////////////////////////////////////////////////////////////////////////
void RTC_IRQHandler(void)
{
    if (RTC_GetITStatus(RTC_IT_SEC) != RESET) {
        RTC_GetTime(&gtp);
    }
    if(RTC_GetITStatus(RTC_IT_ALR) != RESET) {
        RTC_ClearITPendingBit(RTC_IT_ALR);
    }
    RTC_ClearITPendingBit(RTC_IT_SEC);
    RTC_WaitForLastTask();
}

u16 fac_ms = 1000;
void delay_ms(u16 nms)
{	 		  	  
	u32 temp;		   
	SysTick->LOAD=(u32)nms*fac_ms;				//??????(SysTick->LOAD?24bit)
	SysTick->VAL =0x00;							//????????
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;	//???????  
	do
	{
		temp=SysTick->CTRL;
	}while((temp&0x01)&&!(temp&(1<<16)));		//????????   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;	//????????
	SysTick->VAL =0X00;       					//????????	  	    
}

////////////////////////////////////////////////////////////////////////////////
bool initRTC(void)
{
    u32 delay = 0;
    u8 temp = 0;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);
    PWR->CR |= PWR_CR_DBP;

    if (BKP_ReadBackupRegister(BKP_DR1) != 0x2019) {
        BKP_DeInit();
        RCC_LSEConfig(RCC_LSE_ON);
        while (!RCC_GetFlagStatus(RCC_FLAG_LSERDY)) {
            temp ++;
            delay_ms(10);
        };
        if(temp >= 249) return 1;
        RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
        RCC_RTCCLKCmd(ENABLE);
        BKP_WriteBackupRegister(BKP_DR1, 0x2019);
        RTC_WaitForSynchro();
        RTC_WaitForLastTask();
        RTC_SetPrescaler(32767);  ///< RTC period = RTCCLK/RTC_PR = (32.768 KHz)/(32767+1)
        RTC_WaitForLastTask();
    }
    else {
        RTC_WaitForSynchro();
        RTC_WaitForLastTask();
    }

    NVIC_RTC();
    RTC_ITConfig(RTC_IT_SEC, ENABLE);
    RTC_GetTime(&gtp);

    return 0; //ok
}

////////////////////////////////////////////////////////////////////////////////
