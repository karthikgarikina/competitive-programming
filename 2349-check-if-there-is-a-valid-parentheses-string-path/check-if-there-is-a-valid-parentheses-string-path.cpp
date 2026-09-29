class Solution {
public:
    bool checkAll(vector<vector<char>>& grid, int i, int j, int cur, vector<vector<vector<bool>>>&dp){
        if(i >= grid.size() || j >= grid[0].size()) return false;
        if(grid[i][j] == '(') cur++;
        else cur--;
        if(cur < 0) return false;
        if(i == grid.size() - 1 && j == grid[0].size() - 1 and cur == 0) return true;
        if(!dp[i][j][cur]) return false;

        if( checkAll(grid, i + 1, j, cur, dp) ) return true;
        if( checkAll(grid, i, j + 1, cur, dp) ) return true;
        return dp[i][j][cur] = false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<bool>>>dp(m, vector<vector<bool>>(n, vector<bool>((m + n), 1)));
        return checkAll(grid, 0, 0, 0, dp);
    }
};