//
// Created by Houlessodji Kokouvi on 11/03/2022.
//

#include "Graphe_non_oriente.h"

int* Graphe_non_oriente::codage_prufer() {
    int** mat = getMatrice();
    int n = mat[0][0];
    int* p = new int[n-1];
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

int **Graphe_non_oriente::decodage_prufer(int *codage) {
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
    std::vector<int> sd;
    sd.reserve(2);
    for (int i = 1; i <= n ; ++i) {
        if(s[i] == 0) {
            sd.push_back(i);
        }
    }
    mat[sd[0]][sd[1]] = 1;
    return mat;
}

int *Graphe_non_oriente::coloration() {
    int n = d_aps[0];
    int* f = new int[n+1];
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
    return f;
}

int Graphe_non_oriente::nombre_chromatique(int* f) {
    int max = f[1];
    for (int i = 2; i <= f[0] ; ++i) {
        if(f[i] > max)
            max = f[i];
    }
    return max;
}

Graphe_non_oriente::Graphe_non_oriente(Graphe graphe) : Graphe{graphe} {

}
