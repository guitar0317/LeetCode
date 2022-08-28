#include <iostream>
#include <vector>
using namespace std;

//TC:O(n), SC:O(n)
void solutionA(vector<int>& nums){
int n = nums.size();
    vector<int> prifix(n,1);
    vector<int> suffix(n,1);

    for(int i=1; i<n; i++){
        prifix[i] = prifix[i-1]*nums[i-1];
        suffix[i] = suffix[i-1]*nums[n-i];
    }

    vector<int> res(n);
    for(int i=0; i<n; i++){
        res[i] = prifix[i]*suffix[n-1-i];
    }

    for(auto a:res){
        cout << a <<", ";
    }
}

//TC:O(n), SC:O(1)
void solutionB(vector<int>& nums){
    int n = nums.size();
    int pre=1, suf=1;
    vector<int> res(n,1);

    for(int i=0; i<n; i++){
        res[i]*=pre;
        pre*=nums[i];
        res[n-1-i]*=suf;
        suf *= nums[n-1-i];
    }

      for(auto a:res){
        cout << a <<", ";
    }
}

int main(){
    vector<int> nums = 
    {1,2,3,4};
    //{-1,1,0,-3,3};

    solutionA(nums);
    cout << endl;
    solutionB(nums);
}