#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

string strSort(string s){ //use char proptety can improve time compliexty
    int counter[26] ={0};
    for(char c :s){
        counter[c-'a']++;
    }
    string t;
    for(int i=0; i<26; i++){
        t+=string(counter[i], i+'a');
    }
    return t;
}

int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    unordered_map<string, vector<string>> mp;

    for(string s:strs){
        string t = s;
        //sort(t.begin(), t.end());
        mp[strSort(s)].push_back(s);
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