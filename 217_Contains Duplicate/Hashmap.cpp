#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    vector<int> nums = 
    //{1,2,3,1};
    {1,2,3,4};

    unordered_map<int,int> mp;
    for(int i=0; i<nums.size(); i++){
        if(mp[nums[i]] != NULL){
            cout<< "true";
            return 0;
            }
        else mp[nums[i]] = 1;
    }
    cout << "false";
}