// This script is intended for the analyses of the 2015 np capture experiment
// consisting of 3 ATs & 5 BGO detectors.
//
// Function: Combine .evnt files in the same folder into a ROOT tree.
//           Only relies on CINT/ROOT. No compiler dependence.
// Usage:    After loaded into ROOT, run "evnt2tree( fldr_path )"
//
// Written by To Chin Yu for Jan15 np capture at UKY (Jan2015)
//

// pedestals
#define AT_A_T_Ped 65
#define AT_A_B_Ped 77
#define AT_B_T_Ped 64
#define AT_B_B_Ped 62
#define AT_B_T_D_Ped 80
#define AT_B_B_D_Ped 80

// conversions
#define AT_A_Mul 0.1394
#define AT_B_Mul 0.1515
#define AT_B_D_Mul 0.2297

#include <sstream>
#include <TTree.h>
#include <TList.h>

using namespace std;

//struct npEvent_t
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

  Double_t E_AT_A;
  Double_t E_AT_B;
  Double_t E_AT_B_D;

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

Char_t buffer[1500];
Int_t a[44];
bool SCALER=false;


//main evnt2tree
//convert all .evnt in folder to a single .root file
void evnt2tree(const Char_t* eventFolderName, bool rc=true){

  //timing
  TStopwatch clock;


  TString rootFile = eventFolderName;
  rootFile.Append("/events.root");

  //create tree
  TFile* tf;
  if(rc){
    tf = new TFile(rootFile,"RECREATE");
  }else{
    tf = new TFile(rootFile,"UPDATE");
  }
  TTree* np = new TTree("npdg","npdg2015");

  //get directory listing
  TSystemDirectory dir(eventFolderName, eventFolderName);
  TList* evntFiles = dir.GetListOfFiles();
  if(evntFiles){
    TSystemFile* f;
    TIter next(evntFiles);
    TString fName;

    //create a single-event buffer
    npEvent_t event;

    //create branches
    np->Branch("ADC_AT_A_T",&event.ADC_AT_A_T,"ADC_AT_A_T/I");
    np->Branch("ADC_AT_A_B",&event.ADC_AT_A_B,"ADC_AT_A_B/I");
    np->Branch("ADC_AT_B_T",&event.ADC_AT_B_T,"ADC_AT_B_T/I");
    np->Branch("ADC_AT_B_B",&event.ADC_AT_B_B,"ADC_AT_B_B/I");

    np->Branch("ADC_BGO_L_F",&event.ADC_BGO_L_F,"ADC_BGO_L_F/I");
    np->Branch("ADC_BGO_L_B",&event.ADC_BGO_L_B,"ADC_BGO_L_B/I");
    np->Branch("ADC_BGO_M",&event.ADC_BGO_M,"ADC_BGO_M/I");
    np->Branch("ADC_BGO_S_T",&event.ADC_BGO_S_T,"ADC_BGO_S_T/I");
    np->Branch("ADC_BGO_S_B",&event.ADC_BGO_S_B,"ADC_BGO_S_B/I");
    np->Branch("ADC_ND_S",&event.ADC_ND_S,"ADC_ND_S/I");
    np->Branch("ADC_ND_L",&event.ADC_ND_L,"ADC_ND_L/I");
    np->Branch("ADC_AT_B_T_D",&event.ADC_AT_B_T_D,"ADC_AT_B_T_D/I");
    np->Branch("ADC_AT_B_B_D",&event.ADC_AT_B_B_D,"ADC_AT_B_B_D/I");

    np->Branch("E_AT_A",&event.E_AT_A,"E_AT_A/D");
    np->Branch("E_AT_B",&event.E_AT_B,"E_AT_B/D");
    np->Branch("E_AT_B_D", &event.E_AT_B_D,"E_AT_B_D/D");

    np->Branch("TDC_AT_A",&event.TDC_AT_A,"TDC_AT_A/I");
    np->Branch("TDC_AT_B",&event.TDC_AT_B,"TDC_AT_B/I");
    np->Branch("TDC_BGO_L_F",&event.TDC_BGO_L_F,"TDC_BGO_L_F/I");
    np->Branch("TDC_BGO_L_B",&event.TDC_BGO_L_B,"TDC_BGO_L_B/I");
    np->Branch("TDC_BGO_M",&event.TDC_BGO_M,"TDC_BGO_M/I");
    np->Branch("TDC_BGO_S_T",&event.TDC_BGO_S_T,"TDC_BGO_S_T/I");
    np->Branch("TDC_BGO_S_B",&event.TDC_BGO_S_B,"TDC_BGO_S_B/I");
    np->Branch("TDC_ND",&event.TDC_ND,"TDC_ND/I");
    np->Branch("TDC_ND_D",&event.TDC_ND_D,"TDC_ND_D/I");

    np->Branch("TDC_PAT",&event.TDC_PAT,"TDC_PAT/I");
    np->Branch("TDC_PBGO",&event.TDC_PBGO,"TDC_PBGO/I");
    np->Branch("TDC_PND",&event.TDC_PND,"TDC_PND/I");
    np->Branch("TDC_AT_BGO",&event.TDC_AT_BGO,"TDC_AT_BGO/I");
    np->Branch("TDC_AT_ND",&event.TDC_AT_ND,"TDC_AT_ND/I");

    np->Branch("TDC_Beam0",&event.TDC_Beam0,"TDC_Beam0/I");
    np->Branch("TDC_Beam1",&event.TDC_Beam1,"TDC_Beam1/I");

    np->Branch("Scal_AT_A", &event.Scal_AT_A,"Scal_AT_A/I");
    np->Branch("Scal_AT_B", &event.Scal_AT_B,"Scal_AT_B/I");
    np->Branch("Scal_BGO_L_F", &event.Scal_BGO_L_F,"Scal_BGO_L_F/I");
    np->Branch("Scal_BGO_L_B", &event.Scal_BGO_L_B,"Scal_BGO_L_B/I");
    np->Branch("Scal_BGO_M", &event.Scal_BGO_M,"Scal_BGO_M/I");
    np->Branch("Scal_BGO_S_T", &event.Scal_BGO_S_T,"Scal_BGO_S_T/I");
    np->Branch("Scal_BGO_S_B", &event.Scal_BGO_S_B,"Scal_BGO_S_B/I");
    np->Branch("Scal_ND", &event.Scal_ND,"Scal_ND/I");
    np->Branch("Scal_CLK", &event.Scal_CLK,"Scal_CLK/I");
    np->Branch("Scal_CLK_V", &event.Scal_CLK_V,"Scal_CLK_V/I");
    np->Branch("Scal_Charge", &event.Scal_Charge,"Scal_Charge/I");
    np->Branch("Scal_Monitor", &event.Scal_Monitor,"Scal_Monitor/I");

    //iterate through files in folder
    while((f=(TSystemFile*)next())){
      fName = f->GetName();

      if (!f->IsDirectory() && fName.EndsWith("evnt"))
      {
        Char_t* fFullName = new Char_t[1500];
        strcpy(fFullName, eventFolderName);
	      strcat(fFullName, "/");
        strcat(fFullName, fName.Data());

        //open evnt event file
        ifstream evntFile(fFullName, ios::in);

        if(!evntFile.is_open()){
          cout << "Cannot open : " << fFullName <<endl;
          break;
        }

        cout << "File opened : " << fFullName <<endl;

        //free the temporary name string
        delete fFullName;

        //read evnt file line-by-line
        while(!evntFile.eof()){
          evntFile.getline(buffer,1500);
          //skip lines that are too short
          if(strlen(buffer) <= 24) continue;

          istringstream iss(buffer);

          //clear data buffer
          if(!SCALER) for(int i = 0; i < 44; i++) a[i]=0;

          //scaler flag
          SCALER=false;

          //scaler readings
          if (strlen(buffer) > 24 && strlen(buffer) < 80 ) {
            //scaler
            SCALER=true;
            iss >> a[32] >> a[33] >> a[34] >> a[35] >> a[36] >> a[37] >> a[38] >> a[39] >> a[40] >> a[41] >> a[42] >> a[43];
          //ADC readings
          }else if (strlen(buffer) > 80){
            // 16 adc + 16 tdc
            iss >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] >> a[7] >> a[8] >> a[9] >> a[10] >> a[11] >> a[12] >> a[13] >> a[14] >> a[15] >> a[16] >> a[17] >> a[18] >> a[19] >> a[20] >> a[21] >> a[22] >> a[23] >> a[24] >> a[25] >> a[26] >> a[27] >> a[28] >> a[29] >> a[30] >> a[31];
          }

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

          event.E_AT_A= AT_A_Mul*sqrt((event.ADC_AT_A_T-AT_A_T_Ped)*(event.ADC_AT_A_B-AT_A_B_Ped));
          event.E_AT_B= AT_B_Mul*sqrt((event.ADC_AT_B_T-AT_B_T_Ped)*(event.ADC_AT_B_B-AT_B_B_Ped));
          event.E_AT_B_D= AT_B_D_Mul*sqrt((event.ADC_AT_B_T_D-AT_B_T_D_Ped)*(event.ADC_AT_B_B_D-AT_B_B_D_Ped));

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

          //flush event into tree
          if(!SCALER) np->Fill();

        }//end : single file loop by line

        //close file
        evntFile.close();
      }//end : if is a evnt file

      //save after each evnt file
      tf->Write();
    }//end : directory loop by file

  }//end : if directory exists & not empty

  //close tree
  tf->Close();
  clock.Stop();
  clock.Print();
}//end : main
