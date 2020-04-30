#include "graphe.h"
#include <fstream>
#include <iostream>
#include <utility>
#include "Svgfile.h"
#include "Sommet.h"
#include "arete.h"
#include <cmath>
#include <vector>
Graphe::Graphe(std::string nomFichier) //lecture de fichier
{
    fichier.open("resultat.txt");
    if(fichier.bad()) std::cout << "Erreur ecriture de fichier";
    fichier << "Voici les resultats de la console : " << std::endl;
    fichier << "************************************" << std::endl;

     std::ifstream ifs{nomFichier}; //lecture
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
                m_arete.push_back(new Arete{num4, std::make_pair(num5,num6)}); //ajout d'une pair de coord correspondant à un arc
                deg[num5] += 1;
                deg[num6] += 1;
            }
            GrapheCharger("ponde_etoile1.txt");
}

/*void Graphe::AfficherFichier()
{
    fichier << "Voici les resultats de la console : " << std::endl;
    fichier << "************************************" << std::endl;
    for (int i=0 ; i<m_sommets.size() ; ++i)
    {
        fichier<<m_sommets[i]->getCoords1()<<std::endl;

    }
}*/

void Graphe::GrapheCharger(std::string nomFichier)
{
    std::ifstream ifs{nomFichier};
    int taille;
    int poids;
    int id;
    ifs >> taille;
    for(int i=0; i<taille; ++i)
    {
        ifs >> id >> poids;
            if(m_orientation == 0)
            {
                    m_sommets[m_arete[id]->getExt1()]->ajouterSucc(std::make_pair(m_sommets[m_arete[id]->getExt2()],poids));
                    m_sommets[m_arete[id]->getExt2()]->ajouterSucc(std::make_pair(m_sommets[m_arete[id]->getExt1()],poids));
            }
            if(m_orientation == 1)
                     m_sommets[m_arete[id]->getExt1()]->ajouterSucc(std::make_pair(m_sommets[m_arete[id]->getExt2()],poids));
    }

}

void Graphe::Afficher() //affichage du txt
{
    fichier << "Nous avons a faire au graphe suivant :"<<std::endl<<std::endl;
    std::cout <<"orientation: "<< m_orientation <<std::endl; //affichage orientation 1 ou 0 dans la console
    fichier << "orientation: "<< m_orientation <<std::endl; //affichage orientation 1 ou 0 dans le txt
    //fichier << "************************************" << std::endl;
    std::cout <<"ordre: "<< m_ordre <<std::endl<<std::endl; //affichage ordre dans la console
    fichier <<"ordre: "<< m_ordre <<std::endl<<std::endl; //affichage ordre dans le txt
    //fichier << "************************************" << std::endl;
    for(int i=0; i<m_ordre ; ++i) //lecture de tout les sommets ainsi que leurs id, lettre et coordonnées (x,y)
    {
        std::cout << m_sommets[i]->getNum() << ": " << m_sommets[i]->getNom() <<" ";
        m_sommets[i]->afficher();
        std::cout << std::endl;///affichage dans la console

        fichier << m_sommets[i]->getNum() << ": " << m_sommets[i]->getNom() <<" ";
        fichier << m_sommets[i]->getCoords1()<<" ";
        fichier << m_sommets[i]->getCoords2()<<" ";
        fichier << std::endl;///affichage dans le txt
    }
    std::cout <<"taille: "<<m_taille << std::endl; //affichage de la taille du graphe dans la console
    fichier <<"taille: "<<m_taille << std::endl; //affichage de la taille du graphe dans le .txt
    ///fichier << "************************************" << std::endl;
    for(int i=0; i<m_taille; ++i)
    {
        std::cout << m_arete[i]->getId() << ": ";
        m_arete[i]->afficher();
        std::cout << std::endl;///affichage dans la console

        fichier << m_arete[i]->getId() << ": ";
        fichier << m_arete[i]->getExt1()<<" ";
        fichier << m_arete[i]->getExt2()<<" ";
        fichier << std::endl;///affichage de le txt*/
    }
    std::cout<<std::endl;
    fichier << std::endl;
    std::cout << "voici les successeurs de chaque sommet:" << std::endl;///affichage successeur dans la console
    fichier << "************************************" << std::endl;
    fichier << "voici les successeurs de chaque sommet:" << std::endl;///affichage successeur dans le txt
    for(int i=0; i<m_ordre ; ++i)
    {
        std::cout << m_sommets[i]->getNum() <<": ";
         m_sommets[i]->afficherSucc();
         std::cout << std::endl;///affichage console

        /*fichier << m_sommets[i]->getNum() <<": ";
        fichier << m_sommets[i]->getSucc() <<" ";
         fichier << std::endl;///affichage console*/

       fichier << m_sommets[i]->getNum() <<": ";
        //m_sommets[i]->afficherSucc();
        for(int k=0; k<(m_sommets[i]->getSuccSize()) ; ++k) fichier <<  m_sommets[i]->returnSuccFirst(k) << "(" << m_sommets[i]->returnSuccSecond(k) << ")" ;
        fichier << std::endl;///affichage txt

    }
    fichier << std::endl;
}





