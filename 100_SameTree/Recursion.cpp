#include <iostream>
using namespace std;
//Recursion.  TC: O(n),  SC: O(n)
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
    if(t1 == NULL && t2 ==NULL) return true;
    if(t1 == NULL || t2 == NULL) return false;
    if(t1->val != t2->val) return false;

    return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
}

int main(){
    //TreeNode* t1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    //TreeNode* t2 = new TreeNode(1, new TreeNode(1), new TreeNode(2));
    //TreeNode* t2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* t1 = new TreeNode(1, new TreeNode(2), NULL);
    TreeNode* t2 = new TreeNode(1, NULL, new TreeNode(2));
    string result = isSameTree(t1, t2)? "TRUE" : "FALSE";
    cout<<result;
}