#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include "Svgfile.h"
#include <stdio.h>
#include <iostream>
#include "Sommet.h"
#include "arete.h"
//in�s
class Graphe
{
private :
    int m_orientation; //orient�e ou non si = 1 oui si =0 non, en fonction du txt
    int m_ordre; // nombre de sommet indiqu� dans le txt
    int m_taille; //nombre d'aretes indiqu�s dans le txt
    std::vector <Sommet*> m_sommets; //vect avec les sommets
    std::vector <Arete*> m_arete; //vect avec les aretes
    std::vector <int> deg; //vect avec les degr�s

public:
    //Graphe();
    //Graphe(std::string nomFichier);

    void GrapheChargerPonde(std:: string nomFichierPonde);
    void GrapheCharger(std::string nomFichier);

    void VecteurPropreNonN();
    void Afficher(); //appel de la fonction afficher
    void dessinerGraphe() const; //appel void dessiner graphe comme une constante
    void CentraliteDegreNonNorma(); //premier algo centralit� de degr� non normalis�
    void CentraliteDegreNormalise(); //premier algo centralit� de degr� normalis�
    void VecteurPropre(); //deuxieme algo vecteur propre normalis�
    int Dijkstra (int s_initial, int s_final);
    void CentraliteProxNonN();
    void CentraliteProxN();
    void CentraliteInter();
    std::vector<int> DijkstraAdap(int num_s0, int num_sf);
};



#endif // GRAPHE_H_INCLUDED
