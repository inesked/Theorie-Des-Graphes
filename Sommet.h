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
        std::vector<int> m_successeurs; //vecteur d'entier avec tout les successeurs du sommet (utile pour Dijkstra entre autre)

    public:

        Sommet(int num, std::string nom, std::pair<double,double> coordonnees);///constructeur
        int getNum();///getteur

       /*  //m�thode d'affichage
        void afficher() const{
            std::cout<<"     sommet "<<m_num<<" : ";
            for (auto s : m_successeurs) std::cout<<s->getNum()<<" ";
        }
*/

        std::string getNom();
        void afficher();
        double getCoords1();
        double getCoords2();
        void ajouterSucc(Sommet *successeurs);
        std::vector<Sommet*> getSucc();
        void afficherSucc();

};


#endif // SOMMET_H_INCLUDED
