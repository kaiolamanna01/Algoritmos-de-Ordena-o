Este repositório contém uma coleção de implementações práticas de estruturas de dados e algoritmos fundamentais desenvolvidos em C++. O conteúdo abrange desde métodos de ordenação clássicos até estruturas avançadas como Heaps e Tabelas Hash, além de busca em grafos.

📂 Conteúdo do Repositório
1. Algoritmos de Ordenação (main.cpp e bubbleselec.cpp)
Comparações de desempenho entre diferentes estratégias de ordenação, utilizando vetores de strings (lidos de arquivos) e vetores de inteiros aleatórios.

Bubble Sort: Algoritmo iterativo simples que flutua o maior elemento para o fim a cada passagem.

Selection Sort: Seleciona o menor elemento e o coloca na posição correta.

Insertion Sort: Constrói a lista final um item por vez, eficiente para conjuntos de dados pequenos.

Shell Sort: Uma generalização do Insertion Sort que permite a troca de itens distantes.

Merge Sort: Algoritmo do tipo "dividir para conquistar" que divide a lista em sub-listas até que cada uma tenha um elemento e as combina de forma ordenada.

2. Estruturas de Dados Avançadas (lab05.cpp e hash.cpp)
Implementações focadas em eficiência de acesso e organização de dados.

Min-Heap: Uma árvore binária completa onde o valor de cada nó pai é menor ou igual ao valor de seus filhos. Inclui operações de push (inserção com heapfy_up) e pop (remoção do menor elemento com heapfy_down).

Tabela Hash (Hash Table): Sistema de armazenamento de objetos (neste caso, carros) usando chaves (placas). Utiliza uma função hash baseada em valores ASCII e Endereçamento Aberto (Linear Probing) para tratar colisões.

3. Teoria dos Grafos (lab04.cpp)
Aplicação prática de grafos para representar conexões entre cidades.

Busca em Profundidade (DFS): O algoritmo explora o máximo possível ao longo de cada ramo antes de retroceder. É utilizado aqui para identificar todas as cidades acessíveis a partir de um ponto de partida em um mapa de rodovias.

🛠️ Tecnologias Utilizadas
Linguagem: C++

Bibliotecas Padrão: iostream, vector, fstream (para manipulação de arquivos), ctime (para medição de tempo de execução) e string.

🚀 Como Executar
Compilação: Utilize um compilador como o g++.

Bash
g++ nome_do_arquivo.cpp -o programa
Execução:

Bash
./programa
Nota: No arquivo main.cpp, certifique-se de que o caminho do arquivo de texto aurelio40000.txt esteja correto em sua máquina local para que a leitura dos dados funcione conforme o esperado.

📈 Análise de Desempenho
Conforme observado nos comentários do código (main.cpp), algoritmos mais complexos como Merge Sort e Shell Sort apresentam um desempenho significativamente superior ao Insertion Sort e Bubble Sort conforme o volume de dados (n) cresce, demonstrando a importância da complexidade computacional O(nlogn) frente a O(n2).