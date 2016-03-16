typedef struct {

  Int_t ADC_AT_A_T;
  Int_t ADC_AT_A_B;
  Int_t ADC_AT_B_T;
  Int_t ADC_AT_B_B;
  Int_t ADC_BGO_L_F;
  Int_t ADC_BGO_L_B;
  Int_t ADC_BGO_M;
  Int_t ADC_BGO_S_T;
  Int_t ADC_BGO_S_B;
  Int_t ADC_ND_S;
  Int_t ADC_ND_L;
  Int_t ADC_AT_B_T_D; // delayed AT 300ns
  Int_t ADC_AT_B_B_D; // delayed AT 300ns

  Int_t TDC_AT_A;
  Int_t TDC_AT_B;
  Int_t TDC_BGO_L_F;
  Int_t TDC_BGO_L_B;
  Int_t TDC_BGO_M;
  Int_t TDC_BGO_S_T;
  Int_t TDC_BGO_S_B;
  Int_t TDC_PAT;
  Int_t TDC_PBGO;
  Int_t TDC_AT_BGO;
  Int_t TDC_PND;
  Int_t TDC_ND;
  Int_t TDC_ND_D; // delayed ND 200ns
  Int_t TDC_AT_ND;
  Int_t TDC_Beam0;
  Int_t TDC_Beam1; // delayed beam 200ns

  Int_t Scal_AT_A;
  Int_t Scal_AT_B;
  Int_t Scal_BGO_L_F;
  Int_t Scal_BGO_L_B;
  Int_t Scal_BGO_M;
  Int_t Scal_BGO_S_T;
  Int_t Scal_BGO_S_B;
  Int_t Scal_ND;
  Int_t Scal_CLK;
  Int_t Scal_CLK_V;
  Int_t Scal_Charge;
  Int_t Scal_Monitor;

} npEvent_t;
