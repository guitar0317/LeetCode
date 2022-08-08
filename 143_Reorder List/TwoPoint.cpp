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
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    vector<ListNode*> arr;
    for(auto iter = head; iter; iter=iter->next) arr.push_back(iter);

    int L=1, R=arr.size()-1;

    for(int i=0; i<arr.size(); i++){
        if(i & 1) head->next = arr[L++];
        else head->next = arr[R--];

        head = head->next;

    }

    head->next = nullptr;

  
        while(arr[0] != NULL){
            cout << arr[0]->val <<", ";
            arr[0] = arr[0]->next;
        }
    
}