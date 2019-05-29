#ifndef ENTRADASAIDA_H_
#define ENTRADASAIDA_H_
#include "grafo.h"

int insereAresta(grafo *graph, int v1, int v2);

grafo *dadosParaGrafo(char *argv);

grafo *criagrafo(int vertices);

void liberagrafo(grafo *g);

#endif
