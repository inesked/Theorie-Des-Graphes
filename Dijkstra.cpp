#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include "graphe.h"

/*void Graphe::Dijkstra(int num_s0, int num_sf)
{
            //std::vector<int> preds((int) m_sommets.size(), -1); /// vecteur de pr�d�cesseurs
            std::vector<int> preds((int) m_arete.size(), -1);
           std::vector<int> marquage ((int)m_arete.size(),0); /// vecteur de marquage
           auto cmp= [](std::pair<Arete*,int> paire1, std::pair<Arete*,int> paire2){return paire2.second<paire1.second; }; /// auto comp permettant la comparaison automatique entre 2 sommets et leur distance
           std::priority_queue<std::pair<Arete*,int>,std::vector<std::pair<Arete*,int>>,decltype(cmp)> Queue(cmp); /// place en priorit� le sommet avec le moins de distance de son pr�d�cesseurs
           std::vector<int> distance((int)m_arete.size(), -1); /// vecteur contenant les poids de chaque arete
            /// initialisation de la distance du sommet de d�part
           distance[num_s0] =0;
            /// on mets ce sommet dans la priority queue
           Queue.push({m_arete[num_s0],0});
            /// on d�clare un pair contenant sommet et entier
           std::pair<Arete*,int> paire;
            /// tant que la queue n'est pas vide
           while(!Queue.empty())
           {
               paire = Queue.top(); /// on place la paire en d�but de queue
               Queue.pop(); /// puis on la traite directement donc on l'enl�ve
               while((!Queue.empty())&&(marquage[paire.first->getNum()])) /// on r�p�te l'op�ration tant que le sommet est marqu�
               {
                  paire = Queue.top();
                  Queue.pop();
               }
                /// on marque ensuite le sommet non marqu�
               marquage[(paire.first)->getNum()] = 1;
                /// on acc�de aux successeurs de la pair
               for(auto paire_successeurs: (paire.first)->getExt())
               {
                   if(marquage[paire_successeurs.first->getNum()] == 0) /// si le marquage n'est pas effectu�
                   {
                      if((distance[paire_successeurs.first->getNum()]== -1)||(paire.second + paire_successeurs.second < distance[paire_successeurs.first->getNum()])) /// comparaison de distance afin d'avoir la plus courte distance
                      {
                          distance[paire_successeurs.first->getNum()] = paire.second + paire_successeurs.second; /// on attribue � la distance g�n�rale la distance actuelle + la distance de son pr�d�cesseurs
                          preds[paire_successeurs.first->getNum()] = paire.first->getNum(); /// on attribue le sommet en question au vector de pr�d�cesseurs
                          Queue.push(std::make_pair((paire_successeurs.first),distance[paire_successeurs.first->getNum()])); /// on mets ensuite le sommet puis la distance enregistr� dnas la queue
                      }
                   }
               }
           }
           std::cout << "Chemin du sommet "<< num_s0 << " au sommet " << num_sf <<" :" <<std::endl;
            std::cout << num_sf; /// on affiche le sommet finale
            for(auto p = preds[num_sf]; p != -1; p = preds[p]) /// boucle s'arr�tant jusqu'au dernier pr�d�cesseur
            {                                                   /// affiche chaque pr�d�cesseur
                std::cout << "<--"<< p;

            }
            std::cout << std::endl;
            std::cout << "longueur : " << distance[num_sf] - distance[preds[num_sf]]; /// calcul de la distance entre le sommet final et son pr�d�cesseur
            for(auto p = preds[num_sf]; p != -1; p = preds[p])/// boucle s'arr�tant jusqu'au dernier pr�d�cesseur
            {
                if(distance[p] == 0) /// si la distance est null (si on est au sommet final)
                    std::cout << " = " << distance[num_sf]; /// on affiche la distance totale
                else /// sinon on affiche la distance entre chaque pr�d�cesseur
                    std::cout << "+" << distance[p]-distance[preds[p]];

            }

}*/


