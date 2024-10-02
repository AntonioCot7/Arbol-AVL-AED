#include <iostream>
//#include "Arbol.h"
#include "ArbolAVL.h"

/*
const int NULL_NODE = -1;

void example1() {
    Node<int>* root = nullptr;

    root = insert(root, 3);
    root = insert(root, 9);
    root = insert(root, 20);
    root = insert(root, NULL_NODE);
    root = insert(root, NULL_NODE);
    root = insert(root, 15);
    root = insert(root, 7);

    std::cout << (isBalanced(root) ? "true" : "false") << std::endl;
}

void example2() {
    Node<int>* root = nullptr;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 3);
    root = insert(root, NULL_NODE);
    root = insert(root, NULL_NODE);
    root = insert(root, 4);
    root = insert(root, 4);

    std::cout << (isBalanced(root) ? "true" : "false") << std::endl;
}
*/

void exampleAVL() {
    Node<int>* root = nullptr;

    // Insertar elementos en el árbol AVL
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Imprimir el árbol en orden
    std::cout << "Árbol AVL en orden después de las inserciones: ";
    inOrder(root);
    std::cout << std::endl;

    // Eliminar elementos del árbol AVL
    root = remove(root, 40);
    root = remove(root, 50);

    // Imprimir el árbol en orden después de las eliminaciones
    std::cout << "Árbol AVL en orden después de las eliminaciones: ";
    inOrder(root);
    std::cout << std::endl;
}

int main() {
    //example1();
    //example2();
    exampleAVL();
    return 0;
}