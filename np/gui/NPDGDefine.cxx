/**
 * =====================================================================================
 *
 *           @file NPDGDefine.cxx
 *
 *          @brief 
 *         @detail
 *
 *        @version 1.0
 *           @date 11/25/2014 11:24:52 AM
 *        Revision  none
 *        Compiler  gcc
 *
 *         @author Hongwei Yang (UKY), yhw1630@gmail.com
 *      @copyright  
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include "NPDGDefine.h"
    FittedLine
GetBackgroundLine ( TH1F* h, int low1, int high1, int low2, int high2, bool useFormula)
{
    FittedLine line;
    if (h == 0 || low1 >= high1 || high1 >= low2 || low2 >= high2) 
        return line;
    // for y = theA * x + theB;

    if (useFormula) {

        // method 1. from formula
        float sum = 0, sumX = 0, sumY = 0, sumXX = 0, sumXY = 0, yi;
        for (int i = low1; i < high1; i++) {
            yi = h->GetBinContent(i);
            //if (yi == 0) continue;
            sum += 1.0;
            sumX += 1.0 * i;
            sumY += 1.0 * yi;
            sumXX += 1.0 * i * i;
            sumXY += 1.0 * i * yi;
        }
        for (int i = low2; i < high2; i++) {
            //yi = h->Integral(h->FindBin(i),h->FindBin(i+1)-1);
            yi = h->GetBinContent(i);
            //if (yi == 0) continue;
            sum += 1.0;
            sumX += 1.0 * i;
            sumY += 1.0 * yi;
            sumXX += 1.0 * i * i;
            sumXY += 1.0 * i * yi;
        }
        float delta = sum * sumXX - sumX * sumX;
        if (delta != 0) {
            line.a = (sum * sumXY - sumX * sumY) / delta;
            line.b = (sumXX * sumY - sumX * sumXY) / delta;
            line.deltaA = sumXX / delta;
            line.deltaB = sum / delta;
        }
        //printf("sum: %.2f, sumX: %.2f, sumY: %.2f\n", sum, sumX, sumY);
        //printf("delta: %.2f, a: %.6f, b: %.2f\n", delta, line.a, line.b);
    }
    else {
        // method 2. from iteration
        float x1 = (high1 + low1) / 2;
        float x2 = (high2 + low2) / 2;
        float y1 = h->Integral(low1, high1) / (high1 - low1);
        float y2 = h->Integral(low2, high2) / (high2 - low2);
        // initial a, b
        float iA = (y2 - y1) / (x2 - x1);
        float iB = y1 - iA * x1;
        float chi2, d, minChi2 = 100000000;
        float ei;
        // for a range of a and b
        for (float a = iA - 0.2; a < iA + 0.2; a += 0.01) 
            for (float b = 0; b < 2 * iB; b += iB/10.) {
                // for all data range
                chi2 = 0;
                for (int i = low1; i < high1; i++) {
                    ei = a * i + b;
                    d = h->GetBinContent(i) - ei;
                    if (ei < 1) ei = 1;
                    chi2 += d * d / ei;
                }
                for (int i = low2; i < high2; i++) {
                    ei = a * i + b;
                    d = h->GetBinContent(i) - ei;
                    if (ei < 1) ei = 1;
                    chi2 += d * d / ei;
                }
                if (chi2 < minChi2) {
                    line.a = a;
                    line.b = b;
                    minChi2 = chi2;
                    //printf("minChi2: %.2f, a: %.2f, b: %.2f\n", minChi2, line.a, line.b);
                }
            }
    } 
    return line;
}
