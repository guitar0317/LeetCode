#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>

struct Tree{
    int val;
    Tree* left;
    Tree* right;
    Tree(): val(0),left(nullptr),right(nullptr){}
    Tree(int x): val(x),left(nullptr),right(nullptr){}
    Tree(int x, Tree* L, Tree* R): val(x),left(L),right(R){}
};

int main(){
    Tree* root = new Tree(3, new Tree(1, NULL, new Tree(2)), new Tree(4));
    int k=1;
    if(!root) return 0;
    vector<int> ans;
    queue<Tree*> q;
    q.push(root);

    while(!q.empty()){
        Tree* tmp = q.front();
        q.pop();

        ans.push_back(tmp->val);
        if(tmp->left != NULL) q.push(tmp->left);
        if(tmp->right != NULL) q.push(tmp->right);
    }

    sort(ans.begin(), ans.end());
    cout << ans[k-1];
}