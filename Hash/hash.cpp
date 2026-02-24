#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct Carro {
    string placa;
    string modelo;
    string cor;

    // Construtor do Carro
    Carro(string p, string m, string c) : placa(p), modelo(m), cor(c) {}
};

// Classe HashTable
class HashTable {
private:
    struct Elemento {
        bool ocupado;
        Carro* carro;
        
        Elemento() : ocupado(false), carro(nullptr) {}
    };
    
    vector<Elemento> tabela;
    int capacidade;

    // Função de hash que soma os valores ASCII da placa
    int hash(const string& chave) {
        int hashValue = 0;
        for (char c : chave) {
            hashValue += c; // Soma ASCII de cada caractere
        }
        return hashValue % capacidade; // Operação para encontrar o numero do hash
    }

public:
    // Construtor da tabela hash com capacidade 20
    HashTable() : capacidade(20) {
        tabela.resize(capacidade);
    }

    // Função para inserir um carro na tabela
    void put(const string& placa, const string& modelo, const string& cor) {
        int index = hash(placa);
        int originalIndex = index;
        
        while (tabela[index].ocupado) {
            if (tabela[index].carro->placa == placa) {
                // Se já existe um carro com a mesma placa, substitui
                tabela[index].carro = new Carro(placa, modelo, cor);
                cout << "Carro atualizado!" << endl;
                return;
            }
            // Busca linear
            index = (index + 1) % capacidade;
            if (index == originalIndex) {
                cout << "Tabela hash cheia!" << endl;
                return;
            }
        }
        tabela[index].ocupado = true;
        tabela[index].carro = new Carro(placa, modelo, cor);
        cout << "Carro inserido!" << endl;
    }

    // Função para remover um carro da tabela
    void remove(const string& placa) {
        int index = hash(placa);
        int originalIndex = index;

        while (tabela[index].ocupado) {
            if (tabela[index].carro->placa == placa) {
                delete tabela[index].carro;  // Libera a memória do carro
                tabela[index].carro = nullptr;
                tabela[index].ocupado = false;
                cout << "Carro removido!" << endl;
                return;
            }
            // Busca linear
            index = (index + 1) % capacidade;
            if (index == originalIndex) {
                break; // Voltou ao ponto inicial, carro não encontrado
            }
        }
        cout << "Carro não encontrado!" << endl;
    }

    // Função para recuperar um carro da tabela
    Carro* get(const string& placa) {
        int index = hash(placa);
        int originalIndex = index;

        while (tabela[index].ocupado) {
            if (tabela[index].carro->placa == placa) {
                return tabela[index].carro;
            }
            index = (index + 1) % capacidade;
            if (index == originalIndex) {
                break; // Voltou ao ponto inicial, carro não encontrado
            }
        }
        return nullptr; // Retorna nullptr se não encontrar
    }

    // Função para imprimir o estado atual da tabela
    void print() {
        bool tabelaVazia = true;
        for (int i = 0; i < capacidade; ++i) {
            if (tabela[i].ocupado) {
                cout << "Índice " << i << ": " 
                     << "Placa: " << tabela[i].carro->placa 
                     << ", Modelo: " << tabela[i].carro->modelo 
                     << ", Cor: " << tabela[i].carro->cor << endl;
                tabelaVazia = false;
            }
        }
        if (tabelaVazia) {
            cout << "A tabela está vazia!" << endl;
        }
    }
};

int main() {
    HashTable hashTable;
    int opcao;

    do {
        // MENU
        cout << "\n--------- MENU ---------\n";
        cout << "2. Remover carro\n";
        cout << "3. Buscar carro\n";
        cout << "4. Imprimir tabela\n";
        cout << "5. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        cin.ignore();

        switch (opcao) {
            case 1: {
                // Inserir carro
                string placa, modelo, cor;
                cout << "Digite a placa do carro: ";
                getline(cin, placa);
                cout << "Digite o modelo do carro: ";
                getline(cin, modelo);
                cout << "Digite a cor do carro: ";
                getline(cin, cor);
                hashTable.put(placa, modelo, cor);
                break;
            }
            case 2: {
                // Remover carro
                string placa;
                cout << "Digite a placa do carro a ser removido: ";
                getline(cin, placa);
                hashTable.remove(placa);
                break;
            }
            case 3: {
                // Buscar carro
                string placa;
                cout << "Digite a placa do carro a ser buscado: ";
                getline(cin, placa);
                Carro* carro = hashTable.get(placa);
                if (carro) {
                    cout << "Carro encontrado: "
                         << "Placa: " << carro->placa 
                         << ", Modelo: " << carro->modelo 
                         << ", Cor: " << carro->cor << endl;
                } else {
                    cout << "Carro não encontrado!" << endl;
                }
                break;
            }
            case 4: {
                // Imprimir a tabela
                cout << "\nEstado atual da tabela hash:" << endl;
                hashTable.print();
                break;
            }
            case 5: {
                cout << "Saindo do programa..." << endl;
                break;
            }
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }

    } while (opcao != 5);

    return 0;
}
