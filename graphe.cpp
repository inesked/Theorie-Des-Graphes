#include "graphe.h"
#include <fstream>
#include <iostream>
#include <utility>
#include "Svgfile.h"

Graphe::Graphe(std::string nomFichier)
{
     std::ifstream ifs{nomFichier};
            if (!ifs)
                throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
            ifs >> m_orientation;
            if ( ifs.fail() )
                throw std::runtime_error("Probleme lecture orientation du graphe");
            int ordre;
            ifs >> m_ordre;
            if ( ifs.fail() )
                throw std::runtime_error("Probleme lecture ordre du graphe");

            /*int num0,num2,num3;
            char let1;
            deg.resize(ordre);
            for (int i=0; i<ordre; ++i){
                ifs>>num0>>let1>>num2>>num3;
                if ( ifs.fail() )
                throw std::runtime_error("Probleme lecture arc");
                deg[i] = 0;
            }
            int taille;
            ifs >> taille;
            if ( ifs.fail() )
                throw std::runtime_error("Probleme lecture taille du graphe");
            /*int num4,num5,num6;
            for (int i=0;i<taille;++i)
            {
                ifs>>num4>>num5>>num6;
                if ( ifs.fail() )
                throw std::runtime_error("Probleme lecture arc");
                deg[num5] += 1;
                deg[num6] += 1;
            }*/




//sommet
    int num;
    std::string nom;
    double x,y;
    for (int i=0; i<m_ordre; ++i)
    {
        ifs >> num >> nom >> x >> y;
        m_sommets.push_back(new Sommet{num, nom , std::make_pair(x,y)});
    }

    ifs >> m_taille;
    if ( ifs.fail() )
        throw std::runtime_error("Problème lecture m_ordre du graphe");

//arete

    int id,numero1,numero2;
    for(int i = 0; i<m_taille; ++i)
    {
        std::vector<int> extremites;
        ifs >> id >> numero1 >> numero2;// a modifier si orientation
        extremites.push_back(numero1);
        extremites.push_back(numero2);
        m_arete.push_back(new Arete{id,extremites});
    }

}

void Graphe::Afficher()
{
    std::cout <<"orientation: "<< m_orientation <<std::endl;
    std::cout <<"ordre: "<< m_ordre <<std::endl<<std::endl;
    for(int i=0; i<m_ordre ; ++i)
    {
        std::cout << m_sommets[i]->getNum() << ": " << m_sommets[i]->getNom();
        m_sommets[i]->afficher();
        std::cout << std::endl;
    }
    std::cout <<"taille: "<<m_taille << std::endl;
    for(int i=0; i<m_taille; ++i)
    {
        std::cout << m_arete[i]->getId() << ": ";
        m_arete[i]->afficher();
        std::cout << std::endl;
    }
    std::cout<<std::endl;

}

void Graphe::dessinerGraphe() const
{
    Svgfile svgout;
    svgout.addGrid();
    for(int i=0; i<m_ordre; ++i)
    {
        svgout.addDisk((m_sommets[i]->getCoords1())*100,(m_sommets[i]->getCoords2())*100,3,"black");
        svgout.addText((m_sommets[i]->getCoords1())*100,(m_sommets[i]->getCoords2())*100-10,m_sommets[i]->getNom(),"black");
    }
    /*
    for(int i=0; i<m_taille; ++i)
    {
        svgout.addLine()
    }*/

}
/*
/// Comparateur de sommet selon leur distance:
/// (necessaire pour la piority_queue)
bool operator<(Sommet a, Sommet b)
{
    if(a.getDistance()>b.getDistance())
    {
        return true;
    }
    else
    {
        return false;
    }
}
*/
/*
void Graphe::Dijkstra(int s_initial, int s_final)
{
    //VARIABLES
    std::vector<Sommet*> predeceseur;

    //Création d'une file de priorité = priority_queue = file qui permet des comparaisons et donc les tri
    std::priority_queue<Sommet*> file_priorite;

    //SOMMET INITIAL
    m_sommets[s_initial]->setDistance(0); //poid = 0 pour initial
    file_priorite.push(m_sommets[s_initial]); //ajouter le sommet initial à la file de priorité : poid = 0

    while (!file_priorite.empty()) //tant que la file de priorite n'est pas vide
    {
        //récupérer les valeurs du premier élément de la file de priorité = élément avec le plus petit poid
        Sommet* sommet_traitement = file_priorite.top();// on recupère le sommet adjacent
        int poid = sommet_traitement->getDistance();

        file_priorite.pop(); //enlever le sommet traité de la file de priorité
        std::vector<std::pair<Sommet*,int>> adjacent = sommet_traitement->getAdj(); //on recupere les adjacents

        for(auto i : adjacent)//pour chaque adjacent du sommet en traitement
        {
                Sommet* adj = i.first;
                int poid2 = i.second;

                //si la distance entre le sommet en traitement et adj < distance poid 2
                if (poid + poid2 < adj->getDistance())
                {
                    std::cout <<"poid " << poid << std::endl;
                    std::cout <<"poid2 " << poid2 << std::endl;

                    //on met a jour la distance entre le sommet traité et son adjacent
                    adj->setDistance(poid + poid2);//distance entre adj et adj2 + distance entre adj et sommet traité

                    predeceseur.push_back(adj); //sommet traitement est predeceseur de adj
                    file_priorite.push(adj);//ajouter le sommet adjacent a la file de priorité
                }
            }
    }
    //AFFICHAGE
    for(int i=0; i<m_ordre; ++i){
        std::cout<<"Chemin pour le noeud " <<s_initial << " au noeud " << s_final << " a un poid de " << m_sommets[s_final]->getDistance() << std::endl;

        for (auto i = NULL; i<predeceseur.size(); ++i){
            //Affichage du chemin
            std::cout<< "<-- " << predeceseur[i]->getId()<< std::endl;
        }
    }
}
*/


///centralité de degré pour non normalisé <=> dégré du sommet
void Graphe::CentraliteDegreNonNorma()
{
    int ndeg;
    std::cout <<"Donnez un numero de sommet pour connaitre sa centralite de degre: ";
    std::cin >> ndeg;
    std::cout << "Le sommet " << ndeg << " a un degres de "<< deg[ndeg] << std::endl;
}
/*
///centralité de degré normalisé <=> deg/(ordre-1)
void Graphe::CentraliteDegreNormalise()
{
    int const ndeg, ordre; CD(1);
    CD=ndeg/(ordre-1)
    std::cout << "Le sommet choisi à pour Centralité de degré normalisé; CD(s) : " << CD <<std::endl;
}
*/

