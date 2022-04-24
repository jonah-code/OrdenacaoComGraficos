/*
 *  ordenacao.cpp
 *
 *
 *  Created by Luiz Affonso Guedes on 06/03/17.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

// UFRN-CT-DCA
// Programa: programa para ordenação de um vetor

// Manipulação de tempo em c,c++
// Programa: programa que usa manipuladores de tempo para
// medir o desempenho de algoritmos de ordenação


#include <cstdlib>   //qsort
#include  <time.h>   // clock(),time()
#include <stdio.h>   // printf()
#include <stdlib.h>  // exit()
#include<iostream>
#include <time.h>
using namespace std;


//Vetores usados pelos métodos de ordenação
int *vetorQuickSort;
int *vetorBubbleSort;
int tamanho;

//Função usada pelo qsort para comparar dois numeros
int compare_ints( const void* a, const void* b ) {
	int* arg1 = (int*) a;
	int* arg2 = (int*) b;
	if( *arg1 < *arg2 ) return -1;
	else if( *arg1 == *arg2 ) return 0;
	else return 1;
}

//Algoritmos de ordenação bubble sort
void bubbleSort(int *vetor, int tamanho) {
	int aux;
	for (int i = 0; i < tamanho-1; i++) {
		for (int j = 0; j < tamanho-1; j++) {
			if (vetor[j] > vetor[j+1]) {
				aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
			}

		}
	}
	//for (int i= 0; i<tamanho;i++){
      //  cout<<vetor[i]<<" ";
	//}
}






//Observe que os números são gerados aleatoriamente baseados
//em uma semente. Se for passado a mesma semente, os
//números aleatórios serão os mesmos
void criarVetor(int tamanhoVetor, int semente){
	srand (semente);
	vetorQuickSort = new int[tamanhoVetor];
	vetorBubbleSort = new int[tamanhoVetor];
	for (int i=0;i<tamanhoVetor;i++){
		vetorQuickSort[i] =  rand()%100000;
        vetorBubbleSort[i] = vetorQuickSort[i]; // utilizar os mesmos valores
		//vetorBubbleSort[i] = rand()%100000;
	}
}



int main ()
{

    clock_t t,t1;

    FILE *file, *file2;
    file = fopen("C:\\Users\\jonas\\Desktop\\Tempo.txt","w");
    file2 = fopen("C:\\Users\\jonas\\Desktop\\Tamanho.txt","w");

    for (int i=1000;i<=20000;i+=100){


	//Tamanho do vetor
	//Criar vetor com elementos aleatorios[0,100000]
	criarVetor(i,23);
	//Ordenar utilizando quickSort

	t = clock();
	//bubbleSort(vetorBubbleSort,i);
	qsort (vetorQuickSort, i, sizeof(int), compare_ints);
	t = clock() - t;
	double tempo = ((double)t)/((CLOCKS_PER_SEC/1000))/1000;
	printf("Tamanho: %d ", i);
    fprintf(file2,"%d ",i);
	printf("Tempo de execucao: %lf segundos", tempo); //conversão para double
    fprintf(file,"%lf ",tempo);
    printf("\n");

   /* t1 = clock();

    t1 = clock() - t;

    printf("Tempo de execucao: %lf", ((double)t1)/((CLOCKS_PER_SEC/1000))); //conversão para double*/

    }
    fclose(file);
    fclose(file2);




	//Ordenar utilizando bubleSort
	//for (int i=0; i<n; i+=20){
         //armazena tempo
      //
//; //tempo final - tempo inicial
      //  vetor[i]=t;
	//}


    /*for (int i=0;i<n;i++){
        cout<<vetor[i]<<" ";
	}*/

    printf("terminou");
	exit(0);
}


