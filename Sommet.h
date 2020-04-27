#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include <queue>
#include <string>
#include <list>
#include <vector>

class Sommet
{
    private:
        int m_num;
        std::string m_nom;
        std::pair <int,int> m_coordonnees;

    public:

        Sommet(int num, std::string nom, std::pair coordonnees);
};


#endif // SOMMET_H_INCLUDED
