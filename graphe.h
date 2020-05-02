#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include "Svgfile.h"
#include <stdio.h>
#include <iostream>
#include "Sommet.h"
#include "arete.h"
#include <fstream>
//in�s

class Graphe
{
private :
    int m_orientation; //orient�e ou non si = 1 oui si =0 non, en fonction du txt
    int m_ordre; // nombre de sommet indiqu� dans le txt
    int m_taille; //nombre d'aretes indiqu�s dans le txt
    std::vector <Sommet*> m_sommets; //vect avec les sommets
    std::vector <Arete*> m_arete; //vect avec les aretes
    std::vector <float> deg; //vect avec les degr�s

public:

    std::ofstream fichier;
    std::ofstream fichier1;
    void GrapheChargerPonde(std:: string nomFichierPonde);
    void GrapheCharger(std::string nomFichier);
    std::vector<float> VecteurPropreNonN();
    void Afficher(); //appel de la fonction afficher
    void dessinerGraphe(); //appel void dessiner graphe comme une constante
    void CentraliteDegreNonNorma(); //premier algo centralit� de degr� non normalis�
    void CentraliteDegreNormalise(); //premier algo centralit� de degr� normalis�
    std::vector<float> VecteurPropre(); //deuxieme algo vecteur propre normalis�
    int Dijkstra (int s_initial, int s_final);
    float CentraliteProxNonN(int num_s0);
    float CentraliteProxN(int num_s0);
    void CentraliteInter();
    std::vector<int> DijkstraAdap(int num_s0, int num_sf);
    void SauvegardeGraphe();
    void SuppArete(int Ext1,int Ext2);
    void Connexite();
};



#endif // GRAPHE_H_INCLUDED
