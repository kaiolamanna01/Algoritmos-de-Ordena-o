#include <stdio.h>
#include <ctime>
#include <iostream>

using namespace std;

void bubbleSort(int vetor[], int tam);
void selectionSort(int vetor[], int tam);

int main(){
    int tini,tfim,tms;
    int n,aux,*vet1,*vet2;
    int loop = 1;

    while(loop==1){
        std:: cout << "Entre com o valor de n: ";
        std:: cin >> n;

            vet1 = new int[n];
            vet2 = new int[n];

        
            for(int i=0;i<n;i++){
                aux = rand()%1000;
                vet1[i] = aux;
                vet2[i] = aux;
            }

            //BUBBLE SORT
            tini = (int)clock();
            bubbleSort(vet1, n);

            tfim = (int)clock();    

            tms = ((tfim-tini)*1000/CLOCKS_PER_SEC);
            cout << "Tempo total(BS): " << tms << "\n";

            //SELECTION SORT
            tini = (int)clock();
            bubbleSort(vet2, n);

            tfim = (int)clock();    

            tms = ((tfim-tini)*1000/CLOCKS_PER_SEC);
            

            cout << "Tempo total(SS): " << tms << "\n";

            delete[] vet1;
            delete[] vet2;
}
    return 0;

}


void bubbleSort(int vetor[], int tam){
    int aux;
    for(int i=0;i<tam;i++){
        for(int j=0;j<tam-1-i;j++){
            aux = vetor[j];
            vetor[j] = vetor[j+1];
            vetor[j+1] = aux;
        }
    }
}

void selectionSort(int vetor[], int tam){
    int min, aux;
    for(int i=0;i<(tam-1);i++){
        min = i;
        for(int j=(i+1);j<tam;j++){
            if(vetor[j]<vetor[min]){
                min=j;
            }
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }
}