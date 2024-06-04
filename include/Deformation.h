#ifndef __DEFORMATION_H__
#define __DEFORMATION_H__
#include "Interpolation.h"
// #include "Interpolation1.h" // Quand je travaillais sur mon pc j'ai separe Interpolation1 et Interpolation
#include "Transformation.h"
#include "Image.h"

class Deformation
{
    private:
    Interpolation * pInter;
    Transformation Tf;

    public:

    Deformation(Interpolation &objInter, const Transformation & objTf);
    void deforme(Image & Idef, Image & Imask);
};
#endif // __DEFORMATION_H__