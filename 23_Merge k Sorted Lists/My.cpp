//Brute method

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

void mergeKLists(vector<ListNode*>& list){
    vector<int> res;
    for(int i=0; i<list.size(); i++){
        while(list[i] != NULL){
            res.push_back(list[i]->val);
            list[i] = list[i]->next;
        }
    }

    sort(res.begin(), res.end());

    ListNode* l;
    ListNode* temp = l;
    for(int i=0; i<res.size(); i++){
        // ListNode* ln = new ListNode(res[i]);
        temp->next = new ListNode(res[i]);;
        temp = temp->next;
    }


    for(int i=0; i<res.size(); i++){
        cout << res[i] << ", ";
    }

    return;
}

int main(){
    ListNode* a = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* b = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* c = new ListNode(2, new ListNode(6));
    vector<ListNode*> list = {a,b,c};
    mergeKLists(list);
    cout<"====================="<<endl;
    

}