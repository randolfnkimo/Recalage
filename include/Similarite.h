#ifndef SIMILARITE_H
#define SIMILARITE_H
#include <math.h>
#include "Point.h"
#include "Image.h"

class Similarite { // class virtuelle
    protected :
        Image I1, I2, Imask1, Imask2;
    public :
        Similarite(const Image & I1_, const Image & I2_, const Image & Imask1_, const Image & Imask2_);
        virtual double ressemblance() = 0;
};

class Similarite1 : public Similarite {
    public : 
    Similarite1(const Image & I1, const Image & I2, const Image & Imask1, const Image & Imask2);
    virtual double ressemblance();
};

class Similarite2 : public Similarite {
    public : 
    Similarite2(const Image & I1, const Image & I2, const Image & Imask1, const Image & Imask2);
    virtual double ressemblance();

};


double proba(int x0, int y0, const Image & I1, const Image & I2, const Image & Imask1,const Image & Imask2);
double proba(int x0, const Image & I, const Image & Imask);
Image maskCommun(const Image & Imask1,const Image & Imask2);
#endif