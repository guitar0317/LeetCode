#include <iostream>
#include <vector>
using namespace std;
//Optimal approach: TC: O(M*N) SC: O(1)
void setZeroes(vector<vector<int>>& matrix) {
    bool RowZero = false;
    bool ColZero = false;
    for(int i =0; i<matrix[0].size(); i++){ //check the first row
        if(matrix[0][i] ==0){
            RowZero = true;
            break;
        }
    }

    for(int i=0; i<matrix.size(); i++){ //check the first column
        if(matrix[i][0]==0){
            ColZero=true;
            break;
        }
    }

    for(int i=1; i<matrix.size(); i++){  //check except the first row and column
        for(int j=1; j<matrix[0].size(); j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }
    
    for(int i=1; i<matrix.size(); i++){ //process except the first row and column 
        for(int j=1; j<matrix[0].size(); j++){
            if(matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j]=0;
            }
        }
    }
    
    if(RowZero){ //handle the first row
        for(int i=0; i<matrix[0].size(); i++){
            matrix[0][i]=0;
        }
    }

    if(ColZero){ //handle the first column
         for(int i=0; i<matrix.size(); i++){
            matrix[i][0]=0;
        }
    }

    for(auto a: matrix){
        for(auto b : a){
            cout << b << ", ";
        }
        cout << endl;
    }

}

int main(){
    vector<vector<int>> m = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(m);
}