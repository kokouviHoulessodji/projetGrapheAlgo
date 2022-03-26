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
    Graphe_oriente();
    void empiler(std::vector<int> pile,int valeur);
    int depiler(std::vector<int> pile);
    void tarjan(int sommet);
    void composantC();
    void tarjan(int vertex, std::vector<int> st);

    Graphe_oriente calculerGrapheReduit(const std::vector<int>& prem,const std::vector<int>& pilch,const std::vector<int>& cfc) const;
    void traverse(int s,std::vector<int>& prem,std::vector<int>& pilch,std::vector<int>& cfc,std::vector<int>& tarj,std::vector<bool>& enTarj,int& ns,int& nc,std::vector<int>& num,std::vector<int>& ro) const;
    void calculerCFC(std::vector<int>& prem,std::vector<int>& pilch, std::vector<int>& cfc) const;
};


#endif //PROJETGRAPHEALGO_GRAPHE_ORIENTE_H
