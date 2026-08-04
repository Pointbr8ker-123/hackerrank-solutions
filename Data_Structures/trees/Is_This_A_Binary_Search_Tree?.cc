#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	
	Node() {
		this->data = -1;
		this->left = NULL;
		this->right = NULL;
	}
};
	
class Tree {
	
public:
	// List of node data values:
	std::vector<int> values;
	// Total number of nodes in the tree:
	int count;


	Tree() {
		this->count = 0;
	}
#include <climits>
/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
	typedef long long ll;
    bool checkHelper(Node* root, ll mini, ll maxi) {
        if (!root) return true;
        if (!(root->data < mini && root->data > maxi)) return false;
        return checkHelper(root->left, mini, root->data) &&
               checkHelper(root->right, root->data, maxi);
    }
    
    bool checkBST(Node* root) {
        return checkHelper(root, LLONG_MIN, LLONG_MAX);
    }

// 	void inOrder (Node* root, int levels) {

// 		if(root != NULL) {
// 			// If there are still unfilled levels, fill left subtree:
// 			if (levels > 0) {
// 				// Create a new left child node:
// 				root->left = new Node();
// 				inOrder(root->left, levels - 1);
// 			}    
			
// 			// Set node data:
// 			root->data = values.at(count);
// 			count++;
			
// 			// If there are still unfilled levels, fill right subtree:
// 			if (levels > 0) {
// 				// Create a new right child node:
// 				root->right = new Node();
// 				inOrder(root->right, levels - 1);
// 			}
// 		}
// 	}

};

// int main(int argc, char *argv[]) {
// 	int height;
// 	cin >> height;
	
// 	// Read data values for tree's nodes:
// 	Tree* tree = new Tree();
// 	int value;
// 	while (cin >> value){
// 		tree->values.push_back(value);
// 	}
		
// 	// Fill tree:
// 	Node* root = new Node(); 
// 	tree->inOrder(root, height);
	
// 	// Print result:
// 	if(tree->checkBST(root) == true) {
// 		cout << "Yes";
// 	}
// 	else {
// 		cout << "No";
// 	}
// }
