#include "arete.h"

Arete::Arete(int indice, std::pair<int,int> extremites)
    : m_indice{indice}, m_extremites{extremites}
{}

int Arete::getId()
{
    return m_indice;
}

std::pair<int,int> Arete::getExt()
{
   return m_extremites;
}

int Arete::getExt1()
{
    return m_extremites.first;
}

int Arete::getExt2()
{
    return m_extremites.second;
}

int Arete::getPoids()
{
    return m_poids;
}

void Arete::afficher()
{
        std::cout << m_extremites.first << " " << m_extremites.second;
}

