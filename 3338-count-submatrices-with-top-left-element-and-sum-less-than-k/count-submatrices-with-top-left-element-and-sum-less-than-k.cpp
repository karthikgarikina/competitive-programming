class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>>prefix(m,vector<int>(n));
        vector<int>col(m);
        col[0]=grid[0][0];
        for(int i=0;i<m;i++){
            if(i!=0) col[i]=(col[i-1]+grid[i][0]);
            prefix[i][0]=grid[i][0];
            for(int j=1;j<n;j++) prefix[i][j]=(prefix[i][j-1]+grid[i][j]);
        }
        int ans=0;
        int len=0;
        while(len<n || len<m){
            if(len<m){
                if(col[len]<=k) ans++;
            }
            if(len<n and len!=0){
                if(prefix[0][len]<=k) ans++;
            }
            
            int gridSum=0;
            if (len>=n || len==0){
                len++;
                continue;
            }
            for(int i=0;i<m;i++){
                gridSum+=prefix[i][len];
                if(gridSum<=k and i!=0){
                    ans++;
                }
            }

            len++;
        }
        return ans;
    }
};