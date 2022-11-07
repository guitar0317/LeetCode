#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution{
public:
    string longestPalindrome(string s){
        int n = s.size();
        int start=0, maxLen=1;
        if(!n) return "";

        int dp[n][n];
        memset(dp, -1, sizeof dp);

        for(int i =0; i<n; i++){
            dp[i][i]=1;
        }
        
        for(int i=0; i<n-1; i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                start=i;
                maxLen=2;
            }
        }

        for(int k=3; k<=n; k++){
            for(int i=0; i<n-k+1; i++){
                int j=i+k-1;
                if(dp[i+1][j-1]==1 && s[i]==s[j]){
                    dp[i][j]=1;
                    if(k>maxLen){
                        start=i;
                        maxLen=k;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }

    string longestPalindrome2(string s)
    {
        int n = s.size();
        if(n<1) return "";
        int start=0, maxLen=1;

        vector<vector<int>> dp(n, vector<int>(n,1));
        bool b;
        for(int len=2; len<=n; len++){
            for(int i=0,j; (j=i+len-1)<n; i++){
                b = (s[i]==s[j]) && dp[i+1][j-1];
                dp[i][j] = b;
                if(dp[i][j] && len > maxLen) 
                    start=i, maxLen=len;
            }
        }

        return s.substr(start,maxLen);
    }
};

int main(){
    string s = "babad";
    Solution sol;
    cout << sol.longestPalindrome2(s) << endl;
}