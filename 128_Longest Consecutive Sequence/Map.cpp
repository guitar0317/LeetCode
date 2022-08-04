#include#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>

int main(){
    //vector<int> nums = {100,4,200,1,3,2};
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    //vector<int> nums = {1,0,1,2};
    if(nums.size()<1) return 0;
    unordered_set<int> set;

    for(int a : nums){
        set.insert(a);
    }

    int longestStreak =0, currentStreak=0;
    unordered_set<int>  :: iterator itr;
    for(itr = set.begin(); itr!=set.end(); itr++){
        if(set.find(*itr-1)==set.end(){
            //current element can be the starting point of the sequence.

        })
    }
}