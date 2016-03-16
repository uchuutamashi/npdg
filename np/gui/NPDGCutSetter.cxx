/**
 * =====================================================================================
 *
 *           @file NPDGCutSetter.cxx
 *
 *          @brief
 *         @detail
 *
 *        @version 1.0
 *           @date 11/24/2014 03:04:20 PM
 *        Revision  none
 *        Compiler  g++-4.4
 *
 *         @author Hongwei Yang (UKY), yhw1630@gmail.com
 *      @copyright
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <TApplication.h>
#include <TGClient.h>
#include "NPDGCutSetter.h"
#include <TGLabel.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TGFileDialog.h>
#include <TROOT.h>

/**
 *--------------------------------------------------------------------------------------
 *       Class:  NPDGCutSetter
 *      Method:  NPDGCutSetter
 * Description:  constructor
 *--------------------------------------------------------------------------------------
 */
NPDGCutSetter::NPDGCutSetter(const TGWindow *p,UInt_t w,UInt_t h,bool vMode)
{
    isVerboseMode_ = vMode;
	runFile_ = 0;
    //tlBgCurrent_ = 0;
	//tlBg_.SetLineColor(2);
    InitMainFrame(p, w, h);
}  /* -----  end of method NPDGCutSetter::NPDGCutSetter  (constructor)  ----- */

/**
 *--------------------------------------------------------------------------------------
 *       Class:  NPDGCutSetter
 *      Method:  NPDGCutSetter
 * Description:  copy constructor
 *--------------------------------------------------------------------------------------
 */
NPDGCutSetter::NPDGCutSetter ( const NPDGCutSetter &other )
{
}  /* -----  end of method NPDGCutSetter::NPDGCutSetter  (copy constructor)  ----- */

/**
 *--------------------------------------------------------------------------------------
 *       Class:  NPDGCutSetter
 *      Method:  ~NPDGCutSetter
 * Description:  destructor
 *--------------------------------------------------------------------------------------
 */
NPDGCutSetter::~NPDGCutSetter ()
{
	delete cbAT_;
	delete cbBGO_;
	delete hfOptions0_;
	delete hfOptions1_;
	delete hfOptions2_;
	delete hfOptions_;
	//delete nTdcGamma0_;
	//delete nBG1Low_;
	//delete nBG1High_;
	//delete nBG2Low_;
	//delete nBG2High_;
	delete fHProg_;
	delete fStatusBar_;
	delete fMenuFile_;
	if(runFile_) delete runFile_;
    delete fEcanvas_;
	fMain_->Cleanup();
}  /* -----  end of method NPDGCutSetter::~NPDGCutSetter  (destructor)  ----- */

/**
 *--------------------------------------------------------------------------------------
 *       Class:  NPDGCutSetter
 *      Method:  operator =
 * Description:  assignment operator
 *--------------------------------------------------------------------------------------
 */
    NPDGCutSetter&
NPDGCutSetter::operator = ( const NPDGCutSetter &other )
{
    if ( this != &other ) {
    }
    return *this;
}  /* -----  end of method NPDGCutSetter::operator =  (assignment operator)  ----- */

    void
