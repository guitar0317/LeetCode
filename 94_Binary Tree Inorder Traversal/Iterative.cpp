#include <iostream>
using namespace std;
#include <vector>
#include <stack>
//Iterative approach. TC: O(n), SC: O(n)
struct Tree{
    int val;
    Tree* left;
    Tree* right;
    Tree():val(0), left(nullptr), right(nullptr){}
    Tree(int x):val(x), left(nullptr), right(nullptr){}
    Tree(int x, Tree* left, Tree* right):val(x), left(left), right(right){}
};

class Solution{
public:
    void inorderTraversal(Tree* root){ 
        vector<int> res;
        stack<Tree*> sk;
        while(!sk.empty() || root){
            while(root){
                sk.push(root);
                root = root->left;
            }

            root = sk.top();
            sk.pop();
            res.push_back(root->val);
            root = root->right;
        }   

        for(auto a: res){
            cout << a << ", ";
        }
    }

};

int main(){
    Tree* root = new Tree(1, new Tree(2, new Tree(4), new Tree(5)), new Tree(3, new Tree(6), nullptr));
    Solution sol;
    sol.inorderTraversal(root);
    
}