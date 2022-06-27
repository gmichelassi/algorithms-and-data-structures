// #########################################################
// #                      BINARY TREE                      #
// #########################################################

#include <stdlib.h>
#include <stdio.h>

typedef struct aux {
    int key;    
    struct aux *left;
    struct aux *right;
} node;

typedef struct {
    node* root;
} tree;


// 1. Inicializar uma árvore é simples, basta dizer que a raiz está vazia.
void initialize(tree* t) {
    t->root = NULL;
}

// 2. Altura. Pode ser implementada de forma recursiva pela definição do problema.
// A altura de um determinado nó é 1 + MAX(altura_filho_esquerdo, altura_filho_direito).
int max(int first, int second) {
    if(first > second) return first;

    return second;
}

int height(node* n){
    if(n == NULL) return -1;

    return 1 + max(height(n->left), height(n->right));
}

// 3. Número de nós. Análogo ao caso anterior.
int count(node* n) {
    if(n == NULL) return 0;

    return 1 + count(n->left) + count(n->right);
}

// 4. Inserção (sem chaves duplicadas)
// A função abaixo cria um nó com a chave desejada. Ele será inserido futuramente.
node* create_node(int key) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->key = key;

    return new_node;
}

// A função abaixo recebe um nó qualquer e insere ele na árvore na posição correta, seguindo a regra
// que tenta manter valores menores a esquerda e valores maiores a direita.
node* insert(node* root, node* new_node) {
    if(root == NULL) return new_node;

    if(new_node->key < root->key)
        root->left = insert(root->left, new_node);
    else
        root->right = insert(root->right, new_node);

    return root;
}

// 5. Busca binária. O maior motivo para a existência dessa estrutura é a possibilidade de se fazer busca binária
// Pelo menos quando a árvore é balanceada :p.
node* binary_search(node* root, int key) {
    if(root == NULL) return NULL;

    if(root->key == key) return root;

    if(root->key > key)
        return binary_search(root->left, key);

    return binary_search(root->right, key);
}


// 6. Exclusão. Existem muitos casos a serem lidados na exclusão de um nó de árvore binária.
// Primeiro precisamos refazer a busca binária para retornar também o pai do nó procurado.
node* binary_search(node* root, int key, node** parent) {
    node* current = root;
    *parent = NULL;

    while(current) {
        if(current->key == key) return current;

        *parent = current;
        if(current->key < key) current = current->left;
        else current = current->right;
    }

    return NULL;
}

// Casos que precisam ser considerados na exclusão
// 1. nó a ser excluído não tem filhos
// 2. nó a ser excluído possui um filho
// 3. nó a ser excluído possui dois filhos
node* remove(node* root, int key) {
    node* parent;
    node* to_be_removed = binary_search(root, key, &parent);
    node* q;
    node* p;

    if(to_be_removed == NULL) return root;

    if(!to_be_removed->left || !to_be_removed->right) {
        if(!to_be_removed->left) q = to_be_removed->right;
        else q = to_be_removed->left;
    } else {
        p = to_be_removed;
        q = to_be_removed->left;
        while(q->right) {
            p = q;
            q = q->right;
        }

        if(p != to_be_removed) {
            p->right = q->left;
            q->left = to_be_removed->left;
        }

        q->right = to_be_removed->right;
    }

    if(!parent) {
        free(to_be_removed);

        return q;
    }

    if(key < parent->key) parent->left = q;
    else parent->right = q;

    free(to_be_removed);

    return root;
}

// PERCURSOS EM ÁRVORES

// 1. Pré Ordem: Visitamos primeiro a raiz, depois a subárvore esquerda e por fim a subárvore direita
void pre_order(node* n) {
    if(n) {
        printf(" %d", n->key);
        pre_order(n->left);
        pre_order(n->right);
    }
}

// 2. Em Ordem: Visitamos toda a subárvore esquerda, depois a Raiz e por fim toda a subárvore direita
void in_order(node* n) {
    if(n) {
        pre_order(n->left);
        printf(" %d", n->key);
        pre_order(n->right);
    }
}

// 3. Pós ordem: Visitamos toda a subárvore esquerda, depois a subárvore direita e por fim a raiz
void pos_ordem(node* n) {
    if(n) {
        pre_order(n->left);
        pre_order(n->right);
        printf(" %d", n->key);
    }
}


// 4. Em nível
// Não implementado aqui neste momento pois necessita de uma estrutura do tipo fila.
// A ideia geral consiste em percorrer a árvore da esquerda para direita passando por cada nível, um de cada vez.


int main() {
    tree t;

    initialize(&t);

    node* new_node = create_node(10);
    t.root = insert(t.root, new_node);

    new_node = create_node(5);
    insert(t.root, new_node);

    new_node = create_node(13);
    insert(t.root, new_node);

    new_node = create_node(11);
    insert(t.root, new_node);

    new_node = create_node(14);
    insert(t.root, new_node);


    printf("\nContagem de elementos: %d", count(t.root));
    printf("\nAltura da lista: %d", height(t.root));

    printf("\n\nPercursos: ");

    printf("\nPré Ordem: ");
    pre_order(t.root);

    printf("\nEm Ordem: ");
    in_order(t.root);

    printf("\nPós Ordem: ");
    pos_ordem(t.root);

    
    t.root = remove(t.root, 10);

    printf("\n\nContagem de elementos: %d", count(t.root));
    printf("\nAltura da lista: %d", height(t.root));

    printf("\nÁrvore final: ");
    in_order(t.root);
}