NPDGCutSetter::InitMainFrame ( const TGWindow* p, UInt_t w, UInt_t h)
{
	// Create a main frame
	fMain_ = new TGMainFrame(p,w,h);

	fMain_->Connect("CloseWindow()", "NPDGCutSetter", this, "OnCloseMainWindow()");

	// Create menu bar and popup menus
	fMenuFile_ = new TGPopupMenu(gClient->GetRoot());
	fMenuFile_->AddEntry("&Open...", M_FILE_OPEN);
	fMenuFile_->AddEntry("&Save", M_FILE_SAVE);
	fMenuFile_->AddEntry("S&ave as...", M_FILE_SAVEAS);
	fMenuFile_->AddEntry("&Close...", -1);
	fMenuFile_->AddSeparator();
	fMenuFile_->AddEntry("&Print", M_FILE_PRINT);
	fMenuFile_->AddEntry("P&rint setup...", M_FILE_PRINTSETUP);
	fMenuFile_->AddSeparator();
	fMenuFile_->AddEntry("E&xit", M_FILE_EXIT);
	fMenuFile_->DisableEntry(M_FILE_SAVE);
	fMenuFile_->DisableEntry(M_FILE_SAVEAS);
	fMenuFile_->HideEntry(M_FILE_PRINT);
	fMenuFile_->Connect("Activated(Int_t)", "NPDGCutSetter", this, "OnHandleMenu(Int_t)");

	TGLayoutHints *fMenuBarItemLayout = new TGLayoutHints(kLHintsTop | kLHintsLeft, 0, 4, 0, 0);

	TGMenuBar* fMenuBar = new TGMenuBar(fMain_, 100, 20, kHorizontalFrame);

	fMenuBar->AddPopup("&File", fMenuFile_, fMenuBarItemLayout);

	fMain_->AddFrame(fMenuBar, new TGLayoutHints(kLHintsTop | kLHintsExpandX));

	// Create canvas widget
	fEcanvas_ = new TRootEmbeddedCanvas("Ecanvas", fMain_, 1050, 500);
	fEcanvas_->GetCanvas()->Divide(3, 2);
	fEcanvas_->GetCanvas()->SetFillColor(kYellow - 9);

	fMain_->AddFrame(fEcanvas_, new TGLayoutHints(kLHintsExpandX| kLHintsExpandY, 10, 10, 10, 1));

	// Create status bar
	Int_t parts[] = {40, 29, 29, 2};
	fStatusBar_ = new TGStatusBar(fMain_, 50, 10, kHorizontalFrame);
	fStatusBar_->SetParts(parts, 4);
	fMain_->AddFrame(fStatusBar_, new TGLayoutHints(kLHintsBottom | kLHintsLeft | kLHintsExpandX, 0, 0, 2, 0));

	// Create progress bar
	fHProg_ = new TGHProgressBar(fMain_, TGProgressBar::kStandard, 300);

	fHProg_->SetBarColor("yellow");
	fMain_->AddFrame(fHProg_, new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX, 5, 5, 5, 10));

	// Create a horizontal frame widget with buttons
	hfOptions_ = new TGHorizontalFrame(fMain_, 1050,80);

	hfOptions0_ = new TGVerticalFrame(hfOptions_);

	hfOptions1_ = new TGHorizontalFrame(hfOptions0_);

	TGLabel *lCut = new TGLabel(hfOptions1_, " Cuts: ");
	hfOptions1_->AddFrame(lCut);

    // AT
	TGLabel *lATCut = new TGLabel(hfOptions1_, "   AT: ");
	hfOptions1_->AddFrame(lATCut);
	cbAT_ = new TGComboBox(hfOptions1_);
	cbAT_->AddEntry("All", 0);
	cbAT_->AddEntry("Layer A", AT_A);
	cbAT_->AddEntry("Layer B", AT_B);
	cbAT_->AddEntry("Layer C", AT_C);
	cbAT_->SetWidth(100);
	cbAT_->SetHeight(22);
    cbAT_->Select(0);
	hfOptions1_->AddFrame(cbAT_);

    // BGO
	TGLabel *lBGOCut = new TGLabel(hfOptions1_, "   BGO: ");
	hfOptions1_->AddFrame(lBGOCut);
	cbBGO_ = new TGComboBox(hfOptions1_);
	cbBGO_->AddEntry("All", 0);
	cbBGO_->AddEntry("Large Left", BGO_L_L);
	cbBGO_->AddEntry("Large Right", BGO_L_R);
	cbBGO_->AddEntry("Medium", BGO_M);
	cbBGO_->AddEntry("Small Left", BGO_S_L);
	cbBGO_->AddEntry("Small Right", BGO_S_R);
	cbBGO_->SetWidth(100);
	cbBGO_->SetHeight(22);
    cbBGO_->Select(0);
	hfOptions1_->AddFrame(cbBGO_);

    // Gamma flash
	hfOptions2_ = new TGHorizontalFrame(hfOptions0_);
	/*TGLabel *lTdcGamma0 = new TGLabel(hfOptions2_, "   TDC Gamma flash: ");
	nTdcGamma0_ = new TGNumberEntryField(
			hfOptions2_, ITdcGamma0, 0,
			TGNumberFormat::kNESInteger,
			TGNumberFormat::kNEANonNegative,
			TGNumberFormat::kNELLimitMax,
			0, 3000);
	nTdcGamma0_->SetDefaultSize(60,22);
	hfOptions2_->AddFrame(lTdcGamma0);
	hfOptions2_->AddFrame(nTdcGamma0_);

    // Background
	TGLabel *lTdcBG1 = new TGLabel(hfOptions2_, "   Background: (1)");
	nBG1Low_ = new TGNumberEntryField(
			hfOptions2_, IBG1Low, 0,
			TGNumberFormat::kNESInteger,
			TGNumberFormat::kNEANonNegative,
			TGNumberFormat::kNELLimitMax,
			0, MAX_TDC);
	nBG1Low_->SetDefaultSize(60,22);
	nBG1Low_->Connect("ReturnPressed()","NPDGCutSetter",this,"OnBackgroundRangeSet()");
	nBG1High_ = new TGNumberEntryField(
			hfOptions2_, IBG1High, 0,
			TGNumberFormat::kNESInteger,
			TGNumberFormat::kNEANonNegative,
			TGNumberFormat::kNELLimitMax,
			0, MAX_TDC);
	nBG1High_->SetDefaultSize(60,22);
	nBG1High_->Connect("ReturnPressed()","NPDGCutSetter",this,"OnBackgroundRangeSet()");
	TGLabel *lTdcBG2 = new TGLabel(hfOptions2_, "   (2)");
	nBG2Low_ = new TGNumberEntryField(
			hfOptions2_, IBG2Low, 0,
			TGNumberFormat::kNESInteger,
			TGNumberFormat::kNEANonNegative,
			TGNumberFormat::kNELLimitMax,
			0, MAX_TDC);
	nBG2Low_->SetDefaultSize(60,22);
	nBG2Low_->Connect("ReturnPressed()","NPDGCutSetter",this,"OnBackgroundRangeSet()");
	nBG2High_ = new TGNumberEntryField(
			hfOptions2_, IBG2High, 0,
			TGNumberFormat::kNESInteger,
			TGNumberFormat::kNEANonNegative,
			TGNumberFormat::kNELLimitMax,
			0, MAX_TDC);
	nBG2High_->SetDefaultSize(60,22);
	nBG2High_->Connect("ReturnPressed()","NPDGCutSetter",this,"OnBackgroundRangeSet()");
	hfOptions2_->AddFrame(lTdcBG1);
	hfOptions2_->AddFrame(nBG1Low_);
	hfOptions2_->AddFrame(nBG1High_);
	hfOptions2_->AddFrame(lTdcBG2);
	hfOptions2_->AddFrame(nBG2Low_);
	hfOptions2_->AddFrame(nBG2High_);
*/
    //
	TGTextButton *bUpdate = new TGTextButton(hfOptions2_,"&Update");
	bUpdate->Connect("Clicked()","NPDGCutSetter",this,"OnDrawHistograms()");
	hfOptions2_->AddFrame(bUpdate);
	TGTextButton *exit = new TGTextButton(hfOptions2_,"&Exit",
			"gApplication->Terminate(0)");
	hfOptions2_->AddFrame(exit);

	hfOptions_->AddFrame(hfOptions0_);
	hfOptions0_->AddFrame(hfOptions1_);
	hfOptions0_->AddFrame(hfOptions2_);

	fMain_->AddFrame(hfOptions_, new TGLayoutHints(kLHintsRight|kLHintsExpandX,2,2,2,2));

	// Set a name to the main frame
	fMain_->SetWindowName("NPDGCutSetter");
	// Map all subwindows of main frame
	fMain_->MapSubwindows();
	// Initialize the layout algorithm
	fMain_->Resize(fMain_->GetDefaultSize());
	// Map main frame
	fMain_->MapWindow();

	fMain_->HideFrame(hfOptions_);
	fMain_->HideFrame(fHProg_);
    return ;
}		/* -----  end of method NPDGCutSetter::InitMainFrame  ----- */

    void
