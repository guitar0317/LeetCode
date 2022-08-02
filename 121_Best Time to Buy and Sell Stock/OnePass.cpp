#include <iostream>
using namespace std;
#include <vector>
//
int main(){
    //vector<int> prices={7,1,5,3,6,4};
    //vector<int> prices={7,6,4,3,1};
vector<int> prices={1,2};


    int minprices = INT_MAX;
    int maxprofit=0;
     for(int i=0; i<prices.size(); i++){
        /*if(prices[i] < min){
            min = prices[i];
        }else if(prices[i]-min > max){
            max = prices[i]-min;
        }*/
        minprices = min(minprices,prices[i]);
        maxprofit = max(maxprofit, prices[i]-minprices);
    }

       cout << maxprofit;
}