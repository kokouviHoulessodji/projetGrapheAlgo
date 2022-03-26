//
// Created by Houlessodji Kokouvi on 26/03/2022.
//

#include "Graphe_oriente_value.h"

void Graphe_oriente_value::ordonnancement(int *d, int *&fpc, int *&appc, int *&lc)
{
    int *app = getApp();
    int *fp = getFp();
    int n = app[0], m = fp[0];
    fpc = new int[m+1];
    appc = new int[n+1]; appc[0] = n; lc = new int[n+1]; lc[0] = n;
    int kc, t, lg;
    lc[1] = 0;
    fpc[1] = 0; // fin de la liste
    appc[1] = 1;
    kc = 1; // indice de la dernière place remplie dans fpc
    for(int s = 2; s <= n; s++)
    {
        //calcul de lc[s] en fonction des prédécesseurs de s
        lc[s] = 0;
        appc[s] = kc+1; // début de la liste des prédécesseurs critiques de s
        for (int k = app[s]; (t = fp[k]) != 0; k++)
        {
            lg = lc[t] + d[t];
            if (lg >= lc[s])
            {
                if (lg > lc[s])
                {
                    lc[s] = lg; // Nouvelle lg candidate a être critique
                    kc = appc[s];
                    fpc[kc] = t;
                }
                else // lg == lc[s] : ajouter un nouveau prédécesseur critique
                {
                    kc++;
                    fpc[kc] = t;
                }
            }
        }
        kc++ ;
        fpc[kc] = 0;//fin de la liste des prédécesseurs critiques de s
    }
    fpc[0] = kc;
}

Graphe_oriente_value::Graphe_oriente_value(Graphe_oriente graphe_oriente, int **cout) :
    Graphe_oriente{graphe_oriente}, d_cout{cout}
{

}
