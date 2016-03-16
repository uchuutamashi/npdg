#ifndef NP_DEFCUTH
#define NP_DEFCUTH
#include "defs_qty.h"

/* =============================================================================
    Bounds
/* ===========================================================================*/
// ADC AT simple cuts
#define ADC_AT_A_T_LOW 100
#define ADC_AT_A_T_HIGH 1900
#define ADC_AT_A_B_LOW 100
#define ADC_AT_A_B_HIGH 1900
#define ADC_AT_B_T_LOW 100
#define ADC_AT_B_T_HIGH 1900
#define ADC_AT_B_B_LOW 100
#define ADC_AT_B_B_HIGH 1900
// ADC AT Top-Bottom coincidence
#define ADC_AT_TB_HIGH 350
//TDC simple cuts
#define TDC_AT_A_LOW 300
#define TDC_AT_A_HIGH 400
#define TDC_AT_B_LOW 300
#define TDC_AT_B_HIGH 400
#define TDC_AT_BGO_LOW 300
#define TDC_AT_BGO_HIGH 400
//AT-BGO ToFs
#define TOF_ATA_ST_LOW 785
#define TOF_ATA_ST_HIGH 825
#define TOF_ATA_SB_LOW 767
#define TOF_ATA_SB_HIGH 789
#define TOF_ATA_M_LOW 763
#define TOF_ATA_M_HIGH 808
#define TOF_ATA_LF_LOW 803
#define TOF_ATA_LF_HIGH 830
#define TOF_ATA_LB_LOW 795
#define TOF_ATA_LB_HIGH 817

//AT-BGO ToFs
#define TOF_ATB_ST_LOW 765
#define TOF_ATB_ST_HIGH 812
#define TOF_ATB_SB_LOW 737
#define TOF_ATB_SB_HIGH 777
#define TOF_ATB_M_LOW 737
#define TOF_ATB_M_HIGH 787
#define TOF_ATB_LF_LOW 778
#define TOF_ATB_LF_HIGH 815
#define TOF_ATB_LB_LOW 771
#define TOF_ATB_LB_HIGH 805

//Kinematics
#define E_AT_LOW 80
#define E_AT_HIGH 120
#define E_BGO_LOW 2800
#define E_BGO_HIGH 3200

//Shifted Kinematics
#define E_AT_LOW1 130
#define E_AT_HIGH1 300
#define E_BGO_LOW1 3500
#define E_BGO_HIGH1 6000

#define E_AT_LOW2 130
#define E_AT_HIGH2 300
#define E_BGO_LOW2 2800
#define E_BGO_HIGH2 3200

//Beam ToFs
#define TOF_BEAM0_LOW 510
#define TOF_BEAM0_HIGH 560
#define TOF_BEAM0_LOWl 700
#define TOF_BEAM0_HIGHl 800
#define TOF_BEAM0_LOWr 200
#define TOF_BEAM0_HIGHr 300
/* ===========================================================================*/

/* =============================================================================
    Declarations
/* ===========================================================================*/
Int_t xATcBGO; // AT_BGO coincidence trigger
Int_t xATA;    // AT A fired (given ATcBGO)
Int_t xATB;    // AT B fired (given ATcBGO)
Int_t xTOF_ATA_ST; // ToF cut from AT-A to BGO-ST
Int_t xTOF_ATA_SB; // ToF cut from AT-A to BGO-SB
Int_t xTOF_ATA_M; // ToF cut from AT-A to BGO-M
Int_t xTOF_ATA_LF; // ToF cut from AT-A to BGO-LF
Int_t xTOF_ATA_LB; // ToF cut from AT-A to BGO-LB
Int_t xTOF_ATB_ST; // ToF cut from AT-B to BGO-ST
Int_t xTOF_ATB_SB; // ToF cut from AT-B to BGO-SB
Int_t xTOF_ATB_M; // ToF cut from AT-B to BGO-M
Int_t xTOF_ATB_LF; // ToF cut from AT-B to BGO-LF
Int_t xTOF_ATB_LB; // ToF cut from AT-B to BGO-LB

Int_t xEA0; //kinematics for AT-A
Int_t xEB0; //kinematics for AT-B
Int_t xEST0; //kinematics for BGO-ST
Int_t xESB0; //kinematics for BGO-SB
Int_t xEM0; //kinematics for BGO-SB
Int_t xELF0; //kinematics for BGO-SB
Int_t xELB0; //kinematics for BGO-SB

