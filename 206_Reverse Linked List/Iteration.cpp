#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next):val(x), next(next){}
};

int main(){
    ListNode* head = new ListNode(1,new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));



    ListNode* next;
    ListNode* prev = NULL;
    while(head){
        cout << head->val << ", ";
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    cout << endl;
    while(prev){
        if(prev->next) cout << prev->val << ", ";
        else cout << prev->val;
        prev = prev->next;
    }

}