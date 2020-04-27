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
    std::vector<std::pair <Sommet* , Sommet*>> m_extremites; ///creer une paire de sommets

public:
    Arete(int indice, std::pair<Sommet*,Sommet*> extremites); ///constructeur
    ~Arete();///destructeur

};

#endif // ARETE_H_INCLUDED
