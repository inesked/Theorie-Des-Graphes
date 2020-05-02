#include "graphe.h"
#include <fstream>
#include <iostream>
#include <utility>
#include "Svgfile.h"
#include "Sommet.h"
#include "arete.h"
#include <cmath>
#include <string>
//inès

void Graphe::GrapheCharger(std::string nomFichier)
{
    fichier.open("resultat.txt");
    if(fichier.bad()) std::cout << "Erreur ecriture de fichier";
    fichier << "Voici les resultats de la console : " << std::endl;
    fichier << "************************************" << std::endl;
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
                m_arete.push_back(new Arete{num4, std::make_pair(num5,num6)}); //ajout d'une pair de coord correspondant à un arc
                m_numarete.push_back(num5);
                m_numarete.push_back(num6);
                deg[num5] += 1;
                deg[num6] += 1;
            }
}


void Graphe::GrapheChargerPonde(std::string nomFichierPonde)
{
    std::ifstream ifs{nomFichierPonde};
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

       fichier << m_sommets[i]->getNum() <<": ";
        //m_sommets[i]->afficherSucc();
        for(int k=0; k<(m_sommets[i]->getSuccSize()) ; ++k) fichier <<  m_sommets[i]->returnSuccFirst(k) << "(" << m_sommets[i]->returnSuccSecond(k) << ")" ;
        fichier << std::endl;///affichage txt

    }
    fichier << std::endl;
}





void Graphe::dessinerGraphe()  //dessin graphe avec le svg, voir commentaire svgfile
{
    std::vector<float> CVp;
    std::vector<float> CVpN;
    std::vector<float> CPN;
    std::vector <float> CP;
    CVp = VecteurPropre();
    CVpN = VecteurPropreNonN();
    for(int i=0;i<m_ordre;++i)
    {
        float x ;
        x = CentraliteProxNonN(i);
        CPN.push_back(x);
    }
    for(int i=0;i<m_ordre;++i)
    {
        float x ;
        x = CentraliteProxN(i);
        CP.push_back(x);
    }
    Svgfile svgout;
    svgout.addGrid();
    svgout.addText(1000,110,"Centralite de proximite non-normalisé","purple");
    svgout.addText(1000,125,"Centralite de proximite normalisé","gray");
    svgout.addText(1000,140,"Centralite de vect propre normalisé","magenta");
    svgout.addText(1000,155,"Centralite de vect propre non-normalisé","blue");
    svgout.addText(1000,170,"Centralite de degre normalisé","green");
    svgout.addText(1000,185,"Centralite de degre non-normalisé","red");
    for(int i=0; i<m_ordre; ++i)
    {
        svgout.addDisk((m_sommets[i]->getCoords1())*100,(m_sommets[i]->getCoords2())*100,3,"black");
        svgout.addText((m_sommets[i]->getCoords1())*100,(m_sommets[i]->getCoords2())*100-10,m_sommets[i]->getNom(),"black");

        svgout.addDegre ((m_sommets[i]->getCoords1())*100+10,(m_sommets[i]->getCoords2())*100-30,std::to_string(deg[m_sommets[i]->getNum()]),"red");

        svgout.addDegreN ((m_sommets[i]->getCoords1())*100+10,(m_sommets[i]->getCoords2())*100-45,std::to_string((deg[m_sommets[i]->getNum()])/(m_ordre-1)),"green");

        svgout.addVectProp ((m_sommets[i]->getCoords1())*100+10,(m_sommets[i]->getCoords2())*100-60,std::to_string(CVp[i]),"blue");

        svgout.addVectPropN ((m_sommets[i]->getCoords1())*100+10,(m_sommets[i]->getCoords2())*100-75,std::to_string(CVpN[i]),"magenta");

        svgout.addProx ((m_sommets[i]->getCoords1())*100+10,(m_sommets[i]->getCoords2())*100-90,std::to_string(CP[i]),"gray");

        svgout.addProxN ((m_sommets[i]->getCoords1())*100+10,(m_sommets[i]->getCoords2())*100-105,std::to_string(CPN[i]),"purple");
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
    fichier <<  "Le sommet " << ndeg << " a un degres de "<< deg[ndeg] << std::endl;

}


///centralité de degré normalisé <=> deg/(ordre-1)
void Graphe::CentraliteDegreNormalise()
{
    int ndeg;
    float CD;
    for(int i=0; i<m_ordre; ++i)
    {
        CD = (deg[i]/(m_ordre-1));
        std::cout << "Le sommet choisi a pour Centralite de degre normalise; CD(s) : " << CD <<std::endl;
        fichier <<  "Le sommet choisi a pour Centralite de degre normalise; CD(s) : " << CD <<std::endl<<std::endl;
    }

}






///centralité de vecteur propre non-normalisé

std::vector<float> Graphe::VecteurPropre()
{
    float lambda;
    float temp;
    std::vector<float> CVp;
    std::vector<float> CV;
    for(int i=0; i< m_ordre ; ++i) //crée deux vecteurs, un pour CVP et un pour les degrés, on les initialise à 1 et 0
    {
        CVp.push_back(1);
        CV.push_back(deg[i]/m_ordre-1);
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
                    CV[i]=CV[i]+CVp[successeurs]; //le degré du sommet etudié est son degré initial + le CVP de ses succeceurs
                    //deg[i]=deg[i]+deg[successeurs];
                }
                if(m_arete[j]->getExt2() == m_sommets[i]->getNum())
                {
                    int successeurs = m_arete[j]->getExt2();
                    CV[i]=CV[i]+CVp[successeurs];
                    //deg[i]=deg[i]+deg[successeurs];
                }

            }
        }
        for(int k=0; k<deg.size(); ++k)
        {
            temp = temp + pow(CV[k],2); //création d'une valeure tampon pour faciliter le calcul, tampon ! degré au carré
        }
        lambda = sqrt(temp); //lambda = racine carrée de cette vlaure tampon
        for(int i=0; i<m_ordre; ++i)
        {
            CVp[i] = CV[i]/lambda; // pour finir calcul de CVP = degré/lambda
        }
    }
    while(lambda<0.2); //des qu elambda ne varie plus trop donc lambda <0,2 on arete la boucle et on sort le CVp étudié
    //std::cout << "voici le vecteur propre normalise du sommet " << s << ": "<< CVp[s];
    //fichier << "************************************" << std::endl;
    fichier << "CENTRALITE DE VECTEUR PROPRE" << std::endl;
    fichier << "************************************" << std::endl;
    for(int i=0 ; i<m_ordre ;++i)
    {
        fichier << "voici le vecteur propre normalise du sommet " << i << ": "<< CVp[i]<<std::endl;
    }
    return CVp;
}





