#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    unordered_map<string, vector<string>> mp;

    for(string s:strs){
        string t = s;
        sort(t.begin(), t.end());
        mp[t].push_back(s);
    }

    vector<vector<string>> ang;
    for(auto p :mp){
        ang.push_back(p.second);
    }

    for(auto a:ang){
        for(auto b:a){
            cout << b <<", ";
        }
        cout << endl;
    }
}