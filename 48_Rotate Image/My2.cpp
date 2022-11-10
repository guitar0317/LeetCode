#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    //My
    void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> temp;
        for(int j=0; j<c; j++){
             for(int i=r-1; i>=0; i--){
               temp.push_back(matrix[i][j]);
            }
            matrix.push_back(temp);
        }

        matrix.erase(matrix.begin()+2);

        for(auto a:matrix){
            for(auto b:a){
                cout << b << ", ";
            }
            cout << endl;
        }
    }  
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    sol.rotate(matrix);

}