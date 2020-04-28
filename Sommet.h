#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include <queue>
#include <string>
#include <list>
#include <vector>

class Sommet
{
    private:
        int m_num;
        std::string m_nom;
        std::pair <double,double> m_coordonnees;

    public:

        Sommet(int num, std::string nom, std::pair<double,double> coordonnees);
        int getNum();
        std::string getNom();
        void afficher();
        double getCoords1();
        double getCoords2();
};


#endif // SOMMET_H_INCLUDED
