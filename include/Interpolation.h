#ifndef INTERPOLATION_H
#define INTERPOLATION_H
#include <math.h>
#include "Point.h"
#include "Image.h"

class Interpolation { // class virtuelle
    protected :
        Image I;
    public :
        Interpolation(const Image & I_);
        virtual bool interpole(const Point & pf, double & ng) = 0;
};

class Interpolation1 : public Interpolation {
    public : 
    Interpolation1(const Image & I_);
    virtual bool interpole(const Point & pf, double & ng);
};

class Interpolation2 : public Interpolation {
    public : 
    Interpolation2(const Image & I_);
    virtual bool interpole(const Point & pf, double & ng);
};

#endif