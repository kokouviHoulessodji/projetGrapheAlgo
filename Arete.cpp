//
// Created by Houlessodji Kokouvi on 11/03/2022.
//

#include "Arete.h"
#include "Sommet.h"


Arete::Arete(Sommet sommet_depart, Sommet sommet_arrive, bool oriente) :
d_sommet_depart(sommet_depart),
d_sommet_arrive(sommet_arrive),
d_oriente{oriente}
{}
Arete::Arete() :
        d_sommet_depart{0},
        d_sommet_arrive{0},
        d_oriente{false}
{}
Arete::Arete(Sommet sommet_depart, Sommet sommet_arrive) :
        d_sommet_depart{sommet_depart},
        d_sommet_arrive{sommet_arrive},
        d_oriente{false}
{}
Sommet Arete::sommet_depart()
{
    return d_sommet_depart;
}

Sommet Arete::sommet_Arrive() {
    return d_sommet_arrive;
}

void Arete::modifier_sommet_depart(Sommet sommet_depart)
{
    d_sommet_depart = sommet_depart;
}

void Arete::modifier_sommet_arrive(Sommet sommet_arrive)
{
    d_sommet_arrive = sommet_arrive;
}

void Arete::changerOrientation() {

}
