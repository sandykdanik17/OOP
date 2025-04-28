#include <iostream>
#include <windows.h>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;
    Node(T value) : data(value), left(NULL), right(NULL) {}
};

template <typename T>
class BinaryTree {
    Node<T>* root;
public:
    BinaryTree() : root(NULL) {}

    void insert(T value) { root = insertRec(root, value); }

    Node<T>* getRoot() const { return root; }

private:
    Node<T>* insertRec(Node<T>* node, T value) {
        if (node == NULL) return new Node<T>(value);
        if (value < node->data)
            node->left = insertRec(node->left, value);
        else
            node->right = insertRec(node->right, value);
        return node;
    }
};

template <typename T>
class TreeIterator {
    Node<T>* stack[100]; 
    int top;
public:
    TreeIterator(Node<T>* root) {
        top = -1;
        pushLeft(root);
    }

    bool hasNext() {
        return top != -1;
    }

    T next() {
        Node<T>* current = stack[top--];
        T value = current->data;
        if (current->right != NULL) {
            pushLeft(current->right);
        }
        return value;
    }

private:
    void pushLeft(Node<T>* node) {
        while (node != NULL) {
            stack[++top] = node;
            node = node->left;
        }
    }
};

void testBinaryTree() {
    BinaryTree<int> tree;
    int n, value;
    cout << "Скільки елементів додати у дерево? ";
    cin >> n;
    cout << "Введіть " << n << " елементів:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }

    cout << "Обхід дерева (через ітератор):\n";
    TreeIterator<int> it(tree.getRoot());
    while (it.hasNext()) {
        cout << it.next() << " ";
    }
    cout << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Завдання 4.1\n";
    testBinaryTree();
    return 0;
}
