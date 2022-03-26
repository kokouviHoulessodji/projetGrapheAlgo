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
    int *d_fs,*d_aps;
    static int nombre_arc();
public:
    Graphe();
    virtual ~Graphe();

    void ajoutSommet();

    void matriceFromFichier(const string &NomFichier);
    void fsApsFromFichier(const string &NomFichier);
    void matriceToFsAps();
    void fsApsToMatrice();
    int* demi_degre_int() const;
    int* demi_degre_ext() const; //TESTED
    int* getApp()const;//TESTED
    int* getFp()const;//TESTED
    int* distance(int sommet_courant)const;//TESTED
    int** distance()const;//TESTED
    virtual void readFile(const string&fileName);

    void afficheFsAps()const;  //TESTED
    void afficheTab(int*)const;
    void afficheMatrice()const;   //TESTED
    int *getFs()const;      //TESTED
    int *getAps()const;     //TESTED
    int **getMatrice()const;    //TESTED


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
