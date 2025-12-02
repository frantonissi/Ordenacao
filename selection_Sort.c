#include <stdio.h>
#include <stdlib.h>



void selection_Sort(int v[], int n){

    int i, j, minIndex;

    for ( i = 0; i < n - 1; i++){
        int minIndex = i;
     for ( j = i + 1; j < n; j++){
        if (v[minIndex] > v[j]){
            minIndex = j;
        }
    }

    if(minIndex != i){
        int temp = v[i];
        v[i] = v[minIndex];
        v[minIndex] = temp;
    }

}


}



int main(){


     int n, i;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int v[n]; // vetor com n posições (VLA, o compilador precisa aceitar C99+)

    printf("Digite os %d elementos do vetor:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    selection_Sort(v, n);

    printf("Vetor ordenado:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;

    return 0;
}