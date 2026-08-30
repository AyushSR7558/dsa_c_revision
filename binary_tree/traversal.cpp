#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/**
 * Given the root of the binary tree find the preorder, inorder, postorder of the binary tree
 * preorder => root left right
 * inorder => left root right
 * postorder => left right root
*/

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;

    Node(int val) {
       this -> val = val; 
       this -> left = NULL;
       this -> right = NULL;
    }
} Node;

void traversal(vector<int>& preOrder, vector<int>& inOrder, vector<int>& postOrder, Node* root) {
    int curr_val = root -> val; 
    preOrder.push_back(curr_val); 
    if(root -> left != NULL)
        traversal(preOrder, inOrder, postOrder, root -> left);
    inOrder.push_back(curr_val);
    if(root -> right != NULL)
        traversal(preOrder, inOrder, postOrder, root -> right);
    postOrder.push_back(curr_val);
}

int main() {
    Node root(1), left(2), right(3);
    root.left = &left;
    root.right = &right; 
    vector<int> preOrder, inOrder, postOrder;
    traversal(preOrder, inOrder, postOrder, &root);
    int n = preOrder.size();
    for(int i = 0; i < n; i++) {
        cout << preOrder[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        cout << inOrder[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        cout << postOrder[i] << " ";
    }
}

