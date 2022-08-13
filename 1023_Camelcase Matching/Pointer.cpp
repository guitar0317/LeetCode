#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;
        for(string s:queries){
            int i=0, j=0;
            for(char c : s){
                if(c==pattern[i]) i++;
                else if(isupper(c)){//c>='A' && c<='Z'
                    result.push_back(false);
                    break;
                }
                j++;   
            }
            if(i==pattern.size() && j==s.size()){
                result.push_back(true); 
            }else if(j==s.size()){
                result.push_back(false);
            }
        }
        return result;
    }
};

int main(){
    vector<string> queries = {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
    //vector<string> queries = {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
    string pattern = "FoBa";
    Solution sol;
    vector<bool> result = sol.camelMatch(queries,pattern);

    for(bool b:result){
        cout << (b?"True":"False") <<endl;
    }
}