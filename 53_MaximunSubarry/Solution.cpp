#include <iostream>
#include <vector>
using namespace std;

int Brute(vector<int>& nums){
    int n= nums.size(), ans=INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=i, sum=0; j<n; j++){
            sum+=nums[j];
            ans= max(ans,sum);
        }
    }

    return ans;
}

int DP(vector<int>& nums){
    vector<vector<int>> dp(2, vector<int>(nums.size()));
    dp[0][0]=dp[1][0]=nums[0];
    for(int i=1; i<nums.size(); i++){
        dp[1][i] = max(nums[i],nums[i]+dp[1][i-1]);
        dp[0][i] = max(dp[0][i-1], dp[1][i]);
    }
    int result = dp[0].back();
    return result;
}

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << Brute(nums)<<endl;

    cout << DP(nums) << endl;
}