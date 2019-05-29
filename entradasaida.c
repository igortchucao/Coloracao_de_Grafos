#include "entradasaida.h"

int insereAresta(grafo *graph, int v1, int v2){
    // Verificando validade do grafo e dos vértices
    if(graph == NULL) return 0;
    if(v1 < 0 || v1 >= graph->nVertices) return 0;
    if(v2 < 0 || v2 >= graph->nVertices) return 0;

    graph->mArestas[v1][v2] = 1;
    graph->mArestas[v2][v1] = 1;
    
    return 1;
}

grafo *dadosParaGrafo(char *argv){
    FILE *arq;
    grafo *g;
    int v1, v2, nr;
    
    if((arq = fopen(argv, "r"))){
        fscanf(arq, "%d", &nr);
        g = criagrafo(nr);
        while(!feof(arq)){
            fscanf(arq, "%d %d", &v1, &v2);
            insereAresta(g, v1-1, v2-1);
        }
    }else
        printf("Arquivo nao encontrado\n");

    return g;
}

// DES/ALOCAÇÃO DE MEMÓRIA
grafo *criagrafo(int vertices){
    grafo *g;

    if((g = (grafo*)malloc(sizeof(grafo)))){

        g->nVertices = vertices;
        g->mArestas = (int**)malloc(vertices*sizeof(int*));
        g->cores = (int*)malloc(vertices*sizeof(int));
        for (int i = 0; i < vertices; i++){
            g->mArestas[i] = (int*)malloc((vertices+2)*sizeof(int));
        }

        for (int i = 0; i < vertices; i++){
            for (int j = 0; j < vertices+2; j++)
                g->mArestas[i][j] = 0;
            g->cores[i] = 0;
        }

    }
    return g;
}

void liberagrafo(grafo *g){
    for (int i = 0; i < g->nVertices; i++){
        free(g->mArestas[i]);
    }
    free(g->mArestas);
    free(g->cores);
    free(g);
}