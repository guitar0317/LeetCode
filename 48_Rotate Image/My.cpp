#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    //My
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int size = matrix.size();
        for(int i=0; i<size; i++){
            vector<int> v;
            for(int j=size-1; j>=0; j--){
                v.push_back(matrix[j][i]);
            }
          ans.push_back(v);
        }
        matrix = ans;

        for(auto a:matrix){
            for(auto b:a){
                cout << b << ", ";
            }
            cout << endl;
        }
    }

    //swap
    void rotate2(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int depth = n/2;

        for(int i=0; i<depth; i++){
            int len = n-2*i-1;
            int opp=n-1-i;
            for(int j=0; j<len; j++){
                int temp= matrix[i][i+j];
                matrix[i][i+j] = matrix[opp-j][i];
                matrix[opp-j][i] = matrix[opp][opp-j];
                matrix[opp][opp-j] = matrix[i+j][opp];
                matrix[i+j][opp] = temp;
            }
        }

        for(auto a:matrix){
            for(auto b:a){
                cout << b << ", ";
            }
            cout << endl;
        }
    }

     void rotate3(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[i].size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
        }
        PrintMatrix(matrix);
     }

     void PrintMatrix(vector<vector<int>>& matrix){
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
    sol.rotate3(matrix);

    cout << "===================================" << endl;
    matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    sol.rotate3(matrix);

}