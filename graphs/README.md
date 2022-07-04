# Grafos

Grafos são estruturas matemáticas que permitem codificar relacionamentos entre pares de objetos. Cada objeto é representado por um `vértice v` e seus relacionamentos são chamados de `arestas a`.

![image](/assets/basic-graph.png)

Existem alguns tipos de grafos. Veremos a seguir.

1. Grafos Dirigidos

São grafos nos quais as arestas tem um sentido relacionado a elas. As arestas são representados por pares ordenados `(v1, v2)` indicando que existe um caminho entre os vérticas `v1` e `v2` (não necessariamente existe um caminho de `v2` para `v1`).

Isso permite a existência de arestas chamadas de `self-loops`, representadas por `(v1, v1)` que indica uma aresta que conecta um elemento a ele mesmo.

2. Grafos Não Dirigidos

Neste caso as arestas não possuem um sentido pré determinado. Neste casos as arestas são pares NÃO-ordenados `(v1, v2)` = `(v2, v1)`. Neste caso não são permitidos `self-loops`.

#### Conceitos Básicos

- **Vértices Adjascentes**

Supondo uma aresta `(u, v)`, dizemos então que o vértice `v` é adjascente ao vértice `u`. Se o grafo for não dirigido, então a relação `(u, v) <=> (v, u)` é simétrica enquanto no caso dirigido a recíproca não é verdadeira necessariamente.

- **Grau de um vértice**

Indica a quantidade de arestas que incidem em um vértice `v`.

- **Caminhos**

Dado um vértice `v1` e um vértice `vn`, um caminho é uma sequência de vértices em que, para cada vértice, do primeiro ao penúltimo, há uma aresta ligando esse vértice ao próximo na sequência.

Na imagem acima, a tupla `(v1, v2, v3, v5)` indica o caminho entre `v1` até `v5`.

Um caminho tem `comprimento` dado pelo número de arestas que compõem ele. No exemplo anterior, o caminho de `v1` até `v5` tem comprimento igual a 3.

- **Ciclos**

Se a partir de um nó `v1` existe um caminho que incide novamente em `v1`, chamamos esse caminho de `ciclo`.

    - se for um grafo dirigido, são necessários pelo menos três vértices para compor um ciclo;
    - se for um grafo não dirigido, apenas um vértice compõe um ciclo.

Grafos que não possuem ciclos são chamados `grafos acíclicos` e aqueles que possuem pelo menos um ciclo são chamados de `grafos cíclicos`.

- **Conectividade**

Um grafo não direcionado em que todos os pares vértices estão conectados por um caminho qualquer é chamado de `grafo conexo` (ou conectado). Caso a condição anterior não seja satisfeita, chamamos o grafo de `grafo desconexo`.

Em um grafo direcionado, se existe um caminho entre quaisquer dois pares de vértices, esse grafo é dito `fortemente conexo`.

Se existe um caminho entre `u` e `v` OU entre `v` e `u` num grafo dirigido, ele é dito `conexo`.

Se em um grafo direcionado substituirmos todas arestas direcionadas por não direcionadas e isso produzir um grafo conexo, dizemos que esse grafo é `fracamente conexo`.

- **Grafos Ponderados**

Quando associamos pesos `w` as arestas de um grafo, dizemos que ele é ponderado.

## Representação de Grafos

Abaixo veremos algumas representações de grafos. Uma conceitual e duas computacionais. Dentre as computacionais, escolhemos cada uma dependendo da densidade do grafo (i.e. `qtd. arestas / qtd. vértices`). Se for muito denso, preferimos as matrizes de adjascência, se for pouco denso, preferimos as listas de adjascência.

### Mapeamento de Nós

Para cada nó, descrevemos a quais outros nós ele está ligado.

![image](/assets/graph-map.png)

### Matrizes de Adjascência

Um grafo com N vértices pode ser representado por uma matriz de tamanho `N x N` de forma que

```
A[i, j] = 1, se existe uma aresta que liga o vértice i até o vértice j
A[i, j] = 0, se não existe uma aresta que ligue o vértice i até o vértice j
```

![image](/assets/adjascency-matrix.png)

Se o grafo for ponderado, em cada posição colocamos o peso `w` da conexão.

### Listas de Adjascência

Para representar um grafo de N vértices, utilizamos um arranjo com N listas ligadas, na qual cada nó possui uma referência para o vértice específico.

![image](/assets/adjascency-list.png)
