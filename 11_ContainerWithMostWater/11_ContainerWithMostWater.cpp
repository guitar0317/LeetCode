#include <iostream>
using namespace std;

int main(){
    int i[9] = {1,8,6,2,5,4,8,3,7};
    int size = sizeof(i)/sizeof(i[0]);
    int maxarea=0;

    //Approach2: Two point. TC=O(n), SC=O(1)
    int l=0, r= size -1;

    while(l<r){
        int width = r-l;
        maxarea = max(maxarea, min(i[l], i[r])*width);
        if(i[l]<=i[r]) l++;
        else r--;
    }

    //Approach1: Brute Force, TC:O(n2), SC:O(1), it too time consuming, not fit in interview.
   /* for(int left=0; left < size-1; left++){
        for(int right =left+1; right <size; right++){
            int width = right - left;
            maxarea = max(maxarea, min(i[left], i[right])*width);
        }
    }*/

    cout << maxarea <<endl;
}