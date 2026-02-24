# 🚀 Data Structures & Algorithms in C++

## 📌 Visão Geral

Este repositório reúne implementações práticas de **Estruturas de Dados** e **Algoritmos Clássicos** desenvolvidos em C++, com foco em:

* 📊 Análise de desempenho
* 🧮 Complexidade computacional
* 🗂 Organização eficiente de dados
* 🧠 Aplicação prática de fundamentos teóricos da Ciência da Computação

O projeto consolida conceitos essenciais como **Divide and Conquer**, **endereçamento aberto em tabelas hash**, **árvores binárias completas** e **busca em grafos**, demonstrando domínio de estruturas fundamentais utilizadas em sistemas reais.

---

# 🧠 Algoritmos de Ordenação

📁 `main.cpp`
📁 `bubbleselec.cpp`

Implementação e comparação empírica de diferentes algoritmos de ordenação aplicados a:

* Vetores de inteiros gerados aleatoriamente
* Vetores de strings carregadas a partir de arquivos

---

## 🔎 Algoritmos Implementados

### 🔹 Bubble Sort

Algoritmo iterativo baseado em trocas sucessivas de elementos adjacentes.

* Complexidade: **O(n²)**
* Simples implementação
* Baixa eficiência para grandes volumes de dados

---

### 🔹 Selection Sort

Seleciona o menor elemento da lista a cada iteração e o posiciona corretamente.

* Complexidade: **O(n²)**
* Reduz número de trocas comparado ao Bubble Sort

---

### 🔹 Insertion Sort

Insere cada elemento na posição adequada dentro da parte já ordenada do vetor.

* Complexidade: **O(n²)**
* Bom desempenho para conjuntos pequenos ou quase ordenados

---

### 🔹 Shell Sort

Generalização do Insertion Sort que permite comparações entre elementos distantes, reduzindo deslocamentos.

* Complexidade média: **≈ O(n log n)**
* Melhor desempenho prático que algoritmos quadráticos

---

### 🔹 Merge Sort

Baseado na estratégia **Divide and Conquer**, divide o problema recursivamente até unidades mínimas e realiza a intercalação ordenada.

* Complexidade: **O(n log n)**
* Estável
* Excelente desempenho para grandes conjuntos de dados

---

# 🗃️ Estruturas de Dados

📁 `lab05.cpp`
📁 `hash.cpp`

---

## 🔹 Min-Heap

Implementação de uma **árvore binária completa** onde:

* O nó pai possui valor ≤ seus filhos
* Inserção com `heapify_up`
* Remoção com `heapify_down`

Permite operações eficientes de fila de prioridade com:

* Inserção: **O(log n)**
* Remoção: **O(log n)**

---

## 🔹 Hash Table

Estrutura de armazenamento de objetos (ex.: veículos), utilizando:

* 🔑 **Chave:** Placa do veículo
* 🧮 **Função Hash:** Baseada em valores ASCII
* 🔁 **Tratamento de colisão:** Endereçamento Aberto (Linear Probing)

Complexidade média de acesso:

* **O(1)**

---

# 🌎 Teoria dos Grafos

📁 `lab04.cpp`

## 🔹 Depth-First Search (DFS)

Aplicação prática de grafos representando conexões entre cidades em um mapa rodoviário.

O algoritmo **Busca em Profundidade (DFS)**:

* Explora completamente cada ramo antes de retroceder
* Identifica todos os vértices alcançáveis a partir de um ponto inicial
* Analisa conectividade em grafos

Complexidade:

* **O(V + E)**

---

# 📊 Análise de Desempenho

Os testes realizados evidenciam claramente a diferença entre:

* Algoritmos de complexidade **O(n²)**
* Algoritmos de complexidade **O(n log n)**

À medida que o volume de dados cresce:

* **Merge Sort** e **Shell Sort** apresentam desempenho significativamente superior
* Algoritmos quadráticos tornam-se inviáveis em larga escala

A comparação reforça a importância da escolha estratégica de algoritmos conforme a dimensão do problema.

---

# 🛠 Tecnologias Utilizadas

* Linguagem: **C++**
* Bibliotecas padrão:

  * `iostream`
  * `vector`
  * `fstream`
  * `ctime`
  * `string`

---

# ▶️ Como Executar

### 🔹 Compilação

```bash
g++ nome_do_arquivo.cpp -o programa
```

### 🔹 Execução

```bash
./programa
```

⚠️ No arquivo `main.cpp`, verifique se o caminho do arquivo `aurelio40000.txt` está corretamente configurado para evitar erros de leitura.

---

# 🎯 Competências Demonstradas

* Implementação de Estruturas de Dados clássicas
* Análise formal de complexidade
* Comparação empírica de desempenho
* Manipulação de arquivos em C++
* Modelagem e exploração de grafos
* Organização e estruturação de código