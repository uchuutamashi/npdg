/* =============================================================================
Definitions of histograms.
1. Declaration of histograms are contained in initHisto()
2. Instructions for filling in the histograms are contained in FillHisto()

Changelog:
02.20.2016 Created (To Chin Yu)
============================================================================= */

#include "TH1F.h"
#include "TH2F.h"
#include "defs_cuts.h"

TH1F *hE_AT_A;      // AT A engery
TH1F *hE_AT_B;      // AT B engery
TH1F *hE_BGO_ST;    // BGO ST engery
TH1F *hE_BGO_SB;    // BGO SB engery
TH1F *hE_BGO_M;     // BGO M engery
TH1F *hE_BGO_LF;    // BGO LF engery
TH1F *hE_BGO_LB;    // BGO_LB engery

TH1F *hBeam0;
TH1F *hBeam0_A;       // TDC Beam 0. AT A coin BGO-ALL
TH1F *hBeam0_A1;       // TDC Beam 0. AT A coin BGO-ALL , shifted kinematics
TH1F *hBeam0_A2;       // TDC Beam 0. AT A coin BGO-ALL , shifted kinematics
TH1F *hBeam0_AcST;  // TDC Beam 0, AT A coincident with BGO-ST
TH1F *hBeam0_AcSB;  // TDC Beam 0, AT A coincident with BGO-SB
TH1F *hBeam0_AcM;  // TDC Beam 0, AT A coincident with BGO-M
TH1F *hBeam0_AcLF;  // TDC Beam 0, AT A coincident with BGO-LF
TH1F *hBeam0_AcLB;  // TDC Beam 0, AT A coincident with BGO-LB
TH1F *hBeam0_AcST1;  // TDC Beam 0, AT A coincident with BGO-ST, shifted kinematics
TH1F *hBeam0_AcSB1;  // TDC Beam 0, AT A coincident with BGO-SB, shifted kinematics
TH1F *hBeam0_AcM1;  // TDC Beam 0, AT A coincident with BGO-M, shifted kinematics
TH1F *hBeam0_AcLF1;  // TDC Beam 0, AT A coincident with BGO-LF, shifted kinematics
TH1F *hBeam0_AcLB1;  // TDC Beam 0, AT A coincident with BGO-LB, shifted kinematics
TH1F *hBeam0_AcST2;  // TDC Beam 0, AT A coincident with BGO-ST, shifted kinematics
TH1F *hBeam0_AcSB2;  // TDC Beam 0, AT A coincident with BGO-SB, shifted kinematics
TH1F *hBeam0_AcM2;  // TDC Beam 0, AT A coincident with BGO-M, shifted kinematics
TH1F *hBeam0_AcLF2;  // TDC Beam 0, AT A coincident with BGO-LF, shifted kinematics
TH1F *hBeam0_AcLB2;  // TDC Beam 0, AT A coincident with BGO-LB, shifted kinematics

TH1F *hBeam0_B;       // TDC Beam 0. AT A coin BGO-ALL
TH1F *hBeam0_B1;       // TDC Beam 0. AT A coin BGO-ALL , shifted kinematics
TH1F *hBeam0_B2;       // TDC Beam 0. AT A coin BGO-ALL , shifted kinematics


TH2F *hE_AST; //AT BGO Energy
TH2F *hE_ASB; //AT BGO Energy
TH2F *hE_AM; //AT BGO Energy
TH2F *hE_ALF; //AT BGO Energy
TH2F *hE_ALB; //AT BGO Energy

TH2F *hE_AST1; //AT BGO Energy, shifted ToF
TH2F *hE_ASB1; //AT BGO Energy, shifted ToF
TH2F *hE_AM1; //AT BGO Energy, shifted ToF
TH2F *hE_ALF1; //AT BGO Energy, shifted ToF
TH2F *hE_ALB1; //AT BGO Energy,shifted ToF

TH1F *hBeam0_BcBGO;  // TDC Beam 0, AT A coincident with BGOs
TH2F *hEATEBGO; //AT BGO Energy

