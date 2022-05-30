# A-
O programa encontra o caminho em um mapa utilizando métodos distintos.
Este trabalho fo feito em dupla com Eduardo Grillo.

# Do que se trata o trabalho:
No programa o usuário fornece um mapa em forma de matriz NxM que informa as posições que podem ser percorridas com '.' e as impedidas com '-', sendo que a primeira e a
última posição devem obrigatoriamente ser '.' e seus vizinhos não podem estar mutuamente impedidos. O objetivo é encontrar, a partir da posição 1x1, um caminho para a
posição NxM. Diferentes métodos de busca foram implementados, sendo eles 1. BFS, 2. DFS e 3. A*.

# BFS:
Em teoria dos grafos, Breadth First search ou Busca em Largura são algorítmos de busca utilizados para realizar uma travessia em um grafo ou estrutura do tipo árvore
explorando todos os vértices vizinhos. Por checar todos as posições possíveis, este tende a ser o método que exige mais interações emcomparações com os outros quando há poucas posições impedidas.
Para mais informações vide o repositório BFS: https://github.com/KemilyRezende/BFS

# DFS:
Depth first search ou busca em profundidade é o algorítmo usado para fazer buscas em uma árvore ou grafo percorrendo o quanto possível os ramos de cada raiz antes de
retroceder. Quando há poucas posições impedidas tende a ser um dos métodos que exigem menos interações.
Para mais informações vide o repositório DFS: https://github.com/KemilyRezende/DFS

# A*:
Este é uma alteração do BFS que busca encontrar o caminho mais curto, havendo dois métodos de calcular tal caminho:
1. Manhattan: |x1-x2|+|y1-y2|
2. Euclidiana: √((x1-x2)²+(y1-y2)²)
Sendo x1, y1 a posição atual e x2, y2 a final. Asduas posições candidatas à atual são submetidas aos cálculos e a menor é selecionada.
