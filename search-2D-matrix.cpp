class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int M = matrix.size();
        const int N = matrix[0].size();
        
        int minrow = 0;
        int maxrow = M - 1;
        int midrow = (minrow + maxrow)/2;
        
        // Perform binary search
        while (minrow <= maxrow) {
            midrow = (minrow + maxrow) / 2;
            if (matrix[midrow][0] > target) { // Array too high
                maxrow = midrow - 1;
            }
            else if (matrix[midrow][N - 1] < target) { // Array too low
                minrow = midrow + 1;
            }
            else if ((matrix[midrow][0] <= target) && (matrix[midrow][N - 1] >= target)) {
                maxrow = -1;
                minrow = midrow;
            }
        }
        
        // Check if the row is acceptable
        if ((matrix[midrow][0] > target) || (matrix[midrow][N - 1] < target))
            return false;
        
        // Perform binary search on row
        int mincol = 0;
        int maxcol = N - 1;
        int medcol;
        while (mincol <= maxcol) {
            medcol = (mincol + maxcol) / 2;
            if (matrix[midrow][medcol] < target) {
                mincol = medcol + 1;
            }
            else if (matrix[midrow][medcol] > target) {
                maxcol = medcol - 1;
            }
            else {
                return true;   
            }
        }
        return false;
    }
};
