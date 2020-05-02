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
/*
    Graphe graphe1("France.txt");
    graphe1.dessinerGraphe();
/*
    graphe1.Afficher();
     //affiche le graphe avec la liste des sommets adjacents
    graphe1.CentraliteDegreNonNorma();
    graphe1.VecteurPropreNonN();
    graphe1.CentraliteProxNonN();
    graphe1.CentraliteProxN();*/
///menu du programme final
    Graphe g;
    int choix;
    std::string nomFichier;
    std::string Ponde;
    std::cout << std::endl;
    std::cout << "Bienvenue sur notre projet de l'accessibilite et la vulnerabilite des reseaux" << std::endl;
    std::cout << std::endl;
    std::cout << "Selectionnez une action :" << std::endl;
    std::cout << "1. Charger un graphe" << std::endl;
    std::cout << "2. Changer le systeme de ponderation du graphe "<< std::endl;
    std::cout << "3. Calculer, afficher et sauvegarder les differents indices de centralite" << std::endl;
    std::cout << "4. Tester la vulnerabilite du graphe" << std::endl;
    std::cout << "5. Quitter" << std::endl;
    std::cout << std::endl;
    do{
            std::cout << std::endl;
        std::cout << "Entrez choix (numero) : " << std::endl;
        std::cin >> choix;
        switch(choix)
        {
            case 1:
                {
                    std::cout << "Quel graphe voulez-vous charger ?" << std::endl;///on demande � l'utilisateur le nom du graphe qu'il veut charger
                    std::cin >> nomFichier;
                    g.GrapheCharger(nomFichier);
                    int d, a, i;
                    std::cout << "Entrez un sommet de depart:";
                    std::cin >> d;
                    std::cout << "Entrez un sommet d'arrivee:";
                    std::cin >> a;
                    std::cout << "Entrez un sommet intermediaire:";
                    std::cin >> i;
                    g.CentraliteInt1seulPluscourtchemin(d, a, i);
                    break;
                }
            case 2:
                {
                    std::cout <<"Quel fichier de ponderation voulez-vous charger ?" << std::endl;
                    std::cin >> Ponde;
                    g.GrapheChargerPonde(Ponde);
                    g.Afficher();
                    g.dessinerGraphe();
                    break;
                }
            case 3:
                {
                    g.SauvegardeGraphe();
                    break;
                }
            case 4:
                {
                    int cmb;
                    std::cout << "Combien d'arete voulez-vous retirer ?" << std::endl;
                    std::cin >> cmb;
                    int Ext1;
                    int Ext2;
                    for(int i=0; i<cmb ; ++i)
                    {
                        std::cout << "rentrer les extremites de l'arete a supprimer" << std::endl;
                        std::cin >> Ext1;
                        std::cin >> Ext2;
                        g.SuppArete(Ext1,Ext2);
                    }
                    //g.Connexite();
                    break;
                }
        }
    }
    while(choix != 5);


    return 0;
}


