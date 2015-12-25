class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int matrix[m][n];
        if(obstacleGrid[m-1][n-1]) return 0;
        
        bool found = false;
        for (int i=0; i<m; i++) {
            if (obstacleGrid[i][0]) found = true;
            if(!found) matrix[i][0] = 1;
            else matrix[i][0] = 0;
        }
        
        found = false;
        for (int i=0; i<n; i++) {
            if (obstacleGrid[0][i]) found = true;
            if(!found) matrix[0][i] = 1;
            else matrix[0][i] = 0;
        }
        
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                int topVal = (obstacleGrid[i-1][j]?0:matrix[i-1][j]);
                int leftVal = (obstacleGrid[i][j-1]?0:matrix[i][j-1]);
                matrix[i][j] = topVal+leftVal;
            }
        }
        
        return matrix[m-1][n-1];
    }
};