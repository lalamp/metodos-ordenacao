#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

int countComp[8] = {}, countMoves[8] = {};

int menu();
void setVetor(int vetor[], int n);
void getVetor(int vetor[], int n);
void insercao_direta(int vetor[], int n);
void insercao_binaria(int vetor[], int n);
void selecao(int vetor[], int n);
void bubblesort(int vetor[], int n);
void shakesort(int vetor[], int n);
void heapsort(int vetor[], int n);
void heapify(int vetor[], int L, int R);
void quicksort(int v[], int L, int R);
void mergesort(int a[], int n);
void merge(int a[], int L, int m, int R, int c[]);
void mpass(int a[], int n, int p, int c[]);

int main(){
    int n;
    cout << "\nQual o tamanho do vetor? ";
    cin >> n;

    int vetor[n+1], vetor_aux[n+1];
    setVetor(vetor, n);
    for(int i = 1; i <= n; i++){
        vetor_aux[i] = vetor[i];
    }
    cout << "\nVetor inicial: {";
    getVetor(vetor, n);
    cout << "}\n" << endl;

    int option = 0;
    do{
        option = menu();
        countComp[option] = 0;
        countMoves[option] = 0;
        switch(option){
            case 1:
                cout << "Ordenando por insercao direta..." << endl;
                insercao_direta(vetor, n);
                cout << "Numero de comparacoes = " << countComp[option] << endl;
                cout << "Numero de movimentacoes = " << countMoves[option] << endl;
                break;

            case 2:
                cout << "Ordenando por insercao binaria..." << endl;
                insercao_binaria(vetor, n);
                cout << "Numero de comparacoes = " << countComp[option] << endl;
                cout << "Numero de movimentacoes = " << countMoves[option] << endl;
                break;

            case 3:
                cout << "Ordenando por selecao..." << endl;
                selecao(vetor, n);
                cout << "Numero de comparacoes = " << countComp[option] << endl;
                cout << "Numero de movimentacoes = " << countMoves[option] << endl;
                break;

            case 4:
                cout << "Ordenando por fusao..." << endl;
                mergesort(vetor, n);
                cout << "Numero de comparacoes = " << countComp[option] << endl;
                cout << "Numero de movimentacoes = " << countMoves[option] << endl;
                break;

            case 5:
                cout << "Ordenando por bubblesort..." << endl;
                bubblesort(vetor, n);
                cout << "Numero de comparacoes = " << countComp[option] << endl;
                cout << "Numero de movimentacoes = " << countMoves[option] << endl;
                break;
            
            case 6:
                cout << "Ordenando por shakesort..." << endl;
                shakesort(vetor, n);
                cout << "Numero de comparacoes = " << countComp[option] << endl;
                cout << "Numero de movimentacoes = " << countMoves[option] << endl;
                break;
            
            case 7:
                cout << "Ordenando por heapsort..." << endl;
                heapsort(vetor, n);
                cout << "Numero de comparacoes = " << countComp[option] << endl;
                cout << "Numero de movimentacoes = " << countMoves[option] << endl;
                break;

            case 8:
                cout << "Ordenando por quicksort..." << endl;
                quicksort(vetor, 1, n);
                cout << "Numero de comparacoes = " << countComp[option] << endl;
                cout << "Numero de movimentacoes = " << countMoves[option] << endl;
                break;

            case -1:
                insercao_direta(vetor, n);
                break;

            default:
                cout << "Opcao invalida." << endl;
                break;
        }

        cout << "Vetor ordenado: {";
        getVetor(vetor, n);
        cout << "}\n" << endl;

        for(int i = 1; i <= n; i++){
            vetor[i] = vetor_aux[i];
        }

    }while(option != -1);

    return 0;
}

int menu(){
    int option;
    cout << "========METODOS DE ORDENACAO========" << endl;
    cout << "[1]Insercao direta\n[2]Insercao binaria\n[3]Selecao\n[4]Fusao\n[5]Bubblesort\n[6]Shakesort\n[7]Heapsort\n[8]Quicksort\n[-1]Sair do programa" << endl;
    cout << "\nEscolha um metodo de ordenacao: ";
    cin >> option;
    cout << "====================================" << endl;
    return option;
}

