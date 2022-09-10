#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void SlidingWindows(string s, int k){
 int n = s.size();
    int i= 0,j=0, maxi=0;
    unordered_map<char, int> mp;

    int ans=-1;
    while(j<n){
        mp[s[j]]++;
        maxi = max(maxi, mp[s[j]]);
        if((j-i+1) - maxi > k){
            mp[s[i]]--;
            i++;
        }
        ans = max(ans, (j-i+1));
        j++;
    }

    cout<< ans;
}

void slidingWindows2(string s, int k){
    int maxf=0, i=0, n=s.size();
    vector<int> count(26);
    for(int j=0; j<n; j++){
        maxf = max(maxf, ++count[s[j]-'A']);
        if(j-i+1 > maxf+k){
            --count[s[i++]-'A'];
        }
    }

    cout << n-i;
}

int main(){
    string s = "AABABBA";
    int k = 1;
    SlidingWindows(s,k);
    cout << endl;
    slidingWindows2(s,k);
}