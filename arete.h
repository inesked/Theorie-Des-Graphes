#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED

class Arete
{
private:
    int m_poids;
    int m_taille; ///nombre d'arêtes
    char m_indice;
    std::pair <Sommet* , Sommet*> m_extremites; ///creer une paire de sommets

public:
    Arete(int poids, int taille, char indice, std::pair extremites):
        m_poids{poids}, m_taille{taille}, m_indice{indice}, m_extremites{extremites};///constructeur
    ~Arete();///destructeur

};

#endif // ARETE_H_INCLUDED
