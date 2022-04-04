#include "Graphe.h"
#include <iostream>
Graphe::Graphe() : d_matrice_d_adjascence{}, d_aps{}, d_fs{}, dde{}, ddi{}, aretes{}, d_nb_sommet{}, d_nb_aretes{}
{
    menu_console();
}
Graphe::~Graphe(){
    int n = d_matrice_d_adjascence[0][0];
    for (int i = 0; i <= n ; ++i)
        delete[] d_matrice_d_adjascence[i];
    delete[] d_aps;
    delete[] d_fs;
    delete[] ddi;
    delete[] dde;
    delete[] aretes;
}
void Graphe::ajoutSommet()
{
    int n = d_aps[0];
    int np;
    int** mat = new int*[n+2];
    mat[0] = new int[2];
    mat[0][0] = n+1;
    mat[0][1] = d_matrice_d_adjascence[0][1];
    for (int i = 1; i <= n+1 ; ++i)
        mat[i] = new int[n+2];
    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= n ; ++j) {
            mat[i][j] = d_matrice_d_adjascence[i][j];
        }
    }
    for (int i = 1; i <=n+1 ; ++i) {
        mat[n+1][i] = 0;
    }
    for (int i = 1; i <=n+1 ; ++i) {
        mat[i][n+1] = 0;
    }
    cout<<"Quel est le nombre de nombre de prédécésseurs du nouveau sommet n "<<n+1<<" : ";
    cin>>np;
    while (np<0)
    {
        cout<<"Les nombres négatifs ne sont pas autorisés. Retaper : "<<n+1;
        cin>>np;
    }
    for (int i = 1; i <= np ; ++i) {
        int k;
        cout<<i<<"e prédécésseur : ";
        cin>>k;
        while (k<=0 || k>n+1)
        {
            printf("Ce nombre doit être compris entre 1 et %d. Retaper : ", n+1);
            cin>>k;
        }
        mat[i][k] = 1;
        mat[0][1]++;
    }
    int ns;
    cout<<"Quel est le nombre de nombre de successeurs du nouveau sommet n "<<n+1<<" : ";
    cin>>ns;
    while (ns<0)
    {
        cout<<"Les nombres négatifs ne sont pas autorisés. Retaper : "<<n+1;
        cin>>ns;
    }
    for (int i = 1; i <= ns ; ++i) {
        int k;
        cout<<i<<"e successeur : ";
        cin>>k;
        while (k<=0 || k>n+1)
        {
            printf("Ce nombre doit être compris entre 1 et %d. Retaper : ", n+1);
            cin>>k;
        }
        mat[i][k] = 1;
        mat[0][1]++;
    }
    if(ns == 0 && np == 0)
        cout<<"Ce nouveau sommet ne peut être ajouté car il n'a aucun lien avec le graphe précédent."<<endl;
    else
    {
        for (int i = 0; i <= n ; ++i)
            delete[] d_matrice_d_adjascence[i];
        d_matrice_d_adjascence = new int*[n+2];
        for (int i = 0; i <= n+1 ; ++i) {
            d_matrice_d_adjascence[i] = mat[i];
        }
        matriceToFsAps();
        matriceToAretes();
    }
    for (int i = 0; i <= n+1 ; ++i)
        delete[] mat[i];
}
void Graphe::menu_console()
{
    saisir_graphe();
}
void Graphe::menu_graphique()
{

}
void Graphe::saisir_graphe()
{
    int choix;
    cout<<"Comment souhaitez-vous saisir votre graphe? "<<endl;
    cout<<"1 - Sous forme de matrice d'adjascence : taper 1"<<endl;
    cout<<"2 - Sous forme de FS : taper 2"<<endl;
    cout<<"3 - Sous forme de tableau d'arcs ou d'arêtes : taper 3"<<endl;
    cin>>choix;
    while(choix < 1 || choix > 3)
    {
        cout<<"Faites votre choix entre 1, 2 ou 3 svp merci : ";
        cin>>choix;
    }
    switch (choix) {
        case 1: saisir_matrice(); break;
        case 2: saisir_fs_aps();break;
        case 3: saisir_aretes();break;
        default: exit(0);
    }
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
    cout << "Saisie d'un graphe par sa matrice d'adjascence " << endl << endl;
    int n, m = 0;
    printf("Donner le nombre de sommets du graphe : ");
    std::cin>>n;
    while (n<=0)
    {
        printf("Le nombre de sommets minimum pour former un graphe doit être supérieur ou égal à 2, retaper : ");
        cin>>n;
    }
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
        while (ns<0)
        {
            printf("Le nombre de successeurs d'un sommet est au minimum 0 : ");
            cin>>ns;
        }
        for (int j = 1; j <= ns; j++)
        {
            int k;
            std::cout<<j<<"e successeur : ";
            std::cin>>k;
            while (k<=0 || k>n)
            {
                printf("Le numéro du successeur doit être compris entre 1 et %d, retaper : ", n);
                cin>>k;
            }
            d_matrice_d_adjascence[i][k] = 1;
            m++;
        }
    }
    d_matrice_d_adjascence[0][1] = m;
    matriceToFsAps();
    matriceToAretes();
}
void Graphe::saisir_fs_aps()
{
    cout << "Saisie d'un graphe par FS " << endl << endl;
    int n, m;
    printf("Donner le nombre de sommets du graphe : ");
    std::cin>>n;
    while (n<=0)
    {
        printf("Le nombre de sommets minimum pour former un graphe doit être supérieur ou égal à 2, retaper : ");
        cin>>n;
    }
    printf("Donner le nombre d'arêtes ou d'arcs du graphe : ");
    std::cin>>m;
    while (m<=0)
    {
        printf("Le nombre d'arêtes ou d'arcs doit etre positif ou nul, retaper : ");
        cin>>m;
    }
    d_fs = new int[n+m+1];
    d_fs[0] = n+m;
    d_aps = new int[n+1];
    d_aps[0] = n;
    d_aps[1] = 1;
    int i = 1;
    int iAps = 1;
    while(i <= n+m)
    {
        int ns;
        printf("Donner le nombre de successeurs du sommet %d : ", iAps);
        std::cin>>ns;
        while (ns<0)
        {
            printf("Le nombre de successeurs d'un sommet est au minimum 0 : ");
            cin>>ns;
        }
        for (int j = 1; j <= ns; j++)
        {
            int k;
            std::cout<<j<<"e successeur : ";
            std::cin>>k;
            while (k<=0 || k>n)
            {
                printf("Le numéro du successeur doit être compris entre 1 et %d, retaper : ", n);
                cin>>k;
            }
            d_fs[i] = k;
            i++;
        }
        d_fs[i] = 0;
        i++;
        d_aps[++iAps] = i;
    }
    fsApsToMatrice();
    matriceToAretes();
}

