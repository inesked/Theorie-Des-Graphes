#include "arete.h"

Arete::Arete(int indice, std::vector<int> extremites)
    : m_indice{indice}, m_extremites{extremites}
{}

int Arete::getId()
{
    return m_indice;
}

std::vector<int> Arete::getExt()
{
    return m_extremites;
}

void Arete::afficher()
{
    for(int i=0; i<m_extremites.size(); ++i)
        std::cout << m_extremites[i] << " ";
}

