#include <iostream>
#include <string>
using namespace std;

int roman(char c){
    switch(c){
            case 'I':
                return 1;
                break;
            case 'V':
                return 5;
                break;
             case 'X':
                return 10;
                break;
             case 'L':
                return 50;
                break;
             case 'C':
                return 100;
                break;
             case 'D':
                return 500;
                break;
            case 'M':
                return 1000;
                break;
            default:
                return 0;
                break;
    }
}

int romanToInt(string s){
    if(s.empty() || s.size() > 16) return NULL;
    int result=0; 
    for(int i=0; i<s.size(); i++){
       /* if(i==s.size()-1){
            result += roman(s[i]);
            break;
        } */

        if(roman(s[i]) >= roman(s[i+1])){
            result += roman(s[i]);
        }else{
            int v2=roman(s[i+1]);
            int v1 = roman(s[i]);
            result = result + (roman(s[i+1]) - roman(s[i]));
            i++;
        }
    }
    return result;
}

int main(){
    string s = "MCMXCIV";
    cout << romanToInt(s) <<endl;
}