//
// Created by Houlessodji Kokouvi on 11/03/2022.
//

#include "Arete.h"


Arete::Arete(int sommet_depart, int sommet_arrive, int poids) :
d_sommet_depart(sommet_depart),
d_sommet_arrive(sommet_arrive),
d_poids{poids}
{}
Arete::Arete() :
        d_sommet_depart{0},
        d_sommet_arrive{0},
        d_poids{0}
{}
Arete::Arete(int sommet_depart, int sommet_arrive) :
        d_sommet_depart{sommet_depart},
        d_sommet_arrive{sommet_arrive},
        d_poids{0}
{}
int Arete::sommet_depart() const
{
    return d_sommet_depart;
}

int Arete::sommet_Arrive() const {
    return d_sommet_arrive;
}

void Arete::modifier_sommet_depart(int sommet_depart)
{
    d_sommet_depart = sommet_depart;
}

void Arete::modifier_sommet_arrive(int sommet_arrive)
{
    d_sommet_arrive = sommet_arrive;
}

void Arete::changerOrientation() {
    std::swap(d_sommet_depart, d_sommet_arrive);
}
int Arete::poids() const {
    return d_poids;
}

void Arete::setPoids(int poids) {
    d_poids = poids;
}

void Arete::dessiner() {

}
