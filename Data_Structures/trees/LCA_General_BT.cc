#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

Node* lcaBT(Node* root, int v1, int v2) {
    if (!root) return nullptr;

    if (root->data == v1 || root->data == v2) return root;

    Node* left = lcaBT(root->left, v1, v2);
    Node* right = lcaBT(root->right, v1, v2);

    if (left && right) return root;
    if (right) return right;
    else return left;

}