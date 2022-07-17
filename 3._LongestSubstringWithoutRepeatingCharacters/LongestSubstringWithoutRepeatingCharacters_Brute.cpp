#include <iostream>
using namespace std;
#include <vector>

bool checkRepetition(string& s, int start, int end){
    vector<int> chars(128);

    for(int i = start; i<=end; i++){
        char c =s[i];
        chars[c]++;
        if(chars[c] > 1) return false;
    }

    return true;
}


int main(){
    string  s= "pwwkew";
    int len = s.length();
    int res = 0;

    for(int i=0; i< len; i++){
        for(int j=i; j<len; j++){
            if(checkRepetition(s, i,j)){
                res = max(res, j-i+1);
            }
        }
    }

    cout << res << endl;

}