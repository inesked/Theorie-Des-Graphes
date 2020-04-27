#include "Sommet.h"
#include<iostream>


Sommet::Sommet(int num, std::string nom, std::pair<int,int> coordonnees)
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

std::pair<int,int> Sommet::getCoords()
{
    return m_coordonnees;
}

void Sommet::afficher()
{
    std::cout << m_coordonnees.first << " " << m_coordonnees.second;
}

