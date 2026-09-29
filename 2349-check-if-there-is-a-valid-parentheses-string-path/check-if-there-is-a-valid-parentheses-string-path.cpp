class Solution {
public:
    bool checkAll(vector<vector<char>>& grid, int i, int j, int cur, vector<vector<vector<int>>>&dp, int path_len){
        if(i >= grid.size() || j >= grid[0].size()) return false;

        if(grid[i][j] == '(') cur++;
        else cur--;
        int idx = cur + path_len;
        if(cur < 0){
            dp[i][j][idx] = 1;
            return false;
        }
        if(i == grid.size() - 1 && j == grid[0].size() - 1 and cur == 0) return true;
        if(dp[i][j][idx]) return false;

        if(checkAll(grid, i + 1, j, cur, dp, path_len)) return true;
        if(checkAll(grid, i, j + 1, cur, dp, path_len)) return true;
        dp[i][j][idx] = 1;
        return false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int path_len = m + n - 1;
        int all_pos = (2 * path_len) + 1;
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(all_pos, 0)));
        int cur = 0;
        return checkAll(grid, 0, 0, cur, dp, path_len);
    }
};