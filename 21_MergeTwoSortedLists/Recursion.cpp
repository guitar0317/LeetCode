#include <iostream>
using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        // if list1 happen to be NULL
		// we will simply return list2.
        if(list1 == NULL) return list2;

        // if list2 happen to be NULL
		// we will simply return list1.
        if(list2 == NULL) return list1;

        // if value pointend by l1 pointer is less than equal to value pointed by l2 pointer
		// we wall call recursively l1 -> next and whole l2 list.
        if(list1->val <= list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else{ // we will call recursive l1 whole list and l2 -> next
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }


    }

};

int main(){
    Solution sol;
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* result = sol.mergeTwoLists(list1, list2);

    while(result != NULL){
        cout<< result->val <<endl;
        result = result->next;
    }

}