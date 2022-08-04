#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main(){
    //vector<int> nums = {100,4,200,1,3,2};
    //vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    vector<int> nums = {1,0,1,2};
     if(nums.size()<1) return 0;
    sort(nums.begin(), nums.end());
    int count =1, i=0, result=0;
    while(i<nums.size()-1){
        if(nums[i+1]-nums[i]==1){
            count++;
        }else if(nums[i+1]-nums[i]>1){
            count=1;   
        }
        result = max(result,count);
        i++;
    }
    result = max(result,count);
    cout<<result;
    
}