NPDGCutSetter::OnOpenFile ( const char* fname )
{
    if (runFile_) delete runFile_;

    printf("Opening file...\n");
    runFile_ = new NPDGRunFile(fname, "UPDATE");

    if (!runFile_->IsOpen()) {
        printf("Error opening file: %s \n", fname);
        return;
    }

    fMenuFile_ ->EnableEntry(M_FILE_SAVE);
    fMain_->ShowFrame(hfOptions_);

    fStatusBar_->SetText(fname, 0);

    //nTdcGamma0_->SetIntNumber(runFile_->tdcGamma0_);
    //nBG1Low_->SetIntNumber(runFile_->bg1Low_);
    //nBG1High_->SetIntNumber(runFile_->bg1High_);
    //nBG2Low_->SetIntNumber(runFile_->bg2Low_);
    //nBG2High_->SetIntNumber(runFile_->bg2High_);

    gROOT->cd();
    OnDrawHistograms();

    return ;
}		/* -----  end of method NPDGCutSetter::OnOpenFile  ----- */

    void
NPDGCutSetter::UpdateCuts ( )
{
    nAt_ = cbAT_->GetSelected();
    nBgo_ = cbBGO_->GetSelected();
    return ;
}		/* -----  end of method NPDGCutSetter::UpdateCuts  ----- */

    void
