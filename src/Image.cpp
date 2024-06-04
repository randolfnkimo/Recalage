#include "Image.h"
#include <fstream>
#include "string.h"
using namespace std;


bool Image::imread(const char* filename)
{
    ifstream lecture(filename);
    const string fileType = "P2";
    string fileTypeRead;
    double nrows, ncols, ng;
    bool out = true;
    if (!lecture.fail())
    {
        lecture >> fileTypeRead;
        cout << "fileTypeRead: " << fileTypeRead <<endl;;

        if (fileTypeRead == fileType)
            {out = out & true;}
        else
            {out = out & false;}

        if (not out)
        {
            cout << "la lecture a echoue" << endl;
            return out;
        }
        
        else
        {   cout << "La lecture a ete effectue" << endl;
            lecture >> nrows;
            lecture >> ncols;
            lecture >> ng;
            assign(nrows,ncols,0);

            for (int i(0); i<nrows; i++) // Variation suivant les lignes
            {
                for (int j(0); j<ncols; j++) // Variation suivant les colonnes
                
                    lecture >> v[i][j];
            }
            return out;
        }
        
           
        

    }lecture.close();
    return false;

}

void Image::imwrite(const char* filename) const // je viens d'ajouter le const
{
    ofstream write(filename);
    string fileType = "P2";

    write << fileType << "  " << nn << "  " << mm << "  "<< 255 << endl; // Premiere ligne du fichier texte

    for (int i(0); i<nn; i++)
    {
        for (int j(0); j<mm; j++)
        {
            int a = v[i][j];
            if (a<0)
                a=0;
            if (a>255)
                a=255;
                
            write << a << " ";
        }
    }
    
}

