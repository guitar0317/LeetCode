#include <iostream>
using namespace std;
#include <queue>


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0),left(nullptr),right(nullptr){}
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode* L, TreeNode* R): val(x),left(L),right(R){}
};

class Solution{
public:
    queue<TreeNode*> qu;
    TreeNode* inverTree(TreeNode* root){
        if(!root) return NULL;
        qu.push(root);

        while(!qu.empty()){
            TreeNode* tmp = qu.front();
            qu.pop();

            //if(tmp->left !=NULL || tmp->right !=NULL){
                TreeNode* tt = tmp->left? tmp->left: NULL;
                tmp->left = tmp->right? tmp->right:NULL;
                tmp->right = tt;
                if(tmp->left!=NULL) qu.push(tmp->left);
                if(!tmp->right!=NULL)qu.push(tmp->right);
            //}
        }

        return root;
    }
};

int main(){
    //TreeNode* root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7, new TreeNode(6), new TreeNode(9)));
     TreeNode* root = new TreeNode(1, new TreeNode(2),NULL);

    Solution sol;
    sol.inverTree(root);
}