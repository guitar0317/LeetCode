#include <iostream>
using namespace std;
#include <unordered_map>

int main(){
 string s1 = "apple";
 string s2 = "ppela";
 
 unordered_map<char, int> map;
 
 for(int i=0; i<s1.size(); i++){
	map[(char)s1[i]]++;
 }
 
 for(int i=0; i<s2.size(); i++){
	map[(char)s2[i]]--;
	if(map[(char)s2[i]] < 0){
		cout << "False";
		return 0;
	}
 }

 cout<<"True";
}