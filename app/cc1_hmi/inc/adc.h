////////////////////////////////////////////////////////////////////////////////
#ifndef __ADC_H
#define __ADC_H
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
#ifdef _ADC_C_
#define GLOBAL
#else
#define GLOBAL extern
#endif

GLOBAL u32  ADC1Value[2];
GLOBAL u32  adcTickCnt;
GLOBAL u32  adcVol;
GLOBAL u32  adcVolt;

#undef GLOBAL

////////////////////////////////////////////////////////////////////////////////
void initADC();
void adcTick();

////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////
