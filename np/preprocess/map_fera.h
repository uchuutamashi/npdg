inline void MapFERA(npEvent_t &event)
{
    // access global buffer
    extern Int_t a[44];

    // ADC correspondance
    event.ADC_AT_A_T= a[3];
    event.ADC_AT_A_B= a[2];
    event.ADC_AT_B_T= a[5];
    event.ADC_AT_B_B= a[4];
    event.ADC_BGO_L_F= a[6];
    event.ADC_BGO_L_B= a[7];
    event.ADC_BGO_M= a[11];
    event.ADC_BGO_S_T= a[8];
    event.ADC_BGO_S_B= a[10];
    event.ADC_ND_S= a[12];
    event.ADC_ND_L= a[13];
    event.ADC_AT_B_T_D= a[15];
    event.ADC_AT_B_B_D= a[14];

    event.TDC_AT_A= a[17];
    event.TDC_AT_B= a[18];
    event.TDC_BGO_L_F= a[19];
    event.TDC_BGO_L_B= a[20];
    event.TDC_BGO_M= a[23];
    event.TDC_BGO_S_T= a[21];
    event.TDC_BGO_S_B= a[22];
    event.TDC_PAT= a[16];
    event.TDC_PBGO= a[24];
    event.TDC_AT_BGO= a[25];
    event.TDC_PND= a[26];
    event.TDC_ND= a[27];
    event.TDC_ND_D= a[28];
    event.TDC_AT_ND= a[29];
    event.TDC_Beam0= a[30];
    event.TDC_Beam1= a[31];

    event.Scal_AT_A= a[32];     //skip unused TDCs
    event.Scal_AT_B= a[33];
    event.Scal_BGO_L_F= a[34];
    event.Scal_BGO_L_B= a[35];
    event.Scal_BGO_M= a[38];
    event.Scal_BGO_S_T= a[36];
    event.Scal_BGO_S_B= a[37];
    event.Scal_ND = a[41];
    event.Scal_Monitor= a[39];
    event.Scal_CLK= a[42];
    event.Scal_CLK_V= a[43];
    event.Scal_Charge= a[40];
}
