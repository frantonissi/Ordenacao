#include <stdlib.h>
#include <stdio.h>

int particiona(int *v, int inicio, int fim){

    int pivo = (v[inicio] + v[fim] + (v[inicio]+v[fim])/2)/3;
    while(inicio < fim){
        while(inicio < fim && v[inicio] <= pivo){
            inicio++;
        }
        while(inicio < fim && v[fim] > pivo){
            fim--;
        }
        int temp = v[inicio];
         v[inicio] = v[fim];
         v[fim] = temp;
    }
    return inicio;
}

void quickSort(int *v, int inicio, int fim){
    if(inicio < fim){
        int posicao = particiona(v, inicio, fim);
        quickSort(v, inicio, posicao - 1);
        quickSort(v, posicao, fim);
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

    quickSort(vetor, 0, 19);
    imprimir(vetor, 19);
    
    return 0;
}