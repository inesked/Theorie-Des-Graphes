#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

class Sommet
{
    private:
        int m_indice;
        char m_nom;
        std::pair <int , int> m_coordonnees;

    public:

        Sommet(int num, char nom, std::pair coordonnees):
            m_num{num}, m_nom{nom}, m_coordonnees{coordonnes};


};


#endif // SOMMET_H_INCLUDED
