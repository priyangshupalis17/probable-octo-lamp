class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a, int reqSum = 0) {
        if(a.empty()) return {};
        
        vector<vector<int>> res;
        
        sort(a.begin(), a.end());
        
        for(int i=0; i < a.size() - 1; i++) {
            // if(i > 0 && a[i] == a[i-1]) continue;
            int l = i + 1;
            int r = a.size()-1;
            int sum = reqSum - a[i];
            
            while(l < r) {
                if(sum == a[l] + a[r]) {
                    res.push_back(vector<int>());
                    res.back().insert(res.back().end(), {a[i], a[l], a[r]});
                    
                    // while(l < r && a[l] == a[l+1]) l++;
                    // while(l < r && a[r-1] == a[r]) r--;
                }
                if(sum < a[l] + a[r]) r--;
                else l++;
            }
        }
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
