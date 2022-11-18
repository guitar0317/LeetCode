#include <iostream>
#include <vector>
using namespace std;

struct Tree{
    int val;
    Tree* left,*right;
    Tree():val(0),left(nullptr),right(nullptr){}
    Tree(int x):val(x),left(nullptr),right(nullptr){}
    Tree(int x, Tree* l, Tree* r):val(x),left(l),right(r){}
};

bool isValidBST(Tree* root, Tree* minT, Tree* maxT){
    if(!root) return true;
    if((minT && root->val <= minT->val) || (maxT && root->val >= maxT->val))
        return false;
    
    return isValidBST(root->left, minT, root) && isValidBST(root->right, root, maxT);
}

void InOrder(Tree* root, vector<int>& v){
    if(!root) return;
    InOrder(root->left, v);
    v.push_back(root->val);
    InOrder(root->right, v);
}

bool isValidBST(Tree* root){
    vector<int> v;

    if(!root) return false;
    
    InOrder(root, v);

    for(vector<int>::iterator it = v.begin()+1; it!=v.end(); it+=2){
        int a = *it;
        int b = *(--it);
        if(a <= b)
            return false;
    }


}

int main(){
    Tree* root = new Tree(5, new Tree(1), new Tree(7, new Tree(6), new Tree(8)));

    cout << (isValidBST(root, NULL, NULL)?"True":"False")<<endl;


    cout << (isValidBST(root)?"True":"False")<<endl;
}

