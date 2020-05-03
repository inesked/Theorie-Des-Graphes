#include "arete.h"

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

/*ORIENTATION
void Arete::desinnerA(Svgfile& svgout, Graphe* graphe)
{
    if(graphe->orientation() <=true)
    {
        Couleur noir [0,0,0];
        svgout.addLine (m_sommet[0]->getx()*100,m_sommet[0]->gety()*100,m_sommet[1]->gety()*100, noir); //dessiner arete
        svgout.addText(((m_sommet[0]->getx()*100)+m_sommet[1]->getx()*100)/2,
                       ((m_sommet[0]->gety()*100)*m_sommet[1]->gety()*100)/2, getPoids(), noir); //dessin poid sur mileu arete
    }
    else
    {
        Couleur noir (0,0,0);
        Couleur test(255,150,50);
    svgout.addLine (m_sommet[0]->getx()*100,m_sommet[0]->gety()*100,m_sommet[1]->gety()*100, test); //dessiner arete
    svgout.addText(((m_sommet[0]->getx()*100)+m_sommet[1]->getx()*100)/2,
                       ((m_sommet[0]->gety()*100)*m_sommet[1]->gety()*100)/2, getPoids(), noir); //dessin poid sur mileu arete
    }
}
*/

