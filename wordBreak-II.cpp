/**
 * The time complexity of this solution is O(M * N * L), 
 * where M is the number of rows in the board, 
 * N is the number of columns in the board, 
 * and L is the average length of the words in the words list. 
 * The space complexity is O(K), 
 * where K is the total number of characters in all the words in the words list.
 */

class Trie {
public:    
    Trie* ch[128] = {};
    bool end = false;
};
class Solution {
private:
    int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    void found(vector<vector<char>>& board, Trie* root, int i, int j, string res, vector<string>&ans){
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j] == ' ') return;
        if(root->ch[board[i][j]] == NULL) return;
        root = root->ch[board[i][j]];
        res += board[i][j];
        if(root->end) ans.push_back(res);
        root->end = false; // avoid repetation
        char ch = board[i][j];
        board[i][j] = ' ';
        for(auto &[dr, dc]: dir){
            found(board, root, i+dr, j+dc, res, ans);
        }
        board[i][j] = ch;
    }
    void insert(Trie *t, string &word){
        for(char c:word){
            if(!t->ch[c])
                t->ch[c] = new Trie();
            t=t->ch[c];
        }
        t->end = true;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *trie = new Trie();

        //insertion into trie
        for(string &word:words){
            insert(trie, word);
        }
        vector<string>ans;
        Trie *root = trie;
        for(int i=0;i<size(board);i++){
            for(int j=0;j<size(board[0]);j++){
                found(board, root, i, j, "", ans);
            }
        }
        return ans;
    }
};