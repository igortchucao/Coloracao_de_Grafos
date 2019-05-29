all: main
main: main.o grafo.o entradasaida.o funcoesauxiliares.o
		gcc -o main main.o grafo.o entradasaida.o funcoesauxiliares.o

grafo.o: grafo.c grafo.h
		gcc -c grafo.c -W -Wall -pedantic

entradasaida.o: entradasaida.c entradasaida.h grafo.h funcoesauxiliares.h
		gcc -c entradasaida.c -W -Wall -pedantic

funcoesauxiliares.o: funcoesauxiliares.c funcoesauxiliares.h grafo.h entradasaida.h
		gcc -c funcoesauxiliares.c -W -Wall -pedantic

main.o: main.c grafo.h entradasaida.h funcoesauxiliares.h
		gcc -c main.c -W -Wall -pedantic

clean:
		rm -rf *.o
mrproper:
		rm -rf main
