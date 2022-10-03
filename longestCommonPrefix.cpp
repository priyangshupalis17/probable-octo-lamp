class Trie {
    struct TrieNode {
        unordered_map<char, TrieNode*> m;
        int nstr;
        TrieNode() {
            nstr = 0;
        }
    };
    TrieNode *root;
    public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode *cur = root;
        for(char x: word) {
            if(!cur->m.count(x)) {
                cur->m[x] = new TrieNode();
            }
            cur->nstr++;
            cur = cur->m[x];
        }
    }
    string findLongestPrefix(int len) {
        string res;
        TrieNode *cur = root;
        while(true) {
            if(cur->m.size() == 1 && cur->nstr == len) {
                res += cur->m.begin()->first;
                cur = cur->m.begin()->second;
            } else break;
        }
        return res;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        Trie t;
        for(string x: s) {
            if(x == "") return "";
            t.insert(x);
        }
        return t.findLongestPrefix(s.size());
    }
};
