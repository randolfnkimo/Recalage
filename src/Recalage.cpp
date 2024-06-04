#include "Recalage.h"


Recalage::Recalage (Image Iref_, Image I_, int iInter_, int jSim_) {
    Iref = Iref_; I = I_; iInter = iInter_; jSim = jSim_;
    }

double Recalage::operator() (VecDoub & v){  // vecteur de paramètres theta, tx et ty
    double theta = v[0], tx = v[1], ty = v[2];

    Transformation objTf(theta,tx,ty);
    Interpolation * objInter;
    if (iInter == 1){ objInter = new Interpolation1(I);}
    if (iInter == 2){ objInter = new Interpolation2(I);}
    Deformation objDef(*objInter,objTf); // fin définition déformation
    int nl = I.nrows(), nc = I.ncols();
    Image Idef(nl,nc), Imask(nl,nc);


    objDef.deforme(Idef,Imask);

    Image ImaskRef(nl,nc,255); 
    Similarite * objSim;
    if (jSim == 1){ objSim = new Similarite1(Iref,Idef,ImaskRef,Imask);}
    if (jSim == 2){ objSim = new Similarite2(Iref,Idef,ImaskRef,Imask);}
    double res = objSim->ressemblance();
    delete objInter;
    delete objSim; 
    return res;
}