//declare histograms
inline void initHisto(){
  hE_AT_A = new TH1F("hEATA","Energy AT_A / All", 150, 0, 300);
  hE_AT_A->GetXaxis()->SetTitle("Energy / keVee");

  hE_AT_B = new TH1F("hEATB","Energy AT_B / All", 150, 0, 300);
  hE_AT_B->GetXaxis()->SetTitle("Energy / keVee");

  hBeam0 = new TH1F("hBeam0", "Beam TDC / ATcBGO + AT_A",100,0,800);
  hBeam0->GetXaxis()->SetTitle("TDC Channel");

  hBeam0_A = new TH1F("hBeam0_A", "Beam TDC / ATcBGO + AT_A + E-expected ",100,0,800);
  hBeam0_A->GetXaxis()->SetTitle("TDC Channel");

  hBeam0_A1 = new TH1F("hBeam0_A1", "Beam TDC / ATcBGO + AT_A + E-BGO Shifted",100,0,800);
  hBeam0_A1->GetXaxis()->SetTitle("TDC Channel");

  hBeam0_A2 = new TH1F("hBeam0_A2", "Beam TDC / ATcBGO + AT_A + E-AT Shifted",100,0,800);
  hBeam0_A2->GetXaxis()->SetTitle("TDC Channel");

  hBeam0_B = new TH1F("hBeam0_B", "Beam TDC / ATcBGO + AT_B + E-expected ",100,0,800);
  hBeam0_B->GetXaxis()->SetTitle("TDC Channel");

  hBeam0_B1 = new TH1F("hBeam0_B1", "Beam TDC / ATcBGO + AT_B + E-BGO Shifted",100,0,800);
  hBeam0_B1->GetXaxis()->SetTitle("TDC Channel");

  hBeam0_B2 = new TH1F("hBeam0_B2", "Beam TDC / ATcBGO + AT_B + E-AT Shifted",100,0,800);
  hBeam0_B2->GetXaxis()->SetTitle("TDC Channel");

  hBeam0_AcST = new TH1F("hBeam0AcST", "Beam TDC / ATcBGO + BGO_TOF(A,ST) + E",100,0,800);
  hBeam0_AcST->GetXaxis()->SetTitle("TDC Channel");

  hBeam0_AcSB = new TH1F("hBeam0AcSB", "Beam TDC / ATcBGO + BGO_TOF(A,SB) + E",100,0,800);
  hBeam0_AcSB->GetXaxis()->SetTitle("TDC Channel");

  hBeam0_AcM = new TH1F("hBeam0AcM", "Beam TDC / ATcBGO + BGO_TOF(A,M) + E",100,0,800);
  hBeam0_AcM->GetXaxis()->SetTitle("TDC Channel");

  hBeam0_AcLF = new TH1F("hBeam0AcLF", "Beam TDC / ATcBGO + BGO_TOF(A,LF) + E",100,0,800);
  hBeam0_AcLF->GetXaxis()->SetTitle("TDC Channel");

  hBeam0_AcLB = new TH1F("hBeam0AcLB", "Beam TDC / ATcBGO + BGO_TOF(A,LB) + E",100,0,800);
  hBeam0_AcLB->GetXaxis()->SetTitle("TDC Channel");

  hBeam0_AcST1 = new TH1F("hBeam0AcST1", "Beam TDC / ATcBGO + BGO_TOF(A,ST) + E-BGO Shifted",100,0,800);
  hBeam0_AcST1->GetXaxis()->SetTitle("TDC Channel");

  hBeam0_AcSB1 = new TH1F("hBeam0AcSB1", "Beam TDC / ATcBGO + BGO_TOF(A,SB) + E-BGO Shifted",100,0,800);
  hBeam0_AcSB1->GetXaxis()->SetTitle("TDC Channel");

  hBeam0_AcM1 = new TH1F("hBeam0AcM1", "Beam TDC / ATcBGO + BGO_TOF(A,M) + E-BGO Shifted",100,0,800);
  hBeam0_AcM1->GetXaxis()->SetTitle("TDC Channel");

  hBeam0_AcLF1 = new TH1F("hBeam0AcLF1", "Beam TDC / ATcBGO + BGO_TOF(A,LF) + E-BGO Shifted",100,0,800);
  hBeam0_AcLF1->GetXaxis()->SetTitle("TDC Channel");

  hBeam0_AcLB1 = new TH1F("hBeam0AcLB1", "Beam TDC / ATcBGO + BGO_TOF(A,LB) + E-BGO Shifted",100,0,800);
  hBeam0_AcLB1->GetXaxis()->SetTitle("TDC Channel");

  hBeam0_AcST2 = new TH1F("hBeam0AcST2", "Beam TDC / ATcBGO + BGO_TOF(A,ST) + E-AT Shifted",100,0,800);
  hBeam0_AcST2->GetXaxis()->SetTitle("TDC Channel");

  hBeam0_AcSB2 = new TH1F("hBeam0AcSB2", "Beam TDC / ATcBGO + BGO_TOF(A,SB) + E-AT Shifted",100,0,800);
  hBeam0_AcSB2->GetXaxis()->SetTitle("TDC Channel");

  hBeam0_AcM2 = new TH1F("hBeam0AcM2", "Beam TDC / ATcBGO + BGO_TOF(A,M) + E-AT Shifted",100,0,800);
  hBeam0_AcM2->GetXaxis()->SetTitle("TDC Channel");

  hBeam0_AcLF2 = new TH1F("hBeam0AcLF2", "Beam TDC / ATcBGO + BGO_TOF(A,LF) + E-AT Shifted",100,0,800);
  hBeam0_AcLF2->GetXaxis()->SetTitle("TDC Channel");

  hBeam0_AcLB2 = new TH1F("hBeam0AcLB2", "Beam TDC / ATcBGO + BGO_TOF(A,LB) + E-AT Shifted",100,0,800);
  hBeam0_AcLB2->GetXaxis()->SetTitle("TDC Channel");

  hE_AST   = new TH2F("hEAST","E AT-A vs E BGO ST / $", 50,0,200,50,1000,4000);
  hE_AST->GetXaxis()->SetTitle("Energy AT / keVee");
  hE_AST->GetYaxis()->SetTitle("Energy BGO / keVee");

  hE_ASB   = new TH2F("hEASB","E AT-A vs E BGO SB / $", 50,0,200,50,1000,4000);
  hE_ASB->GetXaxis()->SetTitle("Energy AT / keVee");
  hE_ASB->GetYaxis()->SetTitle("Energy BGO / keVee");

  hE_AM    = new TH2F("hEAM","E AT-A vs E BGO M / $", 50,0,200,50,1000,4000);
  hE_AM->GetXaxis()->SetTitle("Energy AT / keVee");
  hE_AM->GetYaxis()->SetTitle("Energy BGO / keVee");

  hE_ALF   = new TH2F("hEALF","E AT-A vs E BGO LF / $", 50,0,200,50,1000,4000);
  hE_ALF->GetXaxis()->SetTitle("Energy AT / keVee");
  hE_ALF->GetYaxis()->SetTitle("Energy BGO / keVee");

  hE_ALB   = new TH2F("hEALB","E AT-A vs E BGO LB / $", 50,0,200,50,1000,4000);
  hE_ALB->GetXaxis()->SetTitle("Energy AT / keVee");
  hE_ALB->GetYaxis()->SetTitle("Energy BGO / keVee");

  hE_AST1   = new TH2F("hEAST1","E AT-A vs E BGO ST / $ + Shifted TOF", 50,0,200,50,1000,4000);
  hE_AST1->GetXaxis()->SetTitle("Energy AT / keVee");
  hE_AST1->GetYaxis()->SetTitle("Energy BGO / keVee");

  hE_ASB1   = new TH2F("hEASB1","E AT-A vs E BGO SB / $ + Shifted TOF", 50,0,200,50,1000,4000);
  hE_ASB1->GetXaxis()->SetTitle("Energy AT / keVee");
  hE_ASB1->GetYaxis()->SetTitle("Energy BGO / keVee");

  hE_AM1    = new TH2F("hEAM1","E AT-A vs E BGO M / $ + Shifted TOF", 50,0,200,50,1000,4000);
  hE_AM1->GetXaxis()->SetTitle("Energy AT / keVee");
  hE_AM1->GetYaxis()->SetTitle("Energy BGO / keVee");

  hE_ALF1   = new TH2F("hEALF1","E AT-A vs E BGO LF / $ + Shifted TOF", 50,0,200,50,1000,4000);
  hE_ALF1->GetXaxis()->SetTitle("Energy AT / keVee");
  hE_ALF1->GetYaxis()->SetTitle("Energy BGO / keVee");

  hE_ALB1   = new TH2F("hEALB1","E AT-A vs E BGO LB / $ + Shifted TOF", 50,0,200,50,1000,4000);
  hE_ALB1->GetXaxis()->SetTitle("Energy AT / keVee");
  hE_ALB1->GetYaxis()->SetTitle("Energy BGO / keVee");

  hEATEBGO   = new TH2F("hEATEBGO","Energy AT vs Energy BGO / $", 50,0,200,50,1000,4000);
  hEATEBGO->GetXaxis()->SetTitle("Energy AT / keVee");
  hEATEBGO->GetYaxis()->SetTitle("Energy BGO / keVee");
}

