#include <iostream>
using namespace std;
#include <vector>
#include <queue>
//TC:O(H) SC:O(1)....H is resprent height of tree.
struct Tree{
    int val;
    Tree* left;
    Tree* right;
    Tree(): val(0),left(nullptr),right(nullptr){}
    Tree(int x): val(x),left(nullptr),right(nullptr){}
    Tree(int x, Tree* L, Tree* R): val(x),left(L),right(R){}
};

Tree* lowestCommonAncestorByRecursion(Tree* root, Tree* p, Tree* q){
    if((root->val > p->val) && (root->val > q->val)){
        return lowestCommonAncestorByRecursion(root->left, p,q);
    }
    if((root->val < p->val) && (root->val < q->val)){
        return lowestCommonAncestorByRecursion(root->right, p,q);
    }else{
        return root;
    }
}

Tree* lowestCommonAncestorByIterative(Tree* root, Tree* p, Tree* q){
    Tree* cur = root;
    while(1){
        if(p->val < cur->val && q->val < cur->val){
            cur = cur->left;
        }
        else if(p->val > cur->val && q->val > cur->val){
            cur = cur->right;
        }else {
            break;
        }
    }
    return cur;
}

int main(){
    Tree* root = new Tree(6, new Tree(2, new Tree(0), new Tree(4, new Tree(3),  new Tree(5))), new Tree(8, new Tree(7), new Tree(9)));
    Tree* p = new Tree(5);
    Tree* q = new Tree(4);
    Tree* result1 = lowestCommonAncestorByRecursion(root, p, q);
    cout << result1->val<<endl;
    cout << "--------------"<<endl;
     Tree* result2 = lowestCommonAncestorByIterative(root, p, q);
    cout << result2->val;
}