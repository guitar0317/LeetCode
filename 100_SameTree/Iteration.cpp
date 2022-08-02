#include <iostream>
using namespace std;
#include <queue>
 //TC: O(n),  SC: O(n)
 // Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

bool isSameTree(TreeNode* t1, TreeNode* t2){
   //for iterative approach, we generally follow the 4 major steps:
    //1. Make a queue 
    //2. Push the current Node in the queue (starting from the root node)
    //3. Process the queue, while its not empty (by adding its left & right child)
    //4. Once the queue is empty, then alorithm has finished
     queue<TreeNode*> qu;
    qu.push(t1);
    qu.push(t2);

    while(qu.size()!=0){
        TreeNode* n1 = qu.front();
        qu.pop();
        TreeNode* n2 = qu.front();
        qu.pop();

        if(n1==NULL && n2==NULL) continue;
        if(n1==NULL || n2 == NULL) return false;
        if(n1->val != n2->val) return false;

        qu.push(n1->left);
        qu.push(n2->left);
        qu.push(n1->right);
        qu.push(n2->right);
    }
    return true;
}

int main(){
    TreeNode* t1 = new TreeNode(1, new TreeNode(2), NULL);
    TreeNode* t2 = new TreeNode(1, NULL, new TreeNode(2));
    //TreeNode* t2 = new TreeNode(1, new TreeNode(2), NULL);
    string result = isSameTree(t1, t2)? "TRUE" : "FALSE";
    cout<<result;
}