#include <iostream>
//#include <iomanip>

using namespace std;

// Classe que define um nó da Árvore Binária de Busca
class TreeNode {
private:
    int data;             // Valor inteiro do nó
    TreeNode* left;       // Ponteiro para o filho esquerdo
    TreeNode* right;      // Ponteiro para o filho direito

    // Função auxiliar para encontrar o nó com menor valor na subárvore
    // Utilizada no caso 3 da deleção (quando há dois filhos)
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        // Continua indo para a esquerda até encontrar o menor valor
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

public:
    // Construtor que inicializa o nó com um valor e filhos nulos
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}

    // Destrutor para liberar recursivamente os nós filhos
    ~TreeNode() {
        delete left;   // chama recursivamente os destrutores
        delete right;
    }

    // Insere 'new_data' na posição correta, mantendo as regras de BST:
    // valores menores à esquerda, valores maiores ou iguais à direita
    void insert(int new_data) {
        if (new_data < data) {
            if (left == nullptr)
                left = new TreeNode(new_data);
            else
                left->insert(new_data);
        } else {
            if (right == nullptr)
                right = new TreeNode(new_data);
            else
                right->insert(new_data);
        }
    }

    // Exibe a árvore de forma hierárquica:
    // A lógica utiliza prefixos (indentação) e caracteres especiais
    // para mostrar a árvore no console
    void printTree(const string& prefix = "", bool isLeft = true) {
        // Caso exista filho à direita, chama recursivamente para ele
        if (right)
            right->printTree(prefix + (isLeft ? "│   " : "    "), false);

        // Exibe o prefixo (indentação) e o tipo de aresta (└── ou ┌──)
        cout << prefix;
        cout << (isLeft ? "└── " : "┌── ");
        cout << data << endl;

        // Caso exista filho à esquerda, chama recursivamente para ele
        if (left)
            left->printTree(prefix + (isLeft ? "    " : "│   "), true);
    }

    // Percurso em Pré-Ordem (Root, Left, Right):
    // Exibe o valor do nó, percorre a subárvore esquerda e depois a direita
    void preOrder() {
        cout << data << " ";
        if (left) left->preOrder();
        if (right) right->preOrder();
    }

    // Percurso em Ordem (Left, Root, Right):
    // Visita primeiro a subárvore esquerda, depois o nó e em seguida a direita
    void inOrder() {
        if (left) left->inOrder();
        cout << data << " ";
        if (right) right->inOrder();
    }

    // Percurso em Pós-Ordem (Left, Right, Root):
    // Visita primeiro a subárvore esquerda, depois a direita e, por fim, o nó
    void postOrder() {
        if (left) left->postOrder();
        if (right) right->postOrder();
        cout << data << " ";
    }

    // Busca um valor 'key' na árvore:
    // Retorna 'true' se encontrado, ou 'false' caso contrário
    bool search(int key) {
        if (data == key)
            return true;
        if (key < data && left)
            return left->search(key);
        if (key > data && right)
            return right->search(key);
        return false;
    }

    // Calcula a altura da árvore, retornando
    // a maior profundidade entre os sub-ramos
    int height() {
        int leftHeight = left ? left->height() : 0;
        int rightHeight = right ? right->height() : 0;
        return 1 + max(leftHeight, rightHeight);
    }

    // Exclui um nó com o valor 'key' da árvore, mantendo as regras da BST.
    // Casos de deleção:
    //  1. Nó folha (sem filhos)
    //  2. Nó com apenas um filho (esquerdo ou direito)
    //  3. Nó com dois filhos (troca pelo sucessor ou predecessor e deleta o substituído)
    TreeNode* deleteNode(int key) {
       

        // Retorna o ponteiro atual (em caso de não remoção)
        return this;
    }

    // Libera recursivamente todos os nós da subárvore
    // transformando o nó atual em uma árvore vazia
    void clear() {
        
    }

    // Retorna o valor mínimo da árvore
    int getMin() {
        return 0;
    }

    // Retorna o valor máximo da árvore
    int getMax() {
        return 0;
    }

    // Retorna a contagem total de nós na subárvore
    int countNodes() {
        
        return 0;
    }

    // Retorna a contagem de folhas (nós sem filhos)
    int countLeaves() {
       return 0; 
    }
};

int main() {
   

    return 0;
}
