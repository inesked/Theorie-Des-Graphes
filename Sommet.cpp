#include "Sommet.h"
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

void Sommet::afficher()
{
    std::cout << m_coordonnees.first << " " << m_coordonnees.second;
}

