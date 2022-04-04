//
// Created by Houlessodji Kokouvi on 11/03/2022.
//

#include "Graphe_non_oriente.h"

void Graphe_non_oriente::codage_prufer(int *&p) {
    int n = d_aps[0];
    int** mat = new int*[n+1];
    for (int i = 0; i <= n ; ++i) {
        mat[i] = d_matrice_d_adjascence[i];
    }

    p = new int[n-1];
    p[0] = n-2;
    for (int i = 1; i <= n ; ++i)
    {
        mat[i][0] = 0;
        for (int j = 1; j <= n; ++j)
            mat[i][0] += mat[i][j];
    }
    for (int k = 1; k <= n-2 ; ++k)
    {
        int i = 1;
        while(mat[i][0] != 1)
            i++;
        int j = 1; //unique voisin de i
        while(mat[i][j] != 1)
            j++;
        p[k] = k;
        mat[i][j] = 0;
        mat[j][i] = 0;
        mat[i][0] = 0;
        mat[j][0]--;
    }
}

int** Graphe_non_oriente::decodage_prufer(int *codage) {
    int m = codage[0], n = m+2;
    int **mat = new int*[n+1];
    mat[0] = new int[1];

    for (int i = 1; i <= n; ++i)
        mat[i] = new int[n+1];
    mat[0][0] = n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n ; ++j)
            mat[i][j] = 0;
    int *s = new int[n+1];
    for (int i = 1; i <= n ; ++i)
        s[i] = 0;
    for (int i = 1; i <= m ; ++i)
        s[codage[i]]++;
    cout<<"Les arêtes du graphe correspondant au codage donné sont :"<<endl;
    for (int i = 1; i <= m ; ++i)
    {
        cout<<"[ "<<codage[i];
        int k = 1;
        while(s[k] != 0)
            k++;
        cout<<" "<<k<<" ]"<<endl;
        s[k] = -1;
        s[codage[i]]--;
        mat[codage[i]][k] = 1;
    }
    cout<<"[ ";
    std::vector<int> sd;
    sd.reserve(2);
    for (int i = 1; i <= n ; ++i) {
        if(s[i] == 0) {
            sd.push_back(i);
            cout << i << " ";
        }
    }
    mat[sd[0]][sd[1]] = 1;
    cout<<"]"<<endl;
}

void Graphe_non_oriente::coloration(int *&f) {
    int n = d_aps[0];
    f = new int[n+1];
    for (int i = 1; i <= n ; ++i) {
        f[i] = 0;
    }
    f[0] = n;
    for (int i = 1; i <= n ; ++i) {
        int c = 1;
        int k = d_aps[i];
        while (d_fs[k]!=0 && f[d_fs[k]] == c) {
            c++; k++;
        }
        f[i] = c;
    }
}

int Graphe_non_oriente::nombre_chromatique(const int *f) const{
    int max = f[1];
    for (int i = 2; i <= f[0] ; ++i) {
        if(f[i] > max)
            max = f[i];
    }
    return max;
}

Graphe_non_oriente::Graphe_non_oriente(Graphe *graphe) : Graphe{*graphe} {

}

Graphe_non_oriente::Graphe_non_oriente() : Graphe{}{

}

int Graphe_non_oriente::menu()
{
    int choix;
    do {
        cout << "Quel algorithme souhaitez-vous testé sur ce graphe orienté? " << endl;
        cout << "1 - Codage de Prufer : taper 1" << endl;
        cout << "2 - Décodage de Prufer : taper 2" << endl;
        cout << "3 - Coloration et nombre chromatique du graphe : taper 3" << endl;
        cout << "4 - Pour quitter : taper 4" << endl;
        cin>>choix;
    }while (choix < 1 || choix > 4);
    return choix;
}
void Graphe_non_oriente::run()
{
    int choix = menu();
    while(choix != 4)
    {
        if(choix == 1){
            int *codage;
            codage_prufer(codage);
            cout<<"Le codage de prufer correspondant au graphe est : [ ";
            for (int i = 0; i <= codage[0] ; ++i) {
                cout<<codage[0]<<" ";
            }
            cout<<"] "<<endl;
            delete[] codage;
        }
        else if(choix == 2)
        {
            int n;
            cout<<"Donner enter le nombre d'élément du tableau correspondant au codage de prufer : ";
            cin>>n;
            int *codage = new int[n];
            codage[0] = n-1;
            cout<<"Rentrer les valeurs du tableau de codage : ";
            for (int i = 1; i <= n-1 ; ++i) {
                cin>>codage[i];
            }
            int **mat = decodage_prufer(codage);
            cout<<"Le graphe correspondant à ce codage a pour matrice : "<<endl;
            for (int i = 1; i <= mat[0][0] ; ++i) {
                cout<<"[ ";
                for (int j = 1; j <= mat[0][0] ; ++j) {
                    cout<<mat[i][j]<<" ";
                }
                cout<<"] "<<endl;
            }
            delete[] codage;
            for (int i = 0; i <= mat[0][0] ; ++i)
                delete[] mat[i];
        }
        else if(choix == 3)
        {
            int *f;
            coloration(f);
            int nChr = nombre_chromatique(f);
            cout<<"La coloration correspondant à votre graphe est : "<<endl<<"[ ";
            for (int i = 1; i <= f[0] ; ++i) {
                cout<<"Couleur du sommet "<<i<<" = "<<f[i]<<" "<<endl;
            }
            cout<<"]"<<endl;
            cout<<"Le nombre chromatique du graphe est égal à "<<nChr<<endl;
            delete[] f;
        }
        choix = menu();
    }

}
