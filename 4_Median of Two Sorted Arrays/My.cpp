#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    //vector<int> nums1 ={1,3};
    //vector<int> nums2 ={2};
    vector<int> nums1 ={1,2};
    vector<int> nums2 ={3,4};

     vector<int> temp;
        
        for(int i=0; i<nums1.size(); i++){
            temp.push_back(nums1[i]);
        }
        
         for(int i=0; i<nums2.size(); i++){
            temp.push_back(nums2[i]);
        }
        
        sort(temp.begin(), temp.end());
        
        int middle = temp.size()/2;
        if(temp.size()%2==1){
            cout<< (double)temp[middle] ;
        }else{
            cout<< (((double)temp[middle])+((double)temp[middle-1]))/2;
        }

}