#include <iostream>
#include <algorithm>
using namespace std;

void reverse_1(char* , char* );
void swap(char*, char*);

bool isPalin(int x){
    if(x<0 || (x%10==0 && x!=0) ) return false;

    int r= 0;
    while(x>r){
        r = r*10 + x%10;
        x/=10;
    }

    return x==r || x== r/10;
}

bool isPalin_str(int x){
     if(x<0 || (x%10==0 && x!=0) ) return false;
    string s = to_string(x);
    string r = s;
    reverse(r.begin(), r.end());
    //reverse_1(p[0], p[3]);
    return r==s;
}

void reverse_1(char* first, char* last){
    --last;
    while (first < last) {
    swap(first, last);
    ++first;
    --last;
    }
}

void swap(char *x, char *y) {
    char tmp = *x;
    *x = *y;
    *y = tmp;
}

int main(){
    string result = isPalin_str(123)? "True":"False";
    cout << result << endl;
}