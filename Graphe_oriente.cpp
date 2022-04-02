#include "Graphe_oriente.h"
#include <vector>

Graphe_oriente::Graphe_oriente(Graphe graphe) : Graphe{graphe}
{

}

void Graphe_oriente::empiler(int *pile, int valeur) const {
    pile[valeur] = pile[0];
    pile[0] = valeur;

}

int Graphe_oriente::depiler(int *pile) const {
    int x = pile[0];
    pile[0] = pile[x];
    return x;
}

Graphe_oriente Graphe_oriente::calculerGrapheReduit(int *prem, int *pilch, int *cfc, int *fs, int *aps, int *&fsr, int *&apsr) const {
    int s, kr = 1, nbc = prem[0];
    bool *deja_mis = new bool[nbc + 1];
    fsr = new int[fs[0] + 1];
    apsr = new int[nbc + 1];
    apsr[0] = kr;
    for (int i = 1; i < nbc; i++) {
        apsr[i] = kr;
        for (int i = 1; i <= nbc; i++) {
            deja_mis[i] = false;
        }
        deja_mis[i] = true;
        s = prem[0];
        while (s != 0) {
            for (int t = aps[s]; fs[t] != 0; t++) {
                if (deja_mis[cfc[fs[t]]] == false) {
                    fs[kr] = cfc[fs[t]];
                    kr++;
                    deja_mis[cfc[fs[t]]] = true;
                }
            }
            s = pilch[s];
        }
        fsr[kr] = 0;
        kr++;
    }
    fsr[0] = kr - 1;
    delete[] deja_mis;
}

void Graphe_oriente::traverse(int s, int &p, int *&num, int *&ro, int *&pilch, int *&cfc, int *aps, int *fs, int *&tarj, bool *&entarj, int *&prem) const {
    int t;
    p++;
    num[s] = p;
    ro[s] = p; // numérote s et initialise ro[s]
    empiler(tarj, s);
    entarj[s] = true;
    for (int k = aps[s]; (t = fs[k]) != 0; k++) {
        if (num[t] == 0) // si t n'est pas encore numéroté { pred[t] = s;
            traverse(t, p, num, ro, pilch, cfc, aps, fs, tarj, entarj, prem);
        if (ro[t] < ro[s])
            ro[s] = ro[t];
        else {
            if ((num[t] < ro[s]) && entarj[t])
                ro[s] = num[t];
        }
        if (ro[s] == num[s]) {
            k++;
            int u;
            do {
                u = depiler(tarj);
                entarj[u] = false;
                empiler(pilch, u);
                cfc[u] = k;
            } while (u != s);
            prem[k] = pilch[0];
            pilch[0] = 0;
        }

    }

}

void Graphe_oriente::calculerCFC(std::vector<int> &prem, std::vector<int> &pilch, std::vector<int> &cfc) const {

}

void Graphe_oriente::graph_reduit(int *prem, int *pilch, int *cfc, int *fs, int *aps, int *&fsr, int *&apsr) {

    int s, kr = 1, nbc = prem[0];
    bool *deja_mis = new bool[nbc + 1];
    fsr = new int[fs[0] + 1];
    apsr = new int[nbc + 1];
    apsr[0] = kr;
    for (int i = 1; i < nbc; i++) {
        apsr[i] = kr;
        for (int i = 1; i <= nbc; i++) {
            deja_mis[i] = false;
        }
        deja_mis[i] = true;
        s = prem[0];
        while (s != 0) {
            for (int t = aps[s]; fs[t] != 0; t++) {
                if (deja_mis[cfc[fs[t]]] == false) {
                    fs[kr] = cfc[fs[t]];
                    kr++;
                    deja_mis[cfc[fs[t]]] = true;
                }
            }
            s = pilch[s];
        }
        fsr[kr] = 0;
        kr++;
    }
    fsr[0] = kr - 1;
    delete[] deja_mis;
}

void Graphe_oriente::base_Greduit(int *apsr, int *fsr, int *&br) {

    int nr = apsr[0];
    br = new int[nr + 1];
    int *ddir = new int[nr + 1];
    for (int i = 0; i <= nr; i++)
        ddir[i] = 0;
    for (int kr = 1; kr <= fsr[kr]; kr++)
        ddir[fsr[kr]]++;
    int nb = 0;
    for (int c = 1; c <= nr; c++)
        if (ddir[c] == 0) br[++nb] = c;
    br[0] = nb;
}

void Graphe_oriente::afficher(int *base, int nb)
{
    for (int i = 0; i < nb; i++)
        std::cout << base[i] << " ";
}
void Graphe_oriente::edition_bases(int *prem, int *pilch, int *br) {

    int nb = br[0]; // Nombre de CFC de l’unique base du graphe réduit
    int *Base = new int[nb + 1]; // pile qui mémorise les sommets des bases du graphe initial Base[0] = nb;
    int p = 1;
    int som = prem[br[1]]; // premier sommet de la première CFC while (p >= 1)
    {
        if ((p <= nb) && (som != 0)) {
            Base[p] = som;
            p++;
            if (p <= nb)
                som = prem[br[p]];
            else
                afficher(Base, nb + 1); // Affiche le contenu du tableau Base //sommets d’une base du graphe initial
            p--;
            som = pilch[Base[p]];
        }
    }
}

void Graphe_oriente::fortconnexe(int *aps, int *fs, int *&prem, int *&pilch, int *&cfc, int *&pred) {

    int n = aps[0];
    prem = new int[n + 1];
    pilch = new int[n + 1];
    cfc = new int[n + 1];
    pred = new int[n + 1];
    int *tarj = new int[n + 1];
    bool *entarj = new bool[n + 1];
    int *num = new int[n + 1];
    int *ro = new int[n + 1];
    int k = 0;
    for (int i = 1; i <= n; i++) {
        num[i] = 0;
        pred[i] = 0;
        ro[i] = 0;
        entarj[i] = false;
    }
    pilch[0] = 0;
    tarj[0] = 0;
    for (int s = 1; s <= aps[0]; s++)
        if (num[s] == 0)
            traverse(s, k, num, ro, pilch, cfc, aps, fs, tarj, entarj, prem);
    prem[0] = k;
    delete[] tarj;
    delete[] entarj;
    delete[] num;
    delete[] ro;
}
