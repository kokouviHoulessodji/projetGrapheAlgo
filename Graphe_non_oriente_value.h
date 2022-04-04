//
// Created by Houlessodji Kokouvi on 02/04/2022.
//

#ifndef PROJETGRAPHEALGO_GRAPHE_NON_ORIENTE_VALUE_H
#define PROJETGRAPHEALGO_GRAPHE_NON_ORIENTE_VALUE_H
#include "Graphe_non_oriente.h"
#include "Arete.h"

class Graphe_non_oriente_value : public Graphe_non_oriente {
    private:
        int** d_cout;
    public:
        Graphe_non_oriente_value(Graphe_non_oriente *graphe_non_oriente);
        Graphe_non_oriente_value();
        void saisir_cout();//TESTED
        void fusionner(int i, int j, int *&prem, int *&pilch, int *&cfc);//TESTED
        void fusionner2(int i, int j, int *&prem, int *&pilch, int *&cfc);//TESTED
        Graphe_non_oriente_value* kruskal(int *&prem, int *&pilch, int *&cfc);/*TODO tester kruskal*/
        bool Dantzig();/*TODO tester Dantzig*/
        int menu() override;
        void run() override;
        ~Graphe_non_oriente_value() override;
};


#endif //PROJETGRAPHEALGO_GRAPHE_NON_ORIENTE_VALUE_H
