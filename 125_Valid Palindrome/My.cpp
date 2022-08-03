#include <iostream>
using namespace std;

int main(){
    //string s = "A man, a plan, a canal: Panama";
    //string s = "race a car";
    string s = "a.";
    //string s = "0P";

    string s1;
    for(auto c : s){
        if(isalnum((char)c))
            s1+= (char)tolower(c);
    }

    int l=0, r=s1.size()-1;
    /*if(s1.size()==2){
        cout << "True";
        return 0;
    }*/
    while(l<r){
        char lc = s1[l];
        char rc = s1[r];
        if(s1[l] == s1[r]){
            r--;
            l++;
        }else{
            cout<<"False";
            return 0;
        }     
    }

    cout<< s1<<endl;
    cout<<"True";
}