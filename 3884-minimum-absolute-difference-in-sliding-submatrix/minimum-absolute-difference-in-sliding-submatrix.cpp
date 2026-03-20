class Solution {
public:
    int find(int i, int j, int m, int n, vector<vector<int>>&grid ){
        set<int>st;
        for(int k=i;k<m;k++){
            for(int l=j;l<n;l++) st.insert(grid[k][l]);
        }
        if(st.size()<2) return 0;
        int ans=INT_MAX;
        for(auto it=st.begin();next(it)!=st.end();it++){
            ans=min(ans,abs(*it-*next(it)));
        }
        return ans;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            vector<int>ds;
            for(int j=0;j<n;j++){
                if( (i+k>m) || (j+k>n)) break;
                ds.push_back(find(i,j,i+k,j+k,grid));
            }
            if(!ds.empty()) ans.push_back(ds);
        }
        return ans;
    }
};