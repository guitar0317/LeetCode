#include <iostream>
using namespace std;
#include <vector>
vector<vector<int>> ans;
void solve(int i,vector<int>& arr, vector<int>& temp, int target){
     if(target==0){
            ans.push_back(temp);
            return;
        }
        
        if(target<0) return;
        
        if(i==arr.size()) return;
        
        solve(i+1, arr, temp, target);
        
        temp.push_back(arr[i]);
        solve(i, arr, temp, target-arr[i]);
        temp.pop_back();
}

int main(){
    vector<int> arr ={2,3,6,7};
    int target =7;


    vector<int> currComb;
    ans.clear(); // clear global array, make to sure that no garbage value is present in it
    vector<int> temp; // temporary vector that tries all possible combination
    solve(0,arr, temp, target); // calling function, and see we start from index zero

    
    
    for(auto a1 : ans){
        for(auto a2: a1){
            cout <<a2<<" ";
        }
        cout << endl;
    }
}