class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int matrix[m][n];
        matrix[0][0] = grid[0][0];
        for (int i=1; i<m; i++) {
            matrix[i][0] = matrix[i-1][0]+grid[i][0];
        }
        
        for (int i=1; i<n; i++) {
            matrix[0][i] = matrix[0][i-1]+grid[0][i];
        }
        
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                matrix[i][j] = min(matrix[i-1][j],matrix[i][j-1])+grid[i][j];
            }
        }
        
        return matrix[m-1][n-1];
    }
};