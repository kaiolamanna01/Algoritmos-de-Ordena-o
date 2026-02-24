🚀 Data Structures & Algorithms in C++
📌 Sobre o Projeto

Este repositório apresenta implementações práticas de Estruturas de Dados e Algoritmos Clássicos desenvolvidos em C++, com foco em:

Análise de desempenho

Complexidade computacional

Organização e eficiência de dados

Aplicação prática de conceitos teóricos

O projeto demonstra domínio de fundamentos essenciais da Ciência da Computação, aplicando conceitos como dividir para conquistar, endereçamento aberto, árvores binárias completas e busca em grafos.

🧠 Algoritmos de Ordenação

📁 main.cpp
📁 bubbleselec.cpp

Implementação e comparação de desempenho entre diferentes algoritmos de ordenação utilizando:

Vetores de inteiros aleatórios

Vetores de strings lidas de arquivos

🔎 Algoritmos Implementados
• Bubble Sort

Algoritmo iterativo que realiza trocas sucessivas, movendo o maior elemento para o final a cada iteração.
Complexidade: O(n²)

• Selection Sort

Seleciona o menor elemento da lista e o posiciona corretamente a cada passo.
Complexidade: O(n²)

• Insertion Sort

Insere cada elemento na posição correta dentro da parte já ordenada do vetor.
Eficiente para pequenos volumes de dados.
Complexidade: O(n²)

• Shell Sort

Extensão do Insertion Sort que permite comparações entre elementos distantes, reduzindo o número de trocas.
Complexidade média: ~O(n log n)

• Merge Sort

Algoritmo baseado na estratégia Divide and Conquer, dividindo o problema em subproblemas menores até que cada um tenha apenas um elemento.
Complexidade: O(n log n)

🗃️ Estruturas de Dados

📁 lab05.cpp
📁 hash.cpp

🔹 Min-Heap

Implementação de uma árvore binária completa onde:

O nó pai possui valor menor ou igual aos filhos

Inserção com heapify_up

Remoção com heapify_down

Permite operações eficientes de prioridade com complexidade O(log n).

🔹 Hash Table

Estrutura para armazenamento de objetos (carros), utilizando:

Chave: Placa do veículo

Função Hash: Baseada em valores ASCII

Tratamento de colisão: Endereçamento Aberto (Linear Probing)

Permite acesso médio em O(1).

🌎 Teoria dos Grafos

📁 lab04.cpp

🔹 Busca em Profundidade (DFS)

Aplicação prática de grafos para representar conexões entre cidades em um mapa de rodovias.

O algoritmo Depth-First Search (DFS) explora completamente cada ramo antes de retroceder, sendo utilizado para:

Identificar todas as cidades acessíveis a partir de um ponto inicial

Explorar conectividade em grafos

Complexidade: O(V + E)

📊 Análise de Desempenho

Os testes realizados demonstram claramente a diferença entre:

Algoritmos de complexidade O(n²)

Algoritmos de complexidade O(n log n)

À medida que o volume de dados cresce, algoritmos como Merge Sort e Shell Sort apresentam desempenho significativamente superior em relação a Bubble Sort, Selection Sort e Insertion Sort.

Essa comparação reforça a importância da escolha adequada do algoritmo conforme a escala do problema.

🛠️ Tecnologias Utilizadas

Linguagem: C++

Bibliotecas padrão:

iostream

vector

fstream

ctime

string

▶️ Como Executar
Compilação
g++ nome_do_arquivo.cpp -o programa
Execução
./programa

⚠️ No main.cpp, verifique se o caminho do arquivo aurelio40000.txt está configurado corretamente em sua máquina para garantir a leitura adequada dos dados.

🎯 Competências Demonstradas

Estruturas de Dados clássicas e avançadas

Análise de Complexidade

Organização eficiente de dados

Manipulação de arquivos em C++

Aplicação prática de Grafos

Comparação empírica de desempenho