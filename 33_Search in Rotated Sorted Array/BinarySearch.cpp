//Binary search. TC:O(log n)
#include <iostream>
using namespace std;
#include <vector>

class Solution{
public:
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
		
		while(left<=right){
			int mid = (left + right)/2;
			
			if(nums[mid]==target) return mid;
			
			if(nums[left] <= nums[mid]){
				if(target >= nums[left] && target < nums[mid]){
					right = mid-1;
				}else{
					left = mid+1;
				}
			}else{
				if(target > nums[mid] && target <= nums[right]){
					left = mid+1;
				}else{
					right = mid-1;
				}
			}
		}
		
		return -1;
    }
};

int main(){
	vector<int> n = {4,5,6,7,0,1,2};
    //vector<int> n = {3,1};
	int target = 1;
	Solution sol;
	cout << sol.search(n, target);
}

