#include <iostream>
#include <vector>
using namespace std;

//TC: O(nlogn)
void VectorMethod(int n){
    vector<int>ans;
    // iterating fromt 0 to n
    for(int i=0; i<=n; i++){
        // sum is initialised as 0
        int sum=0;
        int num =i;
        // while num not equals zero
        while(num != 0){
            // we have to count 1's in binary representation of i, therefore % 2
            sum += num%2;
            num /=2;
        }
        // add sum to ans vector
        ans.push_back(sum);
    }

    for(auto a:ans){
        cout << a <<", ";
    }
}

//TC: O(n)
void Method2(int n){
      
        // n+1 as we are going to count from 0 to n
        vector<int> t(n+1);
        
        // t[0] will be 0 beacuse 0 has count of set bit is 0;
        t[0] = 0;
        
        // we can compute current set bit count using previous count
        // as x/2 in O(1) time
        
        // i%2 will be 0 for even number ans 1 for odd number
        
        for(int i = 1; i<=n; ++i)
            t[i] = t[i/2] + i%2;
        
        for(auto a:t){
             cout << a <<", ";
        }
}

//TC:O(n)
void Method3(int n){
    vector<int> res(n);
    res.push_back(0);
    if(n==0){
        cout << 0;
        return;
    }

    for(int i=0; i<=n; i++){
        if(i%2==0){
            res[i]=res[i/2];
        }else{
            res[i] = res[i-1]+1;
        }
    }

     for(auto a:res){
             cout << a <<", ";
        }
}

int main(){
    int n= 5;

    VectorMethod(n);
    cout << endl;
    Method2(n);
    cout << endl;
    Method3(n);
}