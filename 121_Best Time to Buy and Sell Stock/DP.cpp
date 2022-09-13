#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> stock = {7,1,5,3,6,4};
    
    vector<vector<int>> dp(stock.size(),{0,0});
    int min_price=0, max_profit=0;

    dp[0] = {stock[0],0};
    for(int i=1; i<stock.size(); i++){
        int a = dp[i-1][0], b = stock[i];
        min_price = min(dp[i-1][0], stock[i]);
        int c = dp[i-1][1], d=stock[i]-dp[i-1][0];
        max_profit = max(dp[i-1][1], stock[i]-dp[i-1][0]);
        dp[i]={min_price,max_profit};
    }

    cout << dp[stock.size()-1][1];
}
