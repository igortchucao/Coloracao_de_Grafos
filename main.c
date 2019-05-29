#include "grafo.h"
#include "entradasaida.h"

int main(int argc, char *argv[]){
    char *entrada = argv[1];
    clock_t ti, tf;

    //para criação do grafo através de arquivo 
    grafo *g = dadosParaGrafo(entrada);

    //para criação do grafo através de tamanho personalizado 
    // grafo *g = criagrafo(tamanho);
    // print_matriz(g);
    
    ti = clock();
    int h1 = coloracao1(g);
    tf = clock();
    float t1 = (double)(tf-ti)/(CLOCKS_PER_SEC);
    printf("coloracao1:%d tempo: %f s\n",h1, t1);

    ti = clock();
    int h2 = coloracao2(g);
    tf = clock();
    float t2 = (double)(tf-ti)/(CLOCKS_PER_SEC);
    printf("coloracao2:%d tempo: %f s\n",h2, t2);

    ti = clock();
    int h3 = coloracao3(g);
    tf = clock();
    float t3 = (double)(tf-ti)/(CLOCKS_PER_SEC);
    printf("coloracao3:%d tempo: %f s\n",h3, t3);

    // printf("coloracao2:%d tempo: %fs\ncoloracao4:%d tempo: %fs\n", h1, t1, h4, t4);
    liberagrafo(g);
    
    return argc;
}