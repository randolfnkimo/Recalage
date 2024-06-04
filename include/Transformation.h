#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H
#include <math.h>
#include "Point.h"

class Transformation{ 
    private :
        double theta, tx, ty;
    public :
        Transformation(double vtheta, double vtx, double vty); // initialisation des attributs
        void transforme(const Point & pi, Point & pf); // applique la transformation linéaire à pi et le stocke dans pf sans modifier pi
};


#endif