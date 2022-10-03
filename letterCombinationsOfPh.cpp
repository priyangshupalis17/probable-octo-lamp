class Solution {
public:
    void backtrack(vector<string> &a, vector<string> &res, string digits, string &temp, int start) {
        if(start == digits.size()) {
            res.push_back(temp);
            return;
        }
        for(int i=0; i < a[digits[start] - '0'].size(); i++) {
            temp.push_back(a[digits[start] - '0'][i]);
            backtrack(a, res, digits, temp, start + 1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return {};
        vector<string> a = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> res;
        string temp = "";
        backtrack(a, res, digits, temp, 0);
        return res;
    }
};
