#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if(intervals.size()<1){
            res.push_back(newInterval);
            return res;
        }
        
        /*sort(intervals.begin(), intervals.end());
        if(intervals[0][1] >= newInterval[0]){
            intervals[0][1] = max(intervals[0][1],newInterval[1] );
        }
        res.push_back(intervals[0]);*/
        bool isInsert = false;
        
        for(int i=0; i<intervals.size()-1; i++){
            if(intervals[i+1][0] <= intervals[i][1]){
                intervals[i][1] = max(intervals[i][1] ,intervals[i+1][1]);
                if(newInterval[0] <= res.back()[1] && isInsert==false ){
                     res.back()[1] = max(res.back()[1] ,newInterval[1]);
                    isInsert = true;
                }
            }else{
                if(intervals[i][1] > newInterval[0] && isInsert==false){
                    intervals[i][1] = max(intervals[i][1], newInterval[1]);
                    //res.push_back(newInterval);
                    isInsert = true;
                }
                res.push_back(intervals[i]);
            }       
        }
        return res;
    }

    vector<vector<int>> insert2(vector<vector<int>>& intervals, vector<int>& newInterval) {
         vector<vector<int>> result;
        
        for (size_t i = 0; i < intervals.size(); i++)
        {
			//  the new interval is after the range of other interval, so we can leave the current interval baecause the new one does not overlap with it
            if (intervals[i][1] < newInterval[0])
            {
                result.push_back(intervals[i]);
            }
			// the new interval's range is before the other, so we can add the new interval and update it to the current one
            else if (intervals[i][0] > newInterval[1])
            {
                result.push_back(newInterval);
                newInterval = intervals[i]; 
            }
			// the new interval is in the range of the other interval, we have an overlap, so we must choose the min for start and max for end of interval 
            else if(intervals[i][1] >= newInterval[0] || intervals[i][0] <= newInterval[1])
            {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);

            }
        }
        
        result.push_back(newInterval); 
        return result;
    }
};

int main(){
    //vector<vector<int>> aa = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    //vector<int> insert = {4,8};

    vector<vector<int>> aa = {{1,3},{6,9}};
    vector<int> insert = {2,5};
    Solution s;
    vector<vector<int>> result = s.insert2(aa,insert);

    for(auto a: result){
        for(auto b : a){
            cout << b << ", ";
        }
        cout <<endl;
    }
}