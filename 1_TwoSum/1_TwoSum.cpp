#include <iostream>
using namespace std;
#include <vector>

vector<int> TwoSum(vector<int> &nums, int target){
    vector<int> result;

    for(int i=0; i<nums.size()-1; i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[i]+nums[j]==target){
                result.push_back(i);
                result.push_back(j);
                break;
            }
        }
    }
    return result;
}

int main(){
    vector<int> nums = {2,7,11,15};
    /*nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);*/
    int target = 9;

    //vector<int> result;

    /*for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[i]+nums[j]==target){
                result.push_back(i);
                result.push_back(j);
                break;
            }
        }
    }*/
    vector<int> result = TwoSum(nums, target);
    for(int i=0; i<result.size(); i++){
        cout << result[i] << endl;
    }
}