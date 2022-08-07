#include <iostream>
using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

  int main(){
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(-4);
    ListNode* head = n1;
    head->next = n2;
    head->next->next = n3;
    head->next->next->next = n4;
    head->next->next->next->next = n2;

    if(head == NULL) cout<<"False";

    ListNode* fast = head;
    ListNode* slow = head;

    while(fast != NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){
            cout << "True";
            return 0;
        }
    }
    
    cout << "False";
  }