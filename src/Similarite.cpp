#include "Similarite.h"
#include "nr3.h"

Similarite::Similarite(const Image & I1_, const Image & I2_, const Image & Imask1_, const Image & Imask2_){
    I1 = I1_; I2 = I2_; Imask1 = Imask1_; Imask2 = Imask2_;
}

Similarite1::Similarite1(const Image & I1_, const Image & I2_, const Image & Imask1_, const Image & Imask2_)
    : Similarite(I1_,I2_,Imask1_,Imask2_) {}

double Similarite1::ressemblance(){  // les matrices ont mêmes dimensions
    int nl = I1.nrows();
    int nc = I2.ncols();
    int N = nl*nc; 
    double S = 0;
    double Smask = 0;
    for (int i(0);i<nl;i++){
        for (int j(0);j<nc;j++){
            S += (I2[i][j] - I1[i][j])*(I2[i][j] - I1[i][j])*Imask1[i][j]*Imask2[i][j];
            Smask += Imask1[i][j]*Imask2[i][j];
        }
    }
    S = S/(Smask);
    return S;
}
Similarite2::Similarite2(const Image & I1_, const Image & I2_, const Image & Imask1_, const Image & Imask2_)
    : Similarite(I1_,I2_,Imask1_,Imask2_) {}

double Similarite2::ressemblance(){  // les matrices ont mêmes dimensions
    int nl = I1.nrows();
    int nc = I2.ncols();
    // Définition des matrices à niveaux de gris réduites : 0 à 15
    Image I1q(nl,nc);
    Image I2q(nl,nc);
    for (int i=0;i<nl;i++){
        for (int j=0;j<nc;j++){
            I1q[i][j] = floor((I1[i][j])/16)*(Imask1[i][j])*(Imask1[i][j]); // vaut 0 si x,y not in support commun
            I2q[i][j] = floor((I2[i][j])/16)*(Imask2[i][j])*(Imask2[i][j]);
        }
    }
    // Définition des matrices de probabilités
    VecDoub p1(16);
    VecDoub p2(16);
    NRmatrix<double> p12(16,16); 
    Image Imask = maskCommun(Imask1,Imask2);

    for (int k=0;k<16;k++){
        p1[k] = proba(k,I1q,Imask);
        p2[k] = proba(k,I2q,Imask);
    }
    
    for (int x0=0;x0<16;x0++){
        for (int y0=0;y0<16;y0++){
            p12[x0][y0] = proba(x0,y0,I1q,I2q,Imask1,Imask2);
        }
    }

    // Critère de l'information mutuelle
    double S = 0;
    for (int x0=0;x0<16;x0++){
        for (int y0=0;y0<16;y0++){
            S += (p12[x0][y0])*log((p12[x0][y0])/(p1[x0]*p2[y0]));
        }
    }

    return S;
}


// Fonctions utiles à Similarite2


double proba(int x0, int y0, const Image & I1, const Image & I2, const Image & Imask1,const Image & Imask2){
    int nl = I1.nrows();
    int nc = I1.ncols();
    int N = 0;
    double S = 0;
    for (int i=0;i<nl;i++){
        for (int j=0;j<nc;j++){
            if ((Imask1[i][j] != 0) && (Imask2[i][j] != 0)){
                N++;
                if ((I1[i][j] == x0) && (I2[i][j] == y0)){
                    S += 1;
                }                
            }
        }
    }
    return S/N;
}


double proba(int x0, const Image & I, const Image & Imask){
    int nl = I.nrows();
    int nc = I.ncols();
    int N = 0;
    double S = 0;
    for (int i=0;i<nl;i++){
        for (int j=0;j<nc;j++){
            if (Imask[i][j] != 0){
                N++; std::cout << "N = " << N << std::endl;
                if (I[i][j] == x0) {
                    S += 1; std::cout << "S = " << N << std::endl;
                }                
            }
        }
    }
    return S/N; std::cout << "Sfinal = " << S << std::endl;
}

Image maskCommun(const Image & Imask1,const Image & Imask2){
    int nl = Imask1.nrows();
    int nc = Imask1.ncols();
    Image Imask(nl,nc,255);
    for (int i=0;i<nl;i++){
        for (int j=0;j<nc;j++){
            if ((Imask1[i][j] == 0) || (Imask2[i][j] == 0)){
                Imask[i][j] = 0;
            }
        }
    }
    return Imask;
}