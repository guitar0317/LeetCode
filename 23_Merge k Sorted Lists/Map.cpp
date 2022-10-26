//Brute method
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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

    map<int,int> mp;
    for(int i=0; i<lists.size(); i++){
        while(lists[i]!=NULL){
            mp[lists[i]->val]++;
            lists[i]= lists[i]->next;
        }
    }

    ListNode* res = new ListNode(0);
    ListNode* temp = res;
    for(auto it=mp.begin(); it!=mp.end(); it++){
        for(int i=0; i<(*it).second; i++){
            temp->next = new ListNode((*it).first);
            temp = temp->next;
            cout<<(*it).first<<" ";
        }
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