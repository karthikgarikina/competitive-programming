class Solution {
public:
    int findMaxi(vector<int>count){
        int n=count.size(),maxi=0;
        for(int i=0;i<n;i++){
            int mini=INT_MAX;
            for(int j=i;j<n;j++){
                mini=min(mini,count[j]);
                int score=(j-i+1)*mini;
                maxi=max(score,maxi);
            }
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int>count(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') count[j]++;
                else count[j]=0;
            }
            int maxi=findMaxi(count);
            ans=max(ans,maxi);
        }
        return ans;
    }
};