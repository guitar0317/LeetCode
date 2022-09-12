#include <iostream>
#include <vector>
using namespace std;

int slove(vector<vector<int>>& mem, string& s , int i, int j){
    if(i>=j) return 1;
    int temp = mem[i][j];
    if(mem[i][j]>=0) return mem[i][j];
    return mem[i][j] =  s[i] == s[j]? slove(mem, s, i+1, j-1):0;
}
int DPbyMemoization(string& s){
    vector<vector<int>> mem(s.size(),vector<int>(s.size(),-1));
    int count=0;
    for(int i=0; i< s.size(); i++){
        for(int j=i; j<s.size(); j++){
            count += slove(mem, s,i,j);
        }
    }
    return count;
}

int DPbyTabulation(string& s){
  vector<vector<int>> tab(s.size(), vector<int>(s.size()));
  int count=0;
  for(int i=s.size()-1 ; i>=0; --i){
    for(int j=i; j<s.size(); ++j){
        if(i==j){
            tab[i][j]=1;
        }else if(i+1==j){
            tab[i][j] = (s[i]==s[j]) ? 1:0;
        }else{
            tab[i][j] = (s[i]==s[j]) ? tab[i+1][j-1] : 0;
        }

        count+= tab[i][j];
    }
  }
      return count;
}

int main(){
    string s = 
    //"abc";
    "aaa";
    cout << DPbyMemoization(s)<<endl;
    cout << DPbyTabulation(s) <<endl;
}