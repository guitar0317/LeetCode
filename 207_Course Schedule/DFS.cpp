#include <iostream>
using namespace std;
#include <vector>

class Solution{
public: 
    bool canFinish(int n, vector<vector<int>>& pre){
        vector<int> adj[n];
        for(auto edge: pre){
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n,0);

        for(int i=0; i<n; i++){
            if(isCycle(adj, vis, i));
                return false;
        }

        return true;
    }

    bool isCycle(vector<int> adj[], vector<int>& vis, int id){
        if(vis[id]==1) return true;
        if(vis[id]==0){
            vis[id]=1;
            for(auto edge: adj[id]){
                if(isCycle(adj, vis, edge))
                    return true;
            }
        }

        vis[id]=2;
        return false;
    }

};

int main(){
    int n =2;
    vector<vector<int>> preq={{1,0}};
    Solution sol;
    cout << sol.canFinish(n, preq);
}