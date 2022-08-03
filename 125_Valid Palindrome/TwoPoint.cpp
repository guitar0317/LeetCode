#include <iostream>
using namespace std;

int main(){
    //string s = "A man, a plan, a canal: Panama";
    //string s = "race a car";
    string s = "a.";
    //string s = "0P";

    for(int i=0, j=s.size()-1; i<j; i++,j--){// Move 2 pointers from each end until they collide
        while(isalnum(s[i]) == false && i<j) i++; // Increment left pointer if not alphanumeric
        while(isalnum(s[j]) == false && i<j) j--;  // Decrement right pointer if no alphanumeric
        if(toupper(s[i])!=toupper(s[j])){ // Exit and return error if not match
            cout<<"False";
            return 0;
        }
    }

    cout << "True";
}