#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

#define SIZE 10 // Número de cidades

// Nomes das cidades sem espaços
const string cidades[SIZE] = {
    "Itajuba", "PousoAlegre", "SantaRita", "Cristina",
    "Piranguinho", "DelfimMoreira", "Pedralva", "Paraisopolis",
    "MariaDaFe", "SaoLourenco"
};

// função DFS
void dfs(int grafo[SIZE][SIZE], vector<bool>& visitado, vector<int>& acessiveis, int cidade) {
    visitado[cidade] = true;
    acessiveis.push_back(cidade);

    // visita todas as cidades conectadas
    for (int i = 0; i < SIZE; i++) {
        if (grafo[cidade][i] == 1 && !visitado[i]) {
            dfs(grafo, visitado, acessiveis, i);
        }
    }
}

int main() {
    int arestas;
    int grafo[SIZE][SIZE] = {0}; // matriz de adjacencias

    // le trechos de rodovia
    cout << "Entre com a quantidade de trechos de rodovia: ";
    cin >> arestas;
    cin.ignore();

    cout << "Entre com todos os trechos (fonte destino): \n";
    for (int i = 0; i < arestas; i++) {
        string linha;
        getline(cin, linha);

        // dividir a linha em palavras
        stringstream ss(linha);
        string fonte, destino;

        ss >> fonte;  // Lê a fonte até o primeiro espaço
        ss >> destino; // Lê o destino

        // Mapeia as cidades para índices
        int indiceFonte = -1, indiceDestino = -1;

        for (int j = 0; j < SIZE; j++) {
            if (cidades[j] == fonte) {
                indiceFonte = j;
            }
            if (cidades[j] == destino) {
                indiceDestino = j;
            }
        }

        // Verifica se as cidades foram encontradas
        if (indiceFonte != -1 && indiceDestino != -1) {
            grafo[indiceFonte][indiceDestino] = 1;
            grafo[indiceDestino][indiceFonte] = 1;
        } else {
            cout << "Cidades inválidas: " << fonte << ", " << destino << endl;
        }
    }

    // solicita a cidade inicial
    string cidadeInicial;
    cout << "Entre com a cidade inicial: ";
    getline(cin, cidadeInicial);

    // mapeia a cidade inicial
    int indiceInicial = -1;
    for (int j = 0; j < SIZE; j++) {
        if (cidades[j] == cidadeInicial) {
            indiceInicial = j;
            break;
        }
    }

    // valida a cidade inicial
    if (indiceInicial == -1) {
        cout << "Cidade inicial inválida!" << endl;
        return 1;
    }

    // realiza DFS a partir da cidade inicial
    vector<bool> visitado(SIZE, false);
    vector<int> acessiveis;
    dfs(grafo, visitado, acessiveis, indiceInicial);

    // imprime as cidades acessíveis a partir da cidade inicial
    cout << "Cidades acessiveis a partir de " << cidades[indiceInicial] << ": ";
    for (int cidade : acessiveis) {
        cout << cidades[cidade] << " ";
    }
    cout << endl;

    return 0;
}
