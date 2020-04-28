#include "arete.h"

Arete::Arete(int indice, std::pair<int,int> extremites)
    : m_indice{indice}, m_extremites{extremites}
{}

int Arete::getId()
{
    return m_indice;
}

int Arete::getExt1()
{
    return m_extremites.first;
}

int Arete::getExt2()
{
    return m_extremites.second;
}

void Arete::afficher()
{
        std::cout << m_extremites.first << " " << m_extremites.second;
}

