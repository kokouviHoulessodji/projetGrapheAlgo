//
// Created by Houlessodji Kokouvi on 11/03/2022.
//

#ifndef PROJETGRAPHEALGO_GRAPHE_H
#define PROJETGRAPHEALGO_GRAPHE_H
#include <vector>
#include<iostream>
#include <fstream>
#include <ostream>
#include "Arete.h"
using namespace std;

class Graphe {
protected:
    int **d_matrice_d_adjascence;
    int *d_fs,*d_aps, *ddi, *dde;
    Arete *aretes;
    int d_nb_sommet;
    int d_nb_aretes;
    void empiler(int x, int*&pilch);//TESTED
    int depiler(int *&pile) const;//TESTED
    void trier();//TESTED
public:
    Graphe();
    virtual ~Graphe();

    void ajoutSommet();
    void menu_console();
    void menu_graphique();
    void matriceFromFichier(const string &NomFichier);
    void fsApsFromFichier(const string &NomFichier);
    void matriceToFsAps();//TESTED
    void fsApsToMatrice();//TESTED
    void fs_aps_2_fp_app(int *&fp, int *&app);//TESTED
    void matriceToAretes();//TESTED
    void aretesToMatrice();//TESTED
    void demi_degre_int();//TESTED
    void demi_degre_ext(); //TESTED
    int* distance(int sommet)const;//TESTED
    int** distance()const;//TESTED
    virtual void readFile(const string&fileName);

    void afficheFsAps();  //TESTED
    void afficheMatrice();   //TESTED
    int *getFs()const;      //TESTED
    int *getAps()const;     //TESTED
    int **getMatrice()const;    //TESTED

    void saisir_graphe();//TESTED
    void saisir_matrice();//TESTED
    void saisir_fs_aps();//TESTED
    void saisir_aretes();//TESTED

    int* det_rang( int *&num);
    /*
    int* rang(int *&pileDesEntrets,int *&pileDesElement);
    int* rang()const;*/

    //Les fonction pour les tests
    void afficheDDE()const;
    void afficheDDI()const;
    void afficheFpApp()const;
    void afficheMatrice(int** m)const;

private:
    void creerUnFichierMatrice();
};


#endif //PROJETGRAPHEALGO_GRAPHE_H
