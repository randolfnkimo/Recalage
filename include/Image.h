#ifndef IMAGE_H
#define IMAGE_H
#include "nr3.h"

class Image : public NRmatrix<double> {
	public :
	// Reféfinition des constructeurs
	Image() : NRmatrix(){};
	Image(int n, int m) : NRmatrix(n,m){};
	Image(int n, int m, const double &a) : NRmatrix(n,m,a){};	//Initialize to constant
	Image(int n, int m, const double *a) : NRmatrix(n,m,a){};	// Initialize to array
	Image(const NRmatrix &rhs) : NRmatrix(rhs){};
	
	bool imread(const char * filename);
	void imwrite(const char * filename) const; // je viens d'ajouter le const
};




#endif
