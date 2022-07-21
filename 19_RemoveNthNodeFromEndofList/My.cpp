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
        int size=0;
        ListNode* temp = head;
        ListNode* temp2 = head;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        
        if(size < n) return NULL;
        int removeIndex = size-n;
        for(int i=1; i <= size; i++){
            if(temp2==NULL) break;
            if(i==removeIndex){
                temp2->next = temp2->next->next;
            }
            else temp2 = temp2->next;
        }
        
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