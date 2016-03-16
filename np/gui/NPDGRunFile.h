/**
 * =====================================================================================
 *
 *           @file NPDGRunFile.h
 *
 *          @brief 
 *         @detail
 *
 *        @version 1.0
 *           @date 11/24/2014 02:06:11 PM
 *        Revision  none
 *        Compiler  gcc
 *
 *         @author Hongwei Yang (UKY), yhw1630@gmail.com
 *      @copyright  
 *
 * =====================================================================================
 */

#ifndef  NPDGRunFile_INC
#define  NPDGRunFile_INC

#include <TFile.h>
#include <TTree.h>
#include <TCutG.h>

/**
 * =====================================================================================
 *        @class  NPDGRunFile
 *        @brief  
 *       @detail
 *
 * =====================================================================================
 */
class NPDGRunFile: public TFile
{
    ClassDef(NPDGRunFile, 1);
    public:
        /* ====================  LIFECYCLE     ======================================= */
		NPDGRunFile (const char* fname, Option_t* option = "", const char* ftitle = "", Int_t compress = 1);
        NPDGRunFile ( const NPDGRunFile &other );   /* copy constructor */
        virtual ~NPDGRunFile ();                  /* destructor       */

        /* ====================  ACCESSORS     ======================================= */
        bool AllCutsDefined() {return allCutsDefined_;};
        TTree* getTree() {return tTree_;};

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */

        NPDGRunFile& operator = ( const NPDGRunFile &other ); /* assignment operator */

        /* ====================  METHODS       ======================================= */
        void SaveCuts();

        /* ====================  DATA MEMBERS  ======================================= */

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  METHODS       ======================================= */
        void ResetCuts();
		void ReadAllCuts();

        /* ====================  DATA MEMBERS  ======================================= */
        bool allCutsDefined_;
		TTree* 	tTree_;
        TCutG*  tgCut_;
		int 	tdcGamma0_;
		int 	tdcLow_;
		int 	tdcHigh_;
		int 	ndLongLow_;
		int 	ndLongHigh_;
		int 	bg1Low_;
		int 	bg1High_;
		int 	bg2Low_;
		int 	bg2High_;

}; /* -----  end of class NPDGRunFile  ----- */

#endif   /* ----- #ifndef NPDGRunFile_INC  ----- */
