#include "Transformation.h"

Transformation::Transformation(double vtheta, double vtx, double vty){
    theta = vtheta; tx = vtx; ty = vty; // theta est en degré
}

void Transformation::transforme(const Point & pi, Point & pf){
    pf = pi;
    pf.rotationner(theta);
    pf.translater(tx,ty);
}

/*Exemple utilisation

int main(){
    Point A(2,3);
    Point B;
    Transformation Tf(3.14,2,4);
    Tf.transforme(A,B);
}

*/