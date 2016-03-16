// This script is intended for the analyses of the 2009 npdg test experiment
// Written by Vlad Henzl (Jan 2010)
// Edited by Brian Daub for use on the January 2011 light response experiment at UK (Jan 2011)
// Edited by Hongwei Yang for Sep12 np data at UKY (Oct 2012)
// Edited by Hongwei Yang for Jun13 np data at UKY (Jun 2013)
// Edited by Hongwei Yang for Jul13 np data at UKY (Jul 2013)
// Edited by Hongwei Yang for Jul14 np data at UKY (Jul 2014)
// Edited by Hongwei Yang for Aug14 np data at UKY (Aug 2014)
// Edited by Hongwei Yang for Sep14 np data at UKY (Sep 2014)
// Edited by Hongwei Yang for Jan15 npdg data at UKY (Jan 2015)
// this script is used to make root tree file

#include <iostream>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <fstream>
#include <TFile.h>

#include <TROOT.h>
#include <TBranch.h>
#include <TTree.h>
#include <TObject.h>
#include <TFolder.h>


#include <TRandom3.h>
#include <TVector3.h>
#include <TLorentzVector.h>
#include <TRotation.h>
#include <TLorentzRotation.h>
#include "Event.h"

using namespace std;

//____________________________________________________________________________
void Loop()
{
	Char_t outfilename[100], filename[100];
	Char_t line[1500];

	Int_t a[44];

    bool hasScalarData;
    Event event;
	Int_t nEvent, step;

	Int_t Fileorder[105] = 
	{	 41, 112, 304, // 0, 1, 2
		305, 306, 307, // 3, 4, 5
		308, 309, 310, // 6, 7, 8
		311, 312, 313, // 9, 10, 11
		314, 315, 316, // 12, 13, 14
		317, 318, 319, // 15, 16, 17
		320, 321, 322, // 18, 19, 20
		323, 324, 325, // 21, 22, 23
		326, 327, 328, // 24, 25, 26
		329, 330, 331, // 27, 28, 29
		332, 333, 334, // 30, 31, 32
		335, 336, 337, // 33, 34, 35
		338, 339, 340, // 36, 37, 38
		341, 342, 343, // 39, 40, 41
		344, 345, 346, // 42, 43, 44
		347, 348, 349, // 45, 46, 47
		350, 352, 353, // 48, 49, 50
		354, 356, 359, // 51, 52, 53
		360, 362, 363, // 54, 55, 56
		366, 367, 368, // 57, 58, 59
		369, 370, 371, // 60, 61, 62
		372, 373, 374, // 63, 64, 65
		 73,  74 // 66, 67, 68
	};

	Int_t FirstFile, LastFile;

	FirstFile = 1;    
	LastFile = 1; // 

	for (Int_t i=FirstFile; i<=LastFile; i++)
	{ // loop over all data runs

		sprintf(outfilename,"np_%i.root",Fileorder[i]);
		//sprintf(outfilename,"np_%i.root",Fileorder[i]);
		sprintf(filename,"/media/My\ Passport/npdg-2015Jan/data/phys_%i.evnt",Fileorder[i]);
		//sprintf(filename,"phys_%i.evnt",Fileorder[i]);
		ifstream file(filename,ios::in);
		if(!file.is_open()) {
			cout << "File run " << filename 
				<< " could not be opened!!!" << endl;
			break; // jump out of loop
		}
		else {
			cout << "Run" << Fileorder[i] << " with real data opened." << endl;
		}

		TFile *f = new TFile(outfilename,"RECREATE"); // to overwrite current data
		TTree *np = new TTree("npdg","npdgJan2015 - run");

	    np->Branch("ADC_AT_A_T",&event.ADC_AT_A_T,"ADC_AT_A_T/I");
	    np->Branch("ADC_AT_A_B",&event.ADC_AT_A_B,"ADC_AT_A_B/I");
	    np->Branch("ADC_AT_B_T",&event.ADC_AT_B_T,"ADC_AT_B_T/I");
	    np->Branch("ADC_AT_B_B",&event.ADC_AT_B_B,"ADC_AT_B_B/I");
	    np->Branch("ADC_AT_C_T",&event.ADC_AT_C_T,"ADC_AT_C_T/I");
	    np->Branch("ADC_AT_C_B",&event.ADC_AT_C_B,"ADC_AT_C_B/I");

	    np->Branch("ADC_BGO_L_L",&event.ADC_BGO_L_L,"ADC_BGO_L_L/I");
	    np->Branch("ADC_BGO_L_R",&event.ADC_BGO_L_R,"ADC_BGO_L_R/I");
	    np->Branch("ADC_BGO_M",&event.ADC_BGO_M,"ADC_BGO_M/I");
	    np->Branch("ADC_BGO_S_L",&event.ADC_BGO_S_L,"ADC_BGO_S_L/I");
	    np->Branch("ADC_BGO_S_R",&event.ADC_BGO_S_R,"ADC_BGO_S_R/I");

	    np->Branch("TDC_AT_A",&event.TDC_AT_A,"TDC_AT_A/I");
	    np->Branch("TDC_AT_B",&event.TDC_AT_B,"TDC_AT_B/I");
	    np->Branch("TDC_AT_C",&event.TDC_AT_C,"TDC_AT_C/I");
	    np->Branch("TDC_BGO_L_L",&event.TDC_BGO_L_L,"TDC_BGO_L_L/I");
	    np->Branch("TDC_BGO_L_R",&event.TDC_BGO_L_R,"TDC_BGO_L_R/I");
	    np->Branch("TDC_BGO_M",&event.TDC_BGO_M,"TDC_BGO_M/I");
	    np->Branch("TDC_BGO_S_L",&event.TDC_BGO_S_L,"TDC_BGO_S_L/I");
	    np->Branch("TDC_BGO_S_R",&event.TDC_BGO_S_R,"TDC_BGO_S_R/I");

	    np->Branch("TDC_P_AT",&event.TDC_P_AT,"TDC_P_AT/I");
	    np->Branch("TDC_P_BGO",&event.TDC_P_BGO,"TDC_P_BGO/I");

	    np->Branch("TDC_Beam0",&event.TDC_Beam0,"TDC_Beam0/I");
	    np->Branch("TDC_Beam1",&event.TDC_Beam1,"TDC_Beam1/I");
	    np->Branch("TDC_Beam2",&event.TDC_Beam2,"TDC_Beam2/I");

	    np->Branch("Scal_AT_A", &event.Scal_AT_A,"Scal_AT_A/I");
	    np->Branch("Scal_AT_B", &event.Scal_AT_B,"Scal_AT_B/I");
	    np->Branch("Scal_BGO_L_L", &event.Scal_BGO_L_L,"Scal_BGO_L_L/I");
	    np->Branch("Scal_BGO_L_R", &event.Scal_BGO_L_R,"Scal_BGO_L_R/I");
	    np->Branch("Scal_BGO_M", &event.Scal_BGO_M,"Scal_BGO_M/I");
	    np->Branch("Scal_BGO_S_L", &event.Scal_BGO_S_L,"Scal_BGO_S_L/I");
	    np->Branch("Scal_BGO_S_R", &event.Scal_BGO_S_R,"Scal_BGO_S_R/I");
	    np->Branch("Scal_AT_BGO", &event.Scal_AT_BGO,"Scal_AT_BGO/I");
	    np->Branch("Scal_CLK", &event.Scal_CLK,"Scal_CLK/I");
	    np->Branch("Scal_CLK_V", &event.Scal_CLK_V,"Scal_CLK_V/I");
	    np->Branch("Scal_Charge", &event.Scal_Charge,"Scal_Charge/I");
	    np->Branch("Scal_Monitor", &event.Scal_Monitor,"Scal_Monitor/I");

		nEvent = 0;
		step = 110017; 
        hasScalarData = false;

		while(!file.eof() && file.is_open())
		{ // reading the header of an event
			nEvent ++;    	      
			if (nEvent == step )
			{ 		  
				cout << "nEvent = " << nEvent <<  endl;
				step = step + 110017; 
			}	  
			file.getline(line,1500);
            if (strlen(line) < 24) {
                printf("Skip one line.\r");
                continue;
            }
            if (strlen(line) < 80) {
                //scalar
                sscanf(line,"%i %i %i %i %i %i %i %i %i %i %i %i", &a[32],&a[33],&a[34],&a[35],&a[36],&a[37],&a[38],&a[39],&a[40],&a[41],&a[42],&a[43]);
                hasScalarData = true;
            }
            else {
                // 16 adc + 16 tdc
                sscanf(line,"%i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i",	&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9],&a[10],&a[11],&a[12],&a[13],&a[14],&a[15],&a[16],&a[17],&a[18],&a[19],&a[20],&a[21],&a[22],&a[23],&a[24],&a[25],&a[26],&a[27],&a[28],&a[29],&a[30],&a[31]);
                event.readData(a);

                np->Fill();
                if (hasScalarData) {
                    // clear scalar data flag
                    for (int i = 32; i < 44; ++i) {
                        a[i] = 0;
                    }
                    // prepare for next loop
                    hasScalarData = false;
                }
            }

		} // end of reading data for one particular run  
		file.close();    
		cout << "Run" << Fileorder[i] << " with data closed." << endl;
		f->Write();
	} // end of loop over all data runs

} // end of the function Loop()

