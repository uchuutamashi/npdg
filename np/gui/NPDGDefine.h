/**
 * =====================================================================================
 *
 *           @file NPDGDefine.h
 *
 *          @brief 
 *         @detail
 *
 *        @version 1.0
 *           @date 11/24/2014 02:06:27 PM
 *        Revision  none
 *        Compiler  gcc
 *
 *         @author Hongwei Yang (UKY), yhw1630@gmail.com
 *      @copyright  
 *
 * =====================================================================================
 */

#ifndef  NPDGDefine_INC
#define  NPDGDefine_INC

#include <TH1F.h>

#define AT_A	1
#define AT_B	2
#define AT_C	3

#define BGO_L_L	1
#define BGO_L_R	2
#define BGO_M	3
#define BGO_S_L	4
#define BGO_S_R	5

#define PSD_X_AXIS  "ADC_NDShort*1800/(ADC_NDLong+100)"
#define PSD_Y_AXIS  "ADC_NDLong"

#define MAX_TDC             2000
#define MAX_ABSTDC          4000

typedef struct FittedLine {
    // For line y = a*x + b
    Float_t a;
    Float_t b;
    Float_t deltaA;
    Float_t deltaB;
} FittedLine;

FittedLine GetBackgroundLine(TH1F* h, int low1, int high1,
        int low2, int high2, bool useFormula = true);

inline bool InRange(Int_t x, Int_t l, Int_t h) {return x >= l && x <= h;};

#endif   /* ----- #ifndef NPDGDefine_INC  ----- */
