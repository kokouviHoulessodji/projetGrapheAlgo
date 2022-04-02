//
// Created by Houlessodji Kokouvi on 26/03/2022.
//

#ifndef PROJETGRAPHEALGO_GRAPHE_ORIENTE_VALUE_H
#define PROJETGRAPHEALGO_GRAPHE_ORIENTE_VALUE_H
#include "Graphe_oriente.h"

class Graphe_oriente_value : public Graphe_oriente {
    private:
        int** d_cout;
    public:
        Graphe_oriente_value(Graphe_oriente graphe_oriente);
        void saisir_cout();
        void ordonnancement(int *d, int *&fpc, int *&appc, int *&lc);
        void Dijkstra(int s, int *&d, int *&pr);
        void Dijkstra(int **&mat_d, int **&mat_pred);
};


#endif //PROJETGRAPHEALGO_GRAPHE_ORIENTE_VALUE_H
