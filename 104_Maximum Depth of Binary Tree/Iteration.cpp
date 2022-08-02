#include <iostream>
using namespace std;
#include <vector>
#include <queue>

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

int maxDepth(TreeNode* root){
    vector<vector<int>> res;
    queue<TreeNode*> q;
    if(!root) return 0;
    q.push(root);
    q.push(NULL);
    vector<int> cur;
    while(!q.empty()){
        TreeNode* t = q.front();
        q.pop();

        if(t==NULL){
            res.push_back(cur);
            cur.clear();
            if(q.size()>0) q.push(NULL);
        }else{
            cur.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
    }
    return res.size();
}

int main(){
    TreeNode* root = new TreeNode(3, new TreeNode(6), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    cout << maxDepth(root);
   
}