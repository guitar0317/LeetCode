#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v = {1,2,3,4};

    int tempMax=INT_MIN, index=0;
    for(int i=0; i<v.size(); i++){
        if(v[i]>tempMax){
            tempMax=v[i];
            index = i;
        }
    }

    for(auto a:v){
        if(a*2 > tempMax && a!=tempMax){
            cout << -1;
            return 0;
        }
    }
    cout << index;
     return 0;
}