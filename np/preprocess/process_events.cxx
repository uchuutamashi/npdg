/* =============================================================================
Convert .evnt files to .root files in a given directory
The naming of branches is stored in *np_event.h*
The mapping of FERA channel number to branches is in *map_fera.h*

Usage: .L process_events.cxx
       Loop("(name of directory)")

Changelog:
02.20.2016 Created (To Chin Yu)
============================================================================= */

#include <sstream>
#include <TTree.h>
#include <TList.h>
#include "np_event.h" // definition of struct npEvent_t
#include "map_fera.h" // fera correspondance
//global buffers and flags
Char_t buffer[1500];
Int_t a[44];
bool CONTAIN_SCALER=false;

//turn "/data/08_12_2015_1115_phys_258.evnt" into "Run258"
TString formatRunTitle(const TString fileName)
{
  TString runTitle = fileName;
  runTitle.ReplaceAll(".evnt","");
  runTitle.Remove(0,runTitle.Last('_')+1);
  runTitle.Prepend("Run");

  return runTitle;
}

//loop through each file and create corresponding tree
void Loop(const Char_t* evntDir)
{
  //get directory listing
  TSystemDirectory dir(evntDir, evntDir);
  TList* evntFiles = dir.GetListOfFiles();
  if(evntFiles){
    TSystemFile* f;
    TIter nextFile(evntFiles);
    TString fName;

    while((f=(TSystemFile*)nextFile())){
      fName = f->GetName();

      if (!f->IsDirectory() && fName.EndsWith("evnt"))
      {
        //build evnt file name
        TString fFullName = evntDir;
        fFullName += "/";
        fFullName += fName.Data();

        //build tree file name
        TString tfFullName = fFullName;
        tfFullName.ReplaceAll(".evnt",".root");

        //create tree file and fill with evnt File
        FillTree(tfFullName,fFullName);
      }

    }
  }
}

void FillTree(const TString tfFullName, const TString fFullName)
{
  //open evnt file for reading
  ifstream evntFile(fFullName, ios::in);

  if(!evntFile.is_open()){
    cout << "Cannot open : " << fFullName <<endl;
    return;
  }

  cout << "File opened : " << fFullName <<endl;
  cout << "Filling " << tfFullName << "...";
  cout.flush();

  //create tree and ROOT file
  TFile* tf;
  tf = new TFile(tfFullName,"RECREATE");
  TTree* np = new TTree(formatRunTitle(fFullName),fFullName);

  //create a single-event buffer
  npEvent_t event;

  //create and map branches
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

  //read evnt file line-by-line
  while(!evntFile.eof()){
    evntFile.getline(buffer,1500);
    //skip lines that are too short
    if(strlen(buffer) <= 24) continue;

    istringstream iss(buffer);

    //clear data buffer
    if(!CONTAIN_SCALER) for(int i = 0; i < 44; i++) a[i]=0;

    //reset scaler flag
    CONTAIN_SCALER=false;

    //scaler readings
    if (strlen(buffer) > 24 && strlen(buffer) < 80 ) {
      //scaler
      CONTAIN_SCALER=true;
      iss >> a[32] >> a[33] >> a[34] >> a[35] >> a[36] >> a[37] >> a[38] >> a[39] >> a[40] >> a[41] >> a[42] >> a[43];
    //ADC readings
    }else if (strlen(buffer) > 80){
      // 16 adc + 16 tdc
      iss >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] >> a[7] >> a[8] >> a[9] >> a[10] >> a[11] >> a[12] >> a[13] >> a[14] >> a[15] >> a[16] >> a[17] >> a[18] >> a[19] >> a[20] >> a[21] >> a[22] >> a[23] >> a[24] >> a[25] >> a[26] >> a[27] >> a[28] >> a[29] >> a[30] >> a[31];
    }

    MapFERA(event);

    //flush event into tree
    //if contain scaler then delay fill until next FERA reading
    if(!CONTAIN_SCALER) np->Fill();
  }//end : single file loop by line

  //close file
  evntFile.close();

  //save
  tf->Write();

  cout << "Done." << endl;
}
