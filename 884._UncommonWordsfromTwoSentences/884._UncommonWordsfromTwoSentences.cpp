#include <iostream>
using namespace std;
#include <vector>

void check(vector<string>& vec, string s){

        bool bRepeated = false;
               for(int j=0; j<vec.size();j++){
                if(vec[j]==s){ 
                    bRepeated = true;
                    vec.erase(vec.begin()+j,vec.begin()+j+1);
                    j--;
                }
            }
            
            if(!bRepeated) vec.push_back(s);
        
}

int main(){
    string s1 = "this apple is sweet";
    string s2 = "this apple is sour";

    vector<string> result;
    string temp="";
    char c = ' ';
    bool bRepeated = false;
    for(int i=0; i<s1.size(); i++){
        if(s1[i]!= c && i!=s1.size()){
            temp+=s1[i];
            if(i == s1.size()-1) check(result, temp);
        }else{
            /*for(int j=0; j<result.size();j++){
                if(result[j]==temp){ 
                    bRepeated = true;
                    result.erase(result.begin()+j,result.begin()+j+1);
                    j--;
                }
            }
            
            if(!bRepeated) result.push_back(temp);*/
            check(result, temp);
            temp="";
            bRepeated = false;
        }
        
    }
    temp="";
    int size= result.size();
    for(int i=0; i<s2.size(); i++){
        if(s2[i]!= c && i!=s2.size()){
            temp+=s2[i];
            if(i == s2.size()-1) check(result, temp);
        }else{
           /* for(int j=0; j<result.size();j++){
                if(result[j]==temp){
                     bRepeated = true;
                      result.erase(result.begin()+j,result.begin()+j+1);
                       j--;
                }
            }
            
            if(!bRepeated) result.push_back(temp);*/
            check(result, temp);
            temp="";
            bRepeated = false;
        }
    }

   for(int j=0; j<result.size();j++){
        cout<<result[j] <<endl;
    }

}