class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>prefix(m,vector<int>(n,0));
        int ans=0;
        int vali=INT_MAX, valj=INT_MAX;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='X'){
                    vali=min(i,vali);
                    valj=min(j,valj);
                    prefix[i][j]++;
                }
                else if(grid[i][j]=='Y'){
                    vali=min(i,vali);
                    valj=min(j,valj);
                    prefix[i][j]--;
                }

                if(i>0) prefix[i][j]+=prefix[i-1][j];
                if(j>0) prefix[i][j]+=prefix[i][j-1];
                if(i>0 and j>0) prefix[i][j]-=prefix[i-1][j-1];

                if((vali!=INT_MAX and vali<=i) and (valj!=INT_MAX and valj<=j) and prefix[i][j]==0) ans++;
            }
        }
        return ans;
    }
};