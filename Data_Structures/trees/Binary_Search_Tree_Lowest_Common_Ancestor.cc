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

class Solution {
    public:
  		// Node* insert(Node* root, int data) {
        //     if(root == NULL) {
        //         return new Node(data);
        //     } else {
        //         Node* cur;
        //         if(data <= root->data) {
        //             cur = insert(root->left, data);
        //             root->left = cur;
        //         } else {
        //             cur = insert(root->right, data);
        //             root->right = cur;
        //        }

        //        return root;
        //    }
        // }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  
    Node *lca(Node *root, int v1,int v2) {
		// Write your code here.

        // Since this is a Binary Search Tree, we'd employ a variant of the
        // binary search to traverse the BST in O(log n) time in order to
        // find the common ancestor between v1 and v2

        // The intuition is, if both v1 and v2 are greater than the root node,
        // then they'll lie on the right subtree and we continue our search
        // there... else, if they're both lesser than the value of the root
        // node, then they'd lie on the left subtree

        // At any point, if one of them is greater that a particular ancestor
        // while the other is lesser than that same ancestor, that ancestor is
        // actually common between them OR in the case where they lie on the same 
        // path, the one that preceeds the other becomes the common ancestor
        // between them

        while(root) {
            if (v1 > root->data && v2 > root->data) {
                root = root->right;
            } else if (v1 < root->data && v2 < root->data) {
                root = root->left;
            } else {
                return root;
            }
        }
        return nullptr;
    }

}; //End of Solution

// int main() {
  
//     Solution myTree;
//     Node* root = NULL;
    
//     int t;
//     int data;

//     std::cin >> t;

//     while(t-- > 0) {
//         std::cin >> data;
//         root = myTree.insert(root, data);
//     }
  	
//   	int v1, v2;
//   	std::cin >> v1 >> v2;
  
//     Node *ans = myTree.lca(root, v1, v2);
    
//   	std::cout << ans->data;

//     return 0;
// }
