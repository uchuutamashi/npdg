/**
 * =====================================================================================
 *
 *           @file NPDGRunFile.cxx
 *
 *          @brief 
 *         @detail
 *
 *        @version 1.0
 *           @date 11/24/2014 02:06:20 PM
 *        Revision  none
 *        Compiler  gcc
 *
 *         @author Hongwei Yang (UKY), yhw1630@gmail.com
 *      @copyright  
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include "NPDGRunFile.h"
#include <TParameter.h>
#include <TList.h>

/**
 *--------------------------------------------------------------------------------------
 *       Class:  NPDGRunFile
 *      Method:  NPDGRunFile
 * Description:  constructor
 *--------------------------------------------------------------------------------------
 */
NPDGRunFile::NPDGRunFile ( const char* fname, Option_t* option, const char* ftitle, Int_t compress):
    TFile(fname, option, ftitle, compress)
{
    allCutsDefined_ = false;
    if (IsOpen()) ReadAllCuts();
}  /* -----  end of method NPDGRunFile::NPDGRunFile  (constructor)  ----- */

/**
 *--------------------------------------------------------------------------------------
 *       Class:  NPDGRunFile
 *      Method:  NPDGRunFile
 * Description:  copy constructor
 *--------------------------------------------------------------------------------------
 */
NPDGRunFile::NPDGRunFile ( const NPDGRunFile &other )
{
}  /* -----  end of method NPDGRunFile::NPDGRunFile  (copy constructor)  ----- */

/**
 *--------------------------------------------------------------------------------------
 *       Class:  NPDGRunFile
 *      Method:  ~NPDGRunFile
 * Description:  destructor
 *--------------------------------------------------------------------------------------
 */
NPDGRunFile::~NPDGRunFile ()
{
}  /* -----  end of method NPDGRunFile::~NPDGRunFile  (destructor)  ----- */

/**
 *--------------------------------------------------------------------------------------
 *       Class:  NPDGRunFile
 *      Method:  operator =
 * Description:  assignment operator
 *--------------------------------------------------------------------------------------
 */
    NPDGRunFile&
NPDGRunFile::operator = ( const NPDGRunFile &other )
{
    if ( this != &other ) {
    }
    return *this;
}  /* -----  end of method NPDGRunFile::operator =  (assignment operator)  ----- */

    void
NPDGRunFile::ResetCuts ()
{
    tgCut_ = 0;
    tdcGamma0_ = 0;
    tdcLow_ = 0;
    tdcHigh_ = 0;
    ndLongLow_ = 0;
    ndLongHigh_ = 0;
    bg1Low_ = 0;
    bg1High_ = 0;
    bg2Low_ = 0;
    bg2High_ = 0;
}

    void 
NPDGRunFile::ReadAllCuts() 
{
    printf("Reading tree...\n");
    GetObject("npdg", tTree_); 
    ResetCuts();
    printf("Reading cuts...\n");
    GetObject("tgCut", tgCut_);
    TList* tlCuts = 0;
    GetObject("tlCuts", tlCuts);

    if (tlCuts == 0) return;
    TParameter<int>* p;
    p = (TParameter<int>*) tlCuts->FindObject("tpTdcGamma0");
    if (p) tdcGamma0_ = p->GetVal();
    p = (TParameter<int>*)tlCuts->FindObject("tpTdcLow");
    if (p) tdcLow_ = p->GetVal();
    p = (TParameter<int>*)tlCuts->FindObject("tpTdcHigh");
    if (p) tdcHigh_ = p->GetVal();
    p = (TParameter<int>*)tlCuts->FindObject("tpNdLongLow");
    if (p) ndLongLow_ = p->GetVal();
    p = (TParameter<int>*)tlCuts->FindObject("tpNdLongHigh");
    if (p) ndLongHigh_ = p->GetVal();
    p = (TParameter<int>*)tlCuts->FindObject("tpBG1Low");
    if (p) bg1Low_ = p->GetVal();
    p = (TParameter<int>*)tlCuts->FindObject("tpBG1High");
    if (p) bg1High_ = p->GetVal();
    p = (TParameter<int>*)tlCuts->FindObject("tpBG2Low");
    if (p) bg2Low_ = p->GetVal();
    p = (TParameter<int>*)tlCuts->FindObject("tpBG2High");
    if (p) bg2High_ = p->GetVal();

    allCutsDefined_ = true;
    return;
}

    void
NPDGRunFile::SaveCuts ( )
{
    TList tlCuts;
    TParameter<int> tpTdcLow("tpTdcLow", tdcLow_);
    tlCuts.Add(&tpTdcLow);
    TParameter<int> tpTdcHigh("tpTdcHigh", tdcHigh_);
    tlCuts.Add(&tpTdcHigh);
    TParameter<int> tpNdLongLow("tpNdLongLow", ndLongLow_);
    tlCuts.Add(&tpNdLongLow);
    TParameter<int> tpNdLongHigh("tpNdLongHigh", ndLongHigh_);
    tlCuts.Add(&tpNdLongHigh);
    TParameter<int> tpTdcGamma0("tpTdcGamma0", tdcGamma0_);
    tlCuts.Add(&tpTdcGamma0);
    TParameter<int> tpBG1Low("tpBG1Low", bg1Low_);
    tlCuts.Add(&tpBG1Low);
    TParameter<int> tpBG1High("tpBG1High", bg1High_);
    tlCuts.Add(&tpBG1High);
    TParameter<int> tpBG2Low("tpBG2Low", bg2Low_);
    tlCuts.Add(&tpBG2Low);
    TParameter<int> tpBG2High("tpBG2High", bg2High_);
    tlCuts.Add(&tpBG2High);

    if (tgCut_) WriteObject(tgCut_,"tgCut","WriteDelete");
    WriteObject(&tlCuts,"tlCuts","WriteDelete");

    printf("Cuts saved\n");
    return;
}

