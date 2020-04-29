#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include <queue>
#include <string>
#include <list>
#include <vector>

///cr�ation de la classe Sommet
class Sommet
{
    private:
        int m_num; //numero du sommet (id nombre)
        std::string m_nom; //numero du sommet (id lettre)
        std::pair <double,double> m_coordonnees; //coordonn�es du sommet par pair (x,y)
        std::vector<std::pair<Sommet*,int>> m_successeurs; //vecteur d'entier avec tout les successeurs du sommet (utile pour Dijkstra entre autre)

    public:

        Sommet(int num, std::string nom, std::pair<double,double> coordonnees);///constructeur
        int getNum();///getteur

        std::string getNom();
        void afficher();
        double getCoords1();
        double getCoords2();
        void ajouterSucc(std::pair<Sommet*,int> successeurs);
        std::vector<std::pair<Sommet*,int>> getSucc();
        void afficherSucc();


};


#endif // SOMMET_H_INCLUDED
