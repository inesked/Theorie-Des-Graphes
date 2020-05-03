#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <list>
#include "graphe.h"

int Graphe::Dijkstra(int num_s0, int num_sf)
       {
           std::vector<int> preds((int) m_sommets.size(), -1); /// vecteur de prédécesseurs
           std::vector<int> marquage ((int)m_sommets.size(),0); /// vecteur de marquage
           auto cmp= [](std::pair<Sommet*,int> paire1, std::pair<Sommet*,int> paire2){return paire2.second<paire1.second; }; /// auto comp permettant la comparaison automatique entre 2 sommets et leur distance
           std::priority_queue<std::pair<Sommet*,int>,std::vector<std::pair<Sommet*,int>>,decltype(cmp)> Queue(cmp); /// place en priorité le sommet avec le moins de distance de son prédécesseurs
           std::vector<int> distance((int)m_sommets.size(), -1); /// vecteur contenant les poids de chaque sommet
            /// initialisation de la distance du sommet de départ
           distance[num_s0] =0;
            /// on mets ce sommet dans la priority queue
           Queue.push({m_sommets[num_s0],0});
            /// on déclare un pair contenant sommet et entier
           std::pair<Sommet*,int> paire;
            /// tant que la queue n'est pas vide
           while(!Queue.empty())
           {
               paire = Queue.top(); /// on place la paire en début de queue
               Queue.pop(); /// puis on la traite directement donc on l'enlève
               while((!Queue.empty())&&(marquage[paire.first->getNum()])) /// on répète l'opération tant que le sommet est marqué
               {
                  paire = Queue.top();
                  Queue.pop();
               }
                /// on marque ensuite le sommet non marqué
               marquage[(paire.first)->getNum()] = 1;
                /// on accède aux successeurs de la pair
               for(auto paire_successeurs: (paire.first)->getSucc())
               {
                   if(marquage[paire_successeurs.first->getNum()] == 0) /// si le marquage n'est pas effectué
                   {
                      if((distance[paire_successeurs.first->getNum()]== -1)||(paire.second + paire_successeurs.second < distance[paire_successeurs.first->getNum()])) /// comparaison de distance afin d'avoir la plus courte distance
                      {
                          distance[paire_successeurs.first->getNum()] = paire.second + paire_successeurs.second; /// on attribue à la distance générale la distance actuelle + la distance de son prédécesseurs
                          preds[paire_successeurs.first->getNum()] = paire.first->getNum(); /// on attribue le sommet en question au vector de prédécesseurs
                          Queue.push(std::make_pair((paire_successeurs.first),distance[paire_successeurs.first->getNum()])); /// on mets ensuite le sommet puis la distance enregistré dnas la queue
                      }
                   }
               }
           }
           /*std::cout << "Chemin du sommet "<< num_s0 << " au sommet " << num_sf <<" :" <<std::endl;
            std::cout << num_sf; /// on affiche le sommet finale
            for(auto p = preds[num_sf]; p != -1; p = preds[p]) /// boucle s'arrêtant jusqu'au dernier prédécesseur
            {                                                   /// affiche chaque prédécesseur
                std::cout << "<--"<< p;

            }
            std::cout << std::endl;
            std::cout << "longueur : " << distance[num_sf] - distance[preds[num_sf]]; /// calcul de la distance entre le sommet final et son prédécesseur
            /*for(auto p = preds[num_sf]; p != -1; p = preds[p])/// boucle s'arrêtant jusqu'au dernier prédécesseur
            {
                if(distance[p] == 0) /// si la distance est null (si on est au sommet final)
                    std::cout << " = " << distance[num_sf]; /// on affiche la distance totale
                else /// sinon on affiche la distance entre chaque prédécesseur
                    std::cout << "+" << distance[p]-distance[preds[p]];

            }*/
            return distance[num_sf];

}

