#include <stdio.h>
#include <stdlib.h>

/*Na função merge, ocorre a junção dos vetores unitarios que sao fabricados no merge sort, ai ele coloca cada vetor
 em vetores temporarios para o valor nao se perder e faz o vetor certinho riginal, o v */

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

/*Aqui vai ficar assim: vai chamar primeiro o vetor grandao, que no meu caso o meio é o indice 9, e depois
faz a recursiva com o meio (9) no lugar do fim, ai vai fazedno isso ate ter um vetor unitario, depois volta
e nessa volta os vetores vao sendo gerados e tambem vai fazendo o merge, depois vai fazendo a mesma coisa na
direita, e por fim, o merge juntando todo mundo e assim sai do if e acaba a funcao*/

void mergeSort(int v[], int inicio, int fim){
    int meio = inicio + (fim-inicio)/2;

    if(inicio < fim){
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

void imprimir(int *v, int tam){
    for(int i = 0; i < tam; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){
    int vetor[]={72, 5, 18, 91, 33, 47, 2, 86, 14, 59, 23, 100, 8, 41, 67, 3, 29, 55, 11, 94};

    mergeSort(vetor, 0, 20);
    imprimir(vetor, 20);
    
    return 0;
}