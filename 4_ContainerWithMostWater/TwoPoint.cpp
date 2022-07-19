#include <iostream>
using namespace std;
#include <vector>

class WaterContainer{
public:
	int maxArea(vector<int>& height) {
		int result=0;
		if(height.size()<1) return 0;
		
		int left =0, right=height.size()-1;
		
		while(left < right){
			int width = right - left;
			
			result = max(result, min(height[left], height[right])*width );
			
			if(height[left] <=  height[right]) left++;
			else right--;
		}
		
		return result; 
	}

};

int main(){
	//vector<int> height = {1,8,6,2,5,4,8,3,7};
    vector<int> height = {1,1};
    WaterContainer water;
	cout << water.maxArea(height) <<endl;
}