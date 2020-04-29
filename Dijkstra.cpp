#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
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
           std::cout << "Chemin du sommet "<< num_s0 << " au sommet " << num_sf <<" :" <<std::endl;
            std::cout << num_sf; /// on affiche le sommet finale
            for(auto p = preds[num_sf]; p != -1; p = preds[p]) /// boucle s'arrêtant jusqu'au dernier prédécesseur
            {                                                   /// affiche chaque prédécesseur
                std::cout << "<--"<< p;

            }
            std::cout << std::endl;
            std::cout << "longueur : " << distance[num_sf] - distance[preds[num_sf]]; /// calcul de la distance entre le sommet final et son prédécesseur
            for(auto p = preds[num_sf]; p != -1; p = preds[p])/// boucle s'arrêtant jusqu'au dernier prédécesseur
            {
                if(distance[p] == 0) /// si la distance est null (si on est au sommet final)
                    std::cout << " = " << distance[num_sf]; /// on affiche la distance totale
                else /// sinon on affiche la distance entre chaque prédécesseur
                    std::cout << "+" << distance[p]-distance[preds[p]];

            }
            return distance[num_sf];

}


