#include <iostream>
using namespace std;
//TC: O(n), SC: O(n)
//Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

int maxDepth(TreeNode* root){
    if(!root) return 0;
    int maxLeft = maxDepth(root->left);
    int maxRight = maxDepth(root->right);
    return max(maxLeft,maxRight)+1;
}

  int main(){
    TreeNode* root = new TreeNode(3, new TreeNode(6), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    cout << maxDepth(root);
   
  }