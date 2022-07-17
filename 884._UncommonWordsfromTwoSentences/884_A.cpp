#include <iostream>
using namespace std;
#include <vector>

int main(){
    string s1 = "this apple is sweet";
    string s2 = "this apple is sour";
    vector<string> result;
    char c = ' ';
    string temp="";

    for(int i=0; i<s1.size(); i++){
        if(s1[i]!=c){
            temp += s1[i];
            if(i==s1.size()-1) result.push_back(temp);
        }else{
            result.push_back(temp);
            temp="";
        }
    }

    temp="";

     for(int i=0; i<s2.size(); i++){
        if(s2[i]!=c){
            temp += s2[i];
            if(i==s2.size()-1) result.push_back(temp);
        }else{
            result.push_back(temp);
            temp="";
        }
    }

    bool repeated = false;
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result.size(); j++){
            if(i==j) continue;
            if(result[j]==result[i]){
                result.erase(result.begin()+j, result.begin()+j+1);
                j--;
                repeated = true;
            }      
        }
        if(repeated){
                 result.erase(result.begin()+i, result.begin()+i+1);
                 i--;
                repeated = false;
            }
    }

    for(int i=0; i<result.size() ;i++){
        cout<< result[i]<<endl;
    }
}