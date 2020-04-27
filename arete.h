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
    std::vector<int> m_extremites; ///creer une paire de sommets

public:
    Arete(int indice, std::vector<int> extremites); ///constructeur
    ~Arete();///destructeur
    int getId();
    std::vector<int> getExt();
    void afficher();

};

#endif // ARETE_H_INCLUDED
