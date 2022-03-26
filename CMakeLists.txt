cmake_minimum_required(VERSION 3.21)
project(projetGrapheAlgo)

set(CMAKE_CXX_STANDARD 14)

add_executable(projetGrapheAlgo main.cpp Graphe.cpp Graphe.h Sommet.cpp Sommet.h Graphe_oriente.cpp Graphe_oriente.h Graphe_non_oriente.cpp Graphe_non_oriente.h Arete.cpp Arete.h Arbre.cpp Arbre.h Graphe_oriente_value.cpp Graphe_oriente_value.h)
