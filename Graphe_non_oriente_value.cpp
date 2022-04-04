//
// Created by Houlessodji Kokouvi on 02/04/2022.
//

#include "Graphe_non_oriente_value.h"

void Graphe_non_oriente_value::saisir_cout() {
    int infini = INT_MAX;
    int n = d_aps[0];
    d_cout = new int*[n+1];
    for (int i = 1; i <= n ; ++i)
        d_cout[i] = new int[n+1];
    for (int i = 1; i <= n ; ++i)
        for (int j = 1; j <= n ; ++j)
            d_cout[i][j] = infini;
    for (int i = 0; i < n ; ++i) {
        int p;
        cout<<"Saisir le poids de l'arc [ "<<aretes[i].sommet_depart()<<", "<<aretes[i].sommet_Arrive()<<" ] : ";
        cin>>p;
        aretes[i].setPoids(p);
        d_cout[aretes[i].sommet_depart()][aretes[i].sommet_Arrive()] = p;
    }
}

Graphe_non_oriente_value::Graphe_non_oriente_value(Graphe_non_oriente *graphe_non_oriente) :
Graphe_non_oriente{*graphe_non_oriente}, d_cout{}
{
    saisir_cout();
    matriceToAretes();
}

Graphe_non_oriente_value* Graphe_non_oriente_value::kruskal(int *&prem, int *&pilch, int *&cfc) {
    trier();
    int k=0, s, tt;
    int n = d_matrice_d_adjascence[0][0];
    int m = d_matrice_d_adjascence[0][1];
    //Initialiser cfc, pilch et prem
    cfc = new int[n+1];
    prem = new int[n+1];
    pilch = new int[n+1];
    for (int i = 0; i <= n ; ++i) {
        cfc[i] = i;
        prem[i] = i;
        pilch[i] = 0;
    }
    auto t = new Graphe_non_oriente_value();
    t->aretes = new Arete[n-1];
    for (int i = 0; i < m; ++i)
    {
        s = aretes[i].sommet_depart();
        tt = aretes[i].sommet_Arrive();
        if(cfc[s] != cfc[tt])
        {
            std::cout<<"---- i = "<<i<<" -----"<<endl;
            t->aretes[k++] = aretes[i];
            fusionner(cfc[s], cfc[tt], prem, pilch, cfc);
            std::cout<<"CFC : ";
            for (int j = 0; j <= n ; ++j) {
                std::cout<<cfc[j]<<" ";
            }
            std::cout<<std::endl;
            std::cout<<"PILCH : ";
            for (int j = 0; j <= n ; ++j) {
                std::cout<<pilch[j]<<" ";
            }
            std::cout<<std::endl;
            std::cout<<"PREM : ";
            for (int j = 0; j <= n ; ++j) {
                std::cout<<prem[j]<<" ";
            }
            std::cout<<std::endl;
        }
    }
    t->aretesToMatrice();
    t->matriceToFsAps();
    return t;
}

void Graphe_non_oriente_value::fusionner(int i, int j, int *&prem, int *&pilch, int *&cfc)
// i et j sont les numéros des composantes à fusionner
// en une seule composante qui portera le numéro le plus
// petit des deux
{
    int k = prem[i];
    while (pilch[k] != 0)
    {
        k = pilch[k];
    }
    pilch[k] = prem[j];
    k = prem[j];
    while (k != 0)
    {
        cfc[k] = i;
        k = pilch[k];
    }
}
//TESTED
//2e version avec un seul parcours de prem de i
void Graphe_non_oriente_value::fusionner2(int i, int j, int *&prem, int *&pilch, int *&cfc)
{
    //Si on veut favoriser la composante ayant le plus petit numéro
    //if(i < j) std::swap(i, j);
    int k = prem[i];
    while (pilch[k] != 0)
    {
        cfc[k] = j;
        k = pilch[k];
    }
    cfc[k] = j;
    pilch[k] = prem[j];
    prem[j] = prem[i];
}


Graphe_non_oriente_value::Graphe_non_oriente_value() : Graphe_non_oriente{}, d_cout{}{

}

bool Graphe_non_oriente_value::Dantzig() {
    //c : matrice des coûts qui sera remplacée par la matrice des distances
    //Renvoie false si le graphe contient un circuit absorbant
    int n = (int)(d_aps[0]);
    int **c = d_cout;
    int k, i ,j;
    int x;
    for (k = 1; k < n; ++k)
    {
        for (i = 1; i <= k; ++i)
        {
            for (j = 1; j <= k; ++j)
            {
                if((x = c[i][j] + c[j][k+1]) < c[i][k+1])
                    c[i][k+1] = x;
                if((x = c[k+1][j] + c[j][i]) < c[k+1][i])
                    c[k+1][i] = x;
            }//fin for j
            if((c[i][k+1] + c[k+1][i]) < 0)
            {
                printf("Présence d'un circuit absorbant passant par %d et %d \n", i, k+1);
                return true;
            }
        }//fin for i
        for (i = 1; i <= k; ++i)
            for (j = 1; j <= k; ++j)
                if((x = c[i][k+1] + c[k+1][j]) < c[i][j])
                    c[i][j] = x;
    }//fin for k
}

int Graphe_non_oriente_value::menu() {

}
void Graphe_non_oriente_value::run()
{

}

Graphe_non_oriente_value::~Graphe_non_oriente_value() {
    int n = d_cout[0][0];
    for (int i = 0; i <= n ; ++i)
        delete[] d_cout[i];
}