Int_t xEA1; //kinematics for AT-A
Int_t xEB1; //kinematics for AT-B
Int_t xEST1; //kinematics for BGO-ST
Int_t xESB1; //kinematics for BGO-SB
Int_t xEM1; //kinematics for BGO-SB
Int_t xELF1; //kinematics for BGO-SB
Int_t xELB1; //kinematics for BGO-SB

Int_t xEA2; //kinematics for AT-A
Int_t xEB2; //kinematics for AT-B
Int_t xEST2; //kinematics for BGO-ST
Int_t xESB2; //kinematics for BGO-SB
Int_t xEM2; //kinematics for BGO-SB
Int_t xELF2; //kinematics for BGO-SB
Int_t xELB2; //kinematics for BGO-SB

Int_t xAcST; //time and trigger cuts for AT-A c BGO-ST
Int_t xAcSB; //time and trigger cuts for AT-A c BGO-SB
Int_t xAcM; //time and trigger cuts for AT-A c BGO-M
Int_t xAcLF; //time and trigger cuts for AT-A c BGO-LF
Int_t xAcLB; //time and trigger cuts for AT-A c BGO-LB
Int_t xBcST; //time and trigger cuts for AT-A c BGO-ST
Int_t xBcSB; //time and trigger cuts for AT-A c BGO-SB
Int_t xBcM; //time and trigger cuts for AT-A c BGO-M
Int_t xBcLF; //time and trigger cuts for AT-A c BGO-LF
Int_t xBcLB; //time and trigger cuts for AT-A c BGO-LB

Int_t xTOF_Beam0; //Beam ToF cut
Int_t xTOF_Beam0l; //Beam ToF cut
Int_t xTOF_Beam0r; //Beam ToF cut

Int_t xBeam0AcBGO; //Plot AT-A Beam ToF with $-cut
Int_t xBeam0BcBGO; //Plot AT-B Beam ToF with $-cut
/* ===========================================================================*/

