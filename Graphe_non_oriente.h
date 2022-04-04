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
    Graphe_non_oriente(Graphe *graphe);
    Graphe_non_oriente();
    void codage_prufer(int *&p);/*TODO tester codage prufer*/
    int** decodage_prufer(int *codage);/*TODO tester décodage prufer*/
    void coloration(int *&f);//TESTED
    int nombre_chromatique(const int *f) const;//TESTED
    virtual void run();
    virtual int menu();

};


#endif //PROJETGRAPHEALGO_GRAPHE_NON_ORIENTE_H
