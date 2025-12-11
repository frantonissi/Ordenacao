#include <stdio.h>

// Função auxiliar apenas para trocar dois valores de lugar
void troca(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// O "Operário": Organiza o vetor em torno do pivô
int particiona(int v[], int inicio, int fim) {
    int pivo = v[fim]; // Escolhe o último como pivô
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (v[j] <= pivo) {
            i++;
            troca(v, i, j);
        }
    }
    // Coloca o pivô na posição final correta
    troca(v, i + 1, fim);
    
    // Retorna ONDE o pivô parou (esse índice não muda mais!)
    return i + 1;
}

// O "Gerente": A função que você pediu
void quickSort(int v[], int inicio, int fim) {
    // 1. Base da Recursão: Se o vetor tem tamanho 0 ou 1, para.
    if (inicio < fim) {
        
        // 2. Chama o operário para organizar e descobrir onde está o muro (pivô)
        int pivo_indice = particiona(v, inicio, fim);

        // 3. Recursão para a Esquerda
        // Atenção: Vai do inicio até "pivo_indice - 1"
        // O pivô em si fica de fora, pois já está ordenado!
        quickSort(v, inicio, pivo_indice - 1);

        // 4. Recursão para a Direita
        // Atenção: Começa em "pivo_indice + 1" até o fim
        quickSort(v, pivo_indice + 1, fim);
    }
}

// Um main simples para testar
int main() {
    int v[] = {10, 7, 8, 9, 1, 5};
    int n = 6; // tamanho do vetor

    // Chamada inicial: do índice 0 até o último índice (n-1)
    quickSort(v, 0, n - 1);

    printf("Vetor ordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    return 0;
}