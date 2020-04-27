#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

class Sommet
{
    private:
        int m_indice;
        char m_nom;
        std::pair <int , int> m_coordonnees;

    public:

        Sommet(int num, char nom, std::pair coordonnees);

};


#endif // SOMMET_H_INCLUDED
