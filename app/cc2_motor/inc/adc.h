// Define to prevent recursive inclusion  --------------------------------------
#ifndef __ADC_H
#define __ADC_H

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Example_Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @defgroup EXAMPLE_MOTOR
/// @brief MOTOR example modules
/// @{


////////////////////////////////////////////////////////////////////////////////
/// @defgroup MOTOR_Exported_Variables
/// @{
#ifdef _ADC_C_
#define GLOBAL
#else
#define GLOBAL extern
#endif


#undef GLOBAL
/// @}

////////////////////////////////////////////////////////////////////////////////
/// @defgroup MOTOR_Exported_Functions
/// @{

void adcTick();
void initADC();


/// @}


/// @}

/// @}

////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////