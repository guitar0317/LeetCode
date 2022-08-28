#include <iostream>
#include <unordered_map>
using namespace std;

 void isAnagram1(string s, string t) {
    unordered_map<char,int> mp1;
    unordered_map<char,int> mp2;
    if(s.size()!=t.size()){ 
         cout <<"False";
         return;
    }
    for(int i=0; i< s.size(); i++){
        mp1[s[i]]++;
        mp2[t[i]]++;
    }
    
    for(char c:s){
        if(mp1[c]!=mp2[c]){
            cout <<"False";
            return;
        }
    }
    
        cout <<"True";
 }

 void isAnagram2(string s, string t) {
    if(s.size()!=t.size()){ 
         cout <<"False";
         return;
    }

    unordered_map<char, int> mp;
    for(int i=0;i<s.size(); i++){
        mp[s[i]]++;
        mp[t[i]]--;
    }

    for(auto m:mp){
        if(m.second){
            cout << "False";
            return;
        }
    }

    cout << "True";
 }

int main(){
    string s = "rat";
    string t = "car";
    
   isAnagram1(s,t);
   cout << endl;
   isAnagram2(s,t);
}