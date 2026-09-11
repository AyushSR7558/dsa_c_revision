#include<bits/stdc++.h>

using namespace std;

vector<int> toposort(vector<vector<int>> adjList) {
    int n = adjList.size();
    vector<int> inorder(n, 0), sort;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < adjList[i].size(); j++) {
            int v = adjList[i][j];
            inorder[v]++;
        }
    }

    queue<int> q;
    
    for(int i = 0; i < n; i++) 
        if(!inorder[i]) q.push(i);

    while(!q.empty()) {
        int u = q.front();
        sort.push_back(u);
        q.pop();

        for(int v: adjList[u]) {
            inorder[v]--;
            if(!inorder[v]) q.push(v);
        }
    }

    return sort;

}

int main() {

}
