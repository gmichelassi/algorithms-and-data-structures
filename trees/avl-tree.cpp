// #########################################################
// #                       AVL TREE                        #
// #########################################################

#include <stdlib.h>
#include <stdio.h>

typedef struct aux {
    int key;    
    struct aux *left;
    struct aux *right;
    int balance_factor;
} node;

typedef struct {
    node* root;
} tree;

// 1. Inialização, calculo de altura e contagem de nós ocorrem de maneira semelhante às árvores binárias simples.
void initialize(tree* t) {
    t->root = NULL;
}

int max(int first, int second) {
    if(first > second) return first;

    return second;
}

int height(node* n){
    if(n == NULL) return -1;

    return 1 + max(height(n->left), height(n->right));
}

int count(node* n) {
    if(n == NULL) return 0;

    return 1 + count(n->left) + count(n->right);
}

// 2. É árvore AVL? Pequeno helper para indicar se a árvore analisada é AVL ou não.
// De forma simples, ele verifica se a árvore mantém para todos os nós a condição de balanceamento.
bool isAVL(node* root){
	bool ok = true;
	if(root) {
		ok = isAVL(root->left) && isAVL(root->right);

		if(ok){
			int left_height = height(root->left);
			int right_height = height(root->right);

			ok = !(left_height - right_height > 1 || left_height - right_height < -1);
		}
	}

	return(ok);
}

int update_balance_factor(node* root){
	if (!root) return 0;

	int left_balance_factor = update_balance_factor(root->left);
	int right_balance_factor = update_balance_factor(root->right);

	root->balance_factor = left_balance_factor - right_balance_factor;

	return max(left_balance_factor, right_balance_factor) + 1;
}



// 3. Rotações em árvore AVL

// 3.1 Rotação a Esquerda (tipo L) - Retornaremos a nova raiz, pós rotação.
node* left_rotation(node* p) {
    printf("\nRotação de tipo L para o nó com chave: %i", p->key);

    node* u = p->left;
    node* v;

    // Caso LL (esquerda - esquerda)
    if(u->balance_factor == -1) {
        p->left = u->right;
		u->right = p;

		p->balance_factor = 0;
		u->balance_factor = 0;

		return u;
    } 
    // Caso LR (esquerda - direita)
    else if (u->balance_factor == 1){
        v = u->right;
		u->right = v->left;
		v->left = u;
		p->left = v->right;
		v->right = p;

		if(v->balance_factor == -1) p->balance_factor = 1;
		else p->balance_factor = 0;

		if(v->balance_factor == 1) u->balance_factor = -1;
		else u->balance_factor = 0;

		v->balance_factor = 0;

		return v;
    }
    // Quando fazemos exclusão, é o único momento em que alguma alteração na árvore deixa um nó com balanceamento zero.
    else {
        p->left = u->right;
        u->right = p;

        p->balance_factor = -1;
        u->balance_factor = 1;

        return u;
    }
}


// 3.2 Rotação a Direita (tipo R) - Retornaremos a nova raiz, pós rotação
node* right_rotation(node* p){
	printf("\nRotação de tipo R para o nó com chave: %i", p->key);

    node* u = p->right;
    node* v;

    // Caso RR (direita - direita)
	if(u->balance_factor == 1) {
		p->right = u->left;
		u->left = p;

		p->balance_factor = 0;
		u->balance_factor = 0;

		return u;
	}
    // Caso RL (direita - esquerda)
    else if (u->balance_factor == -1){
		v = u->left;
		u->left = v->right;
		v->right = u;
		p->right = v->left;
		v->left = p;

		if(v->balance_factor == 1) p->balance_factor = -1;
		else p->balance_factor = 0;

		if(v->balance_factor == -1) u->balance_factor = 1;
		else u->balance_factor = 0;

		v->balance_factor = 0;

		return v;
	}
    // Quando fazemos exclusão, é o único momento em que alguma alteração na árvore deixa um nó com balanceamento zero.
    else{
		p->right = u->left;
		u->left = p;

		u->balance_factor = -1;
		p->balance_factor = 1;

		return u;	
	}
}

// 4. Inserção
// Ainda se mantém a característica de se criar um nó individualmente. Este nó recém criado tem fator de balanceamento igual a 0.
node* create_node(int key) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->key = key;
    new_node->balance_factor = 0;

    return new_node;
}

void insert(node** root, int key, bool* changed) {
	node* p = *root;

	if(!p){
		*root = create_node(key);
		*changed = true;
	} else {
        if(key == p->key) *changed = false;
		else if(key <= p->key) {
			insert(&(p->left), key, changed);

			if(*changed)
				switch (p->balance_factor) {
					case 1:
                        p->balance_factor = 0;
					    *changed = false;
					    break;
					case 0:
                        p->balance_factor = -1;
					    break;
					case -1:
                        *root = left_rotation(p);
					    *changed = false;
					    break;
				}
		} else {
			insert(&(p->right), key, changed);

			if(*changed)
				switch (p->balance_factor) {
					case -1:
                        p->balance_factor = 0;
					    *changed = false;
					    break;
					case 0:
                        p->balance_factor = 1;
					    break;
					case 1:
                        *root = right_rotation(p);
					    *changed = false;
					    break;
				}
		}
	}
}

