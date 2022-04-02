//
// Created by Houlessodji Kokouvi on 11/03/2022.
//

#ifndef PROJETGRAPHEALGO_GRAPHE_NON_ORIENTE_H
#define PROJETGRAPHEALGO_GRAPHE_NON_ORIENTE_H
#include "Graphe.h"
#include "Arete.h"
#include <vector>


class Graphe_non_oriente : public Graphe {

public :
    Graphe_non_oriente(Graphe graphe);
    int* codage_prufer();
    int** decodage_prufer(int *codage);
    int* coloration();
    int nombre_chromatique(int *f);
};


#endif //PROJETGRAPHEALGO_GRAPHE_NON_ORIENTE_H
