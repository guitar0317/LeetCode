#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//TC: O(nlogn) ->sort

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()<=1) return 0;

        sort(intervals.begin(), intervals.end(), [](const auto& l, const auto & r){
            return l[1]<r[1];
        });

        int preIindex=0;
        int earseCount=0;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[preIindex][1]> intervals[i][0]) earseCount++;
            else preIindex =i;
        }

        return earseCount;
    }
};

int main(){
    vector<vector<int>> intervals= 
    //{{1,2},{2,3},{3,4},{1,3},{1,4}};
    {{1,100},{11,22},{1,11},{2,12}};
    Solution sol;
    cout << sol.eraseOverlapIntervals(intervals);
}