void setVetor(int vetor[], int n){
    cout << "Informe os elementos do vetor:" << endl;
    for(int i = 1; i <= n; i++){
        cout << "vetor[" << i << "] = ";
        cin >> vetor[i];
    }
}

void getVetor(int vetor[], int n){
    for(int i = 1; i <= n; i++){
        if(i == n)
            cout << vetor[i];
        else
            cout << vetor[i] << ", ";
    }
}

void insercao_direta(int vetor[], int n){ 
    int aux, j;
    for(int i = 2; i <= n; i++){
        aux = vetor[i];
        vetor[0] = aux;
        countMoves[1] += 2; //aux = vetor[i];
                            //vetor[0] = aux;
        j = i;

        countComp[1]++; //aux < vetor[j-1] -> que nao entra no looping
        while(aux < vetor[j-1]){ 
            countComp[1]++; //aux < vetor[j-1]
            vetor[j] = vetor[j-1]; 
            countMoves[1]++; //vetor[j] = vetor[j-1]
            j = j-1; 
        }
        vetor[j] = aux;
        countMoves[1]++; //vetor[j] = aux
    }
}

void insercao_binaria(int vetor[], int n){
    int aux, L, R, m;
    for(int i = 2; i <= n; i++){
        aux = vetor[i];
        countMoves[2]++; //aux = vetor[i]
        L = 1;
        R = i;
        
        while(L < R){
            m = floor((L+R)/2);
            countComp[2]++; //vetor[m] <= aux
            if(vetor[m] <= aux){
                L = m+1;
            }
            else{
                R = m;
            }
        }
        
        int j = i;
        while(j > R){
            vetor[j] = vetor[j-1];
            countMoves[2]++; //vetor[j] = vetor[j-1]
            j = j-1;
        }
        vetor[R] = aux;
        countMoves[2]++; //vetor[R] = aux
    }
}

void selecao(int vetor[], int n){
    int i_menor, aux;
    for(int i = 1; i < n; i++){
        i_menor = i;
        for(int j = i+1; j <= n; j++){ 
            countComp[3]++; //vetor[j] < vetor[i_menor]
            if(vetor[j] < vetor[i_menor]){
                i_menor = j; 
            }
        }
        aux = vetor[i];
        vetor[i] = vetor[i_menor];
        vetor[i_menor] = aux;
        countMoves[3] += 3; //aux = vetor[i];
                            //vetor[i] = vetor[i_menor];
                            //vetor[i_menor] = aux;
    }
}

void bubblesort(int vetor[], int n){
    int aux;
    for(int i = 2; i <= n; i++){
        for(int j = n; j >= i; j--){
            countComp[5]++; //vetor[j-1] > vetor[j]
            if(vetor[j-1] > vetor[j]){
                aux = vetor[j-1];
                vetor[j-1] = vetor[j];
                vetor[j] = aux;
                countMoves[5] += 3; //aux = vetor[j-1];
                                    //vetor[j-1] = vetor[j];
                                    //vetor[j] = aux;
            }
        }
    }
}

void shakesort(int vetor[], int n){
    int aux, inicio = 2, fim = n, k = n;
    do{
        for(int j = fim; j >= inicio; j--){ //subida
            countComp[6]++; //vetor[j-1] > vetor[j]
            if(vetor[j-1] > vetor[j]){
                aux = vetor[j-1];
                vetor[j-1] = vetor[j];
                vetor[j] = aux;
                k = j;
                countMoves[6] += 3; //aux = vetor[j-1];
                                    //vetor[j-1] = vetor[j];
                                    //vetor[j] = aux;
            }
        }
        inicio = k+1;
        for(int j = inicio; j <= fim; j++){ //descida
            countComp[6]++; //vetor[j-1] > vetor[j]
            if(vetor[j-1] > vetor[j]){
                aux = vetor[j-1];
                vetor[j-1] = vetor[j];
                vetor[j] = aux;
                k = j;
                countMoves[6] += 3; //aux = vetor[j-1];
                                    //vetor[j-1] = vetor[j];
                                    //vetor[j] = aux;
            }
        }
        fim = k-1;
    }while(inicio <= fim); 
}

