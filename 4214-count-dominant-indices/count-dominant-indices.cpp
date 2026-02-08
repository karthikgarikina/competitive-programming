class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size();
        vector<int>suffix(n,0);
        suffix[n-1]=nums[n-1];
        int ans=0,by=1;
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+nums[i];
            double avg=(suffix[i+1]*1.0)/by;
            by++;
            if(nums[i]>avg){
                ans++;
            }
        }
        return ans;
    }
};