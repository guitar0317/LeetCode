#include <iostream>
#include <vector>
using namespace std;

vector<int> TwoSum(vector<int> &nums, int target){
    int left=0, right = nums.size()-1;
        vector<int> result;
        while(right>=left){
            if(nums[left]+ nums[right] == target){
                result.push_back(left);
                result.push_back(right);
                return result;
            }else if(nums[left]+ nums[right] > target) right--;
            else left++;
        }
        
        return result;
}

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> result = TwoSum(nums, target);
    for(int i=0; i<result.size(); i++){
        cout << result[i] << endl;
    }
}