#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
       vector<vector<int>> res;
       if(v.size()<1) return res;

       sort(v.begin(),v.end());

       res.push_back(v[0]);

       for(int i=1; i<v.size(); i++){
         if(v[i][0] > res.back()[1]) res.push_back(v[i]);
         else res.back()[1] = max(res.back()[1], v[i][1]);
       }

       return res;
    }
};

int main(){
    vector<vector<int>> a = {{1,3},{2,6},{8,10},{15,18}};
    Solution s;
    vector<vector<int>> result = s.merge(a);
    for(auto a: result){
        for(auto b : a){
            cout << b << ", ";
        }
        cout <<endl;
    }
}