#include <iostream>
using namespace std;
#include <vector>
//O(n^2), too time consuming
int main(){
    vector<int> prices={1,2};

     int top=0;
        int day=0;
       for(int i=0;i<prices.size()-1;i++){
           for(int j=i+1; j<prices.size(); j++){
              int temp = prices[j] -prices[i];
              if(temp > top){
                  top = temp;
                  day = j+1;
              }
           }
       }

       cout << top;
}