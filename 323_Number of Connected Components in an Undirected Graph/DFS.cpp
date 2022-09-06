#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& g, vector<bool>& v, int i){
    if(v[i]) return;
    v[i] = true;
    for(int j=0; j<g[i].size(); j++){
        dfs(g,v,g[i][j]);
    }
}

int countComponents(int n, vector<pair<int,int>>& edge){
    int res = 0;
    vector<vector<int>> g(n);
    vector<bool> v(n,false);

    for(auto a:edge){
        g[a.first].push_back(a.second);
        g[a.second].push_back(a.first);
    }

    for(int i=0; i<n; i++){
        if(!v[i]){
            ++res;
            dfs(g,v,i);
        }
    }

    return res;
}

int main(){
    vector<pair<int,int>> edge = {{0, 1}, {1, 2}, {3, 4}};
    int n=5;
    cout << countComponents(n, edge) << endl;

    edge =  {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
     n=5;
    cout << countComponents(n, edge) << endl;
    
}