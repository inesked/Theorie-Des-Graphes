#include <iostream>
#include "graphe.h"
#include "Sommet.h"
#include <vector>
#include <queue>
#include <fstream>
#include <stack>
#include "Svgfile.h"
#include <fstream>




int main()
{
    Graphe graphe1("graphe_etoile1_topo.txt");
    graphe1.dessinerGraphe();

    graphe1.Afficher();
     //affiche le graphe avec la liste des sommets adjacents


    std::cout<< std::endl<<"CENTRALITE DE DEGRE"<<std::endl;
    graphe1.CentraliteDegreNonNorma();
    graphe1.CentraliteDegreNormalise();

    std::cout<< std::endl<<"CENTRALITE DE VECTEUR PROPRE"<<std::endl;
    graphe1.VecteurPropre();
    graphe1.VecteurPropreNonN();

    std::cout<< std::endl<<"CENTRALITE DE PROXIMITE"<<std::endl;
    graphe1.CentraliteProxNonN();
    graphe1.CentraliteProxN();


/*

/*    ///menu du programme final

    std::vector < Graphe* > mesGraphe;
    bool continuer;
    int nom;
    int supprimer;

     std::cout << std::endl;
    std::cout << "Bienvenue sur notre projet de l'accessibilite et la vulnerabilite des reseaux" << std::endl;

    do{
        std::cout << std::endl;
        std::cout << "Selectionnez une action :" << std::endl;
        std::cout << "1. Charger un graphe" << std::endl;
        std::cout << "2. Changer le syst�me de pond�ration du graphe "<< std::endl;
        std::cout << "3. Calculer, afficher et sauvegarder les diff�rents indices de centralit�" << std::endl;
        std::cout << "4. Tester la vuln�rabilit� du graphe" << std::endl;
        std::cout << "5. Quitter" << std::endl;
        std::cout << std::endl;
        std::cout << "Entrez choix (numero) : " << std::endl;
        std::cin >> nom;
        switch(nom)
        {
            case 1:
                {
                    std::cout << "Quel graphe voulez-vous charger ?" << std::endl;///on demande � l'utilisateur le nom du graphe qu'il veut charger
                    std::cin >> nom;
                    nom="graphe.txt";
                    Graphe g{"graphe.txt"};
                    break;
                }
            case 2:
                {
                    ///

                    break;
                }
            case 3:


                    break;
                }
            case 4:



                    break;
                }
        }
    }while(choix != 5);
    return 0;
}
*/

    return 0;
}


