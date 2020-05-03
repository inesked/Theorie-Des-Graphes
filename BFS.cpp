/// Code réalisé par Roxane Calor Inès Kedjem et Alex Chrétien
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <list>
#include "graphe.h"

///https://www.geeksforgeeks.org/print-paths-given-source-destination-using-bfs/
///https://www.geeksforgeeks.org/number-shortest-paths-unweighted-directed-graph/
///code source
void Graphe::linkBFS(int d, int a, int it)///fonction qui permet d'afficher les différents plus courts chemins
{
    std::cout << std::endl << "Admettons qu'il n'existe un ou plusieurs plus courts chemins possibles du sommet " << d << " au sommet " << a << "," <<std::endl;///on considère qu'il n'existe qu'un seul plus court chemin entre deux sommets, même si ce n'est pas le cas
    fichier << std::endl << "Admettons qu'il n'existe un ou plusieurs plus courts chemins possibles du sommet " << d << " au sommet " << a << "," <<std::endl;///on prend en compte tous les plus courts chemins entre deux sommets
    std::cout << "Les plus courts chemins du sommet " << d << " au sommet " << a << " sont: \n";
    chemins(gra, d, a, it);///on prend en valeurs une grandeur, un sommet initial, un sommet final et un sommet intermédiaire
}

void Graphe::afficheChemin(std::vector<int>& chemin, int minimum, int it, int &nbr1, int &nbr2)///fonction qui permet d'afficher les différents plus courts chemin
{
    int taille = chemin.size();///on compare la taille de chaque chemin du graphe pour savoir quels sont les plus courts
    if(taille == minimum){///si la taille de chemin en paramètre est de la m^me taille que les chemins les plus courts alors on l'affiche
    nbr1 ++;///met à jour le compteur des chemins les plus courts
    for (int i = taille-1; i >= 0; i--){
        std::cout << chemin[i];
        if(it == chemin[i]) {
                std::cout << "(sommet intermediaire)";///précise le sommet intermédiaire à chaque fois qu'il existe
                nbr2 ++;///met à jour le compteur des chemins les plus courts passant par le sommet intermédiaire
        }
        if (i != 0) std:: cout << "<--";///affichage standard comme dans dijsktra
    }
    std::cout << std::endl;
    }
}

int Graphe::pasVisite(int x, std::vector<int>& chemin)///si le cheminn n'a pas été visité on le prend en compte
{
    int size = chemin.size();
    for (int i = 0; i < size; i++)
        if (chemin[i] == x)
            return 0;
    return 1;
}

///on parcourt tous les chemins entre sommet d'arrivée et de départ mais on affiche que les plus courts chemins
void Graphe::chemins(std::vector<std::vector<int> >&g, int d, int a, int it)///on prend en compte la taille du chemin, un sommet initial, un sommet final et un sommet intermédiare
{
    int minimum = 99999;///permet d'initialiser la variable minimum qui correspond au nombre min de sommets par lesquels on passe pour aller au sommet de départ au sommet d'arriver
    int nbrche = 0;///nombre de  plus courts chemins entre le sommet de départ et celui d'arriver
    int nbrcheit = 0;///nombre de  plus courts chemins entre le sommet de départ et celui d'arriver passant par le sommet intermédiaire
    std::queue<std::vector<int> > q;
    std::vector<int> chemin;
    chemin.push_back(d);
    q.push(chemin);///un tableau est donné à chaque chemin
    while (!q.empty()) {///tant que la queue n'est pas vide, on continue l'exploration
        chemin = q.front();
        q.pop();
        int dernier = chemin[chemin.size() - 1];///le dernier sommet de chaque plus court chemin
        if (dernier == a){///si ce dernier sommet correspond au sommet d'arrivée
            if(chemin.size()<minimum) minimum = chemin.size();///si la longueur du chemin trouvé est inf à la longueur des chemins plus courts trouvés avant
            ///alors mettre à jour la taille du plys court chemin
            afficheChemin(chemin, minimum, it, nbrche, nbrcheit);///affiche le chemin
        }
        for (int i = 0; i < g[dernier].size(); i++) {///prend en compte les chemins pas encore visité et les mets à jour
            if (pasVisite(g[dernier][i], chemin)) {
                std::vector<int> nouvchemin(chemin);
                nouvchemin.push_back(g[dernier][i]);
                q.push(nouvchemin);
            }
        }
    }
    ///affichage de la console, mise à jour du fichier txt et de la console avec toutes les données récoltées
    std::cout << "Le nombre de plus courts chemins est de: "<< nbrche << std::endl;
    fichier << "Le nombre de plus courts chemins est de: "<< nbrche << std::endl;
    std::cout << "Le nombre de plus courts chemins passant par " << it << " est de: "<< nbrcheit << std::endl;
    fichier << "Le nombre de plus courts chemins passant par " << it << " est de: "<< nbrcheit << std::endl;
    std::cout << "Donc la centralite d'intermediarite non numerise du sommet " << it << " est de " << float(nbrcheit)/float(nbrche) <<std::endl;
    fichier << "Donc la centralite d'intermediarite non numerise du sommet " << it << " est de " << float(nbrcheit)/float(nbrche) <<std::endl;
    std::cout << "Et le centralite d'intermediarite numerise du sommet " << it << " est de " << ((2.)*(float(nbrcheit)/float(nbrche)))/float(m_ordre*m_ordre - 3*m_ordre + 2) <<std::endl;
    fichier << "Et le centralite d'intermediarite numerise du sommet " << it << " est de " << ((2.)*(float(nbrcheit)/float(nbrche)))/float(m_ordre*m_ordre - 3*m_ordre + 2) <<std::endl;
}

