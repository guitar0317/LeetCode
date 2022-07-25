#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> n1 ={1,3};
    vector<int> n2 ={2};
    //vector<int> n1 ={1,2};
    //vector<int> n2 ={3,4};

    double med = 0.0;

    n1.insert(n1.end(), n2.begin(), n2.end());

    sort(n1.begin(), n1.end());

    int size = n1.size();

    if(size%2 ==0){
        cout << (n1[size/2] + n1[size/2-1])/2.0 << endl;
    }else{
        cout << n1[size/2] << endl;
    }
    

}