#include <stdio.h>
#include <stdlib.h>

// CountingSort - Ordenação por Contagem - Matheus Martins Batista - Universidade Federal de Itajuba - 2021

//Necessario escontrar maior elemento para alocar o vetor auxiliar de contagem
int findMax (int *arr, int tam) {
	int max, i;

	max = arr[0];

	for (i = 1; i < tam; i++) 
		if (arr[i] > max)
	    	max = arr[i];

	return max;
}

// Ordenas os valores presentes em A e armazena em B
void countingSort(int *arrA, int *arrB, int tam){
	int i;
    //Vetor de contagem tera a frequencia que um numero aparece no vetor
    //deve-se setar 0 para todos os elementos ou usar calloc
    int max = findMax(arrA, tam);
    int* count = calloc(max + 1, sizeof(int)); 

    // Frequencia que determinado valor aparece no vetor
    for (i = 0; i < tam; i++)
    	count[arrA[i]]++;

    // Acumulativo da frequencia dos valores menores que um elemento i do vetor original (A)
    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Percorrer o vetor original com início no ultimo elemento, subtituindo os indices nos elementos do vetor count e decrescendo a cada atribuição
    for (i = tam - 1; i >= 0; i--){
        arrB[count[arrA[i]] - 1] = arrA[i];
        count[arrA[i]]--;
    }
}



int main(){
    
    int *arrA, *arrB;
    int tam = 10;
    arrA = malloc(tam * sizeof(int));
    arrB = calloc(tam, sizeof(int));

    // Popular vetor A
    srand(48+tam); 
    for(int j = 0; j < tam; j++) arrA[j] = rand()%100;

    countingSort(arrA, arrB, tam);

    printf("Vetor ordenado: ");
    for (int i = 0; i < tam; i++)
        printf("%d ", arrB[i]);

    return 0;
}