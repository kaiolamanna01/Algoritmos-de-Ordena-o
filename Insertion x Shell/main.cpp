#include <stdio.h>
#include <ctime>
#include <iostream>
#include <string.h>
#include <fstream>

/*
Com a utilização dos algoritmos Insertion Sort, Shell Sort e Merge Sort foi possível analisar uma grande diferença de desempenho, 
principalmente, na relação entre o Insertion Sort e os demais, pois a diferença de tempo de execução foi muito alta. No caso do Insertion Sort 
que possui um algoritmo de implementação simples, o tempo de execução foi alto, enquanto o Shell Sort e Merge Sort que possuem algoritmos mais
complexos, possuem um tempo de execução muito inferior.
*/

using namespace std;

void insertionSort(std::string* vet, int n);
void ler_arquivo(std::string *vet, int n);
void mergeIntercala(std::string *vet, std::string *aux, int ini, int meio, int fin);
void mergeDivide(std::string *vet, std::string *aux, int ini, int fin);
void merge(std::string *vet, int n);
void shell(std::string *vet, int n);

int main(){
    int tini,tfim,tms;
    int n;
    std::string *vet1,*vet2,*vet3;
    int loop = 1;

    while(loop==1){
        std:: cout << "Entre com o valor de n: ";
        std:: cin >> n;

        std::string* vet1 = new std::string[n];
        std::string* vet2 = new std::string[n];
        std::string* vet3 = new std::string[n];

            //INSERTION SORT
            ler_arquivo(vet1,n);  // le os arquivos do aurelio40000.txt

            /* TESTE DE LEITURA
                for (int i = 0; i < n; ++i) {
                    if (vet1[i].empty()) {
                        std::cout << "Elemento " << i << " está vazio." << std::endl;
                    } else {
                        std::cout << vet1[i] << std::endl; // Imprime cada elemento
                    }
                }
            */

            tini = (int)clock();
            insertionSort(vet1, n);

            tfim = (int)clock();    

            tms = ((tfim-tini)*1000/CLOCKS_PER_SEC);
            cout << "Tempo total(Insertion Sort): " << tms << "\n";


            //SHELL SORT
            ler_arquivo(vet2,n);  // le os arquivos do aurelio40000.txt
            tini = (int)clock();
            shell(vet2, n);

            tfim = (int)clock();    

            tms = ((tfim-tini)*1000/CLOCKS_PER_SEC);
            cout << "Tempo total(Shell Sort): " << tms << "\n";

            //MERGE SORT
            ler_arquivo(vet3,n);  // le os arquivos do aurelio40000.txt
            tini = (int)clock();
            merge(vet3, n);

            tfim = (int)clock();    

            tms = ((tfim-tini)*1000/CLOCKS_PER_SEC);
            cout << "Tempo total(Merge Sort): " << tms << "\n";

            delete[] vet1;
            delete[] vet2;
            delete[] vet3;
}
    return 0;

}


void ler_arquivo(string *vet, int n){
    ifstream arquivo("C:/Users/kaio/Desktop/bot-click/lab02/aurelio40000.txt");
    if(arquivo){
        for(int i=0;i<n;i++){
            arquivo >> vet[i];
        }
    }
            arquivo.close();
}



void shell(std::string *vet, int n) {
    int j, h;
    std::string aux;
    h = n / 2;

    while (h >= 1) {
        for (int i = h; i < n; i++) {
            aux = vet[i];
            j = i;

            while (j >= h && vet[j - h] > aux) {
                vet[j] = vet[j - h];
                j -= h;
            }
            vet[j] = aux;
        }
        h /= 2;
    }
}

void merge(std::string *vet, int n){

    std::string *aux = new std::string[n];

    mergeDivide(vet, aux, 0, n-1);

    delete[] aux;
}

void mergeDivide(std::string *vet, std::string *aux, int ini, int fin){
    int meio;

    if(fin>ini){
        meio = (fin+ini)/2;

        mergeDivide(vet,aux,ini,meio);
        mergeDivide(vet,aux,meio+1,fin);

        mergeIntercala(vet,aux,ini,meio+1,fin);
    }
}

void mergeIntercala(std::string *vet, std::string *aux, int ini, int meio, int fin){
    int atual,fimEsq,n;
    atual = ini;
    fimEsq = meio-1;
    n = fin-ini+1;

    while((ini <=fimEsq)&&(meio<=fin)){
        if(vet[ini] <= vet[meio])
            aux[atual++] = vet[ini++];
        else
            aux[atual++] = vet[meio++];
    }

    while(ini <= fimEsq)
        aux[atual++] = vet[ini++];

    while(meio <= fin)
        aux[atual++] = vet[meio++];
    
    for(int i=0;i<n;i++){
        vet[fin] = aux[fin];
        fin--;
    }
}

void insertionSort(std::string *vet, int n){
    int j;
    string aux;
    for(int i = 1;i<n;i++){
        aux = vet[i];

        for(j=i-1;(j>=0)&&(vet[j]>aux);j--){
            vet[j+1] = vet[j];
                    }
            vet[j+1] = aux;
    }
}