#ifndef FUNCOESAUXILIARES_H_
#define FUNCOESAUXILIARES_H_
#include "grafo.h"

int eValido(int vertice, grafo *g, int c);

int coloracaoFb(grafo *g, int vertice);

void zera_cores(grafo *g);

void preenche_matriz(grafo *g);

void print_matriz(grafo *g);

int maiorGrau(grafo *g);

int menorCor(grafo *g, int vertice);

void aumentaSat(grafo *g, int vertice);

void grauGrafo(grafo *g);

void satGrafo(grafo *g);

#endif