///Concevez et implémentez un algorithme de calcul en supposant qu’il
///n’existe qu’un seul plus court chemin reliant chaque paire de sommets
std::vector<int> Graphe::CentraliteInt1seulPluscourtchemin(int num_s0, int num_sf, int num_si)
       {

       std::vector<int> preds((int) m_sommets.size(), -1); /// vecteur de prédécesseurs
           std::vector<int> marquage ((int)m_sommets.size(),0); /// vecteur de marquage
           auto cmp= [](std::pair<Sommet*,int> paire1, std::pair<Sommet*,int> paire2){return paire2.second<paire1.second; }; /// auto comp permettant la comparaison automatique entre 2 sommets et leur distance
           std::priority_queue<std::pair<Sommet*,int>,std::vector<std::pair<Sommet*,int>>,decltype(cmp)> Queue(cmp); /// place en priorité le sommet avec le moins de distance de son prédécesseurs
           std::vector<int> distance((int)m_sommets.size(), -1); /// vecteur contenant les poids de chaque sommet
           //int b
            /// initialisation de la distance du sommet de départ
           distance[num_s0] =0;
            /// on mets ce sommet dans la priority queue
           Queue.push({m_sommets[num_s0],0});
            /// on déclare un pair contenant sommet et entier
           std::pair<Sommet*,int> paire;
            /// tant que la queue n'est pas vide
           while(!Queue.empty())
           {
               paire = Queue.top(); /// on place la paire en début de queue
               Queue.pop(); /// puis on la traite directement donc on l'enlève
               while((!Queue.empty())&&(marquage[paire.first->getNum()])) /// on répète l'opération tant que le sommet est marqué
               {
                  paire = Queue.top();
                  Queue.pop();
               }
                /// on marque ensuite le sommet non marqué
               marquage[(paire.first)->getNum()] = 1;
                /// on accède aux successeurs de la pair
               for(auto paire_successeurs: (paire.first)->getSucc())
               {
                   if(marquage[paire_successeurs.first->getNum()] == 0) /// si le marquage n'est pas effectué
                   {
                      if((distance[paire_successeurs.first->getNum()]== -1)||(paire.second + paire_successeurs.second < distance[paire_successeurs.first->getNum()])) /// comparaison de distance afin d'avoir la plus courte distance
                      {
                            distance[paire_successeurs.first->getNum()] = paire.second + paire_successeurs.second; /// on attribue à la distance générale la distance actuelle + la distance de son prédécesseurs
                            preds[paire_successeurs.first->getNum()] = paire.first->getNum(); /// on attribue le sommet en question au vector de prédécesseurs
                            Queue.push(std::make_pair((paire_successeurs.first),distance[paire_successeurs.first->getNum()])); /// on mets ensuite le sommet puis la distance enregistré dnas la queue
                      }
                   }
               }
           }
           std::cout << std::endl;
           std::cout << "Admettons qu'il n'existe qu'un seul plus court chemin possible du sommet " << num_s0 << " au sommet " << num_sf <<" :" <<std::endl;
            std::cout << num_sf; /// on affiche le sommet finale
            for(auto p = preds[num_sf]; p != -1; p = preds[p]) /// boucle s'arrêtant jusqu'au dernier prédécesseur
            {                                                   /// affiche chaque prédécesseur
                std::cout << "<--"<< p;

            }
            bool inter = false;
            std::cout << std::endl;
            for(auto p = preds[num_sf]; p != -1; p = preds[p]) /// boucle s'arrêtant jusqu'au dernier prédécesseur
            {                                                   /// affiche chaque prédécesseur
                if(num_si == p) inter = true;

            }
            if(inter){
                std::cout << "la centralite d'intermediarite non numerise du sommet " << num_si << " est de 1"  <<std::endl;
                std::cout << "le centralite d'intermediarite numerise du sommet " << num_si << " est de " << 2./float(m_ordre*m_ordre - 3*m_ordre + 2) <<std::endl;
            }
            else{
                std:: cout << "le centralite d'intermediarite non numerise du sommet " << num_si << " est de 0"  <<std::endl;
                std:: cout << "le centralite d'intermediarite numerise du sommet " << num_si << " est de 0"  <<std::endl;
            }
            return preds;
}



/*///permet de déterminer combien il y a de plus courts chemins d'un sommet A à un sommet B
///code public trouve sur internet :
///https://www.geeksforgeeks.org/number-shortest-paths-unweighted-directed-graph/
void BFS(vector<int> adj[], int src, int dist[], int paths[], int n)
{
	bool visited[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;
	dist[src] = 0;
	paths[src] = 1;

	queue <int> q;
	q.push(src);
	visited[src] = true;
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		for (auto x : adj[curr])
		{
			if (visited[x] == false)
			{
				q.push(x);
				visited[x] = true;
			}
			if (dist[x] > dist[curr] + 1)
			{
				dist[x] = dist[curr] + 1;
				paths[x] = paths[curr];
			}
			else if (dist[x] == dist[curr] + 1){
				paths[x] += paths[curr];
		}
        }
	}
}

//n = nombre de sommets
//d = sommet de départ
//a = sommet d'arrivee
void NbrPlusCourtsChemins(vector<int> adj[], int n, int d, int a) {
	int dist[n], paths[n];
	for (int i = 0; i < n; i++)
		dist[i] = INT_MAX;
	for (int i = 0; i < n; i++)
		paths[i] = 0;
	BFS(adj, d, dist, paths, n);
    cout << "Le nombre de plus courts chemins de " << d << " à " << a <<" est " << paths[a] << " " <<endl;
}

void ajouterArete(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
}

int main()
{
	int n = 9; // nombre de sommet
	vector <int> adj[n];
	ajouterArete(adj, 0, 1);
    ajouterArete(adj, 0, 2);
    ajouterArete(adj, 1, 0);
    ajouterArete(adj, 1, 3);
    ajouterArete(adj, 1, 7);
    ajouterArete(adj, 2, 0);
    ajouterArete(adj, 2, 3);
    ajouterArete(adj, 2, 8);
    ajouterArete(adj, 3, 1);
    ajouterArete(adj, 3, 2);
    ajouterArete(adj, 3, 6);
    ajouterArete(adj, 3, 4);
    ajouterArete(adj, 4, 3);
    ajouterArete(adj, 4, 5);
    ajouterArete(adj, 4, 7);
    ajouterArete(adj, 5, 4);
    ajouterArete(adj, 5, 6);
    ajouterArete(adj, 6, 3);
    ajouterArete(adj, 6, 5);
    ajouterArete(adj, 6, 8);
    ajouterArete(adj, 7, 4);
    ajouterArete(adj, 7, 1);
    ajouterArete(adj, 8, 2);
    ajouterArete(adj, 8, 6);
	NbrPlusCourtsChemins(adj, n, 0, 4);
	return 0;
}*/