void Graphe::dessinerGraphe() const //dessin graphe avec le svg, voir commentaire svgfile
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
    fichier << "************************************" << std::endl;
    fichier << "CENTRALITE DE DEGRE " << std::endl;
    //fichier << "************************************" << std::endl;
    fichier <<  "Le sommet " << ndeg << " a un degres de "<< deg[ndeg] << std::endl;
}




///centralité de degré normalisé <=> deg/(ordre-1)
void Graphe::CentraliteDegreNormalise()
{
    int ndeg, CD;
    CD=deg[ndeg]/(m_ordre-1);
    std::cout << "Le sommet choisi a pour Centralite de degre normalise; CD(s) : " << CD <<std::endl;
    fichier <<  "Le sommet choisi a pour Centralite de degre normalise; CD(s) : " << CD <<std::endl<<std::endl;

}



///centralité de vecteur propre non-normalisé

void Graphe::VecteurPropre()
{
    float lambda;
    float temp;
    int s;
    std::cout << "Rentrer le sommet voulu" << std::endl;
    std::cin >> s;
    std::vector<float> CVp;
    std::vector<float> deg;
    for(int i=0; i< m_ordre ; ++i) //crée deux vecteurs, un pour CVP et un pour les degrés, on les initialise à 1 et 0
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
                if(m_arete[j]->getExt1() == m_sommets[i]->getNum()) //on attribue à larete la valeure d'une extremitée et au sommet son num
                {
                    int successeurs = m_arete[j]->getExt1();
                    deg[i]=deg[i]+CVp[successeurs]; //le degré du sommet etudié est son degré initial + le CVP de ses succeceurs
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
            temp = temp + pow(deg[k],2); //création d'une valeure tampon pour faciliter le calcul, tampon ! degré au carré
        }
        lambda = sqrt(temp); //lambda = racine carrée de cette vlaure tampon
        for(int i=0; i<m_ordre; ++i)
        {
            CVp[i] = deg[i]/lambda; // pour finir calcul de CVP = degré/lambda
        }
    }
    while(lambda<0.2); //des qu elambda ne varie plus trop donc lambda <0,2 on arete la boucle et on sort le CVp étudié
    std::cout << "voici le vecteur propre normalise du sommet " << s << ": "<< CVp[s];
    fichier << "************************************" << std::endl;
    fichier << "CENTRALITE DE VECTEUR PROPRE" << std::endl;
    //fichier << "************************************" << std::endl;
    fichier << "voici le vecteur propre normalise du sommet " << s << ": "<< CVp[s]<<std::endl;
}





///centralité de vecteur propre normalisé
/* pour ce sous programe les commentaires sont identiques aux précedents,
la seule difference est que le degré utilisé ici est la centralité de degré normalisé,
pour étudier le vecteur propre NORMALISE
*/
void Graphe::VecteurPropreNonN()
{

    //CD=deg[ndeg]/(m_ordre-1);
    float lambda;
    float temp;
    int s;
    std::cout <<std::endl<< "Rentrer le sommet voulu" << std::endl;
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
    std::cout << "voici le vecteur propre non-normalise du sommet " << s << ": "<< CVp[s] <<std::endl;
    fichier << "voici le vecteur propre non-normalise du sommet " << s << ": "<< CVp[s]<<std::endl<<std::endl;
}

void Graphe::CentraliteProxNonN()
{
    int num_s0;
    float longueurtot;
    float CP;
    std::cout << "Rentrer le sommet de depart" << std::endl;
    std::cin >> num_s0;
    for(int i=0; i<m_ordre; ++i)
    {
        if(i != num_s0)
        {
            longueurtot = longueurtot + Dijkstra(num_s0, i);
            std::cout << std::endl;
        }
    }
    std::cout << longueurtot << std::endl;
    CP = (1/longueurtot);
    std::cout << "Voici la centralite de proximite non normalise pour le sommet " << num_s0 << ": " << std::endl;
    std::cout << CP << std::endl;
    fichier << "************************************" << std::endl;
    fichier << "CENTRALITE DE PROXIMITE" << std::endl;
    //fichier << "************************************" << std::endl;
    fichier << "Voici la centralite de proximite non normalise pour le sommet " << num_s0 << ": " << CP << std::endl;

}

void Graphe::CentraliteProxN()
{
    int num_s0;
    float longueurtotale;
    float CP;
    std::cout << "Rentrer le sommet de depart" << std::endl;
    std::cin >> num_s0;
    for(int i=0; i<m_ordre; ++i)
    {
        if(i != num_s0)
        {
            longueurtotale = longueurtotale + Dijkstra(num_s0, i);
            std::cout << std::endl;
        }
    }
    std::cout << longueurtotale << std::endl;
    CP = ((m_ordre-1)/longueurtotale);
    std::cout << "Voici la centralite de proximite normalise pour le sommet " << num_s0 << ": " << std::endl;
    std::cout << CP << std::endl;
    fichier << "Voici la centralite de proximite normalise pour le sommet " << num_s0 << ": " << CP << std::endl<<std::endl;
}


