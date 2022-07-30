#include <iostream>
using namespace std;
#include <vector>
#include <set>
//AdditionMermory apporach: TC: O(M*N), SC: O(M+N)
 void setZeroes(vector<vector<int>>& m) {
        int R = m.size();
        int C = m[0].size();
        set<int> rows;
        set<int> cols;
// We mark the rows and columns that are to be made zero
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(m[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        // Iterate over the array once again and using the rows and cols sets, update the elements.
        for(int i =0; i<R; i++){
            for(int j=0; j<C; j++){
                if(rows.count(i) || cols.count(j)){
                    m[i][j] = 0;
                    //cout << m[i][j] << ", ";
                }
                cout << m[i][j] << ", ";
            }
            cout<<endl;
        }
}

int main(){
    //vector<vector<int>> m = {{1,1,1},{1,0,1},{1,1,1}};
vector<vector<int>> m = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(m);
}