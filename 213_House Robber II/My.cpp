#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int rob(vector<int>& nums){
        int n = nums.size();
        if(n<2) return n? nums[0]:0;
        return max(robber(nums, 0, n-2), robber(nums, 1, n-1));
    }

    int robber(vector<int>& nums, int l, int r){
        int pre=0, cur=0;
        for(int i=l; i<=r; i++){
            int temp = max(pre+nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};

int main(){
    vector<int> nums=
    //{2,3,2};
    {1,2,3,1};
    //{1,2,3};
    Solution sol;
    cout << sol.rob(nums);
}