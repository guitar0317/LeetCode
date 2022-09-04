#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int max = amount+1;
    vector<int> dp(amount+1, max);
    dp[0]=0;
    for(int i =0; i<=amount; i++){
        for(int j=0; j<coins.size(); j++){
            if(coins[j]<=i){
                dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
    }

    return dp[amount] > amount? -1 : dp[amount];
} 

int main(){
    vector<int> coins={1,2,5};
    int amount = 11;

    cout << coinChange(coins, amount)<<endl;
}