#ifndef EVALUATION_H
#define EVALUATION_H

#include "Interpolation.h"
#include "Transformation.h"
#include "Deformation.h"
#include "Similarite.h"
#include "Image.h"
#include "nr3.h"

class Evaluation
{
    private :
        Image Iref, I;
    public :
        Evaluation (Image Iref_, Image I_);
        double operator() (VecDoub & v);
};


#endif // EVALUATION_H