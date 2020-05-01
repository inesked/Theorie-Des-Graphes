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

void Graphe::SuppArete(int id)
{
    std::ofstream ofs {"graphe_etoile1_topo_bis.txt"};
    if(ofs.bad()) std::cout << "Erreur ecriture de fichier";
    ofs << m_orientation << std::endl;
    ofs << m_ordre << std::endl;
    for(int i=0; i<m_ordre ; ++i)
    {
        ofs << m_sommets[i]->getNum() << " " << m_sommets[i]->getNom() << " " << m_sommets[i]->getCoords1() << " " << m_sommets[i]->getCoords2() << std::endl;
    }
    ofs << m_taille-1 << std::endl;
    int i=0;
    for(i; i<m_taille; ++i)
    {
        if(id == m_arete[i]->getId())
        {
            std::cout << m_arete[i]->getId();
            m_arete.erase(m_arete.begin()+i);
        }
        /*if(id < m_arete[i]->getId())
        {
            std::cout << "c";
            int x = m_arete[i]->getId();
            m_arete[i]->setId(x-1);
        }*/
    }
    for(int i=0; i<m_taille; ++i)
    {
        if(id < m_arete[i]->getId())
        {
            int x = m_arete[i]->getId();
            m_arete[i]->setId(x-1);
            std::cout << m_arete[i]->getId();
        }
    }
    for(int j=0; j<m_taille-1;++j)
    {
        ofs << m_arete[j]->getId() << " " << m_arete[j]->getExt1() << " " << m_arete[j]->getExt2() << std::endl;
    }
    m_sommets.clear();
    m_arete.clear();
}

