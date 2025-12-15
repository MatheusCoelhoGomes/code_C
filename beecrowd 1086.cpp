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

int main()
{
    int m,n;
    scanf("%d %d",&m,&n);

    while(m + n != 0){
        int l_menor,l_maior;

        if(m > n){
            l_maior = m * 100;
            l_menor = n * 100;
        }
        else{
            l_maior = n * 100;
            l_menor = m * 100;
        }

        int l,k;
        scanf("%d",&l);
        scanf("%d",&k);
        int tabua[k];

        for(int i = 0; i < k; i++){
            int a;
            scanf("%d",&a);
            tabua[i] = a * 100;
        }

        quick(tabua, 0,k - 1);
        
        int i = 0;
        int j = k - 1;
        int contagem = 0;
        int contagem2 = 0;
        int lado = 0;
        int lado2 = 0;

        if(l_menor % l == 0){
            while(i <= j){
                if(tabua[j] == l_maior){
                    contagem++;
                    lado++;
                    j--;
                }
                else if(tabua[j] > l_maior){
                    j--;
                }
                else if( i != j && tabua[i] + tabua[j] == l_maior){
                    i++;
                    j--;
                    contagem = contagem + 2;
                    lado++;
                }
                else if(i != j && tabua[i] + tabua[j] > l_maior){
                    j--;
                }
                else if(i != j && tabua[i] + tabua[j] < l_maior){
                    i++;
                }
                else {
                    j--;
                }
                if(lado == l_menor/l){
                    break;
                }
            }
        }
        i = 0;
        j = k - 1;
        if(l_maior % l == 0){
            while(i <= j){
                if(tabua[j] == l_menor){
                    contagem2++;
                    lado2++;
                    j--;
                }
                else if(tabua[j] > l_menor){
                    j--;
                }
                else if( i != j && tabua[i] + tabua[j] == l_menor){
                    i++;
                    j--;
                    contagem2 = contagem2 + 2;
                    lado2++;
                }
                else if(i != j &&  tabua[i] + tabua[j] > l_menor){
                    j--;
                }
                else if( i != j && tabua[i] + tabua[j] < l_menor){
                    i++;
                }
                else{
                    j--;
                }
                if(lado2 == l_maior/l){
                    break;
                }
            }
        }
        if(lado != l_menor/l && lado2 != l_maior/l){
            printf("impossivel\n");
        }
        if(lado == l_menor/l && lado2 == l_maior/l){
            if(contagem > contagem2){
                printf("%d\n",contagem2);
            }
            else{
                printf("%d\n",contagem);
            }
        }
        if(lado == l_menor/l && lado2 != l_maior/l){
            printf("%d\n",contagem);
        }
        if(lado != l_menor/l && lado2 == l_maior/l){
            printf("%d\n",contagem2);
        }
        scanf("%d %d",&m,&n);
    }
}