/// Code r�alis� par Roxane Calor In�s Kedjem et Alex Chr�tien
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

std::pair<int,int> Arete::getExt() //extremit�s (2 x coord) de l'arete
{
   return m_extremites;
}

int Arete::getExt1() //extremit� 1
{
    return m_extremites.first;
}

int Arete::getExt2() //extremit� 2
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

