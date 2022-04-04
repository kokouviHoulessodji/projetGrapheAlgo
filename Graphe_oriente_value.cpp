//
// Created by Houlessodji Kokouvi on 26/03/2022.
//

#include "Graphe_oriente_value.h"

void Graphe_oriente_value::saisir_cout() {
    int infini = INT_MAX;
    int n = d_aps[0];
    d_cout = new int*[n+1];
    d_cout[0] = new int[2];
    d_cout[0][0] = n;
    for (int i = 1; i <= n ; ++i)
        d_cout[i] = new int[n+1];
    for (int i = 1; i <= n ; ++i)
        for (int j = 1; j <= n ; ++j)
            d_cout[i][j] = infini;
    for (int i = 0; i < d_fs[0]-n ; ++i) {
        double p;
        cout<<"Saisir le poids de l'arc [ "<<aretes[i].sommet_depart()<<", "<<aretes[i].sommet_Arrive()<<" ] : ";
        cin>>p;
        aretes[i].setPoids(p);
        d_cout[aretes[i].sommet_depart()][aretes[i].sommet_Arrive()] = p;
    }
}
void Graphe_oriente_value::ordonnancement(int *d, int *&fpc, int *&appc, int *&lc)
{
    int *app, *fp;
    fs_aps_2_fp_app(fp, app);
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

Graphe_oriente_value::Graphe_oriente_value(Graphe_oriente *graphe_oriente) :
    Graphe_oriente{*graphe_oriente}, d_cout{}
{
    saisir_cout();
}

void Graphe_oriente_value::Dijkstra(int s, int *&d, int *&pr)
{
    int ind; /* nombre d'elements qui restent a traiter */
    int i, j, k, v;
    int n = d_aps[0];
    int m = d_fs[0];
    pr = (int *) malloc((n + 1) * sizeof(int));
    d = (int *) malloc((n + 1) * sizeof(int));
    int *inS = (int *) malloc((n + 1) * sizeof(int));
    /* sert a dire quels sont les sommets qui restent a traiter inS[i] = 0 ou 1*/
    /* initialisation des tableaux d, pr et inS*/
    for (i = 1; i <= n; i++)
    {
        d[i] = d_cout[s][i];
        inS[i] = 1;
        k = d_aps[s];
        while(d_fs[k] != 0 && d_fs[k] != i)
            k++;
        if(d_fs[k] == i)
            pr[i] = 1;
        else
            pr[i] = -1;
    }
    d[s] = 0;
    pr[s] = 0;
    inS[s] = 0; /* on supprime le sommet 1 */
    ind = n - 1;
    while (ind > 0)
    {
        /* calcule du minimum selon d des sommets de S */
        m = INT_MAX;
        for (i = 1; i <= n; i++)
            if (inS[i] == 1)
                if (d[i] < m) {
                    m = d[i];
                    j = i;
                }
        if (m == INT_MAX)
            return;
        inS[j] = 0;
        ind--;
        k = d_aps[j];
        while (d_fs[k] != 0)
        {
            if (inS[d_fs[k]] == 1) {
                v = d[j] + d_cout[j][d_fs[k]];
                if (v < d[d_fs[k]]) {
                    d[d_fs[k]] = v;
                    pr[d_fs[k]] = j;
                }
            }
            k++;
        }
    }
}
void Graphe_oriente_value::Dijkstra(int **&mat_d, int **&mat_pred)
{
    int n = d_aps[0];
    mat_d = new int*[n+1];
    mat_d[0] = new int[1];
    mat_d[0][0] = n;
    mat_pred = new int*[n+1];
    mat_pred[0] = new int[1];
    mat_pred[0][0] = n;
    for (int s = 1; s <= n; ++s)
        Dijkstra(s, mat_d[s], mat_pred[s]);
}
int Graphe_oriente_value::menu()
{
    int choix;
    {
        cout << "Quel algorithme souhaitez-vous testé sur ce graphe orienté? " << endl;
        cout << "1 - Djikstra : taper 1" << endl;
        cout << "2 - Ordonnancement : taper 2" << endl;
        cout << "3 - Pour quitter : taper 3" << endl;
        cin >> choix;
    }
    while (choix < 1 || choix > 3);
    return choix;
}
void Graphe_oriente_value::run()
{
    int choix = menu();
    while (choix != 3)
    {
        if(choix == 1){
            int** dist, **pred;
            Dijkstra(dist, pred);
            std::cout<<"------ Matrice des distances ------"<<std::endl;
            for(int i=1;i<=dist[0][0];i++){
                std::cout<<"sommet "<<i<<" : [ ";
                for(int j=1;j<=dist[0][0];j++)
                    cout<<dist[i][j]<<" ";
                cout<<"]"<<endl;
            }
            std::cout<<"------ Matrice des pred ------"<<std::endl;
            for(int i=1;i<=dist[0][0];i++){
                std::cout<<"sommet "<<i<<" : [ ";
                for(int j=1;j<=dist[0][0];j++)
                    cout<<pred[i][j]<<" ";
                cout<<"]"<<endl;
            }
            int n = dist[0][0];
            for (int i = 0; i <= n ; ++i)
                delete[] dist[i];
            for (int i = 0; i <= n ; ++i)
                delete[] pred[i];
        }
        else if(choix == 2)
        {

        }
        choix = menu();
    }
}

Graphe_oriente_value::~Graphe_oriente_value() {
    for (int i = 1; i <= d_cout[0][0] ; ++i)
        delete[] d_cout[i];
}
