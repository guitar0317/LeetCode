#include <iostream>
using namespace std;

struct ListNode
{
    
    int val;   //當前節點的值
    ListNode *next;   //指向下一個節點的指針
    ListNode() : val(0), next(nullptr) {
    }   //初始化當前結點值為默認值0,指針為空
    ListNode(int x) : val(x), next(nullptr) {
    }    //初始化當前結點值為x,指針為空
    ListNode(int x, ListNode *next) : val(x), next(next) {
    }    //初始化當前結點值為x,下一個績點為next
};

ListNode* addTwoSum(ListNode* l1, ListNode* l2){
    ListNode* result = new ListNode(0);
    ListNode* curr = result;
    int carry = 0;
    while(l1 !=NULL || l2 != NULL || carry !=0){
        int x = l1? l1->val:0;
        int y = l2? l2->val:0;
        int sum = carry+x+y;
        carry = sum/10;
        curr->next = new ListNode(sum%10);
        curr = curr->next;
        l1 = l1? l1->next: nullptr;
        l2 = l2? l2->next: nullptr;
    }
    return result->next;
}

int main(){
    ListNode* L1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    /*L1->val = 3;
    L1->next = new ListNode(4);
    L1 =L1->next;
    L1->next = new ListNode(5);*/

     ListNode* L2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    /*L2->next = new ListNode(1);
    L2 =L2->next;
    L2->next = new ListNode(4);*/

    ListNode* result =  addTwoSum(L1, L2);

    while(result != NULL){
        int r = result->val;
        cout << to_string(r) << endl;
        result = result->next;
    }

}