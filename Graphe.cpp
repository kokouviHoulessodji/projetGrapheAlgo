#include "Graphe.h"
#include <iostream>
Graphe::Graphe() : d_matrice_d_adjascence{}, d_aps{}, d_fs{}, dde{}, ddi{}
{
    saisir_matrice();
}
Graphe::~Graphe(){

}
void Graphe:: ajoutSommet()
{

}
void Graphe:: matriceFromFichier(const string &NomFichier)
{
    ifstream file;
    file.open(NomFichier);
    if(!file)
        cout<<"FILE_ERROR";
    int NombreSommet;
    int NombreArc;
    file>>NombreSommet;
    file>>NombreArc;
    d_matrice_d_adjascence=new int*[NombreSommet+1];
    for(int i=0;i<=NombreSommet;i++)
    {
        d_matrice_d_adjascence[i]=new int[NombreSommet+1];
    }
    d_matrice_d_adjascence[0][0]=NombreSommet;
    d_matrice_d_adjascence[0][1]=NombreArc;
    for(int i=2;i<=NombreSommet;i++)
    {
        file>>d_matrice_d_adjascence[0][i];
    }
    for(int i=1;i<=NombreSommet;i++)
    {
        for(int j=0;j<=NombreSommet;j++)
        {
            file>>d_matrice_d_adjascence[i][j];

        }
    }
}
void Graphe:: fsApsFromFichier(const string &NomFichier)
{
    ifstream file;
    file.open(NomFichier);
    if(!file)
        cout<<"FILE_ERROR";
    int tailleFs;
    file>>tailleFs;
    d_fs=new int[tailleFs+1];
    d_fs[0]=tailleFs;
    for(int j=1;j<=tailleFs;j++){
        file>>d_fs[j];
    }
    int NombreSommet;
    file>>NombreSommet ;
    d_aps=new int [NombreSommet+1];
    d_aps[0]=NombreSommet;
    for(int j=1;j<=NombreSommet;j++){
        file>>d_aps[j];
    }
}
void Graphe:: matriceToFsAps()
{
    int NombreSommet=d_matrice_d_adjascence[0][0];
    int NombreArc=d_matrice_d_adjascence[0][1];
    d_fs=new int [NombreSommet+NombreArc+1];
    d_aps=new int[NombreSommet+1];
    d_fs[0]=NombreSommet+NombreArc;
    d_aps=new int[NombreSommet+1];
    d_aps[0]=NombreSommet;
    int indexFs=1;
    int indexAps=indexFs;
    for(int i=1;i<=NombreSommet;i++)
    {
        d_aps[indexAps]=indexFs;
        for(int j=1;j<=NombreSommet;j++)
        {
            if(d_matrice_d_adjascence[i][j]==1)
            {
                d_fs[indexFs]=j;
                indexFs++;
            }
        }
        d_fs[indexFs]=0;
        indexFs++;
        indexAps++;
    }
}
void Graphe:: fsApsToMatrice()
{
    int NombreSommet=d_aps[0];
    d_matrice_d_adjascence=new int*[NombreSommet+1];
    for(int i=0;i<=NombreSommet;i++){
        d_matrice_d_adjascence[i]=new int[NombreSommet+1];
    }
    for(int i=0;i<=NombreSommet;i++){
        for(int j=0;j<=NombreSommet;j++){
            d_matrice_d_adjascence[i][j]=0;
        }
    }
    d_matrice_d_adjascence[0][0]=NombreSommet;

    int NombreArc=d_fs[0]-NombreSommet;
    d_matrice_d_adjascence[0][1]=NombreArc;

    int indexFs;
    for(int i=1;i<=d_aps[0];i++){
        indexFs=d_aps[i];
        while(d_fs[indexFs]!=0){
            d_matrice_d_adjascence[i][d_fs[indexFs]]=1;
            indexFs++;
        }
    }
}
void Graphe::demi_degre_int()
{
    int n = d_aps[0];
    int taille_fs = d_fs[0];
    ddi = new int [n+1];
    ddi[0] = n;
    for (int i = 1; i <= n; ++i)
        ddi[i] = 0;
    for (int i = 1; i < taille_fs; ++i)
        if (d_fs[i] != 0)
            ddi[d_fs[i]]++;
}
void Graphe::demi_degre_ext()
{
    int n = d_aps[0];
    dde = new int [n+1];
    dde[0] = n;
    for (int i = 1; i < n; ++i)
        dde[i] = d_aps[i + 1] - d_aps[i] - 1;
    dde[n] = d_fs[0] - d_aps[n];
}
void Graphe::saisir_matrice()
{
    int n, m = 0;
    printf("Donner le nombre de sommets du graphe : ");
    std::cin>>n;
    d_matrice_d_adjascence = new int*[n+1];
    d_matrice_d_adjascence[0] = new int[2];
    for (int k = 1; k <= n ; ++k) {
        d_matrice_d_adjascence[k] = new int[n+1];
    }
    for (int k = 1; k <= n ; ++k) {
        for (int l = 1; l <= n ; ++l) {
            d_matrice_d_adjascence[k][l] = 0;
        }
    }
    d_matrice_d_adjascence[0][0] = n;
    /* saisie du graphe et initialisations */
    for (int i = 1; i <= n; i++)
    {
        int ns;
        printf("Donner le nombre de successeurs du sommet %d : ", i);
        std::cin>>ns;
        for (int j = 1; j <= ns; j++)
        {
            int k;
            std::cout<<j<<"e successeur : ";
            std::cin>>k;
            d_matrice_d_adjascence[i][k] = 1;
            m++;
        }
    }
    d_matrice_d_adjascence[0][1] = m;
    matriceToFsAps();
}
int* Graphe::getApp()const
{

}
int* Graphe::getFp()const
{

}
int* Graphe::distance(int sommet) const
{
    int *tab;
    int NombreSommet=d_aps[0];
    tab=new int[NombreSommet+1];
    tab[0]=d_aps[0];
    for(int i=1;i<=d_aps[0];i++)
        tab[i]=-1;
    tab[sommet]=0;
    int file[NombreSommet];
    int distance=1;
    int indexFs;
    int debut=1,courant=0,fin=1;
    file[debut]=sommet;
    while(courant<fin){
        for(int i=courant+1;i<=debut;i++){
            indexFs=d_aps[file[i]];
            while(d_fs[indexFs]!=0){
                if(tab[d_fs[indexFs]]==-1){
                    tab[d_fs[indexFs]]=distance;
                    fin++;
                    file[fin]=d_fs[indexFs];
                }
                indexFs++;
            }
        }
        courant=debut;
        debut=fin;
        distance++;
    }
    return tab;
}
int** Graphe:: distance()const
{
    int nbSommet=d_aps[0];
    int **mat;
    mat=new int*[nbSommet+1];
    mat[0]=new int[nbSommet+1];
    mat[0][0]=nbSommet;
    mat[0][1]=d_fs[0]-nbSommet;
    for(int i=1;i<=nbSommet;i++){
        mat[i]=distance(i);
    }
    return mat;
}