NPDGCutSetter::OnDrawHistograms ( )
{
    if (runFile_ == 0 || !runFile_->IsOpen()) {
        return;
    }

    UpdateCuts();

    printf("Drawing histograms...\n");

    DrawPad1();

    DrawPad2();

    DrawPad3();

    DrawPad4();

    DrawPad5();

    DrawPad6();

    return ;
}		/* -----  end of method NPDGCutSetter::OnDrawHistograms  ----- */

    void
NPDGCutSetter::GetATId ( TString &id)
{
    switch (nAt_) {
        case AT_A:
            id.Form("ADC_AT_A");
            break;
        case AT_B:
            id.Form("ADC_AT_B");
            break;
        case AT_C:
            id.Form("ADC_AT_C");
            break;
        default:
            id.Form("ADC_AT_A");
            break;
    }
    return;
}		/* -----  end of method NPDGCutSetter::GetATId  ----- */

    void
NPDGCutSetter::GetBGOId ( TString &id)
{
    switch (nBgo_) {
        case BGO_L_L:
            id.Form("ADC_BGO_L_L");
            break;
        case BGO_L_R:
            id.Form("ADC_BGO_L_R");
            break;
        case BGO_M:
            id.Form("ADC_BGO_M");
            break;
        case BGO_S_L:
            id.Form("ADC_BGO_S_L");
            break;
        case BGO_S_R:
            id.Form("ADC_BGO_S_R");
            break;
        default:
            id.Form("ADC_BGO_L_L");
            break;
    }
    return;
}		/* -----  end of method NPDGCutSetter::GetBGOId  ----- */

    void
NPDGCutSetter::DrawPad1 ( )
{
    TTree* tree = runFile_->getTree();
    TCanvas *fCanvas = fEcanvas_->GetCanvas();
    fCanvas->cd(1);
    TString id;
    GetATId(id);
    TString str;
    str.Form("%s_T>>h1(2000,0,2000)", id.Data());
    tree->Draw(str.Data(), tcAll_);
    TH1F* h = (TH1F*)gDirectory->Get("h1");
    str.Form("%s Top", id.Data());
    h->SetTitle(str.Data());
    fCanvas->Update();
    return ;
}		/* -----  end of method NPDGCutSetter::DrawPad1  ----- */

    void
NPDGCutSetter::DrawPad2 ( )
{
    TTree* tree = runFile_->getTree();
    TCanvas *fCanvas = fEcanvas_->GetCanvas();
    fCanvas->cd(2);
    TString id;
    GetBGOId(id);
    TString str;
    str.Form("%s>>h2(2000,0,2000)", id.Data());
    tree->Draw(str.Data(), tcAll_);
    TH1F* h = (TH1F*)gDirectory->Get("h2");
    h->SetTitle(id.Data());
    fCanvas->Update();
    return ;
}		/* -----  end of method NPDGCutSetter::DrawPad2  ----- */

    void
NPDGCutSetter::DrawPad3 ( )
{
    TTree* tree = runFile_->getTree();
    TCanvas *fCanvas = fEcanvas_->GetCanvas();
    fCanvas->cd(3);
    tree->Draw("TDC_Beam0>>h3(2000,0,2000)", tcAll_);
    TH1F* h = (TH1F*)gDirectory->Get("h3");
    h->SetTitle("TDC Beam");
    fCanvas->Update();
    return ;
}		/* -----  end of method NPDGCutSetter::DrawPad3  ----- */

    void
NPDGCutSetter::DrawPad4 ( )
{
    TTree* tree = runFile_->getTree();
    TCanvas *fCanvas = fEcanvas_->GetCanvas();
    fCanvas->cd(4);
    TString id;
    GetATId(id);
    TString str;
    str.Form("%s_B>>h4(2000,0,2000)", id.Data());
    tree->Draw(str.Data(), tcAll_);
    TH1F* h = (TH1F*)gDirectory->Get("h4");
    str.Form("%s Bottom", id.Data());
    h->SetTitle(str.Data());
    fCanvas->Update();
    return ;
}		/* -----  end of method NPDGCutSetter::DrawPad4  ----- */

    void
