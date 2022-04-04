#include <iostream>
#include "Graphe.h"
#include "Graphe_oriente.h"
#include "Graphe_oriente_value.h"
#include "Graphe_non_oriente.h"
#include "Graphe_non_oriente_value.h"
#include <iomanip>
int menu()
{
    int choix;
    {
        cout << "Sur quel type de graphe souhaitez-vous exécuter vos algorithmes? " << endl;
        cout << "1 - Orienté non valué : taper 1" << endl;
        cout << "2 - Orienté valué : taper 2" << endl;
        cout << "3 - Non orienté non valué : taper 3" << endl;
        cout << "4 - Non orienté valué : taper 4" << endl;
        cout << "5 - Pour quitter : taper 5" << endl;
        cin >> choix;
    }
    while(choix < 1 || choix > 5);
    return choix;
}
void run()
{
    int choix = menu();
    while (choix != 5)
    {
        auto graphe = new Graphe();
        if(choix == 1)
        {
            auto graphe_oriente = new Graphe_oriente(graphe);
            graphe_oriente->run();
            delete graphe_oriente;
        }
        else if(choix == 2)
        {
            auto graphe_oriente = new Graphe_oriente(graphe);
            auto graphe_oriente_value = new Graphe_oriente_value(graphe_oriente);
            graphe_oriente_value->run();
            delete graphe_oriente_value;
            delete graphe_oriente;
        }
        else if(choix == 3)
        {
            auto graphe_non_oriente = new Graphe_non_oriente(graphe);
            graphe_non_oriente->run();
            delete graphe_non_oriente;
        }
        else if(choix == 4)
        {
            auto graphe_non_oriente = new Graphe_non_oriente(graphe);
            auto graphe_non_oriente_value = new Graphe_non_oriente_value(graphe_non_oriente);
            graphe_non_oriente_value->run();
            delete graphe_non_oriente_value;
            delete graphe_non_oriente;
        }
        delete graphe;
        choix = menu();
    }
}
int main() {
    run();
}