void Graphe::readFile(const string&fileName)
{

}

void Graphe:: afficheFsAps()
{
    std::cout<<"FS : [ ";
    for (int i = 1; i <= d_fs[0] ; ++i)
        std::cout<<d_fs[i]<<" ";
    std::cout<<"]"<<std::endl;
    std::cout<<"APS : [ ";
    for (int i = 1; i <= d_aps[0] ; ++i)
        std::cout<<d_aps[i]<<" ";
    std::cout<<"]"<<std::endl;
}
void Graphe::afficheMatrice()
{
    std::cout<<"Matrice d'adjascence : "<<std::endl;
    for(int i=1;i<=d_matrice_d_adjascence[0][0];i++){
        std::cout<<"[ ";
        for(int j=1;j<=d_matrice_d_adjascence[0][0];j++)
            cout<<d_matrice_d_adjascence[i][j]<<" ";
        cout<<"]"<<endl;
    }
}
int* Graphe::getFs()const
{
    return d_fs;
}
int* Graphe::getAps() const
{
    return d_aps;
}
int** Graphe::getMatrice() const
{
    return d_matrice_d_adjascence;
}

int* Graphe:: det_rang( int *&num)
{
    int *rrang;
    int n = d_aps[0];
    num = new int[n+1];
    rrang = new int[n+1];
    num[0] = n;

    int *pile = new int[n+1]; // pour gérer les sommets
    // indices dans la pile
    int t = 1;
    int r = 0;
    int pas = -1;
    int e = 0;
    int y,d;

    //init le rang
    for(int i = 1; i <= n; i++)
    {
        rrang[i] = -1;
        num[i] = -1;
    }
    rrang[0] = n;
    num[0] = n;

    for(int i = 1; i <= n; i++)
    {
        if(dde[i] == 0) //pas d'arc vers le sommet i
            pile[++e] = i; //empile le sommet i
    }
    d = n+1;
    while((e != 0) && (e != n+1)) //tant qu'il reste des arcs de ddi dans la pile
    {
        int x = e; // permutation des elements de la pile
        e = d;
        d = x;
        while((d != 0)&&(d != n+1)) // s'il reste des atcs de ddi dans la pile inversée
        {
            int s = pile[d]; // sommet de la pile
            rrang[s] = r; // le rang du sommet courant
            num[s] = t;
            t++;
            for(int l = d_aps[s]; (y=d_fs[l]) > 0; l++) // parcours des successeurs du sommet
            {
                dde[y]--; // arc de moins
                if(dde[y] == 0)
                {
                    e += pas;
                    pile[e] = y; // ajout du sommet qui n'a plus d'arcs
                }
            }
            d += pas; //
        }
        r++; // rang suivant
        pas = -pas; // parcours au sens inverse
    }
    return rrang;
}
int* Graphe::rang(int *&pileDesEntrets,int *&pileDesElement)
{

}
int* Graphe::rang()const
{

}
void Graphe::empiler(int x, int*&pilch) const {
    pilch[x] = pilch[0];
    pilch[0] = x;
}

//Les fonction pour les tests
void Graphe::afficheDDE()const
{
    int n = d_aps[0];
    for (int i = 1; i <= n; ++i)
        cout<<dde[i]<<"";
}
void Graphe::afficheDDI()const
{
    int n = d_aps[0];
    for (int i = 1; i <= n; ++i)
        cout<<ddi[i]<<"";
}
void Graphe::afficheFpApp()const
{

}
void Graphe::afficheMatrice(int** m)const
{
    for(int i=0;i<=m[0][0];i++){
        for(int j=0;j<=m[0][0];j++){
            cout<<' '<<m[i][j];
        }cout<<endl;
    }cout<<endl;
}