/**
 * =====================================================================================
 *
 *           @file NPDGCutSetter.h
 *
 *          @brief 
 *         @detail
 *
 *        @version 1.0
 *           @date 11/24/2014 03:03:53 PM
 *        Revision  none
 *        Compiler  gcc
 *
 *         @author Hongwei Yang (UKY), yhw1630@gmail.com
 *      @copyright  
 *
 * =====================================================================================
 */


#ifndef  NPDGCutsetter_INC
#define  NPDGCutsetter_INC

#include "NPDGDefine.h"
#include "NPDGRunFile.h"
#include <TQObject.h>
#include <RQ_OBJECT.h>
#include <TGMenu.h>
#include <TGFrame.h>
#include <TGNumberEntry.h>
#include <TRootEmbeddedCanvas.h>
#include <TGStatusBar.h>
#include <TGProgressBar.h>
#include <TGButtonGroup.h>
#include <TCut.h>
#include <TCutG.h>
#include <TGComboBox.h>
#include <TLine.h>

#define RB_TDC_SHORT_ID     1
#define RB_TDC_LONG_ID      2

enum FileMenuEntryId {
	M_FILE_OPEN,
	M_FILE_SAVE,
	M_FILE_SAVEAS,
	M_FILE_PRINT,
	M_FILE_PRINTSETUP,
	M_FILE_EXIT,
};

enum InputFields{
	//ITdcGamma0,
	//IBG1Low,
	//IBG1High,
	//IBG2Low,
	//IBG2High,
};

/**
 * =====================================================================================
 *        @class  NPDGCutSetter
 *        @brief  
 *       @detail
 *
 * =====================================================================================
 */
class NPDGCutSetter
{
	RQ_OBJECT("NPDGCutSetter")
    public:
        /* ====================  LIFECYCLE     ======================================= */
        NPDGCutSetter (const TGWindow *p, UInt_t w, UInt_t h, bool vMode);                             /* constructor      */
        NPDGCutSetter ( const NPDGCutSetter &other );   /* copy constructor */
        ~NPDGCutSetter ();                        /* destructor       */

        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */

        NPDGCutSetter& operator = ( const NPDGCutSetter &other ); /* assignment operator */

        /* ====================  METHODS       ======================================= */
		void OnHandleMenu(Int_t id);
		void OnBackgroundRangeSet();
		void OnSaveCuts();
		void OnDrawHistograms();
		void OnCloseMainWindow();

        /* ====================  DATA MEMBERS  ======================================= */


    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  METHODS       ======================================= */
        void InitMainFrame(const TGWindow *p, UInt_t w, UInt_t h);
        void OnOpenFile(const char* fname);
		void DrawBackgroundLine(TH1F* h);
        void GetATId(TString &id);
        void GetBGOId(TString &id);
        void UpdateCuts();
		void DrawPad1();
		void DrawPad2();
		void DrawPad3();
		void DrawPad4();
		void DrawPad5();
		void DrawPad6();

        /* ====================  DATA MEMBERS  ======================================= */
        bool                isVerboseMode_;
        NPDGRunFile*        runFile_;
		TRootEmbeddedCanvas *fEcanvas_;
		TGMainFrame*	    fMain_;
		TGPopupMenu*	    fMenuFile_;
		TGStatusBar*	    fStatusBar_;
		TGHProgressBar*	    fHProg_;
		TGHorizontalFrame*	hfOptions_;
		TGVerticalFrame*	hfOptions0_;
		TGHorizontalFrame*	hfOptions1_;
		TGHorizontalFrame*	hfOptions2_;
		TGComboBox*		    cbAT_;
		TGComboBox*		    cbBGO_;

		//TGNumberEntryField* nTdcGamma0_;
		//TGNumberEntryField* nBG1Low_;
		//TGNumberEntryField* nBG1High_;
		//TGNumberEntryField* nBG2Low_;
		//TGNumberEntryField* nBG2High_;

		//TLine			tlBg_;
        //TLine*          tlBgCurrent_;

        TCut            tcAll_;
        Int_t           nAt_;
        Int_t           nBgo_;
}; /* -----  end of class NPDGCutSetter  ----- */

#endif   /* ----- #ifndef NPDGCutsetter_INC  ----- */
