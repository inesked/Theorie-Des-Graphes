#include "graphe.h"
#include <fstream>
#include <iostream>
#include <utility>
#include "Svgfile.h"
#include "Sommet.h"
#include <cmath>
//inès
Graphe::Graphe(std::string nomFichier) //lecture de fichier
{
     std::ifstream ifs{nomFichier}; //
            if (!ifs)
                throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier ); //blindage overture du fichier
            ifs >> m_orientation; //lecture de l'orientation
            if ( ifs.fail() ) //si echec
                throw std::runtime_error("Probleme lecture orientation du graphe"); //blindage lecture orientation
            ifs >> m_ordre; //lecture de l'ordre
            if ( ifs.fail() ) //si echec
                throw std::runtime_error("Probleme lecture ordre du graphe"); //blindage de la lecture ordre

            int num0,num2,num3; //3 valeurs dans le txt, la premiere est l'id le deuxieme la premiere coord (x) la deuxieme coord (y)
            std::string let1;
            deg.resize(m_ordre);
            for (int i=0; i<m_ordre; ++i){ //pour i compris entre 0 et l'ordre, on esplore toutes les coord
                ifs>>num0>>let1>>num2>>num3;
                if ( ifs.fail() )
                throw std::runtime_error("Probleme lecture arc"); //blindage, si il n'arrive pas à lire les coordonnées
                m_sommets.push_back(new Sommet{num0, let1 , std::make_pair(num2,num3)}); //creation de la pair avec les coordonnées (x,y)
                deg[i] = 0;
            }
            ifs >> m_taille; //lecture de la taille
            if ( ifs.fail() )
                throw std::runtime_error("Probleme lecture taille du graphe"); //blindage si pb de lecture de la taille
            int num4,num5,num6;
            for (int i=0;i<m_taille;++i)
                /*3 valeurs dans le txt, la premiere est l'id
                le deuxieme le premier sommet qui est extremité de l'arc
                et la deuxieme qui est l'autre extrémitée de l'arc*/
            {
                ifs>>num4>>num5>>num6;
                if ( ifs.fail() )
                throw std::runtime_error("Probleme lecture arc"); //blindage si pb lecture arc
                m_arete.push_back(new Arete{num4, std::make_pair(num5,num6)}); //aijout d'une pair de coord correspondant à un arc
                deg[num5] += 1;
                deg[num6] += 1;
            }

}

void Graphe::Afficher() //affichage du txt
{
    std::cout <<"orientation: "<< m_orientation <<std::endl; //affichage orientation 1 ou 0
    std::cout <<"ordre: "<< m_ordre <<std::endl<<std::endl; //affichage ordre
    for(int i=0; i<m_ordre ; ++i) //lecture de tout les sommets ainsi que leurs id, lettre et coordonnées (x,y)
    {
        std::cout << m_sommets[i]->getNum() << ": " << m_sommets[i]->getNom();
        m_sommets[i]->afficher();
        std::cout << std::endl;
    }
    std::cout <<"taille: "<<m_taille << std::endl; //lecture de la taille du graphe
    for(int i=0; i<m_taille; ++i)
    {
        std::cout << m_arete[i]->getId() << ": ";
        m_arete[i]->afficher();
        std::cout << std::endl;
    }
    std::cout<<std::endl;

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
    /*for(int i=0; i<m_taille; ++i)
    {
        if(m_sommets[i]->getNum() == m_arete[i]->getExt1())
        {
            for(int j=0; j<m_taille ;++i)
            {
                if(m_sommets[j]->getNum() == m_arete[j]->getExt2())
                {
                    svgout.addLines((m_sommets[i]->getCoords1())*100,(m_sommets[i]->getCoords2())*100,(m_sommets[j]->getCoords1())*100,(m_sommets[j]->getCoords2())*100,"black");
                }
            }
        }
    }*/
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





///centralité de vecteur propre normalisé
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
                    //deg[i]=deg[i]+deg[successeurs];
                }
                if(m_arete[j]->getExt2() == m_sommets[i]->getNum())
                {
                    int successeurs = m_arete[j]->getExt2();
                    deg[i]=deg[i]+CVp[successeurs];
                    //deg[i]=deg[i]+deg[successeurs];
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
    std::cout << "voici le vecteur propre normalisé du sommet " << s << ": "<< CVp[s];
}





///centralité de vecteur propre non-normalisé
void Graphe::VecteurPropreNonN()
{

    //CD=deg[ndeg]/(m_ordre-1);
    float lambda;
    float temp;
    int s;
    std::cout << "Rentrer le sommet voulu" << std::endl;
    std::cin >> s;
    std::vector<float> CVp;
    std::vector<float> CD;
    for(int i=0; i< m_ordre ; ++i)
    {
        CVp.push_back(1);
        CD.push_back(0);
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
                    CD[i]=CD[i]+CVp[successeurs];
                    //deg[i]=deg[i]+deg[successeurs];
                }
                if(m_arete[j]->getExt2() == m_sommets[i]->getNum())
                {
                    int successeurs = m_arete[j]->getExt2();
                    CD[i]=CD[i]+CVp[successeurs];
                    //deg[i]=deg[i]+deg[successeurs];
                }

            }
        }
        for(int k=0; k<deg.size(); ++k)
        {
            temp = temp + pow(CD[k],2);

        }
        lambda = sqrt(temp);
        for(int i=0; i<m_ordre; ++i)
        {
            CVp[i] = CD[i]/lambda;
        }
    }
    while(lambda<0.2);
    std::cout << "voici le vecteur propre non-normalisé du sommet " << s << ": "<< CVp[s];
}


