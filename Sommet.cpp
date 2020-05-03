/// Code r�alis� par Roxane Calor In�s Kedjem et Alex Chr�tien
#include "Sommet.h"
#include "arete.h"
#include "graphe.h"
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



void Sommet::ajouterSucc(std::pair<Sommet *,int> successeurs) //Ajout d'un successeur
{
    m_successeurs.push_back(successeurs);
}

std::vector<std::pair<Sommet*,int>> Sommet::getSucc() //renvoie le successeur
{
    return m_successeurs;
}

int Sommet::getSuccSize(){
    return m_successeurs.size();
}

void Sommet::afficherSucc()
{
    for(int i=0; i<m_successeurs.size(); ++i)
    {
        std::cout <<  (m_successeurs[i].first)->getNum() << "(" << m_successeurs[i].second << ")" << " ";
    }
}

int Sommet::returnSuccFirst(int i){
    return (m_successeurs[i].first)->getNum();
    }
int Sommet::returnSuccSecond(int i){
    return m_successeurs[i].second;
}

void Sommet::afficher() //fct afficher x" "y
{
    std::cout << m_coordonnees.first << " " << m_coordonnees.second <<" ";
}

void Sommet::SuppAdj(Sommet* a)
{
    for(int i=0; i<m_successeurs.size();++i)
    {
        if(m_successeurs[i].first == a)
            m_successeurs.erase(m_successeurs.begin()+i);
    }
}

/*
void Sommet::Connexite(int ext1, int&l)
{
    if(getCouleur()==2)//si il est noir
    {
        return;
    }

    if(ext1==getNum())
    {
        l++;
        return;
    }
    m_couleur = 2;

    for(int i=0; i<m_adjacents.size(), ++i)
    {
        m_adjacents[i]->connexite (ext1,l);
    }
}*/
