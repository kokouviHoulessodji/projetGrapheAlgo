#include <iostream>
#include "Graphe.h"
#include "Graphe_oriente.h"
#include "Graphe_oriente_value.h"
int main() {
    Graphe graphe{};
    Graphe_oriente graphe_oriente{graphe};
    auto grapheorientevalue = new Graphe_oriente_value(graphe_oriente);
    //graphe_oriente->afficheMatrice();
    //graphe_oriente->afficheFsAps();
    int** dist, **pred;
    grapheorientevalue->Dijkstra(dist, pred);

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
}
