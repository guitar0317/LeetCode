#include <iostream>
using namespace std;
#include <bitset>

int main(){
    uint32_t n = 11111111111111111111111111111101;

    bitset<32> bit_set(n);

    for(int i=0; i<32/2; i++){
        bool temp = bit_set[i];
        bit_set[i] = bit_set[bit_set.size()-1-i];
        bit_set[bit_set.size()-1-i] = temp;
    }

    cout << bit_set.to_ulong();
}