class Solution {
public:
    int findMaxi(vector<int>count){
        int n=count.size(), maxArea=0;

        for(int i=0;i<n;i++){
            int mini=INT_MAX;
            for(int j=i;j<n;j++){
                mini=min(mini,count[j]);
                int area=(j-i+1)*mini;
                maxArea=max(area,maxArea);
            }
        }
        return maxArea;
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
            int maxArea=findMaxi(count);
            ans=max(ans,maxArea);
        }
        return ans;
    }
};