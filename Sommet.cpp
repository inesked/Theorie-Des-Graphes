#include "Sommet.h"
#include "arete.h"
#include<iostream>


Sommet::Sommet(int num, std::string nom, std::pair<double,double> coordonnees)
    : m_num{num} , m_nom{nom} , m_coordonnees{coordonnees}
{}


int Sommet::getNum()
{
    return m_num;
}

std::string Sommet::getNom()
{
    return m_nom;
}

double Sommet::getCoords1()
{
    return m_coordonnees.first;
}

double Sommet::getCoords2()
{
    return m_coordonnees.second;
}

void Sommet::ajouterSucc(Sommet *successeurs)
{
    m_successeurs.push_back(successeurs);
}

std::vector<Sommet*> Sommet::getSucc()
{
    return m_successeurs;
}

void Sommet::afficherSucc()
{
    for(int i=0; i<m_successeurs.size(); ++i)
    {
        std::cout << m_successeurs[i] << " ";
    }
}

void Sommet::afficher()
{
    std::cout << m_coordonnees.first << " " << m_coordonnees.second <<" ";
    for(int i=0; i<m_successeurs.size(); ++i)
    {
        std::cout << m_successeurs[i] << " ";
    }
}

