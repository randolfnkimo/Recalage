#ifndef RECALAGE_H
#define RECALAGE_H

#include "Interpolation.h"
#include "Transformation.h"
#include "Deformation.h"
#include "Similarite.h"
#include "Image.h"
#include "nr3.h"

class Recalage
{
    private :
        Image Iref, I;
        int iInter, jSim;
    public :
        Recalage (Image Iref_, Image I_,int iInter_, int jSim_);
        double operator() (VecDoub & v);
};


#endif // EVALUATION_H