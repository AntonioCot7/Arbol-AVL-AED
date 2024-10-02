#ifndef ARBOL_AED_ARBOL_H
#define ARBOL_AED_ARBOL_H

#include <iostream>
using namespace std;

template<typename T>
struct Node {
    T data;
    Node* left;
    Node* right;

    Node(T val) : data(val), left(nullptr), right(nullptr) {}
};

// Función para insertar un valor en el árbol
template<typename T>
Node<T>* insert(Node<T>* node, T value) {
    if (node == nullptr) {
        return new Node<T>(value);
    }
    if (value < node->data) {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }
    return node;
}

// Función para buscar un valor en el árbol
template<typename T>
bool search(Node<T>* node, T value) {
    if (node == nullptr) {
        return false;
    }
    if (value < node->data) {
        return search(node->left, value);
    } else if (value > node->data) {
        return search(node->right, value);
    } else {
        return true;
    }
}

// Función para encontrar el valor mínimo de un subárbol
template<typename T>
Node<T>* findMin(Node<T>* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Función para eliminar un valor del árbol
template<typename T>
Node<T>* remove(Node<T>* node, T value) {
    if (node == nullptr) {
        return nullptr;
    }

    if (value < node->data) {
        node->left = remove(node->left, value);
    } else if (value > node->data) {
        node->right = remove(node->right, value);
    } else {
        // Nodo encontrado
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        } else if (node->left == nullptr) {
            Node<T>* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node<T>* temp = node->left;
            delete node;
            return temp;
        } else {
            Node<T>* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
    }
    return node;
}

// Función para calcular la altura de un árbol
template<typename T>
int height(Node<T>* node) {
    if (node == nullptr) {
        return -1;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return max(leftHeight, rightHeight) + 1;
}

// Función para verificar si un árbol está balanceado
template<typename T>
bool isBalanced(Node<T>* node) {
    if (node == nullptr) {
        return true;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return abs(leftHeight - rightHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right);
}

#endif //ARBOL_AED_ARBOL_H
