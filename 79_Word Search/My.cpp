#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<char>>& board, int i, int j, string& word){
    if(!word.size()) return true;

    if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[0]){
        return false;
    }

    char c = board[i][j];
    board[i][j] = '*';
    string s = word.substr(1);
    bool ret = dfs(board, i-1, j, s) || dfs(board, i+1, j, s) || dfs(board, i, j+1, s) || dfs(board, i, j-1, s);
    board[i][j] = c;
    return ret;
}

bool exist(vector<vector<char>>& board, string word){
    vector<vector<int>> store;

    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(board[i][j] == word[0]){
                if(dfs(board, i, j, word)){
                    return true;
                }
            }
        }
    }

   /* if(store.size() < 1) return false;
    
    int move[][]={"1,1"};

    for(int i=1; i<word.size(); i++){
        int x = store[0].front();
        int y = store[0].back();
    }*/

    return false;
}

int main(){
    vector<vector<char>> board ={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    cout << exist(board, word);
 
}