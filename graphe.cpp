#include "graphe.h"


Graphe::Graphe(std::string nomFichier)
{
    std::ifstream ifs{nomFichier};// ouvre un fichier
    if (!ifs)//test si  le fichier existe
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );

    ifs >> m_ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture m_ordre du graphe");

    ifs >> m_taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture m_ordre du graphe");
/*
    //On créer le vecteur qui va stocker tous les sommets récupérés
    for (int i=0; i<m_ordre; ++i) //parcourt tous les sommets : ordre = nombre de sommet
    {
        int sommet;
        ifs >> sommet;

        //ON CREE UN NOUVEAU SOMMET A CHAQUE FOIS
        m_sommets.push_back(new Sommet((ifs),sommet));//mets les données dans un vecteur de taille "ordre"
    }
    for(auto i=0; i<m_taille; ++i) //parcourt de 0 a nombres d'arêtes
    {
        int id1, id2, poid;//recupère les éléments du fichier mot par moi
        ifs >> id1;//1e element de la ligne
        ifs >> id2;//2e element de la ligne
        ifs >> poid;//3e element de la ligne = distance entre id1 et id2
        m_sommets[id1]->Ajouter_adj(m_sommets[id2], poid);
    }
}
*/
void Graphe::Afficher()
{
    std::cout <<"ordre: "<<m_ordre<<std::endl;
    std::cout <<"taille: "<<m_taille<<std::endl<<std::endl;

    /*std::cout<<"Sommets adjacences : "<<std::endl<<std::endl;
    for(size_t i=0; i<m_sommets.size(); ++i)
    {
        m_sommets[i]->Afficher();
    }
    std::cout<<std::endl;*/
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
