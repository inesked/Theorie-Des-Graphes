/// Code réalisé par Roxane Calor Inès Kedjem et Alex Chrétien
#include "arete.h"
#include "graphe.h"

Arete::Arete(int indice, std::pair<int,int> extremites)
    : m_indice{indice}, m_extremites{extremites}
{}//indice, et coord de l'arete


void Arete::setId(int id)
{
    m_indice = id;
}

int Arete::getId() //iD de l'arete
{
    return m_indice;
}

std::pair<int,int> Arete::getExt() //extremités (2 x coord) de l'arete
{
   return m_extremites;
}

int Arete::getExt1() //extremité 1
{
    return m_extremites.first;
}

int Arete::getExt2() //extremité 2
{
    return m_extremites.second;
}

int Arete::getPoids() // poid de l'arete
{
    return m_poids;
}

void Arete::afficher() //fct affichage
{
        std::cout << m_extremites.first << " " << m_extremites.second;
}

