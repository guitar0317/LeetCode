#include <iostream>
using namespace std;

//Floyd’s Cycle-Finding Algorithm  Floyd判圈算法

//Definition for single-linked list.
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL){}
};

int main(){
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

     ListNode* fast= head;
        ListNode* slow=head;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow){ 
                cout<<"True"<<endl;
                return 0;
                }
        }
        
        cout<<"False"<<endl;
}