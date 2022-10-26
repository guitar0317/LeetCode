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

void mergeKLists(vector<ListNode*>& lists){
    if (lists.size()<1) return;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<lists.size(); i++){
        ListNode* temp = lists[i];
        while(temp != NULL){
            pq.push(temp->val);
            temp = temp->next;
        }
    }

    ListNode* res = new ListNode();
    ListNode* tmp = res;
    while(!pq.empty()){
        tmp->next = new ListNode(pq.top());
        cout << pq.top() << " " ;
        pq.pop();
        tmp = tmp->next;
    }

    return;
}

int main(){
    ListNode* a = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* b = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* c = new ListNode(2, new ListNode(6));
    vector<ListNode*> list = {a,b,c};
    mergeKLists(list);
}