#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void dfs(vector<vector<int>>& adjList, stack<int>& st, vector<bool>& vis, int u) {
   vis[u] = true; 
   
   for(int v: adjList[u]) {
       if(!vis[v]) dfs(adjList, st, vis, v);
   }

   st.push(u);
}

vector<int> toposort(vector<vector<int>> adjList) {
    int n = adjList.size();
    vector<int> sort;
    vector<bool> vis(n, false);
    stack<int> st;

    for(int i = 0; i < n; i++) {
        if(!vis[i])
            dfs(adjList, st, vis, i);
    } 

    while(!st.empty()) {
        sort.push_back(st.top());
        st.pop();
    }

    return sort;
}

int main() {

}

