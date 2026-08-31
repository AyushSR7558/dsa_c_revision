#include<bits/stdc++.h>
#include "node.h"
using namespace std;

void levelOrderTraversal(vector<vector<int>>& arr, int level, Node* head) {
    while(arr.size() <= level) {
        arr.push_back({});
    }

    arr[level].push_back(head -> val);

    if(head -> left)
        levelOrderTraversal(arr, level + 1, head -> left);
    if(head -> right) 
        levelOrderTraversal(arr, level + 1, head -> right);
}

void levelOrderTraversalIterative(vector<vector<int>>& arr, Node* head) {
    queue<Node*> q;
    q.push(head);
    int level = 0;

    while(!q.empty()) {
        int sz = q.size();
        arr.push_back({});
        for(int i = 0; i < sz; i++) {
            Node* node = q.front();
            q.pop();
           arr[level].push_back(node -> val);

           if(node -> left) q.push(node -> left);
           if(node -> right) q.push(node -> right);
        }
        level++;
    }
}

int main() {
    Node root(1), left(2), right(3);
    vector<vector<int>> arr; 

    root.left = &left;
    root.right = &right;

    left.left = new Node(4);
    left.right = new Node(5);
    right.left = new Node(6);
    right.right = new Node(7);

    levelOrderTraversalIterative(arr, &root);

    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }   
}
