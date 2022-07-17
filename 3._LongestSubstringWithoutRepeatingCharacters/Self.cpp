#include <iostream>
using namespace std;

int main(){
    string s = "abba";

     int head=-1, tail=-1;
     int temp=0;
     bool newstr= false;
        for(int i=0; i<s.size(); i++){
            if (i==0){
                head=tail=i;
                continue;
            }
            
            for(int j=i-1; j>=0; j--){
                if(s[j]==s[i]){
                    temp = i-j; 
                    //break;  
                }
            }
            
            if(temp==0){ 
                tail=i;
             }else if(temp==1){
                if(i+1==s.size()) break;
                head = tail = i;
                newstr = true;
                temp=0;
            }else{ 
               if(newstr){
                tail=i;
                newstr = false;
               }
               temp=0; 
            }
            
        }
        
        int res = tail-head+1;
}