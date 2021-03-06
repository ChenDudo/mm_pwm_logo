// Define to prevent recursive inclusion  --------------------------------------
#define _SYNC_C_

// Includes  -------------------------------------------------------------------
#include <string.h>
#include "system_mm32.h"

#include "common.h"
#include "bsp.h"
#include "sync.h"
#include "hal_uart.h"
#include "hal_gpio.h"

////////////////////////////////////////////////////////////////////////////////
/// @brief  This function handles App SysTick Handler.
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void syncTick()
{
    if (!readSync()){
        syncFlag = true;
    }
    if (syncFlag){
        
        
    }
}

////////////////////////////////////////////////////////////////////////////////
void initSyncPin_Master()
{
    COMMON_EnableIpClock(emCLOCK_GPIOB);
    SYNC_H;
    GPIO_Mode_OUT_PP_Init(GPIOB, GPIO_Pin_8);
}

////////////////////////////////////////////////////////////////////////////////
void initSyncPin_Slave()
{
    COMMON_EnableIpClock(emCLOCK_GPIOB);
    
    GPIO_InitTypeDef 	GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
    
}

////////////////////////////////////////////////////////////////////////////////
bool readSync()
{
    return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8);
}
