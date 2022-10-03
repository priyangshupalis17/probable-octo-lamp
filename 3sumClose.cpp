class Solution {
public:
    int threeSumClosest(vector<int>& a, int t) {
        sort(a.begin(), a.end());
        
        int res(0), md(INT_MAX);
        
        for(int i=0; i < a.size() - 1; i++) {
            int l = i + 1, r = a.size() - 1;
            while(l < r) {
                int sum = a[i] + a[l] + a[r];
                int cd = abs(t - sum);
                if(cd == 0) return t;
                if(cd < md) {
                    res = sum;
                    md = cd;
                }
                if(sum < t) l++;
                else r--;
            }
        }
        return res;
    }
};
