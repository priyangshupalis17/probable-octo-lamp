class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;
        
        int i = 0, j = matrix[0].size()-1, cur;
        
        while(i < matrix.size() && j >= 0) {
            cur = matrix[i][j];
            if(target == cur) return true;
            else if(target > cur) i++;
            else j--;
        }
        
        return false;
    }
};
