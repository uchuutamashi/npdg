#ifndef NP_DEFQTYH
#define NP_DEFQTYH
#include <math.h>

Float_t E_AT_A;
Float_t E_AT_B;

Float_t E_BGO_ST;
Float_t E_BGO_SB;
Float_t E_BGO_M;
Float_t E_BGO_LF;
Float_t E_BGO_LB;

inline void updateQty(){
  extern npEvent_t event;
  E_AT_A=(0.1394*sqrt((event.ADC_AT_A_T-65)*(event.ADC_AT_A_B-77)));
  E_AT_B=(0.1515*sqrt((event.ADC_AT_B_T-64)*(event.ADC_AT_B_B-62)));

  E_BGO_ST=(3.8199*(event.ADC_BGO_S_T-78));
  E_BGO_SB=(3.4566*(event.ADC_BGO_S_B-67));
  E_BGO_M=(3.27217*(event.ADC_BGO_M-50));
  E_BGO_LF=(4.32*(event.ADC_BGO_L_F-60));
  E_BGO_LB=(3.78307*(event.ADC_BGO_L_B-59));
}
#endif
