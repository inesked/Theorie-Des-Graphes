#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <list>
#include "graphe.h"


///https://www.geeksforgeeks.org/number-shortest-paths-unweighted-directed-graph/
///code source
void Graphe::linkBFS(int d, int a, int it)
{
    std::cout << std::endl << "Admettons qu'il n'existe un ou plusieurs plus courts chemins possibles du sommet " << d << " au sommet " << a << "," <<std::endl;
    fichier << std::endl << "Admettons qu'il n'existe un ou plusieurs plus courts chemins possibles du sommet " << d << " au sommet " << a << "," <<std::endl;
    std::cout << "Les plus courts chemins du sommet " << d << " au sommet " << a << " sont: \n";
    chemins(gra, d, a, it);
}

void Graphe::afficheChemin(std::vector<int>& chemin, int minimum, int it, int &nbr1, int &nbr2)
{
    int taille = chemin.size();
    if(taille == minimum){
    nbr1 ++;
    for (int i = taille-1; i >= 0; i--){
        std::cout << chemin[i];
        if(it == chemin[i]) {
                std::cout << "(sommet intermediaire)";
                nbr2 ++;
        }
        if (i != 0) std:: cout << "<--";
    }
    std::cout << std::endl;
    }
}

int Graphe::pasVisite(int x, std::vector<int>& chemin)
{
    int size = chemin.size();
    for (int i = 0; i < size; i++)
        if (chemin[i] == x)
            return 0;
    return 1;
}

void Graphe::chemins(std::vector<std::vector<int> >&g, int d, int a, int it)
{
    int minimum = 99999;
    int nbrche = 0;
    int nbrcheit = 0;
    std::queue<std::vector<int> > q;
    std::vector<int> chemin;
    chemin.push_back(d);
    q.push(chemin);
    while (!q.empty()) {
        chemin = q.front();
        q.pop();
        int dernier = chemin[chemin.size() - 1];
        if (dernier == a){
            if(chemin.size()<minimum) minimum = chemin.size();
            afficheChemin(chemin, minimum, it, nbrche, nbrcheit);
        }
        for (int i = 0; i < g[dernier].size(); i++) {
            if (pasVisite(g[dernier][i], chemin)) {
                std::vector<int> nouvchemin(chemin);
                nouvchemin.push_back(g[dernier][i]);
                q.push(nouvchemin);
            }
        }
    }
    std::cout << "Le nombre de plus courts chemins est de: "<< nbrche << std::endl;
    fichier << "Le nombre de plus courts chemins est de: "<< nbrche << std::endl;
    std::cout << "Le nombre de plus courts chemins passant par " << it << " est de: "<< nbrcheit << std::endl;
    fichier << "Le nombre de plus courts chemins passant par " << it << " est de: "<< nbrcheit << std::endl;
    std::cout << "Donc la centralite d'intermediarite non numerise du sommet " << it << " est de " << float(nbrcheit)/float(nbrche) <<std::endl;
    fichier << "Donc la centralite d'intermediarite non numerise du sommet " << it << " est de " << float(nbrcheit)/float(nbrche) <<std::endl;
    std::cout << "Et le centralite d'intermediarite numerise du sommet " << it << " est de " << ((2.)*(float(nbrcheit)/float(nbrche)))/float(m_ordre*m_ordre - 3*m_ordre + 2) <<std::endl;
    fichier << "Et le centralite d'intermediarite numerise du sommet " << it << " est de " << ((2.)*(float(nbrcheit)/float(nbrche)))/float(m_ordre*m_ordre - 3*m_ordre + 2) <<std::endl;
}

