#include <iostream>
using namespace std;
//Recursion, but occur time limit exceeded if large number;
// Complexity : Time: O(2^n) ; Space: O(n)
int climb(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 2;

    return climb(n-1)+climb(n-2);
}

int main(){
    cout << climb(45) ;
    

}