#include <iostream>
#include <vector>
using namespace std;

int main(){
    //vector<int> v = {3,4,5,1,2};
    //vector<int> v = {4,5,6,7,0,1,2};
   vector<int> v = {11,13,15,17};
    int n = v.size();
    if(n==1){
        cout << v[0];
        return 0;
     }
    else if(n==2){
        cout << min(v[0],v[1]);
        return 0;
    }

    int mid = n/2, min_n = INT_MAX;

    if(v[n-1]>v[0]){
        cout << v[0];
        return 0;
    }
    else if(v[mid]>v[0]){
        for(int i=mid+1; i<n; i++){
            min_n = min(min_n, v[i]);
        }
    }else{
        for(int i=0; i<=mid; i++){
            min_n = min(min_n, v[i]);
        }
    }

    cout << min_n;
}