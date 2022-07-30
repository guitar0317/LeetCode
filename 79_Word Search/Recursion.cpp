#include <iostream>
using namespace std;
//Recursion: TC: O(N), SC: O(n)
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,NULL,NULL);
    }

    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode){
        if(!root) return true;
        if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val){
            return false;
        }
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
 };

int main(){
    //TreeNode* root = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    TreeNode* root = new TreeNode(5, new TreeNode(1), new TreeNode(4, new TreeNode(3), new TreeNode(6)));
    Solution sol;
    cout << sol.isValidBST(root);
}
