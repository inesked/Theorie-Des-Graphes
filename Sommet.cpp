#include "Sommet.h"
#include "arete.h"
#include<iostream>


Sommet::Sommet(int num, std::string nom, std::pair<double,double> coordonnees)
    : m_num{num} , m_nom{nom} , m_coordonnees{coordonnees}
{}


int Sommet::getNum() //id numero du sommet
{
    return m_num;
}

std::string Sommet::getNom() //id lettre du sommet
{
    return m_nom;
}

double Sommet::getCoords1() //coord x du sommet
{
    return m_coordonnees.first;
}

double Sommet::getCoords2() //coord y du sommet
{
    return m_coordonnees.second;
}

void Sommet::afficher() //fct afficher x" "y
{
    std::cout << m_coordonnees.first << " " << m_coordonnees.second;
}