///centralité de vecteur propre normalisé
/* pour ce sous programe les commentaires sont identiques aux précedents,
la seule difference est que le degré utilisé ici est la centralité de degré normalisé,
pour étudier le vecteur propre NORMALISE
*/
std::vector<float> Graphe::VecteurPropreNonN()
{
    float lambda;
    float temp;
    /*int s;
    std::cout <<std::endl<< "Rentrer le sommet voulu" << std::endl;
    std::cin >> s;*/
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
    //std::cout << "voici le vecteur propre non-normalise du sommet " << s << ": "<< CVp[s] <<std::endl;
    fichier << std::endl;
    for(int i=0 ; i<m_ordre ; ++i)
    {
        fichier << "voici le vecteur propre non-normalise du sommet " << i << ": "<< CVp[i]<<std::endl;
    }
    return CVp;
}

float Graphe::CentraliteProxNonN(int num_s0)
{
    float longueurtot;
    float CP=0;
    /*std::cout << "Rentrer le sommet de depart" << std::endl;
    std::cin >> num_s0;*/
    /*for(int j=0; j<m_ordre; ++j)
    {*/
        for(int i=0; i<m_ordre; ++i)
        {
            if(i != num_s0)
            {
                longueurtot = longueurtot + Dijkstra(num_s0,i);
                std::cout << std::endl;
            }
        }
    //}
    CP = 1/longueurtot;
    /*std::cout << "Voici la centralite de proximite non normalise pour le sommet " << num_s0 << ": " << std::endl;
    std::cout << CP << std::endl;*/
    fichier << "************************************" << std::endl;
    fichier << "CENTRALITE DE PROXIMITE" << std::endl;
    //fichier << "************************************" << std::endl;
    fichier << "Voici la centralite de proximite non normalise pour le sommet " << num_s0 << ": " << CP << std::endl;
    std::cout << CP;
    return CP;
}

