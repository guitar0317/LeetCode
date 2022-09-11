#include <iostream>
using namespace std;


  //Definition for a binary tree node.
  struct Tree {
      int val;
      Tree *left;
      Tree *right;
      Tree() : val(0), left(nullptr), right(nullptr) {}
      Tree(int x) : val(x), left(nullptr), right(nullptr) {}
     Tree(int x, Tree *left, Tree *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    bool isSubtree(Tree* root, Tree* subRoot) {
       if(!root) return false;
       else if(isSameTree(root, subRoot)){
        return true;
       }else{
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
       }
    }

    bool isSameTree(Tree* s, Tree* t){
        if(!s || !t) return s==NULL && t==NULL;
        else if(s->val == t->val){
            return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
        }else {
            return false;
        }
    }
};

int main(){
    Tree* root = 
    //new Tree(3, new Tree(4, new Tree(1), new Tree(2)), new Tree(5));
    new Tree(3, new Tree(4, new Tree(1), new Tree(2, new Tree(0), new Tree(6))), new Tree(5));
    Tree* sub = new Tree(4, new Tree(1), new Tree(2));
    Solution s;
    cout << s.isSubtree(root, sub);
}