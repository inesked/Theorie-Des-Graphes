#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include "Svgfile.h"
#include <stdio.h>
#include <iostream>
#include "Sommet.h"
#include "arete.h"

class Graphe
{
private :
    int m_orientation; //oui non
    int m_ordre; // nb sommet
    int m_taille; //nb aretes
    std::vector <Sommet*> m_sommets; //vect avec les sommets
    std::vector <Arete*> m_arete; //vect avec les aretes
    std::vector <int> deg;

public:
    Graphe();
    Graphe(std::string nomFichier);
    //void Dijkstra(int num_s0,int num_sf);
    void Afficher();
    void dessinerGraphe() const;
    void CentraliteDegreNonNorma();
    void CentraliteDegreNormalise();
    void VecteurPropre();
    //void GrapheCharger(std:: string nomFichier);
    //void Dijkstra (int s_initial, int s_final);
};



#endif // GRAPHE_H_INCLUDED
