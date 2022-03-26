//
// Created by Houlessodji Kokouvi on 11/03/2022.
//

#ifndef PROJETGRAPHEALGO_GRAPHE_NON_ORIENTE_H
#define PROJETGRAPHEALGO_GRAPHE_NON_ORIENTE_H
#include "Graphe.h"
#include "Arete.h"
#include <vector>


class Graphe_non_oriente : public Graphe {

private :
    std::vector<Arete> d_tableau_arete();
public :
    Graphe_non_oriente();
    void kruskal();



};


#endif //PROJETGRAPHEALGO_GRAPHE_NON_ORIENTE_H
