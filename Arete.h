//
// Created by Houlessodji Kokouvi on 11/03/2022.
//

#ifndef PROJETGRAPHEALGO_ARETE_H
#define PROJETGRAPHEALGO_ARETE_H

#include "Sommet.h"
#include <iostream>
class  Arete{
protected:
    int d_sommet_depart, d_sommet_arrive;
    int d_poids;
public:
    Arete(int sommet_depart, int sommet_arrive, int poids);//TESTED
    Arete(int sommet_depart, int sommet_arrive);//TESTED
    Arete();
    int sommet_depart() const;//TESTED
    int sommet_Arrive() const;//TESTED
    int poids() const;//TESTED
    void setPoids(int poids);//TESTED

    void modifier_sommet_depart(int sommet_depart);//TESTED
    void modifier_sommet_arrive(int sommet_arrive);//TESTED
    void changerOrientation();//TESTED

    void dessiner();/*TODO tester dessiner*/
};


#endif //PROJETGRAPHEALGO_ARETE_H
