class Solution {
public:
    int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    int dfs(vector<vector<int>>& a, int i, int j, vector<vector<bool>> vis,
            vector<vector<int>> memo) {
        if(i < 0 || j < 0 || i >= a.size() || j >= a[i].size() || vis[i][j]) return;
        if(memo[i][j] != -1) return memo[i][j];
        
        int x=0;
        for(int i=0; i < 4; i++) {
            
        }
    }
    int longestIncreasingPath(vector<vector<int>>& a) {
        vector<vector<bool>> vis(a.size(), vector<bool> (a[0].size(), false));
        vector<vector<int>> memo(a.size(), vector<int> (a[0].size(), -1));
        for(int i=0; i < a.size(); i++) {
            for(int j=0; j < a[i].size(); j++) {
                res = max(res, dfs(a, i, j, vis, memo));
            }
        }
        return res;
    }
};