void Graphe::saisir_aretes()
{
    int s, t, n, m;
    cout << "Saisie d'un graphe arête/arc par arête/arc " << endl << endl;
    cout << "Donnez le nombre de sommets : ";
    cin >> n;
    d_nb_sommet = n;
    while(n < 2){
        printf("Le nombre de sommets minimum pour former un graphe doit être supérieur ou égal à 2, retaper : ");
        cin>>n;
    }
    d_matrice_d_adjascence = new int*[n+1];
    for (int i = 1; i <= n ; ++i) {
        d_matrice_d_adjascence[i] = new int[n+1];
    }
    d_matrice_d_adjascence[0] = new int[2];
    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= n ; ++j)
            d_matrice_d_adjascence[i][j] = 0;
    }
    d_matrice_d_adjascence[0][0] = n;
    cout << "Donnez le nombre d'aretes : ";
    cin >> m;
    while (m <= 0 ){
        printf("Le nombre d'arêtes ou d'arcs doit etre positif ou nul, retaper : ");
        cin>>m;
    }
    d_matrice_d_adjascence[0][1] = m;
    d_nb_aretes = m;
    aretes = new Arete[m];

    cout << "Saisissez les " << m << " arêtes" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << "arête n " << i + 1 << " :" << endl;
        cout << "extrémité 1 (entre 1 et " << n << " ) : ";
        cin >> s;
        while ((s < 1) && (s > n))
        {
            cout << "Le numéro doit être compris entre 1 et : "<<n<<", retaper :";
            cin >> s;
        }
        aretes[i].modifier_sommet_depart(s);
        cout << "extrémité 2 (entre 1 et " << n << " ) : ";
        cin >> t;
        while ((t < 1) && (t > n))
        {
            cout << "Le numéro doit être compris entre 1 et : "<<n<<", retaper :";
            cin >> t;
        }
        aretes[i].modifier_sommet_arrive(t);
        d_matrice_d_adjascence[s][t] = 1;
        /*
        cout << "Poids de l'arete : ";
        cin >> p;
        aretes[i].setPoids(p);*/
    }
    matriceToFsAps();
    afficheMatrice();
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
/*
int* Graphe::rang(int *&pileDesEntrets,int *&pileDesElement)
{

}
int* Graphe::rang()const
{

}*/
void Graphe::empiler(int x, int*&pilch) {
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

void Graphe::matriceToAretes()
{
    int m = d_matrice_d_adjascence[0][1], n = d_matrice_d_adjascence[0][0];
    aretes = new Arete[m];
    int k = 0;
    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= n ; ++j) {
            if(d_matrice_d_adjascence[i][j] == 1)
            {
                aretes[k] = {i, j};
                k++;
            }
        }
    }
}
void Graphe::aretesToMatrice()
{
    d_matrice_d_adjascence = new int*[d_nb_sommet+1];
    d_matrice_d_adjascence[0] = new int[2];
    d_matrice_d_adjascence[0][0] = d_nb_sommet;
    d_matrice_d_adjascence[0][1] = 0;
    for (int i = 1; i <= d_nb_sommet ; ++i) {
        d_matrice_d_adjascence[i] = new int[d_nb_sommet+1];
    }
    for (int i = 1; i <= d_nb_sommet ; ++i) {
        for (int j = 1; j <= d_nb_sommet ; ++j) {
            d_matrice_d_adjascence[i][j] = 0;
        }
    }
    for (int i = 0; i < d_nb_aretes ; ++i) {
        d_matrice_d_adjascence[aretes[i].sommet_depart()][aretes[i].sommet_Arrive()] = 1;
        d_matrice_d_adjascence[0][1]++;
    }
}

