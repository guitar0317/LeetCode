#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m=3,n=7;

    vector<int> dp(n,1);
    for(int i=1;i<m; i++){
        for(int j=1; j<n; j++){
            dp[j]+=dp[j-1];
        }
    }

    cout << dp[n-1];
}