void checkCond(){
  xATcBGO = (event.TDC_AT_BGO>TDC_AT_BGO_LOW) && (event.TDC_AT_BGO<TDC_AT_BGO_HIGH);
  xATA = (event.TDC_AT_A>TDC_AT_A_LOW && event.TDC_AT_A<TDC_AT_A_HIGH) &&
        (event.ADC_AT_A_T<ADC_AT_A_T_HIGH && event.ADC_AT_A_B<ADC_AT_A_B_HIGH) &&
        (event.ADC_AT_A_T>ADC_AT_A_T_LOW && event.ADC_AT_A_B>ADC_AT_A_B_LOW &&
        abs(event.ADC_AT_A_T-event.ADC_AT_A_B)<ADC_AT_TB_HIGH);
  xATB = (event.TDC_AT_B>TDC_AT_B_LOW && event.TDC_AT_B<TDC_AT_B_HIGH) &&
        (event.ADC_AT_B_T<ADC_AT_B_T_HIGH && event.ADC_AT_B_B<ADC_AT_B_B_HIGH) &&
        (event.ADC_AT_B_T>ADC_AT_B_T_LOW && event.ADC_AT_B_B>ADC_AT_B_B_LOW &&
        abs(event.ADC_AT_B_T-event.ADC_AT_B_B)<ADC_AT_TB_HIGH);

  xTOF_ATA_ST = event.TDC_BGO_S_T>TOF_ATA_ST_LOW && event.TDC_BGO_S_T<TOF_ATA_ST_HIGH;
  xTOF_ATA_SB = event.TDC_BGO_S_B>TOF_ATA_SB_LOW && event.TDC_BGO_S_B<TOF_ATA_SB_HIGH;
  xTOF_ATA_M = event.TDC_BGO_M>TOF_ATA_M_LOW && event.TDC_BGO_M<TOF_ATA_M_HIGH;
  xTOF_ATA_LF = event.TDC_BGO_L_F>TOF_ATA_LF_LOW && event.TDC_BGO_L_F<TOF_ATA_LF_HIGH;
  xTOF_ATA_LB = event.TDC_BGO_L_B>TOF_ATA_LB_LOW && event.TDC_BGO_L_B<TOF_ATA_LB_HIGH;
  xTOF_ATB_ST = event.TDC_BGO_S_T>TOF_ATB_ST_LOW && event.TDC_BGO_S_T<TOF_ATB_ST_HIGH;
  xTOF_ATB_SB = event.TDC_BGO_S_B>TOF_ATB_SB_LOW && event.TDC_BGO_S_B<TOF_ATB_SB_HIGH;
  xTOF_ATB_M = event.TDC_BGO_M>TOF_ATB_M_LOW && event.TDC_BGO_M<TOF_ATB_M_HIGH;
  xTOF_ATB_LF = event.TDC_BGO_L_F>TOF_ATB_LF_LOW && event.TDC_BGO_L_F<TOF_ATB_LF_HIGH;
  xTOF_ATB_LB = event.TDC_BGO_L_B>TOF_ATB_LB_LOW && event.TDC_BGO_L_B<TOF_ATB_LB_HIGH;

  xEA0 = E_AT_A > E_AT_LOW && E_AT_A < E_AT_HIGH;
  xEB0 = E_AT_B > E_AT_LOW && E_AT_B < E_AT_HIGH;
  xEST0= E_BGO_ST > E_BGO_LOW && E_BGO_ST < E_BGO_HIGH;
  xESB0= E_BGO_SB > E_BGO_LOW && E_BGO_SB < E_BGO_HIGH;
  xEM0= E_BGO_M > E_BGO_LOW && E_BGO_M < E_BGO_HIGH;
  xELF0= E_BGO_LF > E_BGO_LOW && E_BGO_LF < E_BGO_HIGH;
  xELB0= E_BGO_LB > E_BGO_LOW && E_BGO_LB < E_BGO_HIGH;

  xEA1 = E_AT_A > E_AT_LOW1 && E_AT_A < E_AT_HIGH1;
  xEB1 = E_AT_B > E_AT_LOW1 && E_AT_B < E_AT_HIGH1;
  xEST1= E_BGO_ST > E_BGO_LOW1 && E_BGO_ST < E_BGO_HIGH1;
  xESB1= E_BGO_SB > E_BGO_LOW1 && E_BGO_SB < E_BGO_HIGH1;
  xEM1= E_BGO_M > E_BGO_LOW1 && E_BGO_M < E_BGO_HIGH1;
  xELF1= E_BGO_LF > E_BGO_LOW1 && E_BGO_LF < E_BGO_HIGH1;
  xELB1= E_BGO_LB > E_BGO_LOW1 && E_BGO_LB < E_BGO_HIGH1;

  xEA2 = E_AT_A > E_AT_LOW2 && E_AT_A < E_AT_HIGH2;
  xEB2 = E_AT_B > E_AT_LOW2 && E_AT_B < E_AT_HIGH2;
  xEST2= E_BGO_ST > E_BGO_LOW2 && E_BGO_ST < E_BGO_HIGH2;
  xESB2= E_BGO_SB > E_BGO_LOW2 && E_BGO_SB < E_BGO_HIGH2;
  xEM2= E_BGO_M > E_BGO_LOW2 && E_BGO_M < E_BGO_HIGH2;
  xELF2= E_BGO_LF > E_BGO_LOW2 && E_BGO_LF < E_BGO_HIGH2;
  xELB2= E_BGO_LB > E_BGO_LOW2 && E_BGO_LB < E_BGO_HIGH2;

  xTOF_Beam0 = event.TDC_Beam0>TOF_BEAM0_LOW && event.TDC_Beam0<TOF_BEAM0_HIGH;
  xTOF_Beam0l = event.TDC_Beam0>TOF_BEAM0_LOWl && event.TDC_Beam0<TOF_BEAM0_HIGHl;
  xTOF_Beam0r = event.TDC_Beam0>TOF_BEAM0_LOWr && event.TDC_Beam0<TOF_BEAM0_HIGHr;

  xAcST= xATcBGO & xATA & xTOF_ATA_ST;
  xAcSB= xATcBGO & xATA & xTOF_ATA_SB;
  xAcM= xATcBGO & xATA & xTOF_ATA_M;
  xAcLB= xATcBGO & xATA & xTOF_ATA_LB;
  xAcLF= xATcBGO & xATA & xTOF_ATA_LF;

  xBcST= xATcBGO & xATB & xTOF_ATB_ST;
  xBcSB= xATcBGO & xATB & xTOF_ATB_SB;
  xBcM= xATcBGO & xATB & xTOF_ATB_M;
  xBcLB= xATcBGO & xATB & xTOF_ATB_LB;
  xBcLF= xATcBGO & xATB & xTOF_ATB_LF;

  xBeam0AcBGO= xATcBGO & xATA & xEA0 & ( (xTOF_ATA_ST&xEST0) | (xTOF_ATA_SB&xESB0) | (xTOF_ATA_M&xEM0) | (xTOF_ATA_LF&xELF0) | (xTOF_ATA_LB&xELB0) ) ;
  xBeam0BcBGO= xATcBGO & xATB & xEB0 & ( (xTOF_ATB_ST&xEST0) | (xTOF_ATB_SB&xESB0) | (xTOF_ATB_M&xEM0) | (xTOF_ATB_LF&xELF0) | (xTOF_ATB_LB&xELB0) ) ;

}

#endif
