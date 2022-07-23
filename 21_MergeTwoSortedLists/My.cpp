#include <iostream>
using namespace std;
#include <unordered_map>

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
     
        ListNode* result=NULL;
        unordered_map<int,int> map;
        
        while(list1 != NULL){
            if(list1->val < -100 || list1->val >100) return NULL;
            map[list1->val]++;
            list1 = list1->next;
        }
        
        while(list2 != NULL){
            if(list2->val < -100 || list2->val >100) return NULL;
            map[list2->val]++;
            list2 = list2->next;
        }
        
        for(int i=-100; i<101; i++){
            if(map[i]<=0){
                continue;
            }else{
                for(int j=1; j<= map[i]; j++){
                       ListNode* temp = new ListNode(i);
                       if(result == NULL)
                            result = temp;
                       else{
                                ListNode *current = result;
                                while (current->next != 0) {           // Traversal
                                    current = current->next;
                                }
                                current->next = temp;
                       }
                }     
            }
        }
        
        return result;
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