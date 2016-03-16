/* =============================================================================
Read single raw .root file or multiple files in a directory and generate
new .root file with combined histograms as well as histograms with various cuts.

Definitions of various quantities (energies,etc) are stored in *defs_qty.h*
Definitions of histograms are stored in *defs_histo.h*
Definitions of cuts on the various histograms are stored in *defs_cuts.h*
>> Make sure both files are modified if changes are made. <<

Usage: .L run.cxx
       run("(name of directory) || (name of root file).root ")

Changelog:
02.20.2016 Created (To Chin Yu)
============================================================================= */
#include <sstream>
#include <iostream>
#include "TROOT.h"
#include <TTree.h>
#include <TList.h>
#include "TROOT.h"
#include "TMath.h"
#include "TStorage.h"
#include "TObject.h"
#include "TFile.h"
#include "TTree.h"
#include "np_event.h"
#include "defs_histo.h" //histograms to be plotted
#include "load_tree.h"  //read tree into buffer

//global buffer
npEvent_t event;

//turn "/data/08_12_2015_1115_phys_258.root" into "Run258"
TString formatRunTitle(const TString fileName)
{
  TString runTitle = fileName;
  runTitle.ReplaceAll(".root","");
  runTitle.Remove(0,runTitle.Last('_')+1);
  runTitle.Prepend("Run");

  return runTitle;
}

void run(const Char_t* dataDir)
{
  TString path = dataDir;
  //create output file containing the histograms
  TString rootFile = dataDir;
  rootFile.Append("/output/npdg.root");
  TFile *tf = new TFile(rootFile,"RECREATE");

  TTree* temp; //for reading from root files
  initHisto();
  cout << "Initialized!" << endl;
  cout.flush();

  //single file
  if(path.EndsWith(".root")){
    //connect to tree file
    TFile inpfile(fFullName);
    //access the tree
    temp = (TTree*) inpfile.Get(formatRunTitle(fFullName));
    //connect branch to buffer
    LoadTree(fFullName, temp);

    //loop over entries and put into suitable histograms
    Int_t numEntries = temp->GetEntries();
    for(int i=0; i<numEntries; ++i){
      //read entry into buffer
      temp->GetEntry(i);
      FillHisto();
    }

  }else{
    //directory
    //get directory listing
    TSystemDirectory dir(dataDir, dataDir);
    TList* dataFiles = dir.GetListOfFiles();
    if(dataFiles){
      TSystemFile* f;
      TIter nextFile(dataFiles);
      TString fName;
      //loop through files
      while((f=(TSystemFile*)nextFile())){
        fName = f->GetName();
        if (!f->IsDirectory() && fName.EndsWith("root")){
          //build root file name
          TString fFullName = dataDir;
          fFullName += "/";
          fFullName += fName.Data();

          //connect to tree file
          TFile inpfile(fFullName);
          //access the tree
          temp = (TTree*) inpfile.Get(formatRunTitle(fFullName));
          //connect branch to buffer
          LoadTree(fFullName, temp);

          //loop over entries and put into suitable histograms
          Int_t numEntries = temp->GetEntries();
          for(int i=0; i<numEntries; ++i){
            //read entry into buffer
            temp->GetEntry(i);
            FillHisto();
          }
        }
      }// end of file loop
    }
  }//end if single file else directory
  tf->Write();
}
