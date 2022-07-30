#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> matrix){
 vector<vector<int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
            vector<int> res;
            int nr = matrix.size();
            if(nr==0) return res;
            int nc = matrix[0].size();
            if(nc==0) return res;
            
            vector<int> Step{nc,nr-1};
            
            int iDir=0;
            int ir=0, ic=-1;
            while(Step[iDir%2]){
                for(int i=0; i<Step[iDir%2]; i++){
                    ir+=dirs[iDir][0];
                    ic+=dirs[iDir][1];
                    res.push_back(matrix[ir][ic]);
                }
                Step[iDir%2]--;
                iDir = (iDir+1)%4;
            }
        
        return res;
}

int main(){
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};

    vector<int> res = spiralOrder(matrix);

    for(int r:res){
        cout << r << ", ";
    }

}