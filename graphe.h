#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include "Svgfile.h"
#include <stdio.h>
#include <iostream>
#include "Sommet.h"
#include "arete.h"
//inès
class Graphe
{
private :
    int m_orientation; //orientée ou non si = 1 oui si =0 non, en fonction du txt
    int m_ordre; // nombre de sommet indiqué dans le txt
    int m_taille; //nombre d'aretes indiqués dans le txt
    std::vector <Sommet*> m_sommets; //vect avec les sommets
    std::vector <Arete*> m_arete; //vect avec les aretes
    std::vector <int> deg; //vect avec les degrés

public:
    Graphe();
    Graphe(std::string nomFichier);
    //void Dijkstra(int num_s0,num_sf);
    void Afficher(); //appel de la fonction afficher
    void dessinerGraphe() const; //appel void dessiner graphe comme une constante
    void CentraliteDegreNonNorma(); //premier algo centralité de degré non normalisé
    void CentraliteDegreNormalise(); //premier algo centralité de degré normalisé
    void VecteurPropre(); //deuxieme algo vecteur propre normalisé
    void VecteurPropreNonN(); //deuxieme algo non normalisé
    //void Dijkstra (int s_initial, int s_final);
};



#endif // GRAPHE_H_INCLUDED