void heapify(int vetor[], int L, int R){
    int i = L, 
    j = 2*L;
    int aux = vetor[L];
    countMoves[7]++; //aux = vetor[L]

    if(j < R){
        countComp[7]++; //vetor[j] < vetor[j+1]
    }
    if((j < R) && (vetor[j] < vetor[j+1])){
        j = j+1;
    }
   
    while((j <= R) && (aux < vetor[j])){
        countComp[7]++; //aux < vetor[j] 
        vetor[i] = vetor[j];
        countMoves[7]++; //vetor[i] = vetor[j]
        
        i = j;
        j = 2*j;
        
        if(j < R){
            countComp[7]++; ////vetor[j] < vetor[j+1] (if)
        }
        if((j < R) && (vetor[j] < vetor[j+1])){
            j = j+1;
        }
    }
    if((j > R)){
        countComp[7]++; //aux < vetor[j] -> que nao entra no looping
    }

    vetor[i] = aux;
    countMoves[7]++; //vetor[i] = aux 
}
void heapsort(int vetor[], int n){
    for(int i = n/2; i >= 1; i--){
        heapify(vetor, i, n);
    }

    int aux; 
    for(int i = n; i >= 2; i--){
        aux = vetor[1];
        vetor[1] = vetor[i];
        vetor[i] = aux;
        countMoves[7] += 3; //aux = vetor[1];
                            //vetor[1] = vetor[i];
                            //vetor[i] = aux;
        heapify(vetor, 1, i-1);
    }
}

void quicksort(int v[], int L, int R){
    int i, j, m, x, aux;

    i = L;
    j = R;
    m = floor((L+R)/2);
    x = v[m];
    countMoves[8]++;

    //algoritmo de partição
    do{
        countComp[8]++; //v[i] < x -> que nao entra no looping
        while(v[i] < x){
            countComp[8]++; //v[i] < x
            i++;
        }
        countComp[8]++; //x < v[j] -> que nao entra no looping
        while(x < v[j]){
            countComp[8]++; //x < v[j]
            j--;
        }
        if(i <= j){
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            countMoves[8] += 3; //aux = v[i]
                                //v[i] = v[j]
                                //v[j] = aux
            i++;
            j--;
        }
    }while(i <= j);

    if(L < j){
        quicksort(v, L, j);
    }
    if(i < R){
        quicksort(v, i, R);
    }
}

void merge(int a[], int L, int m, int R, int c[]){
    int i = L;
    int j = m + 1;
    int k = L - 1;

    while(i <= m && j <= R){
        k++;
        countComp[4]++; //a[i] < a[j]
        if(a[i] < a[j]){
            c[k] = a[i];
            countMoves[4]++; //c[k] = a[i]
            i++;
        }
        else{
            c[k] = a[j];
            countMoves[4]++; //c[k] = a[j]
            j++;
        }
    }

    //coloca no vetor os elementos que sobraram 
    while(i <= m){
        k++;
        c[k] = a[i];
        countMoves[4]++; //c[k] = a[i]
        i++;
    }
    while(j <= R){
        k++;
        c[k] = a[j];
        countMoves[4]++; //c[k] = a[j]
        j++;
    }
}
void mpass(int a[], int n, int p, int c[]){
    int i = 1;
    while(i <= n - 2*p + 1){
        merge(a, i, i+p-1, i+2*p-1, c);
        i += 2*p;
    }

    //não consegue mais formar sequências de p elementos
    if(i+p-1 < n){ 
        merge(a, i, i+p-1, n, c);
    }
    else{ //o único elemento sobrou é adicionado ao vetor
        for(int j = i; j <= n; j++){
            c[j] = a[j];
            countMoves[4]++; //c[j] = a[j]
        }
    }
}
void mergesort(int a[], int n){
    int c[n];
    int p = 1;
    while(p < n){
        mpass(a, n, p, c);
        p *= 2;
        mpass(c, n, p, a);
        p *= 2;
    }
}