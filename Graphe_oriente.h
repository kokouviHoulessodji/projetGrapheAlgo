//
// Created by Houlessodji Kokouvi on 11/03/2022.
//

#ifndef PROJETGRAPHEALGO_GRAPHE_ORIENTE_H
#define PROJETGRAPHEALGO_GRAPHE_ORIENTE_H
#include "Graphe.h"
#include "Arete.h"
#include <vector>

class Graphe_oriente : public Graphe {

public:
    Graphe_oriente(Graphe graphe);
    //void tarjan(int sommet);
    //void tarjan(int vertex, std::vector<int> st);
    void traverse(int s, int &p, int *&num, int *&ro, int *&pilch, int *&cfc, int *aps, int *fs, int *&tarj, bool *&entarj, int *&prem) const;
    //void calculerCFC(std::vector<int>& prem,std::vector<int>& pilch, std::vector<int>& cfc) const;
    //Graphe_oriente calculerGrapheReduit(int *prem, int *pilch, int *cfc, int *fs, int *aps, int *&fsr, int *&apsr) const;

    void graph_reduit(int *prem, int *pilch, int *cfc, int *fs, int *aps, int *&fsr, int *&apsr);
    void base_Greduit(int *apsr, int *fsr, int *&br) ;
    void afficher(int *base, int nb);
    void edition_bases(int *prem, int *pilch, int *br);
    void fortconnexe(int *aps, int *fs, int *&prem, int *&pilch, int *&cfc, int *&pred);
protected:


};


#endif //PROJETGRAPHEALGO_GRAPHE_ORIENTE_H
