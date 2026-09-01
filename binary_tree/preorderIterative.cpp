#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode {
    struct TreeNode* left;
    struct TreeNode* right;
    int val;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
} TreeNode;

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> preorder;
    // We will stack first 
    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        preorder.push_back(node -> val);

        if(node -> right)
            st.push(node -> right);

        if(node -> left) 
            st.push(node -> left);
    }

    return preorder;
}

int main() {
    TreeNode root(1), left(2), right(3);
    root.left = &left;
    root.right = &right;
    vector<int> preOrder;
    preOrder = preorderTraversal(&root);
    int n = preOrder.size();
    for(int i = 0; i < n; i++) {
        cout << preOrder[i] << " ";
    }
}

