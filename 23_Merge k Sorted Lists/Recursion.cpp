//Brute method
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* merge(ListNode* l1, ListNode* l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    ListNode* head = l1->val <= l2->val ? l1:l2;
    head->next =  l1->val <= l2->val ? merge(l1->next, l2) : merge(l1, l2->next);
    return head;
}

void mergeKLists(vector<ListNode*>& lists){
    if (lists.size()<1) return;
    ListNode* head = lists[0];

    for(int i =1; i<lists.size(); i++){
        head = merge(head, lists[i]);
    }
    
    while(head!=NULL){
        cout << head->val << " ";
        head = head->next;
    }
}

int main(){
    ListNode* a = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* b = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* c = new ListNode(2, new ListNode(6));
    vector<ListNode*> list = {a,b,c};
    mergeKLists(list);
}