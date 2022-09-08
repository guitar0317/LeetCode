#include <iostream>
using namespace std;

int main(){
    int a = 5, b=0;
    int sum=0;
    while(b!=0){
        sum = a^b;
        b=(unsigned)(a & b)<<1;
        a = sum;
    }

    cout << a;
}