// 5. Exclusão.
// Queremos excluir um nó que possua uma determinada chave e corrigir o balanceamento da árvore.

// Auxiliar - Procura a MAIOR chave que é MENOR que a chave que será excluida
node* biggest_key(node* p, node** ant){
    *ant = p;
    p = p->left;

    while (p->right) {
        *ant = p;
        p = p->right;
    }

    return(p);
}

void remove(node** raiz, int ch, bool* changed) {
    node* current = *raiz;

    if (!current) {
        *changed = false;
        return;
    }

    if (current->key == ch) {
        node* replacement;
        node* replacement_parent;

        if(!current->left || !current->right) {
            if(current->left) replacement = current->left;
            else replacement = current->right;

            *raiz = replacement;

            free(current);

            *changed = true;

            return;
        } else {
            replacement = biggest_key(current, &replacement_parent);
            current->key = replacement->key;
            ch = replacement->key;
        }
    }

    if (ch > current->key) {
        remove(&(current->right), ch, changed);

        printf("\nExcluir recursivo a direita: %i(%i)\n", current->key, current->balance_factor);

        if (*changed){
            switch (current->balance_factor){
                case 1:
                    current->balance_factor = 0;

                    return;
                case 0:
                    current->balance_factor = -1;
                    *changed = false;

                    return;
                case -1:
                    *raiz = left_rotation(current);

                    if (current->balance_factor != 0)
                        *changed = false;

                    return;
            }
        }
    }else{
        remove(&(current->left), ch, changed);

        printf("\nExcluir recursivo a esquerda: %i(%i)\n", current->key, current->balance_factor); 

        if (*changed){
            switch (current->balance_factor){
                case -1:
                    current->balance_factor = 0;

                    return;
                case 0:
                    current->balance_factor = 1;
                    *changed = false;

                    return;
                case 1:
                    *raiz = right_rotation(current);

                    if (current->balance_factor != 0)
                        *changed = false;

                    return;
            }
        }
    }
}


// 6 - Percursos na Árvore e Busca
// Nas árvores AVL, percursos e busca são idênticos aos das árvores de busca binária
node* binary_search(int key, node* root){
	if (root == NULL) return NULL;

	if (root->key == key) return root;

	if (root->key<key) 
		return binary_search(key, root->right);

	return binary_search(key, root->left);
}

// a. Pré Ordem: Visitamos primeiro a raiz, depois a subárvore esquerda e por fim a subárvore direita
void pre_order(node* n) {
    if(n) {
        printf(" %d", n->key);
        pre_order(n->left);
        pre_order(n->right);
    }
}

// b. Em Ordem: Visitamos toda a subárvore esquerda, depois a Raiz e por fim toda a subárvore direita
void in_order(node* n) {
    if(n) {
        in_order(n->left);
        printf(" %d", n->key);
        in_order(n->right);
    }
}

// c. Pós ordem: Visitamos toda a subárvore esquerda, depois a subárvore direita e por fim a raiz
void post_ordem(node* n) {
    if(n) {
        post_ordem(n->left);
        post_ordem(n->right);
        printf(" %d", n->key);
    }
}

int main() {
    tree t;
    bool changed;

    initialize(&t);

    insert(&(t.root), 29, &changed);
    printf("\nAlterou a árvore? %d", changed);
    changed = false;

    insert(&(t.root), 31, &changed);
    printf("\nAlterou a árvore? %d", changed);
    changed = false;

    insert(&(t.root), 54, &changed);
    printf("\nAlterou a árvore? %d", changed);
    changed = false;

    insert(&(t.root), 1, &changed);
    printf("\nAlterou a árvore? %d", changed);
    changed = false;

    insert(&(t.root), 10, &changed);
    printf("\nAlterou a árvore? %d", changed);
    changed = false;

    insert(&(t.root), 6, &changed);
    printf("\nAlterou a árvore? %d", changed);
    changed = false;

    printf("\nContagem de elementos: %d", count(t.root));
    printf("\nAltura da árvore: %d", height(t.root));
    printf("\nÉ AVL? %d", isAVL(t.root));

    printf("\n\nPercursos: ");

    printf("\nPré Ordem: ");
    pre_order(t.root);

    printf("\nEm Ordem: ");
    in_order(t.root);

    printf("\nPós Ordem: ");
    post_ordem(t.root);

    remove(&(t.root), 10, &changed);
    printf("\nAlterou a árvore? %d", changed);
    changed = false;

    remove(&(t.root), 54, &changed);
    printf("\nAlterou a árvore? %d", changed);
    changed = false;

    remove(&(t.root), 1000, &changed);
    printf("\nAlterou a árvore? %d", changed);
    changed = false;


    printf("\n\nContagem de elementos: %d", count(t.root));
    printf("\nAltura da árvore: %d", height(t.root));
    printf("\nÉ AVL? %d", isAVL(t.root));

    printf("\nÁrvore final: ");
    in_order(t.root);
}