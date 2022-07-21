#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(1>=s.length() || s.length()>=10000) return false;
        
        bool result=false;
        
        for(int i=0; i<s.size()-1; i++){
            if(s[i]==' ') continue;
            if(s[i]=='(' && s[i+1]==')'){
                result=true;
                i++;
                continue;
            }else if(s[i]=='{' && s[i+1]=='}'){
                result=true;
                i++;
                continue;
            }else if(s[i]=='[' && s[i+1]==']'){
                 result=true;
                i++;
                continue;
            }
            i++;
            result = false;
        }
        
        return result;
    }
       
};

int main(){
    string s = "{[]}";
    Solution sol;
    string res = sol.isValid(s)? "True":"False";
    cout << res << endl;
}