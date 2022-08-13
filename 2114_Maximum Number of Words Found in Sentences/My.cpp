#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n=0, maxcount=0;
        for(auto s:sentences ){
            n = count(s.begin(), s.end(), ' ')+1;
            maxcount = max(maxcount , n);
        }
        
        return maxcount;
    }
};

int main(){
    vector<string> sentences = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
    Solution sol; 
        
    cout<< sol.mostWordsFound(sentences);
}