#include "arete.h"

Arete::Arete(int indice, std::pair<Sommet*,Sommet*> extremites)
    : m_indice{indice}, m_extremites{extremites}
{}
