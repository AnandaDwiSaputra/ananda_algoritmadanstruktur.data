#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = NULL;
    }

    Node* insert(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }
        if (value <= node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void inorder(Node* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == NULL) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void showTraversals() {
        cout << "Pre-order traversal  : ";
        preorder(root);
        cout << "\nIn-order traversal   : ";
        inorder(root);
        cout << "\nPost-order traversal : ";
        postorder(root);
        cout << endl;
    }
};

int main() {
    Tree tree;

    int values[] = {12, 16, 20, 24, 32};
    for (int i = 0; i < 5; i++) {
        tree.insert(values[i]);
    }

    tree.showTraversals();

    return 0;
}
