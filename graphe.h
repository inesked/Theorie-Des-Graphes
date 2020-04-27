#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED

#include <stdio.h>

#include "Sommet.h"

class Graphe
{
private :
    int m_orientation; //1 element du fichier
    int m_ordre;
    int m_taille; //2e element du fichier
    std::vector <Sommet*> m_sommets; //1er liste du fichier aretes
    std::vector <std::pair<Sommet*, Sommet*>> m_arete;

public:
    Graphe();
    Graphe(std::string nomFichier);
    void Afficher();
    //void Dijkstra (int s_initial, int s_final);
};



#endif // GRAPHE_H_INCLUDED
