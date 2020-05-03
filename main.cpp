/// Code réalisé par Roxane Calor Inès Kedjem et Alex Chrétien
/// sources : nos TP 2 et 3 (BFS, DFS et Dijsktra)
/// Recherche personnelle
///http://recherche.ign.fr/labos/cogit/pdf/RAPPORTS/Gleyze_rapport_reseaux.pdf
///https://www.eecs.wsu.edu/~assefaw/CptS580-06/papers/brandes01centrality.pdf
///https://piazza.com/class_profile/get_resource/hc7r2hz5r3y38z/hg7zvceh68t6q0

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
                    std::cout << "Quel graphe voulez-vous charger ? (Entrer un fichier de topologie et dessous un fichier de ponderation)" << std::endl;///on demande � l'utilisateur le nom du graphe qu'il veut charger
                    std::cin >> nomFichier;
                    g.GrapheCharger(nomFichier);
                    break;
                }
            case 2:
                {
                    std::cout <<"Quel fichier de ponderation correspondant au graphe voulez-vous charger ?" << std::endl;
                    std::cin >> Ponde;
                    g.GrapheChargerPonde(Ponde);
                    break;
                }
            case 3:
                {
                    g.Afficher();
                    int d, a, i;
                    std::cout << "*****************************" <<std::endl;
                    std::cout <<"CENTRALITE DEGRE D'INTERMEDIARITE" <<std::endl;
                    std::cout << "Entrez un sommet de depart:";
                    std::cin >> d;
                    std::cout << "Entrez un sommet d'arrivee:";
                    std::cin >> a;
                    std::cout << "Entrez un sommet intermediaire:";
                    std::cin >> i;
                    g.CentraliteInt1seulPluscourtchemin(d, a, i);
                    g.linkBFS(d, a, i);
                    g.dessinerGraphe();
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
                        std::cout << "rentrer la premiere extremite"<<std::endl;
                        std::cin >> Ext1;
                        std::cout << "rentrer la seconde extremite"<<std::endl;
                        std::cin >> Ext2;
                        g.SuppArete(Ext1,Ext2);
                    }
                    g.dessinerGraphe();
                    break;
                }
        }
    }
    while(choix != 5);
    return 0;
}


