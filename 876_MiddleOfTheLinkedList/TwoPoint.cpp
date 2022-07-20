#include <iostream>
using namespace std;

//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

int main(){
 ListNode* head = new ListNode(1, new ListNode {(2), new ListNode {(3), new ListNode {(4), new ListNode {(5)}}}});
 ListNode* slow = head;
 ListNode* fast = head;

 while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
 }

 while(slow!=NULL){
    cout << slow->val <<endl;
    slow = slow->next;
 }

}