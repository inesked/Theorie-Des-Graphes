#include <iostream>
#include "graphe.h"
#include "Sommet.h"
#include <vector>
#include <queue>
#include <fstream>
#include <stack>
#include "Svgfile.h"

int main()
{
    int num_s0,num_sf;
    Graphe graphe1("graphe_cycle4_topo.txt");
    graphe1.dessinerGraphe();
    /*int s_initial;//num»ro du sommet initial
    std::cout<<"Saisir identifiant du sommet de depart"<<std::endl;
    std::cin>>s_initial;

    int s_final;//num»ro du sommet final
    std::cout<<"Saisir identifiant du sommet d'arrivee"<<std::endl;
    std::cin >> s_final;*/

    graphe1.Afficher();
     //affiche le graphe avec la liste des sommets adjacents
    graphe1.CentraliteDegreNonNorma();
    graphe1.CentraliteDegreNormalise();
    graphe1.VecteurPropre();
    graphe1.Dijkstra(num_s0,num_sf);
    //graphe1.VecteurPropre();

    /*std::cout<<"Algorithme de Dijstra"<<std::endl;
    graphe1.CentraliteDegreNormalise();
/*
    std::cout<<"Algorithme de Dijstra"<<std::endl;
    graphe1.Dijkstra(s_initial, s_final);*/





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
        std::cout << "2. Changer le systËme de pondÈration du graphe "<< std::endl;
        std::cout << "3. Calculer, afficher et sauvegarder les diffÈrents indices de centralitÈ" << std::endl;
        std::cout << "4. Tester la vulnÈrabilitÈ du graphe" << std::endl;
        std::cout << "5. Quitter" << std::endl;
        std::cout << std::endl;
        std::cout << "Entrez choix (numero) : " << std::endl;
        std::cin >> nom;
        switch(nom)
        {
            case 1:
                {
                    std::cout << "Quel graphe voulez-vous charger ?" << std::endl;///on demande ‡ l'utilisateur le nom du graphe qu'il veut charger
                    std::cin >> nom;
                    nom="graphe.txt";
                    Graphe g{"graphe.txt"};
                    break;
                }
            case 2:
                {


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


