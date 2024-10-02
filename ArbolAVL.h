#ifndef ARBOL_AED_ARBOLAVL_H
#define ARBOL_AED_ARBOLAVL_H

#include <iostream>

// Estructura del nodo AVL usando templates
template <typename T>
struct Node {
    T key;            // Clave del nodo (de tipo genérico)
    int height;       // Altura del nodo
    Node* left;       // Puntero al hijo izquierdo
    Node* right;      // Puntero al hijo derecho

    // Constructor para un nuevo nodo
    Node(T k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

// Función para obtener la altura de un nodo
template <typename T>
int height(Node<T>* node) {
    if (node == nullptr) return 0;
    return node->height;
}

// Función para calcular el factor de balance
template <typename T>
int getBalance(Node<T>* node) {
    if (node == nullptr) return 0;
    return height(node->left) - height(node->right);
}

// Rotación a la derecha
template <typename T>
Node<T>* rotateRight(Node<T>* y) {
    Node<T>* x = y->left;
    Node<T>* T2 = x->right;

    // Realizar la rotación
    x->right = y;
    y->left = T2;

    // Actualizar alturas
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    // Retornar la nueva raíz
    return x;
}

// Rotación a la izquierda
template <typename T>
Node<T>* rotateLeft(Node<T>* x) {
    Node<T>* y = x->right;
    Node<T>* T2 = y->left;

    // Realizar la rotación
    y->left = x;
    x->right = T2;

    // Actualizar alturas
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    // Retornar la nueva raíz
    return y;
}

// Función para balancear un nodo AVL
template <typename T>
Node<T>* balance(Node<T>* node) {
    int balanceFactor = getBalance(node);

    // Caso LL
    if (balanceFactor > 1 && getBalance(node->left) >= 0)
        return rotateRight(node);

    // Caso LR
    if (balanceFactor > 1 && getBalance(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Caso RR
    if (balanceFactor < -1 && getBalance(node->right) <= 0)
        return rotateLeft(node);

    // Caso RL
    if (balanceFactor < -1 && getBalance(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Función para insertar un nodo en el árbol AVL
template <typename T>
Node<T>* insert(Node<T>* node, T key) {
    // Inserción normal en un árbol binario de búsqueda
    if (node == nullptr)
        return new Node<T>(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    // Actualizar la altura de este nodo
    node->height = 1 + std::max(height(node->left), height(node->right));

    // Balancear el nodo
    return balance(node);
}

// Función para encontrar el nodo con el valor mínimo
template <typename T>
Node<T>* minValueNode(Node<T>* node) {
    Node<T>* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// Función para eliminar un nodo del árbol AVL
template <typename T>
Node<T>* remove(Node<T>* root, T key) {
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = remove(root->left, key);
    else if (key > root->key)
        root->right = remove(root->right, key);
    else {
        if (root->left == nullptr || root->right == nullptr) {
            Node<T>* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;

            delete temp;
        } else {
            Node<T>* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = remove(root->right, temp->key);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + std::max(height(root->left), height(root->right));

    return balance(root);
}

// Función para imprimir el árbol AVL en orden
template <typename T>
void inOrder(Node<T>* root) {
    if (root != nullptr) {
        inOrder(root->left);
        std::cout << root->key << " ";
        inOrder(root->right);
    }
}

#endif //ARBOL_AED_ARBOLAVL_H
