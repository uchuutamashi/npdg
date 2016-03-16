#include "np_event.h"

void LoadTree(TString rootFile, TTree* tree)
{
    //access global buffer
    extern npEvent_t event;

    //unload to buffer
    tree->GetBranch("ADC_AT_A_T")->SetAddress(&event.ADC_AT_A_T);
    tree->GetBranch("ADC_AT_A_B")->SetAddress(&event.ADC_AT_A_B);
    tree->GetBranch("ADC_AT_B_T")->SetAddress(&event.ADC_AT_B_T);
    tree->GetBranch("ADC_AT_B_B")->SetAddress(&event.ADC_AT_B_B);
    tree->GetBranch("ADC_AT_B_T_D")->SetAddress(&event.ADC_AT_B_T_D);
    tree->GetBranch("ADC_AT_B_B_D")->SetAddress(&event.ADC_AT_B_B_D);

    tree->GetBranch("ADC_BGO_L_F")->SetAddress(&event.ADC_BGO_L_F);
    tree->GetBranch("ADC_BGO_L_B")->SetAddress(&event.ADC_BGO_L_B);
    tree->GetBranch("ADC_BGO_M")->SetAddress(&event.ADC_BGO_M);
    tree->GetBranch("ADC_BGO_S_T")->SetAddress(&event.ADC_BGO_S_T);
    tree->GetBranch("ADC_BGO_S_B")->SetAddress(&event.ADC_BGO_S_B);

    tree->GetBranch("ADC_ND_S")->SetAddress(&event.ADC_ND_S);
    tree->GetBranch("ADC_ND_L")->SetAddress(&event.ADC_ND_L);

    tree->GetBranch("TDC_AT_A")->SetAddress(&event.TDC_AT_A);
    tree->GetBranch("TDC_AT_B")->SetAddress(&event.TDC_AT_B);
    tree->GetBranch("TDC_BGO_L_F")->SetAddress(&event.TDC_BGO_L_F);
    tree->GetBranch("TDC_BGO_L_B")->SetAddress(&event.TDC_BGO_L_B);
    tree->GetBranch("TDC_BGO_M")->SetAddress(&event.TDC_BGO_M);
    tree->GetBranch("TDC_BGO_S_T")->SetAddress(&event.TDC_BGO_S_T);
    tree->GetBranch("TDC_BGO_S_B")->SetAddress(&event.TDC_BGO_S_B);

    tree->GetBranch("TDC_PAT")->SetAddress(&event.TDC_PAT);
    tree->GetBranch("TDC_PBGO")->SetAddress(&event.TDC_PBGO);
    tree->GetBranch("TDC_PND")->SetAddress(&event.TDC_PND);
    tree->GetBranch("TDC_AT_BGO")->SetAddress(&event.TDC_AT_BGO);
    tree->GetBranch("TDC_ND")->SetAddress(&event.TDC_ND);
    tree->GetBranch("TDC_ND_D")->SetAddress(&event.TDC_ND_D);
    tree->GetBranch("TDC_AT_ND")->SetAddress(&event.TDC_AT_ND);
    tree->GetBranch("TDC_Beam0")->SetAddress(&event.TDC_Beam0);
    tree->GetBranch("TDC_Beam1")->SetAddress(&event.TDC_Beam1);

    tree->GetBranch("Scal_AT_A")->SetAddress(&event.Scal_AT_A);
    tree->GetBranch("Scal_AT_B")->SetAddress(&event.Scal_AT_B);
    tree->GetBranch("Scal_BGO_L_F")->SetAddress(&event.Scal_BGO_L_F);
    tree->GetBranch("Scal_BGO_L_B")->SetAddress(&event.Scal_BGO_L_B);
    tree->GetBranch("Scal_BGO_M")->SetAddress(&event.Scal_BGO_M);
    tree->GetBranch("Scal_BGO_S_T")->SetAddress(&event.Scal_BGO_S_T);
    tree->GetBranch("Scal_BGO_S_B")->SetAddress(&event.Scal_BGO_S_B);
    tree->GetBranch("Scal_ND")->SetAddress(&event.Scal_ND);
    tree->GetBranch("Scal_Monitor")->SetAddress(&event.Scal_Monitor);
    tree->GetBranch("Scal_CLK")->SetAddress(&event.Scal_CLK);
    tree->GetBranch("Scal_CLK_V")->SetAddress(&event.Scal_CLK_V);
    tree->GetBranch("Scal_Charge")->SetAddress(&event.Scal_Charge);
}
