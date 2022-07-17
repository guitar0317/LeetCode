#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

int main(){
    string s1=  "apple apple", s2 = "banana";

    vector<string> res;
    unordered_map<string, int> mm;
    string word ="";

    for(int i=0; i<s1.size(); i++){
        if(s1[i] == ' '){
            mm[word]++;
            word="";
        }else{
            word += s1[i];
        }
    }
    if(word!= ""){
        mm[word]++;
        word="";
    }

    for(int i=0; i<s2.size(); i++){
        if(s2[i]==' '){
            if(mm[word]!=0) mm[word]=-1;
            else mm[word]++;
            word="";
        }else{
            word+= s2[i];
        }
    }

    if(word !=""){
        if(mm[word]!=0) mm[word]=-1;
        else mm[word]++;
    }

    for(auto s:mm){
        if(s.second==1){
            res.push_back(s.first);
        }
    }

    for(string s : res){
        cout<< s <<endl;
    }

}