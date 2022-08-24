#include <iostream>
#include <vector>
using namespace std;

struct TrieNode{
    TrieNode* children[26]={};
    string* word;

    void addWord(string& word){
        TrieNode* cur = this;
        for(char c : word){
            c-='a';
            if(cur->children[c]==nullptr) cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->word =&word;
    }
};

class Solution{
public:
    int m,n;
    int DIR[5] = {0,1,0,-1,0};
    vector<string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
        m = board.size();
        n = board[0].size();
        TrieNode trie;

        for(string& word:words){
            trie.addWord(word);
        }

        for(int r=0; r<m; r++){
            for(int c=0; c<n; c++){
                dfs(board, r, c, &trie);
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* cur){
        if(r < 0 || r==m || c<0 || c==n || board[r][c]=='#' || cur->children[board[r][c]-'a']==nullptr)
            return;
        char orgChar = board[r][c];
        cur = cur->children[orgChar-'a'];
        if(cur->word != nullptr){
            ans.push_back(*cur->word);
            cur->word = nullptr;
        }
        board[r][c]='#';
        for(int i=0; i<4 ; i++){
            dfs(board, r+DIR[i], c+DIR[i+1], cur);
        }
        board[r][c]=orgChar;
    }

    void PrintAns(){
        for(auto s:ans){
            cout << s <<endl;
        }
    }

};

int main(){
    vector<vector<char>> board = 
    //{{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    {{'a','b'},{'c','d'}};

    vector<string> words =
    //{"eat","oath"};
    {"abcd"};
    Solution sol;
    sol.findWords(board, words);
    sol.PrintAns();

}