#include "graphe.h"

void Graphe::SauvegardeGraphe()
{
    std::ifstream in{ "resultat.txt" };
    std::ofstream out{ "Sauvegarde.txt" };
    for (std::string s; getline(in, s); )
      out << s << std::endl;
    /*in.open("resultat.txt", std::ofstream::in | std::ofstream::trunc);
    in.close();

    m_sommets.clear();
    m_arete.clear();*/
}

void Graphe::SuppArete(int Ext1, int Ext2)
{
    std::ofstream ofs {"graphe_etoile1_topo_bis.txt"};
    std::ofstream ponde{"ponde_bis.txt"};
    if(ofs.bad()) std::cout << "Erreur ecriture de fichier";
    ofs << m_orientation << std::endl;
    ofs << m_ordre << std::endl;
    for(int i=0; i<m_ordre ; ++i)
    {
        ofs << m_sommets[i]->getNum() << " " << m_sommets[i]->getNom() << " " << m_sommets[i]->getCoords1() << " " << m_sommets[i]->getCoords2() << std::endl;
    }
    ofs << m_taille-1 << std::endl;
    ponde << m_taille-1 << std::endl;
    for(int i=0; i<m_taille; ++i)
    {
        if( Ext1 == m_arete[i]->getExt1() && Ext2 == m_arete[i]->getExt2())
        {
            m_arete.erase(m_arete.begin()+i);
        }
    }
    for(int j=0; j<m_taille ;++j)
    {
        if(j < m_arete[j]->getId())
        {
            int x = m_arete[j]->getId();
            m_arete[j]->setId(x-1);
        }
    }
    int k=0;
    for(int j=0; j<m_taille-1;++j)
    {
        ofs << m_arete[j]->getId() << " " << m_arete[j]->getExt1() << " " << m_arete[j]->getExt2() << std::endl;
        ponde << m_arete[j]->getId() << " " ;
        if( j != Ext1)
        {
                ponde << m_sommets[j]->returnSuccSecond(k) << std::endl;
                if(m_sommets[j]->getSuccSize()>1)
                    ++k;
        }
        else
        {
            //if (m_sommets[j]->getSuccSize() == 1)
                ponde << m_sommets[j+1]->returnSuccSecond(k) << std::endl;
        }
    }
    m_sommets.clear();
    m_arete.clear();
    GrapheCharger("graphe_etoile1_topo_bis.txt");

}

void Graphe::Connexite()
{
    for(int i=0; i<m_ordre; ++i)
    {
        if(deg[i]==0)
            std::cout << "le graphe n'est pas connexe" << std::endl;
    }
}

