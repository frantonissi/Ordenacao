#include <stdio.h>
#include <stdlib.h>

void merge(int v[], int inicio, int meio, int fim){
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int *esquerda = malloc(n1*sizeof(int));
    int *direita = malloc(n2* sizeof(int));

    for(int i = 0; i < n1; i++){
        esquerda[i] = v[inicio + i];
    }
    for(int j = 0; j < n2; j++){
        direita[j] = v[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = inicio;

    while(i < n1 && j < n2){
        if(esquerda[i] < direita[j]){
            v[k++] = esquerda[i++];
        }else{
            v[k++] = direita[j++];
        }
    }

    while (i < n1){
        v[k++] = esquerda[i++];
    }

    while (j < n2){
        v[k++] = direita[j++];
    }
    
  
}

void mergeSort(int v[], int inicio, int fim){
    int meio = inicio + (fim-inicio)/2;

    if(inicio < fim){
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

void imprimir(int *v, int tam){
    for(int i = 0; i <= tam; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){
    int vetor[]={72, 5, 18, 91, 33, 47, 2, 86, 14, 59, 23, 100, 8, 41, 67, 3, 29, 55, 11, 94};

    mergeSort(vetor, 0, 19);
    imprimir(vetor, 19);
    
    return 0;
}