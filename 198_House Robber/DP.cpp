#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
//TC: O(n), SC:O(n)
int rob(vector<int>& A, vector<int>& dp, int i){
    if(i >= A.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    return dp[i] = max(rob(A,dp,i+1), A[i]+rob(A,dp,i+2));
}

int main(){
    vector<int> n = {2,7,9,3,1};
    //vector<int> n = {1,2,3,1};

    vector<int> dp(n.size(), -1);

    cout << rob(n,dp,0);

}