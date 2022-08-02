#include <iostream>
using namespace std;
#include <vector>
#include <queue>

  //Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

void PrintVector(vector<vector<int>>& v){
    for(auto a:v){
        for(auto b : a){
            cout << b << ", ";
        }
        cout << endl;
    }
}

  int main(){
    TreeNode* root = new TreeNode(3, new TreeNode(9, nullptr, new TreeNode(6, new TreeNode(5), nullptr)), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    vector<vector<int>> res;
    
    if(!root){PrintVector(res); return 0;}
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    vector<int> cur_vec;

    while(!q.empty()){
        TreeNode* t = q.front();
        q.pop();
        if(t==NULL){
            res.push_back(cur_vec);
            cur_vec.clear();
            if(q.size()>0) q.push(NULL);
        }else{
            cur_vec.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
    }
    PrintVector(res);
    
  }