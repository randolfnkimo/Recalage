#include <iostream>
#include "nr3.h"
#include "Image.h"
#include <fstream>
#include "Point.h"
#include "Transformation.h"
#include "Interpolation.h"
#include "Deformation.h"
#include "Similarite.h"
#include "Evaluation.h"
#include "amoeba.h"
#include "Recalage.h"
void affiche(Image I);

// int main(){

// 	Image Iref, I;
// 	Iref.imread("reference.pgm");
// 	I.imread("floating.pgm");
// 	Evaluation m(Iref,I);
// 	//0.01 est la taille du simplex minimale avant arrêt de l'algo
// 	Amoeba opt(0.01);

// 	/*Point de départ*/
// 	VecDoub ystart(3);
// 	//Initialisation
// 	ystart[0]=2;
// 	ystart[1]=0;
// 	ystart[2]=0;
// 	/*resultat*/
// 	VecDoub yfinal1(3);

// 	yfinal1 = opt.minimize(ystart,2.,m); //2 est la taille du simplex au départ
// 	std::cout << "ystart " << ystart[0] << " " << ystart[1] << " " << ystart[2] << m(ystart) << std::endl;
// 	std::cout << "yfinal1 " << yfinal1[0] << " " << yfinal1[1] << " " << yfinal1[2] << m(yfinal1) << std::endl;

// 	Transformation objTf(yfinal1[0],yfinal1[1],yfinal1[2]);
// 	Interpolation2 objInter(I);
// 	Deformation objDef(objInter,objTf);
// 	int nl = I.nrows(), nc = I.ncols();
// 	Image Idef(nl,nc), Imask(nl,nc);
// 	objDef.deforme(Idef,Imask);
// 	Idef.imwrite("I_recalage.pgm");
// 	Imask.imwrite("Imask.pgm");

// 	return 0;
// }

void affiche(Image I)
{
	for (int i = 0; i < I.nrows(); i++)
	{
		for (int j = 0; j < I.ncols(); j++)
		{
			std::cout << I[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

// int main(){

// 	Image I1(2,2),I2(2,2),Imask1(2,2,255), Imask2(2,2,255);
// 	I1[0][0] = 1;
// 	I1[0][1] = 1;
// 	I1[1][0] = 1;
// 	I1[1][1] = 3;
// 	I2[0][0] = 2;
// 	I2[0][1] = 2;
// 	I2[1][0] = 2;
// 	I2[1][1] = 4;
// 	Imask1[0][0] = 0;
// 	affiche(I1);
// 	affiche(I2);
// 	std::cout << "proba = " << proba(1,2,I1,I2,Imask1,Imask2) << std::endl;
// 	affiche(maskCommun(Imask1,Imask2));
// 	return 0;
// }




int main(){

	Image Iref, I;
	Iref.imread("reference.pgm");
	I.imread("floating.pgm");


	Recalage m(Iref,I,1,1);
	//0.01 est la taille du simplex minimale avant arrêt de l'algo
	Amoeba opt(0.01);

	/*Point de départ*/
	VecDoub ystart(3);
	//Initialisation
	ystart[0]=2;
	ystart[1]=0;
	ystart[2]=0;
	/*resultat*/
	VecDoub yfinal1(3);

	yfinal1 = opt.minimize(ystart,2.,m); //2 est la taille du simplex au départ
	std::cout << "ystart " << ystart[0] << " " << ystart[1] << " " << ystart[2] << m(ystart) << std::endl;
	std::cout << "yfinal1 " << yfinal1[0] << " " << yfinal1[1] << " " << yfinal1[2] << m(yfinal1) << std::endl;

	Transformation objTf(yfinal1[0],yfinal1[1],yfinal1[2]);
	Interpolation1 objInter(I);
	Deformation objDef(objInter,objTf);
	int nl = I.nrows(), nc = I.ncols();
	Image Idef(nl,nc), Imask(nl,nc);
	objDef.deforme(Idef,Imask);
	Idef.imwrite("Idef.pgm");
	Imask.imwrite("Imask.pgm");

	return 0;
}