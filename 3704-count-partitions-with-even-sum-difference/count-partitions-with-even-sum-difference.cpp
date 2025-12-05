class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixSum(n);
        int ans=0;
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++) prefixSum[i]=prefixSum[i-1]+nums[i];
        for(int i=0;i<n-1;i++){
            if(abs(prefixSum[i]-(prefixSum[n-1]-prefixSum[i]))%2==0) ans++;
        }
        return ans;
    }
};