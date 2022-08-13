#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* L;
    TreeNode* R;
    TreeNode(): val(0), L(nullptr), R(nullptr){}
    TreeNode(int x): val(x), L(nullptr), R(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), L(left), R(right){}
};

class Solution{
public:
    static bool checkTree(TreeNode* root){
       return ((root->L->val+root->R->val) == root->val); 
    }

};

int main(){
    //TreeNode* root = new TreeNode(10, new TreeNode(3), new TreeNode(7));
    TreeNode* root = new TreeNode(12, new TreeNode(3), new TreeNode(7));
    cout << (Solution::checkTree(root)? "True":"False");
}