float Graphe::CentraliteProxN(int num_s0)
{
    float longueurtotale=0;
    float CP=0;
    /*std::cout << "Rentrer le sommet de depart" << std::endl;
    std::cin >> num_s0;*/
    for(int i=0; i<m_ordre; ++i)
    {
        if(i != num_s0)
        {
            longueurtotale = longueurtotale + Dijkstra(num_s0, i);
            std::cout << std::endl;
        }
    }
    //std::cout << longueurtotale << std::endl;
    CP = ((m_ordre-1)/longueurtotale);
    //std::cout << "Voici la centralite de proximite normalise pour le sommet " << num_s0 << ": " << std::endl;
    //std::cout << CP << std::endl;
    fichier << "Voici la centralite de proximite normalise pour le sommet " << num_s0 << ": " << CP << std::endl<<std::endl;
    return CP;
}

/*void Graphe::CentraliteInter()
{
    int num_s0=0;
    int b=0;
    int CI=0;
    std::cin >> b;
    float compteur =0;
    std::vector<int> PCC;
    for(int i= 0 ; i<m_ordre ; ++i)
    {
        if( num_s0 < i )
        {
            PCC = DijkstraAdap(num_s0,i);
            for(int j= 0 ; j<m_ordre ; ++j)
            {
                if(j < b)
                {
                    PCC = DijkstraAdap(j,b);
                    for(int k= 0 ; k<m_ordre ; ++k)
                    {
                        if(b < k)
                        {
                            PCC = DijkstraAdap(b,k);
                            std::cout << std::endl;
                            if(PCC[k] == b)
                            {
                                compteur ++;
                            }
                        }
                    }
                }
                std::cout << compteur << std::endl;
            }
            num_s0 ++;
        }
    }
    std::cout << std::endl;
    CI = compteur/4;
    std::cout << CI;
}*/

/*void Graphe::CentraliteInter()
{
    for()
            /// déclaration de la pile
            std::stack<Sommet*> DFS;
            /// pour le marquage
            std::vector<int> couleurs((int)m_sommets.size(),0);
            ///pour noter les prédécesseurs : on note les numéros des prédécesseurs (on pourrait stocker des pointeurs sur ...)
            std::vector<int> preds((int)m_sommets.size(),-1);

            ///étape initiale : on enfile et on marque le sommet initial
            /// on initiale les sommets précédent à une couleur 0
            for(int i=0; i< num_s0;++i)
            {
                couleurs[i]= 0;
            }
            /// on enfile dans notre pile le premier sommet
            DFS.push(m_sommets[num_s0]);
            /// on le marque
            couleurs[num_s0] = 1;
            Sommet*s;
            std::vector<Sommet*> successeurs;
            ///tant que la file n'est pas vide
            while(!DFS.empty())
            {
                ///on défile le prochain sommet
                /// on le place au dessus de la pile
                s = DFS.top();
                /// on le détruit directement après (premier arrivée, premier servi)
                DFS.pop();
                /// on attribue à successeurs les successeurs du sommet initial.
                successeurs = m_sommets[s->getNum()]->getSucc();

                ///pour chaque successeur du sommet défilé
                for(int i=0 ; i < successeurs.size() ; ++i){
                     if(couleurs[successeurs[i]->getNum()] == 0)
                        {

                            couleurs[successeurs[i]->getNum()] = 1; ///s'il n'est pas marqué
                            preds[successeurs[i]->getNum()]= s->getNum(); ///on le marque
                            DFS.push(successeurs[i]); ///on note son prédecesseur (=le sommet défilé)
                        }

              }
            }
}*/

///méthode pour calculer la centralite d'intermediraite si on considere qu'il n'existe qu'un seul chemin plus court d'un point A un un pt B
///non-normalise
void Graphe::CentrInter1CPC ()
{
    int num_sint;
    int n_pccjk(i);
    int n_pccjk;
    for(int i=0; i<m_ordre; ++i)
    {
        if ()
    }

}





///méthode pour calculer la centralite d'intermediraite si on considere qu'il n'existe qu'un seul chemin plus court d'un point A un un pt B
///normalise
void Graphe::CentrInter1CPCN ()
{

}





