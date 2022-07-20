#include <iostream>
using namespace std;
#include <vector>

//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

int main(){
    ListNode* head = new ListNode(1, new ListNode {(2), new ListNode {(3), new ListNode {(4), new ListNode {(5), new ListNode {(6)}}}}});

    vector<ListNode*> a = {head};

    while(a.back()->next !=NULL){
        a.push_back(a.back()->next);
    }

    for(int i=a.size()/2; i<a.size(); i++){
        cout << a[i]->val <<endl;
    }

}