void Graphe::trier()
{
    int p;
    int m = d_matrice_d_adjascence[0][1];
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if ((aretes[j].poids() < aretes[i].poids()) || (aretes[j].poids() == aretes[i].poids() && aretes[j].sommet_depart() < aretes[i].sommet_Arrive()) ||
                (aretes[j].poids() == aretes[i].poids() && aretes[j].sommet_depart() < aretes[i].sommet_Arrive())) {
                p = aretes[j].poids();
                aretes[j].setPoids(aretes[i].poids());
                aretes[i].setPoids(p);
            }
        }
    }
}

void Graphe::fs_aps_2_fp_app(int *&fp, int *&app)
{
    int n = d_aps[0], m = d_fs[0];
    fp = new int [m+1];
    app = new int[n+1];
    demi_degre_int();
    app[0] = n;
    app[1] = 1;
    for (int i = 2; i <= n; ++i)
        app[i] = app[i-1] + ddi[i-1] + 1;
    int i = 1;
    for (int j = 1; j < m; ++j)
    {
        if(d_fs[j] != 0)
        {
            fp[app[d_fs[j]]] = i;
            app[d_fs[j]]++;
        }
        else
            i++;
    }
    for (int j = 1; j <= n; ++j)
        fp[app[j]] = 0;
    for (int j = m; j >= 1; --j)
        app[j] = app[j-1] + 1;
    app[1] = 1;
}

int Graphe::depiler(int *&pile) const {
    int x = pile[0];
    pile[0] = pile[x];
    return x;
}


void Graphe::creerUnFichierMatrice() {

}


