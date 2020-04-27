#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include "Sommet.h"
#include "arete.h"

class Graphe
{
private :
    int m_orientation; //1 element du fichier
    int m_ordre;
    int m_taille; //2e element du fichier
    std::vector <Sommet*> m_sommets; //1er liste du fichier aretes
    std::vector <Arete*> m_arete;
    std::vector <int> deg;

public:
    Graphe();
    Graphe(std::string nomFichier);
    void Afficher();
    void CentraliteDegreNonNorma();
    //void Dijkstra (int s_initial, int s_final);
};



#endif // GRAPHE_H_INCLUDED
