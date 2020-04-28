#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED
#include <vector>
#include <queue>
#include "Sommet.h"
#include <iostream>
//inès
class Arete
{
private:
    int m_poids; //initialisation du poid
    int m_indice; //initialisation de l'indice de l'arete
    std::pair<int,int> m_extremites; //creation d'une paire de sommets

public:
    Arete(int indice, std::pair<int,int> extremites); //constructeur de la paire
    ~Arete();// destructeur de la paire
    int getId(); //initialisation de l'iD
    int getExt1(); //initialisation de la premiere extremitée
    int getExt2(); //affichage
    void afficher(); //affichage

};

#endif // ARETE_H_INCLUDED
