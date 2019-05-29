#include "grafo.h"

int coloracao1(grafo *g){
    /*
        método de coloração por recursividade
    */
    int max = -1;
    
    zera_cores(g);
    coloracaoFb(g, 0);
    
    //verifica qual a "maior" cor no vetor de cores e a retorna
    for(int i = 0; i < g->nVertices; i++){
        if(max < g->cores[i])
            max = g->cores[i];
    }
    return max;
}

int coloracao2(grafo *g){
    /*
        Coloração através da heurística DSatur
        prioriza os vértices com maior grau de saturação, considerados os mais difíceis
        de serem coloridos no final 
    */

    // LIMPEZA DAS CORES
    zera_cores(g);
    
    grauGrafo(g);
    satGrafo(g);

    int qtdCores = -1, vertice, vColoridos = 0;

    while(vColoridos != g->nVertices){
        //procura pelo vertice de maior grau ainda não colorido
        vertice = maiorGrau(g);
        if(g->cores[vertice] == 0){
            //procura pela menor cor disponível através dos vizinhos
            int cor = menorCor(g, vertice);
            //colore com o menor valor
            g->cores[vertice] = cor;
            vColoridos++;
            //aumenta grau de saturação dos vizinhos
            aumentaSat(g, vertice);
        }
    }

    //atualiza o grau final
    for(int i = 0; i < g->nVertices; i++)
        if(qtdCores < g->cores[i])
            qtdCores = g->cores[i];
    
    return qtdCores;
}

int coloracao3(grafo *g){
    /*
        coloração sequencial. Testa, vértice por vértice, se daterminada
        cor é permitida.
        Inicialmente todas começam com a cor 1
    */
    zera_cores(g);

    int min = 0, cor = 1;
    for(int i = 0; i < g->nVertices; i++){
        for(int j = 0; j < g->nVertices; j++){
            g->cores[i] = cor;
            if(g->mArestas[i][j] == 1){
                if(g->cores[j] == g->cores[i]){
                    cor++;
                    g->cores[i] = cor;
                    if(cor > min)
                        min = cor;
                }
            }
        }
        cor = 1;
    }

    return min;
}