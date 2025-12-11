#include <stdlib.h>
#include <stdio.h>

void buble (int v[], int n){

    //o laço externo serve para saber se ainda tem vetor para caminhar
    for (int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){ //o -i serve para nao contar o que ja foi ordenado
            if(v[j] > v[j+1]){
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp; 
            }
        }  
    }
}

int main(){


    int v[5] = {10,9,7,1,3};

    buble(v,5);

    printf("Vetor ordenado: ");
    for(int i = 0; i < 5; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}