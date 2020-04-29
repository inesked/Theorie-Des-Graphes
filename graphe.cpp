#include "graphe.h"
#include <fstream>
#include <iostream>
#include <utility>
#include "Svgfile.h"
#include "Sommet.h"
#include <cmath>

Graphe::Graphe(std::string nomFichier)
{
     std::ifstream ifs{nomFichier};
            if (!ifs)
                throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
            ifs >> m_orientation;
            if ( ifs.fail() )
                throw std::runtime_error("Probleme lecture orientation du graphe");
            ifs >> m_ordre;
            if ( ifs.fail() )
                throw std::runtime_error("Probleme lecture ordre du graphe");

            int num0,num2,num3;
            std::string let1;
            deg.resize(m_ordre);
            for (int i=0; i<m_ordre; ++i){
                ifs>>num0>>let1>>num2>>num3;
                if ( ifs.fail() )
                throw std::runtime_error("Probleme lecture arc");
                m_sommets.push_back(new Sommet{num0, let1 , std::make_pair(num2,num3)});
                deg[i] = 0;
            }
            ifs >> m_taille;
            if ( ifs.fail() )
                throw std::runtime_error("Probleme lecture taille du graphe");
            int num4,num5,num6;
            for (int i=0;i<m_taille;++i)
            {
                ifs>>num4>>num5>>num6;
                if ( ifs.fail() )
                throw std::runtime_error("Probleme lecture arc");
                m_arete.push_back(new Arete{num4, std::make_pair(num5,num6)});
                deg[num5] += 1;
                deg[num6] += 1;
            }
            for(int i=0; i<m_arete.size(); ++i)
            {
                if(m_orientation == 0)
                {
                    m_sommets[m_arete[i]->getExt1()]->ajouterSucc(m_sommets[m_arete[i]->getExt2()]);
                    m_sommets[m_arete[i]->getExt2()]->ajouterSucc(m_sommets[m_arete[i]->getExt1()]);
                }
                if(m_orientation == 1)
                     m_sommets[m_arete[i]->getExt1()]->ajouterSucc(m_sommets[m_arete[i]->getExt2()]);
            }

}

/*void Graphe::GrapheCharger(std::string nomFichier)
{
    std::ifstream ifs{nomFichier};
    int taille;
    int poids;
    ifs >> taille;
    for(int i=0; i<taille; ++i)
    {
        ifs >> poids;
        m_arete[i]->getPoids() = poids;
    }

}*/

void Graphe::Afficher()
{
    std::cout <<"orientation: "<< m_orientation <<std::endl;
    std::cout <<"ordre: "<< m_ordre <<std::endl<<std::endl;
    for(int i=0; i<m_ordre ; ++i)
    {
        std::cout << m_sommets[i]->getNum() << ": " << m_sommets[i]->getNom() <<" ";
        m_sommets[i]->afficher();
        std::cout << std::endl;
    }
    std::cout <<"taille: "<<m_taille << std::endl;
    for(int i=0; i<m_taille; ++i)
    {
        std::cout << m_arete[i]->getId() << ": ";
        m_arete[i]->afficher();
        std::cout << std::endl;
    }
    std::cout<<std::endl;
    /*for(int i=0; i<m_ordre ; ++i)
    {
         m_sommets[i]->afficherSucc();
         std::cout << std::endl;
    }*/

}

void Graphe::dessinerGraphe() const
{
    Svgfile svgout;
    svgout.addGrid();
    for(int i=0; i<m_ordre; ++i)
    {
        svgout.addDisk((m_sommets[i]->getCoords1())*100,(m_sommets[i]->getCoords2())*100,3,"black");
        svgout.addText((m_sommets[i]->getCoords1())*100,(m_sommets[i]->getCoords2())*100-10,m_sommets[i]->getNom(),"black");
    }
    for(int i=0; i<m_taille; ++i)
    {
        svgout.addLine((m_sommets[m_arete[i]->getExt1()]->getCoords1())*100,(m_sommets[m_arete[i]->getExt1()]->getCoords2())*100,(m_sommets[m_arete[i]->getExt2()]->getCoords1())*100,(m_sommets[m_arete[i]->getExt2()]->getCoords2())*100,"black");
    }
}

///centralité de degré pour non normalisé <=> dégré du sommet
void Graphe::CentraliteDegreNonNorma()
{
    int ndeg;
    std::cout <<"Donnez un numero de sommet pour connaitre sa centralite de degre: ";
    std::cin >> ndeg;
    std::cout << "Le sommet " << ndeg << " a un degres de "<< deg[ndeg] << std::endl;
}

///centralité de degré normalisé <=> deg/(ordre-1)
void Graphe::CentraliteDegreNormalise()
{
    int ndeg, CD;
    CD=deg[ndeg]/(m_ordre-1);
    std::cout << "Le sommet choisi a pour Centralite de degre normalise; CD(s) : " << CD <<std::endl;
}

void Graphe::VecteurPropre()
{
    float lambda;
    float temp;
    int s;
    std::cout << "Rentrer le sommet voulu" << std::endl;
    std::cin >> s;
    std::vector<float> CVp;
    std::vector<float> deg;
    for(int i=0; i< m_ordre ; ++i)
    {
        CVp.push_back(1);
        deg.push_back(0);
    }
    do
    {
        for(int i= 0; i< m_ordre; ++i)
        {
            for(int j=0; j< m_arete.size(); ++j)
            {
                if(m_arete[j]->getExt1() == m_sommets[i]->getNum())
                {
                    int successeurs = m_arete[j]->getExt1();
                    deg[i]=deg[i]+CVp[successeurs];
                }
                if(m_arete[j]->getExt2() == m_sommets[i]->getNum())
                {
                    int successeurs = m_arete[j]->getExt2();
                    deg[i]=deg[i]+CVp[successeurs];
                }

            }
        }
        for(int k=0; k<deg.size(); ++k)
        {
            temp = temp + pow(deg[k],2);
        }
        lambda = sqrt(temp);
        for(int i=0; i<m_ordre; ++i)
        {
            CVp[i] = deg[i]/lambda;
        }
    }
    while(lambda<0.2);
    std::cout << "voici le vecteur propre du sommet " << s << ": "<< CVp[s];
}
