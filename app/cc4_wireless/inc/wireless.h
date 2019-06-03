// Define to prevent recursive inclusion  --------------------------------------
#ifndef __WIRELESS_H
#define __WIRELESS_H

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Example_Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @defgroup EXAMPLE_WIRELESS
/// @brief WIRELESS example modules
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @defgroup BLE_SERVICE_Exported_Constants
/// @{

typedef enum {
    emWL_NULL,
    emWL_BLE,
    emWL_2_4G
} EM_WL_MODE;

/// @}

////////////////////////////////////////////////////////////////////////////////
/// @defgroup WIRELESS_Exported_Variables
/// @{
#ifdef _WIRELESS_C_
#define GLOBAL

#else
#define GLOBAL extern
#endif


GLOBAL EM_WL_MODE wl_mode;
GLOBAL EM_WL_MODE wl_last_mode;

#undef GLOBAL
/// @}

////////////////////////////////////////////////////////////////////////////////
/// @defgroup WIRELESS_Exported_Functions
/// @{

/// @}


/// @}

/// @}

////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////