//fill in histograms
inline void FillHisto()
{
  //access global buffer
  extern npEvent_t event;
  //update quantities
  updateQty();
  //update condition bits
  checkCond();

  //fill in histograms
  hE_AT_A->Fill(E_AT_A);
  hE_AT_B->Fill(E_AT_B);

  if( ((xAcST & xEST0) | (xAcSB & xESB0) | (xAcM & xEM0) | (xAcLF & xELF0) | (xAcLB & xELB0)) & xEA0) hBeam0_A->Fill(event.TDC_Beam0);
  if( ((xAcST & xEST1) | (xAcSB & xESB1) | (xAcM & xEM1) | (xAcLF & xELF1) | (xAcLB & xELB1)) & xEA1) hBeam0_A1->Fill(event.TDC_Beam0);
  if( ((xAcST & xEST2) | (xAcSB & xESB2) | (xAcM & xEM2) | (xAcLF & xELF2) | (xAcLB & xELB2)) & xEA2) hBeam0_A2->Fill(event.TDC_Beam0);

  if( ((xBcST & xEST0) | (xBcSB & xESB0) | (xBcM & xEM0) | (xBcLF & xELF0) | (xBcLB & xELB0)) & xEB0) hBeam0_B->Fill(event.TDC_Beam0);
  if( ((xBcST & xEST1) | (xBcSB & xESB1) | (xBcM & xEM1) | (xBcLF & xELF1) | (xBcLB & xELB1)) & xEB1) hBeam0_B1->Fill(event.TDC_Beam0);
  if( ((xBcST & xEST2) | (xBcSB & xESB2) | (xBcM & xEM2) | (xBcLF & xELF2) | (xBcLB & xELB2)) & xEB2) hBeam0_B2->Fill(event.TDC_Beam0);

  if(xAcST & xEA0 & xEST0) hBeam0_AcST->Fill(event.TDC_Beam0);
  if(xAcSB & xEA0 & xESB0) hBeam0_AcSB->Fill(event.TDC_Beam0);
  if(xAcM & xEA0 & xEM0) hBeam0_AcM->Fill(event.TDC_Beam0);
  if(xAcLF & xEA0 & xELF0) hBeam0_AcLF->Fill(event.TDC_Beam0);
  if(xAcLB & xEA0 & xELB0) hBeam0_AcLB->Fill(event.TDC_Beam0);

  if(xAcST & xEA1 & xEST1) hBeam0_AcST1->Fill(event.TDC_Beam0);
  if(xAcSB & xEA1 & xESB1) hBeam0_AcSB1->Fill(event.TDC_Beam0);
  if(xAcM & xEA1 & xEM1) hBeam0_AcM1->Fill(event.TDC_Beam0);
  if(xAcLF & xEA1 & xELF1) hBeam0_AcLF1->Fill(event.TDC_Beam0);
  if(xAcLB & xEA1 & xELB1) hBeam0_AcLB1->Fill(event.TDC_Beam0);

  if(xAcST & xEA2 & xEST2) hBeam0_AcST2->Fill(event.TDC_Beam0);
  if(xAcSB & xEA2 & xESB2) hBeam0_AcSB2->Fill(event.TDC_Beam0);
  if(xAcM & xEA2 & xEM2) hBeam0_AcM2->Fill(event.TDC_Beam0);
  if(xAcLF & xEA2 & xELF2) hBeam0_AcLF2->Fill(event.TDC_Beam0);
  if(xAcLB & xEA2 & xELB2) hBeam0_AcLB2->Fill(event.TDC_Beam0);

  if(xAcST & xTOF_Beam0) hE_AST->Fill(E_AT_A, E_BGO_ST);
  if(xAcSB & xTOF_Beam0) hE_ASB->Fill(E_AT_A, E_BGO_SB);
  if(xAcM & xTOF_Beam0) hE_AM->Fill(E_AT_A, E_BGO_M);
  if(xAcLF & xTOF_Beam0) hE_ALF->Fill(E_AT_A, E_BGO_LF);
  if(xAcLB & xTOF_Beam0) hE_ALB->Fill(E_AT_A, E_BGO_LB);

  if(xAcST & xTOF_Beam0l) hE_AST1->Fill(E_AT_A, E_BGO_ST);
  if(xAcSB & xTOF_Beam0l) hE_ASB1->Fill(E_AT_A, E_BGO_SB);
  if(xAcM & xTOF_Beam0l) hE_AM1->Fill(E_AT_A, E_BGO_M);
  if(xAcLF & xTOF_Beam0l) hE_ALF1->Fill(E_AT_A, E_BGO_LF);
  if(xAcLB & xTOF_Beam0l) hE_ALB1->Fill(E_AT_A, E_BGO_LB);

  if(xAcST & xTOF_Beam0) hEATEBGO->Fill(E_AT_A, E_BGO_ST);
  if(xAcSB & xTOF_Beam0) hEATEBGO->Fill(E_AT_A, E_BGO_SB);
  if(xAcM & xTOF_Beam0) hEATEBGO->Fill(E_AT_A, E_BGO_M);
  if(xAcLF & xTOF_Beam0) hEATEBGO->Fill(E_AT_A, E_BGO_LF);
  if(xAcLB & xTOF_Beam0) hEATEBGO->Fill(E_AT_A, E_BGO_LB);
}
