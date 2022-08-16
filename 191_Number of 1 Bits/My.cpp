#include <iostream>
using namespace std;
#include <bitset>

int main(){
    uint32_t n = 00000000000000000000000000001011;

    bitset<32> bs(n);
    int count=0;
    for(int i=0; i<32; i++){
        if(bs[i]==1) count++;
    }

    cout << count;
}