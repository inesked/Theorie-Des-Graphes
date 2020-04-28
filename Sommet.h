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
        std::vector<int> m_successeurs;

    public:

        Sommet(int num, std::string nom, std::pair<double,double> coordonnees);
        int getNum();

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
