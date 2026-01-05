class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        int n=matrix.size(), mini=INT_MAX, cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val=matrix[i][j];
                mini=min(abs(val),mini);
                ans+=abs(val);
                if(val<0){
                    cnt++;
                }
            }
        }

        if(cnt%2==0) return ans;
        else return (ans-(2*mini));
    }
};