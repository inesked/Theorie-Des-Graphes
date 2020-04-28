#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED
#include <vector>
#include <queue>
#include "Sommet.h"
#include <iostream>

class Arete
{
private:
    int m_poids;
    int m_indice;
    std::pair<int,int> m_extremites; ///creer une paire de sommets

public:
    Arete(int indice, std::pair<int,int> extremites); ///constructeur
    ~Arete();///destructeur
    int getId();
    int getExt1();
    int getExt2();
    int getPoids();
    std::pair<int,int> getExt();
    void afficher();

};

#endif // ARETE_H_INCLUDED
