//
// Created by Houlessodji Kokouvi on 11/03/2022.
//

#ifndef PROJETGRAPHEALGO_ARETE_H
#define PROJETGRAPHEALGO_ARETE_H

#include "Sommet.h"

class  Arete{
protected:
    Sommet d_sommet_depart, d_sommet_arrive;
    bool d_oriente;
public:
    Arete(Sommet sommet_depart, Sommet sommet_arrive, bool oriente);
    Arete(Sommet sommet_depart, Sommet sommet_arrive);
    Arete();
    Sommet sommet_depart();
    Sommet sommet_Arrive();

    void modifier_sommet_depart(Sommet sommet_depart);
    void modifier_sommet_arrive(Sommet sommet_arrive);
    void changerOrientation();

    void dessiner();
};


#endif //PROJETGRAPHEALGO_ARETE_H
