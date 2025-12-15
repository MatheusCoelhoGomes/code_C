#include <stdio.h>


void troca(int array[], int i, int j){
    int c = array[i];
    array[i] = array[j];
    array[j] = c;
}

int ordenar_pivo(int array[], int inicio, int fim){
    int j = inicio;
    for(int i = inicio; i < fim; i++){
        if(array[i] <= array[fim]){
            troca(array,j,i);
            j++;
        }
    }
    troca(array, j, fim);
    return j;
}

void quick(int array[], int inicio, int fim){
    if(inicio > fim){
        return;
    }

    int pivo = ordenar_pivo(array,inicio,fim);

    quick(array, inicio, pivo - 1);
    quick(array, pivo + 1, fim);
    
    
}

int main(){
    int array[5];

    for(int i = 0; i < 5; i++){
        scanf("%d",&array[i]);
    }

    quick(array, 0, 4);

    for(int i = 0; i < 5; i++){
        printf("%d ",array[i]);
    }
}