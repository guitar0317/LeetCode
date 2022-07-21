#include <iostream>
using namespace std;
#include <cstring>

bool isUnique(string s){
	if(s.size()>128 || s.size()<1) return false;
	
	bool bar[128];
    memset(bar, 0, 128); //initial all element to false value
	for(int i=0;i<s.size(); i++){
        char c = s[i];
		if(bar[c]){
			return false;
		}
		
		bar[c] = true;
	}
	
	return true;
}

int main(){
    string s="ASUS";
    cout << isUnique(s)<<endl;
}