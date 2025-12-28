class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int total=m*n;
        vector<int>ans;
        int i=0,j=0;
        m--,n--;
        while(true){
            for(int t=j;t<=m;t++) ans.push_back(matrix[i][t]);
            i++;
            if(ans.size()==total) break;

            for(int t=i;t<=n;t++) ans.push_back(matrix[t][m]);
            m--;
            if(ans.size()==total) break;

            for(int t=m;t>=j;t--) ans.push_back(matrix[n][t]);
            n--;
            if(ans.size()==total) break;

            for(int t=n;t>=i;t--) ans.push_back(matrix[t][j]);
            j++;
            if(ans.size()==total) break;
        }
        return ans;
    }
};