#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void ThreeSum(vector<int>& num){
    vector<vector<int>> res;
    int n = num.size();
    sort(num.begin(),num.end());

    for(int i=0; i<n; i++){
        if(i>0){
            while(i<n && num[i]==num[i-1]){
                ++i;
            }
        }

        int j=i+1, k=n-1;
        while(j<k){
            if(num[i]+num[j]+num[k] == 0) {
                res.push_back({num[i],num[j],num[k]});
                ++j;
                --k;
                while(j<n && num[j]==num[j-1]){
                    ++j;
                }
                
                while(k>=0 && num[k]==num[k+1]){
                    --k;
                }
            }else if(num[i]+num[j]+num[k] > 0) --k;
            else ++j;
        }     
    }

     for(int a=0; a<res.size(); a++){
            for(int b=0; b< res[a].size();b++){
                cout << res[a][b] << ", ";
            }
            cout<<endl;
        }
        return;
}

int main(){
    vector<int> num = {-1,0,1,2,-1,-4};
    ThreeSum(num);
    cout<< "================================" <<endl;
    num = {0,1,1};
    ThreeSum(num);
    cout<< "================================" <<endl;
    num = {0,0,0};
    ThreeSum(num);
}