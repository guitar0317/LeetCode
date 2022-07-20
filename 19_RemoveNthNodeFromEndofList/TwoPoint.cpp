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

ListNode*  removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast =head;
        ListNode* slow = head;
        for(int i=0; i < n ;i++){
            fast = fast->next;
        }
        
        if(fast==NULL) return head->next;
        
        while(fast->next != NULL){
            fast= fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        return head;
}


int main(){
    int n =2;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    removeNthFromEnd(head,n);
    while(head!=NULL){
        cout << head->val <<endl;
        head = head->next;
    }
  

}