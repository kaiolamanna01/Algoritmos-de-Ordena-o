#include <iostream>
#include <cstdlib>
#define SIZE 20
using namespace std;

class MinHeap {
  private:
    int vet[SIZE];   // Vetor que armazena os elementos do heap
    int elems;       // Número de elementos no heap
    void heapfy_down(int i);  // Função abaixar elemento na posição i
    void heapfy_up(int i);    // Função para subir elemento na posição i

  public:
    MinHeap() { elems = 0; }
    ~MinHeap() {}
    bool empty() { return elems == 0; }  // Verifica se o heap está vazio
    int top() { return vet[0]; }         // Retorna o menor elemento
    void push(int);                      // Adiciona um elemento ao heap
    void pop();                          // Remove o menor elemento
};

void MinHeap::heapfy_down(int i) {
  int left = 2*i + 1;  
  int right = 2*i + 2; 
  int smallest = i;

  if (left < elems && vet[left] < vet[smallest])
    smallest = left;
  
  if (right < elems && vet[right] < vet[smallest])
    smallest = right;
  
  if (smallest != i) {
    swap(vet[i], vet[smallest]);
    heapfy_down(smallest);
  }
}

void MinHeap::heapfy_up(int i) {
  int parent = (i - 1) / 2;  // Índice do pai
  
  if (i > 0 && vet[i] < vet[parent]) {
    swap(vet[i], vet[parent]);
    heapfy_up(parent);
  }
}

void MinHeap::push(int el) {
  if (elems == SIZE) {
    cout << "Heap cheia!" << endl;
    return;
  }

  vet[elems] = el;
  elems++;
  heapfy_up(elems - 1);
}

void MinHeap::pop() {
  if (empty()) {
    cout << "Heap vazia!" << endl;
    return;
  }

  vet[0] = vet[elems - 1];
  elems--;
  heapfy_down(0);
}

void init_vetor(int *v) {
  for (int i = 0; i < SIZE; i++)
    v[i] = rand() % 100;
}

int main() {
  MinHeap heap;
  int vet[SIZE];
  init_vetor(vet);

  cout << "\nInserindo elementos na Heap:\n";
  for (int i = 0; i < SIZE; i++) {
    cout << vet[i] << " ";
    heap.push(vet[i]);
  }

  cout << "\nRemovendo todos os elementos da Heap:\n";
  while (!heap.empty()) {
    cout << heap.top() << " ";
    heap.pop();
  }

  return 0;
}
