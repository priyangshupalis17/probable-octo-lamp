class Solution {
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool isValid(int i, int j, int m, int n) {
        if((i >= m || j >= n) || (i < 0 || j < 0))
            return false;
        return true;
    }
    int longestIncreasingPathMemo(vector<vector<int>>& matrix, int i, int j, int m, int n, vector<vector<bool>>& visited, vector<vector<int>>& memo) {
        if(!isValid(i, j , m, n))
            return 0;
        
        if(memo[i][j] != -1)
            return memo[i][j];
         
        int x = 0;
        for(int k = 0;  k < 4; k++) {
            int xcord = i+dir[k][0];
            int ycord = j + dir[k][1];
            if(isValid(xcord, ycord, m, n) && matrix[xcord][ycord] > matrix[i][j] && visited[xcord][ycord] == false) {
                visited[xcord][ycord] = true;
                x = max(x, 1 + longestIncreasingPathMemo(matrix, xcord, ycord, m, n, visited, memo));
                visited[xcord][ycord] = false;
            }
        }
        return memo[i][j] = x;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> memo(m, vector<int>(n, -1));
        int ans = INT_MIN;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                visited[i][j] = true;
                ans = max(ans,  1 + longestIncreasingPathMemo(matrix, i, j, m, n, visited, memo));
                visited[i][j] = false;
            }
        }
        return ans;
    }
};
