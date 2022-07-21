#include <iostream>
using namespace std;
#include <stack>

int main(){
    string s ="([]){]";
    if(s.size() <=1 || s.size()>=10000) {
        cout<<"False"<<endl;
        return 0;
    }
    stack<char> st;

    for(int i=0; i<s.size(); i++){
        char ch = s[i];

        if(ch == '(' || ch=='{' || ch =='[') st.push(ch);
        else{
            if(!st.empty()){
                char c = st.top();
                if((c=='(' && ch==')') || (c=='{' && ch=='}') || (c == '[' && ch==']')){
                    st.pop();
                }else{
                     cout << "False" <<endl;
                     return 0;
                }
            }else{
                cout << "False" <<endl;
                 return 0;
            }
        }
    }

    if(st.empty()) cout << "True" <<endl;
    else cout << "False" <<endl;
    return 0;
}