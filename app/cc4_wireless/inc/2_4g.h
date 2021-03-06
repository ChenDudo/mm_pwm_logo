////////////////////////////////////////////////////////////////////////////////
/// @file     2_4G.H
/// @author   YQ Liu
/// @version  v2.0.0
/// @date     2019-02-18
/// @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE 2.4GHZ
///           EXAMPLES.
////////////////////////////////////////////////////////////////////////////////
/// @attention
///
/// THE EXISTING FIRMWARE IS ONLY FOR REFERENCE, WHICH IS DESIGNED TO PROVIDE
/// CUSTOMERS WITH CODING INFORMATION ABOUT THEIR PRODUCTS SO THEY CAN SAVE
/// TIME. THEREFORE, MINDMOTION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR
/// CONSEQUENTIAL DAMAGES ABOUT ANY CLAIMS ARISING OUT OF THE CONTENT OF SUCH
/// HARDWARE AND/OR THE USE OF THE CODING INFORMATION CONTAINED HEREIN IN
/// CONNECTION WITH PRODUCTS MADE BY CUSTOMERS.
///
/// <H2><CENTER>&COPY; COPYRIGHT 2018-2019 MINDMOTION </CENTER></H2>
////////////////////////////////////////////////////////////////////////////////

// Define to prevent recursive inclusion  --------------------------------------
#ifndef __2_4G_H
#define __2_4G_H

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Example_Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @defgroup EXAMPLE_2.4GHZ
/// @brief BLE example modules
/// @{


////////////////////////////////////////////////////////////////////////////////
/// @defgroup 2.4GHZ_Exported_Constants
/// @{

/// @}


////////////////////////////////////////////////////////////////////////////////
/// @defgroup 2.4GHZ_Exported_Variables
/// @{
#ifdef _2_4G_C_
#define GLOBAL


#else
#define GLOBAL extern
#endif

GLOBAL u32 counter;

#undef GLOBAL

/// @}

////////////////////////////////////////////////////////////////////////////////
/// @defgroup 2.4GHZ_Exported_Functions
/// @{

void wl_2_4g_mode();

void wl_2_4g_tick_task();
void wl_2_4g_task();

/// @}

/// @}

/// @}

////////////////////////////////////////////////////////////////////////////////
#endif /* 2_4G_H */
////////////////////////////////////////////////////////////////////////////////
