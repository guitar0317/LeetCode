#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    string maskPII(string s) {
        auto index = s.find('@');
        if(index != string::npos){ //email
            transform(s.begin(),s.end(), s.begin(), ::tolower);
            return s.substr(0,1)+"*****"+s.substr(index-1);
        }else{ //phone
            string sTemp="";
            for(char c : s){
                if(isdigit(c)) sTemp+=c;
            }

            return ((sTemp.size() == 13 ? "+***-" : sTemp.size() == 12 ? "+**-" : sTemp.size() == 11 ? "+*-" : "") + ("***-***-" + sTemp.substr(sTemp.size()-4)));
        }
    }
};

int main(){
    vector<string> testcase = {"LeetCode@LeetCode.com","AB@qq.com", "1(234)567-890"};
    Solution sol;
    for(string s: testcase)
        cout<< sol.maskPII(s)<<endl;;
}