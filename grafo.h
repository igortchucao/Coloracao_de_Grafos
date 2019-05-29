#ifndef GRAFO_H_
#define GRAFO_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct dado{
    int **mArestas;
    int *cores;
    int nVertices;
} grafo;

int coloracao1(grafo *g);
int coloracao2(grafo *g);
int coloracao3(grafo *g);

#endif
