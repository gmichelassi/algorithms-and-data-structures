# Árvores

Uma `árvore` é um conjunto de `nós` consistindo de um `nó raiz`, abaixo do qual estão outras `subárvores` que compõem a estrutura.

Todo nó possui um `pai`, exceto o nó raiz, que não possui um pai.

![image](/assets/basic-tree.png)

## Conceitos básicos

- <ins>Grau de um nó</ins>: é dado pelo número de sub árvores do nó.

  O grau máximo presente em uma árvore também define seu tipo. Por exemplo, uma árvore de grau máximo dois é dita uma `árvore binária`.

- <ins>Folhas e descendentes</ins>: Os nós abaixo de um determinado nó são chamados de descendentes (ou filhos) do nó. Um nó sem filhos é chamado de `folha`.

- <ins>Nível</ins>: Definimos o nível de um nó começando da raiz que possui nível zero. Seus filhos possuem nível 1, os netos nível 2 e assim por diante.

- <ins>Altura</ins>: A altura de um nó é definida como o comprimento do maior caminho entre ele e uma folha. Dessa forma, **a altura de uma árvore é a altura do nó raiz**.

- <ins>Profundidade</ins>: É dado pela distância entre a raiz até determinado nó.

# Árvores Binárias

Uma árvore binária é aquela que cada nó possui no máximo dois filhos. Um filho esquerdo e um filho direito.

![image](/assets/binary-search-tree.png)

- Essas árvores também podem ser chamadas de `árvores de busca binária`, pois é possível fazer busca binária, um grande avanço em relação as estruturas lineares ligadas.
- Os nós a direita sempre possuem chaves com valores maiores e os nós a esquerda sempre possuem chaves com valores menores.

- Um grande problema dessa estrutura é que em algum momento, devido a regra de inserção (menores a esquerda e maiores a direita), a árvore tende a se desbalancear dependendo da ordem que os elementos foram inseridos, formando eventualmente uma estrutura ligada.

![image](/assets/imbalancing-problem.png)

# Árvores AVL (Adelson Velsky e Landis, 1962)

Uma árvore AVL é um tipo específico de árvore binária de busca que se mantém balanceada após qualquer operação realizada sobre ela, utilizando algoritmos de rotação para remanejar os nós da árvore.

O balanceamento é garantido pela regra: `para todo nó, a diferença (em módulo) entre a altura da sub-árvore direita e da sub-árvore esquerda deve ser no máximo 1.`

Devido a propriedade anterior a altura da árvore é de no máximo O(log n).

## Balanceamento e Rotações

Chamaremos o nó com desbalanceamento igual a 2 de `p`. Seu filho da direção da inserção será chamado de `u` e seu neto também no sentido da inserção será chamado de `v`. Faremos uma rotação para corrigir o desbalanceamento.

![image](/assets/avl-rotation.png)

Existem em total de quatro combinações possíveis para os nós `p`, `u` e `v`. Utilizamos um algoritmo específico para cada rotação.

![image](/assets/avl-node-combinations.png)

Dessas quatro combinações, derivamos quatro casos de rotação, conforme a figura a seguir.

![image](/assets/avl-node-rotations.png)
