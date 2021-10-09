class Trie {
    public:
    struct TrieNode {
        TrieNode *children[26];
        bool isEnd;
        TrieNode() {
            memset(children, 0, sizeof(children));
            isEnd = false;
        }
    };
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* cur = root;
        for(char x: word) {
            if(!cur->children[x - 'a']) cur->children[x - 'a'] = new TrieNode();
            cur = cur->children[x - 'a'];
        }
        cur->isEnd = true;
    }
    bool isPrefix(string word) {
        TrieNode *cur = root;
        for(char x: word) {
            if(!cur->children[x - 'a']) return false;
            cur = cur->children[x - 'a'];
        }
        return true;
    }
    bool search(string word) {
        TrieNode* cur = root;
        for(char x: word) {
            if(!cur->children[x - 'a']) return false;
            cur = cur->children[x - 'a'];
        }
        return cur->isEnd;
    }
};

class Solution {
public:
    void backtrack(set<string> &res, string &temp, vector<vector<char>> &board, Trie t, int i, int j) {
        if(i < 0 || i > board.size() - 1 || j < 0 || j > board[i].size() - 1 || board[i][j] == ' ' || !t.isPrefix(temp)) return;
        
        temp += board[i][j];
        
        if(t.search(temp)) res.insert(temp);
        
        char tmp = board[i][j];
        board[i][j] = ' ';
        
        backtrack(res, temp, board, t, i + 1, j);
        backtrack(res, temp, board, t, i - 1, j);
        backtrack(res, temp, board, t, i, j + 1);
        backtrack(res, temp, board, t, i, j - 1);
        
        board[i][j] = tmp;
        temp.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t;
        for(string word: words) t.insert(word);
        
        set<string> res;
        string temp = "";
        for(int i=0; i < board.size(); i++) {
            for(int j=0; j < board[i].size(); j++) {
                backtrack(res, temp, board, t, i, j);
            }
        }
        vector<string> ans;
        for(string x: res) ans.push_back(x);
        
        return ans;
    }
};
