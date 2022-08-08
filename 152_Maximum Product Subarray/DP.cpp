#include <iostream>
using namespace std;
#include <vector>

int main(){
    vector<int> n = {2,3,-2,4};

    int s = n.size(), res=n[0], l=0, r=0;

    for(int i=0; i <s; i++){
        l = (l? l:1)*n[i];
        r = (r? r:1)*n[s-1-i];
        res = max(res, max(l,r));
    }

    cout <<res;
}