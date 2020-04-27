#include "graphe.h"
#include <fstream>
#include <iostream>

Graphe::Graphe(std::string nomFichier)
{
    std::ifstream ifs{nomFichier};// ouvre un fichier
    if (!ifs)//test si  le fichier existe
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
//orientation
    ifs >> m_orientation;
    if ( ifs.fail() )
        throw std::runtime_error("Problème lecture m_orientation du graphe");

    ifs >> m_ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Problème lecture m_ordre du graphe");

//sommet
    int num;
    std::string nom;
    int x,y;
    for (int i=0; i<m_ordre; ++i)
    {
        ifs >> num >> nom >> x >> y;
        m_sommets.push_back(new Sommet{num, nom , std::make_pair(x,y)});
    }

    ifs >> m_taille;
    if ( ifs.fail() )
        throw std::runtime_error("Problème lecture m_ordre du graphe");

//arete

    int id,num1,num2;
    for(int i = 0; i<m_taille; ++i)
    {
        ifs >> id >> num1 >> num2;// a modifier si orientation
        m_arete.push_back(new Arete{id, std::make_pair(m_sommets[num1],m_sommets[num2])});
    }

}

void Graphe::Afficher()
{
    std::cout <<"orientation: "<<m_orientation <<std::endl;
    std::cout <<"ordre: "<<m_ordre <<std::endl<<std::endl;
    for(int i=0; i<m_ordre ; ++i)
    {
        std::cout << m_sommets[i]->getNum() << ": " << m_sommets[i]->afficher() << std::endl;
    }
    std::cout<<std::endl;
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
