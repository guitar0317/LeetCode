#include <iostream>
using namespace std;
#include <vector>

int main(){
    //vector<int> n = {2,7,9,3,1};
    vector<int> n = {1,2,3,1};

    int a=0,b=0;
    for(int i=0; i<n.size(); i++){
        if(i%2==0) a = max(a+n[i], b);
        else b = max(a, b+n[i]);
    }

    cout << max(a,b);

}