/// Code rÈalisÈ par Roxane Calor InËs Kedjem et Alex ChrÈtien
#include "graphe.h"

void Graphe::SauvegardeGraphe()
{
    std::ifstream in{ "resultat.txt" };/// lecture
    std::ofstream out{ "Sauvegarde.txt" };/// ecriture
    for (std::string s; getline(in, s); )/// Copiage
      out << s << std::endl;
}

void Graphe::SuppArete(int Ext1, int Ext2)
{
    for(int i=0; i<m_taille; ++i)
    {
        if( Ext1 == m_arete[i]->getExt1() && Ext2 == m_arete[i]->getExt2())/// On supprime l'arete correspondant aux extremites
        {
            m_arete.erase(m_arete.begin()+i);
        }
    }
    for(int j=0; j<m_taille ;++j)
    {
        if(j < m_arete[j]->getId())/// Pour les sommets supÈrieur ‡ celui demander on leur attribue une nouvelle Id
        {
            int x = m_arete[j]->getId();
            m_arete[j]->setId(x-1);
        }
    }
    for(int a=0; a<m_ordre; ++a)
    {
        if(Ext1 == m_sommets[a]->getNum())/// On supprime la deuxieme extremite dans les successeurs de la premiere
        {
            for(int j=0; j<m_sommets[a]->getSuccSize(); ++j)
            {
                if(Ext2 == m_sommets[a]->returnSuccFirst(j))
                {
                    m_sommets[a]->SuppAdj(m_sommets[j]);
                    deg[m_sommets[a]->getNum()] = deg[m_sommets[a]->getNum()]-1;///On enlËve un degre ‡ cause de la suppression
                }
            }
        }
        if(Ext2 == m_sommets[a]->getNum())/// On supprime la premiere extremite dans les successeurs de la deuxieme
        {
            for(int j=0; j<m_sommets[a]->getSuccSize(); ++j)
            {
                if(Ext1 == m_sommets[a]->returnSuccFirst(j))
                {
                    m_sommets[a]->SuppAdj(m_sommets[j]);
                    deg[m_sommets[a]->getNum()] = deg[m_sommets[a]->getNum()]-1;///On enlËve un degre ‡ cause de la suppression
                }
            }
        }

    }

}

/*
void Graphe::Connexite()
{
    if (m_orientation==1)
        std::cout<<"le graphe est orientÈ, donc pas de k-connexitÈ"<<std::endl;
    else
    {
        int l, nbchem;
        l=100;

        for(unsigned int i=0; i<m_sommets.size(); ++i)
        {
            for(unsigned int j=0; j<m_sommets.size(); ++j)
            {
            if(i!=j)
                {
                for(unsigned int m=0; m<m_sommets.size();++m)
                    {
                        m_sommets[m]->setCouleur(0);
                    }
                    nbchem = 0;
                    m_sommets[i]->connexite(j, nbchem);

                    if(nbchem<l)
                    {
                    l=nbchem;
                    }
                }
            }
        }
    }
}


std::vector<int> Graphe::DFS(int num_s0)const
    {
            /// d»claration de la pile
            std::stack<int>pile;
            /// pour le marquage
            std::vector<int> couleurs((int)m_sommets.size(),0);
            ///pour noter les pr»d»cesseurs : on note les num»ros des pr»d»cesseurs (on pourrait stocker des pointeurs sur ...)
            std::vector<int> preds((int)m_sommets.size(),-1);

            ///»tape initiale : on enfile et on marque le sommet initial
            pile.push(num_s0);
            couleurs[num_s0]=1;

            const Sommet*s;
            ///tant que la file n'est pas vide
            while (!pile.empty())

            {
                ///on d»file le prochain sommet
                        s=m_sommets[pile.top()]; //on prend le premier sommet de la file //sommet ou sommets ?

                        pile.pop();
                        ///pour chaque successeur du sommet d»fil»

                        s=m_sommets[pile.top()]; //on prend le premier sommet de la file //sommet ou sommets ?

                        pile.pop();
                        //pour chaque successeur du sommet d»fil»

                        for (auto succ:s->getSucc().first)
                        {
                            if (couleurs[succ->getNum()]==0)//si il n'est pas marquÈ
                            {
                                couleurs[succ->getNum()]=1;//on le marque
                                preds[succ->getNum()]=s->getNum();
                                pile.push(succ->getNum()); //et on le met dans la file
                            }
                            couleurs[s->getNum()]=2;
                        }
                        s=m_sommet[pile.top()];
                        pile.pop();
                    }
        return preds;
            }



//recherche et affichage des composantes connexes
void Graphe::CC()
    {
            size_t num=0;
            bool test;
            int ncc=0;
            ///pour noter les num»ros de CC
            std::vector<int> cc(m_sommets.size(),-1);
            do
            {
                cc[num]=num;
                std::cout<<std::endl<<"composante connexe "<<ncc<<" : "<<num<<" ";
                ncc++;
                ///lancement d'un DFS sur le sommet num
                std::vector<int> arbre_DFS=DFS(num);
                ///affichage des sommets decouverts lors du parcours (ceux qui ont un predecesseur
                for(size_t i=0;i<arbre_DFS.size();++i)
                {
                    if ((i!=num)&&(arbre_DFS[i]!=-1))
                    {
                            cc[i]=num;
                            std::cout<<i<<" ";
                    }
                }
                ///recherche d'un sommet non explor»
                ///pour relancer un DFS au prochain tour
                test=false;
                for(size_t i=0;i<m_sommets.size();++i)
                {
                    if (cc[i]==-1)
                    {
                        num=i;
                        test=true;
                        break;
                    }
                }
            }
            while(test==true);
            std::cout<<std::endl;
        }
};
*/



