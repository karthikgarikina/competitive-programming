class Solution {
public:
    int findpath(int i, int j, vector<vector<int>>&obstacleGrid, vector<vector<int>>&dp){
        if(i>=obstacleGrid.size() || j>=obstacleGrid[0].size() || obstacleGrid[i][j]==1) return 0;
        if(i==obstacleGrid.size()-1 and j==obstacleGrid[0].size()-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=findpath(i,j+1,obstacleGrid,dp);
        int left=findpath(i+1,j,obstacleGrid,dp);
        return dp[i][j]=right+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return findpath(0,0,obstacleGrid,dp);
    }
};