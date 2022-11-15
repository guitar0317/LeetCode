#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
       int i=0;
        int n = nums.size();
        for(int reach =0; i < n && i<=reach; i++){
            reach=max(i+nums[i], reach);
        }
        return i==n;
    }

     bool canJump2(vector<int>& nums) {
        int dis = 0;
        for (int i = 0; i <= dis; i++) {
             dis = max(dis, i + nums[i]);
        if (dis >= nums.size()-1) {
            return true;
        }
        }
        return false;
        }

    bool canJump3(vector<int>& nums){
        int dis=0, size=nums.size();
        for(int i=0; i<size; i++)
        {
            if(i>dis)
                return false;
            if(dis>size)
                return true;
            
            dis = max(dis, i+nums[i]);
        }

        return true;
    }
};

int main(){
    vector<int> n = {2,3,1,1,5};
    //vector<int> n ={3,2,1,0,4};
    //vector<int> n ={2};
    Solution s;
    string result = s.canJump(n) ? "True":"False";
    cout<<result<<endl;
    result = s.canJump2(n) ? "True":"False";
    cout<<result<<endl;
    result = s.canJump3(n) ? "True":"False";
    cout<<result<<endl;
}