#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include <queue>
#include <string>
#include <list>
#include <vector>

///création de la classe Sommet
class Sommet
{
    private:
        ///données qui correspondent au sommet dans la lecture de fichier
        int m_num;///identifiant associé au sommet
        std::string m_nom;///nom associé au sommet
        std::pair <double,double> m_coordonnees;///coordonnees associées au sommet
        std::vector<int> m_successeurs;///vecteur des successeurs (utile pour Dijkstra entre autre

    public:

        Sommet(int num, std::string nom, std::pair<double,double> coordonnees);///constructeur
        int getNum();///getteur

    /*    //accesseur : pour la liste des successeurs
        const std::vector<const Sommet*>& getSuccesseurs()const {return m_successeurs;}
        //pour ajouter un successeur ‡ la liste
        void ajouterSucc(const Sommet*s){
            m_successeurs.push_back(s);
        }
        //mèthode d'affichage
        void afficher() const{
            std::cout<<"     sommet "<<m_num<<" : ";
            for (auto s : m_successeurs) std::cout<<s->getNum()<<" ";
        }
*/

        std::string getNom();
        void afficher();
        double getCoords1();
        double getCoords2();


};


#endif // SOMMET_H_INCLUDED
