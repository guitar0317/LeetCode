#include <iostream>
using namespace std;
#include <vector>


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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx=0;
        return build(preorder, inorder, rootIdx, 0, inorder.size()-1);
    }

    TreeNode* build(vector<int>& prorder, vector<int>& inorder, int& rootIdx, int left, int right){
        if(left > right) return NULL;
        int pivot = left;//find the root from inorder;
        while(inorder[pivot] != prorder[rootIdx] ){ 
            pivot++;
        }

        rootIdx++;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->left = build(prorder,inorder, rootIdx, left, pivot-1);
        newNode->right = build(prorder, inorder, rootIdx, pivot+1, right);
        return newNode;
    }
};

int main(){
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    Solution sol;
    TreeNode* res = sol.buildTree(preorder, inorder);
    int temp=1;
}