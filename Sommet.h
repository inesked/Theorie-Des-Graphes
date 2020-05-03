#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include <queue>
#include <string>
#include <list>
/// Code réalisé par Roxane Calor Inès Kedjem et Alex Chrétien
#include <vector>
//#include "graphe.h"

///cr�ation de la classe Sommet
class Sommet
{
    private:
        int m_num; //numero du sommet (id nombre)
        std::string m_nom; //numero du sommet (id lettre)

        std::pair <double,double> m_coordonnees; //coordonn�es du sommet par pair (x,y)
        std::vector<std::pair<Sommet*,int>> m_successeurs; //vecteur d'entier avec tout les successeurs du sommet (utile pour Dijkstra entre autre)

    public:
        std::vector<int> txtaffsuccfirst;
        std::vector<int> txtaffsuccsecond;

        float getLambda();
        int getDeg();
        Sommet(int num, std::string nom, std::pair<double,double> coordonnees);///constructeur
        int getNum();///getteur
        std::string getNom();
        void afficher();
        void afficherFichier();
        double getCoords1();
        double getCoords2();
        int getSuccSize();
        void ajouterSucc(std::pair<Sommet*,int> successeurs);
        std::vector<std::pair<Sommet*,int>> getSucc();
        void afficherSucc();
        int returnSuccFirst(int i);
        int returnSuccSecond(int i);
        void SuppAdj(Sommet* a);

};


#endif // SOMMET_H_INCLUDED
