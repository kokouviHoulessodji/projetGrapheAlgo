//
// Created by Houlessodji Kokouvi on 11/03/2022.
//

#ifndef PROJETGRAPHEALGO_GRAPHE_H
#define PROJETGRAPHEALGO_GRAPHE_H
#include <vector>
#include<iostream>
#include <fstream>
#include <ostream>
using namespace std;

class Graphe {
protected:
    int **d_matrice_d_adjascence;
    int *d_fs,*d_aps, *ddi, *dde, **d_cout;
public:
    Graphe();
    virtual ~Graphe();

    void ajoutSommet();

    void matriceFromFichier(const string &NomFichier);
    void fsApsFromFichier(const string &NomFichier);
    void matriceToFsAps();
    void fsApsToMatrice();
    void demi_degre_int();
    void demi_degre_ext(); //TESTED
    int* getApp()const;//TESTED
    int* getFp()const;//TESTED
    int* distance(int sommet)const;//TESTED
    int** distance()const;//TESTED
    virtual void readFile(const string&fileName);

    void afficheFsAps();  //TESTED`
    void afficheMatrice();   //TESTED
    int *getFs()const;      //TESTED
    int *getAps()const;     //TESTED
    int **getMatrice()const;    //TESTED
    void empiler(int x, int*&pilch);
    int depiler(int *&pile) const;
    void saisir_matrice();


    int* det_rang( int *&num);
    int* rang(int *&pileDesEntrets,int *&pileDesElement);
    int* rang()const;

    //Les fonction pour les tests
    void afficheDDE()const;
    void afficheDDI()const;
    void afficheFpApp()const;
    void afficheMatrice(int** m)const;

private:
    void creerUnFichierMatrice()const;
};


#endif //PROJETGRAPHEALGO_GRAPHE_H