NPDGCutSetter::DrawPad5 ( )
{
    TTree* tree = runFile_->getTree();
    TCanvas *fCanvas = fEcanvas_->GetCanvas();
    fCanvas->cd(5);
    TString atId, bgoId;
    GetATId(atId);
    GetBGOId(bgoId);
    TString str;
    str.Form("sqrt(%s_T*%s_B):%s>>h5(2000,0,2000,2000,0,2000)",
            atId.Data(), atId.Data(), bgoId.Data());
    tree->Draw(str.Data(), tcAll_);
    TH2F* hh = (TH2F*)gDirectory->Get("h5");
    str.Form("%s Mean vs %s", atId.Data(), bgoId.Data());
    hh->SetTitle(str.Data());
    fCanvas->Update();
    return ;
}		/* -----  end of method NPDGCutSetter::DrawPad5  ----- */

    void
NPDGCutSetter::DrawPad6 ( )
{
    TTree* tree = runFile_->getTree();
    TCanvas *fCanvas = fEcanvas_->GetCanvas();
    fCanvas->cd(6);
    tree->Draw("TDC_Beam1>>h6(2000,0,2000)", tcAll_);
    TH1F* h = (TH1F*)gDirectory->Get("h6");
    h->SetTitle("TDC Beam1");
    fCanvas->Update();
    return ;
}		/* -----  end of method NPDGCutSetter::DrawPad6  ----- */

    void
NPDGCutSetter::OnBackgroundRangeSet ( )
{
	TCanvas *fCanvas = fEcanvas_->GetCanvas();
    fCanvas->cd(2);
    DrawBackgroundLine((TH1F*)gDirectory->Get("h2"));
    fCanvas->Update();
    return ;
}		/* -----  end of method NPDGCutSetter::OnBackgroundRangeSet  ----- */

    void
NPDGCutSetter::DrawBackgroundLine ( TH1F *h )
{
    return ;
}		/* -----  end of method NPDGCutSetter::DrawBackgroundLine  ----- */

    void
NPDGCutSetter::OnSaveCuts ( )
{
    if (!runFile_) return;
    //runFile_->tdcGamma0_ = nTdcGamma0_->GetIntNumber();
    //runFile_->bg1Low_ = nBG1Low_->GetIntNumber();
    //runFile_->bg1High_ = nBG1High_->GetIntNumber();
    //runFile_->bg2Low_ = nBG2Low_->GetIntNumber();
    //runFile_->bg2High_ = nBG2High_->GetIntNumber();

    runFile_->SaveCuts();
    return ;
}		/* -----  end of method NPDGCutSetter::OnSaveCuts  ----- */

    void
NPDGCutSetter::OnHandleMenu ( Int_t id )
{
	switch(id) {
		case M_FILE_OPEN:
			{
				static TString dir(".");
				TGFileInfo fi;
				new TGFileDialog(gClient->GetRoot(), fMain_, kFDOpen, &fi);
				if (fi.fFilename) {
					//printf("Open file: %s (dir: %s)\n",
					//		fi.fFilename, fi.fIniDir);
					OnOpenFile(fi.fFilename);
				}
			}
			break;
		case M_FILE_SAVE:
			OnSaveCuts();
			break;
		case M_FILE_PRINT:
			break;
		case M_FILE_PRINTSETUP:
			break;
		case M_FILE_EXIT:
            OnCloseMainWindow();
			break;
        default:break;
    }
    return ;
}		/* -----  end of method NPDGCutSetter::OnHandleMenu  ----- */

void NPDGCutSetter::OnCloseMainWindow() {
	gApplication->Terminate(0);
}

int main(int argc, char **argv) {
    TApplication cutSetterApp("NPDGCutSetterApp",&argc,argv);

    bool verboseMode = false;
    if (argc > 1) {
        verboseMode = (argv[1][0] == '-' && argv[1][1] == 'v');
    }
    else printf("Tip: use -v to have verbose output.\n");

    // Popup the GUI...
    new NPDGCutSetter(gClient->GetRoot(),1050,700, verboseMode);

    cutSetterApp.Run();

    return 0;
}
