#include <iostream>
using namespace std;

int main(){
	string s = "Mr John Smith   ";
	string result= "";
	for(int i=0; i<s.size(); i++){
		if(s[i]==' '){
			result += "%20";
		}
		else result += s[i];
	}
	
	cout << result <<endl;
}