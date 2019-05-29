#include "funcoesauxiliares.h"

int eValido(int vertice, grafo *g, int c){
    for(int i = 0; i < g->nVertices; i++)
        if(g->mArestas[vertice][i] == 1 && c == g->cores[i])
            return 0;
    return 1;
}
 
int coloracaoFb(grafo *g, int vertice){
    /*
        Semelhante à coloração sequencial, porem usa recursividade
    */


    if(vertice == g->nVertices)
        return 1;
 
    for(int i = 1; i <= g->nVertices; i++){
        if(eValido(vertice, g, i)){
           g->cores[vertice] = i;
           if(coloracaoFb(g, vertice+1) == 1)
             return 1;
          g->cores[vertice] = 0;
        }
    }
    return 0;
}

void zera_cores(grafo *g){
    for(int i = 0; i < g->nVertices; i++)
        g->cores[i] = 0;
}

void preenche_matriz(grafo *g){
    for(int i = 0; i < g->nVertices; i++){
        for(int j = i; j < g->nVertices; j++){
            g->mArestas[i][j] = rand()%2;
            g->mArestas[j][i] = g->mArestas[i][j];
            if(i == j){
                g->mArestas[j][i] = 0;
            }
        }
    }
}

void print_matriz(grafo *g){
    //IMPRIME MATRIZ
    printf("\t");
    for(int i = 0; i < g->nVertices; i++)
        printf("|%i", i);
    printf("|\n\n");    

    for(int i = 0; i < g->nVertices; i++){
        printf("|%i|\t", i);
        for(int j = 0; j < g->nVertices+2; j++){
            if(g->mArestas[i][j] == 0)
                printf("|*");
            else
                printf("|%i",g->mArestas[i][j]);
        }
        printf("|\n");
    }
}

int maiorGrau(grafo *g){

    int vetor, maxGrau = -1;

    for(int i = 0; i < g->nVertices; i++)
        if((g->mArestas[i][g->nVertices] > maxGrau) && (g->cores[i] == 0)){
            vetor = i;
            maxGrau = g->mArestas[i][g->nVertices];
        }
    
    return vetor;
}

int menorCor(grafo *g, int vertice){
    int min = 1;

    for(int i = 0; i < g->nVertices; i++){
        if(g->mArestas[vertice][i] == 1 && g->cores[i] == min){
            min++;
            i = -1;
        }

    }

    return min;
}

void aumentaSat(grafo *g, int vertice){

    for(int j = 0; j < g->nVertices; j++){
        if(g->mArestas[vertice][j] == 1 && g->cores[j] == 0){
            g->mArestas[j][g->nVertices+1]++;
        }
    }
}

void grauGrafo(grafo *g){

    for(int i = 0; i < g->nVertices; i++){
        for(int j = 0; j < g->nVertices; j++){
            if(g->mArestas[i][j] == 1)
                g->mArestas[i][g->nVertices]++;
        }
    }
}

void satGrafo(grafo *g){

    for(int i = 0; i < g->nVertices; i++){
        for(int j = 0; j < g->nVertices; j++){
            if(g->mArestas[i][j] == 1)
                g->mArestas[i][g->nVertices+1]++;
        }
    }
}