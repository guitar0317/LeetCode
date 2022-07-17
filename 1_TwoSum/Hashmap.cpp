#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> TwoSum(vector<int> &nums, int target){
    vector<int> result;
    unordered_map<int,int> m;

    for(int i=0; i< nums.size(); i++){
        int com = target - nums[i];
        if(m.find(com) != m.end()){
            result.push_back(i);
            result.push_back(m[com]);
            return result;
        }
       // m[nums[i]] = i;
        m.insert(make_pair(nums[i],i));
    }
      return result;
}

int main(){
//vector<int> nums = {2,7,11,15};
vector<int> nums = {3,2,4};
    int target = 6;
    vector<int> result = TwoSum(nums, target);
    for(int i=0; i<result.size(); i++){
        cout << result[i] << endl;
    }

}