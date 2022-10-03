class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> a(256);
        int begin(0), end(0), res(0), counter(0);
        while(end < s.length()) {
            if(a[s[end++]]++ == 1) counter++;
            while (counter > 0) if(a[s[begin++]]-- == 2) counter--;
            res = max(res, end - begin);
        }
        return res;
    }
};
