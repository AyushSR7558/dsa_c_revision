#include<bits/stdc++.h>

using namespace std;

class Solution {
    private:
        string bfs(vector<vector<int>>& adjlist, vector<bool>& isValid) {
           vector<int> inDegree(26, 0);

           for(int i = 0; i < 26; i++) {
               if(!isValid[i]) continue;
               for(int j = 0; j < adjlist[i].size(); j++) {
                   inDegree[adjlist[i][j]]++;
               }
           }

           queue<int> q;
           vector<int> topoSort;

           for(int i = 0; i < 26; i++) {
               if(isValid[i] && inDegree[i] == 0)
                   q.push(i);
           }

           while(!q.empty()) {
               int u = q.front();
               q.pop();
               topoSort.push_back(u);
            
               for(int v: adjlist[u]) {
                   inDegree[v]--;
                   if(inDegree[v] == 0) q.push(v);
               }
           }
           int validCnt = 0;

           for(int i = 0; i < 26; i++) {
                if(isValid[i]) validCnt++;
           }


           if(validCnt != topoSort.size()) return "";

           string s = "";
           for(int i = 0; i < topoSort.size(); i++) {
               s += (topoSort[i] + 'a');
           }

           return s;
        }
	public:
	string findOrder(vector<string> &words) {
        int n = words.size();
        vector<bool> isValid(26, false);
        vector<vector<int>> adjlist(26);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < words[i].size(); j++) {
                isValid[words[i][j] - 'a'] = true;
            }
        }


        for(int i = 0; i < n - 1; i++) {
            int currWordSize = words[i].size(), nextWordSize = words[i + 1].size();
           
           int p = 0, q = 0;

           while(p < currWordSize && q < nextWordSize && words[i][p] == words[i + 1][q]) {
               p++;
               q++;
           }
          
           if((p < currWordSize)) {
                adjlist[words[i][p] - 'a'].push_back(words[i + 1][q] - 'a');
           } 
        }
       
       return bfs(adjlist, isValid);
	}
};


int main() {
    int n; 
    cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; i++) {
       cin >> words[i];
    }
    Solution s;
    cout << s.findOrder(words);
}
