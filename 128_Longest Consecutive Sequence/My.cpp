#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main(){
    vector<int> nums = {100,4,200,1,3,2};
    sort(nums.begin(), nums.end());
    int count =1, i=0;
    while(i<nums.size()){
        if(nums[i+1]-nums[i]==1){
            count++;
        }else{
            count=1;
        }
        i++;
    }

    cout<<count;
    
}