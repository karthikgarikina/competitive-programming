class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size(),curn=0,total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
            curn+=i*nums[i];
        }
        int ans=curn;
        for(int i=n-1;i>=1;i--){
            curn+=total;
            curn-=nums[i]*n;
            ans=max(ans,curn);
        }
        return ans;
    }
};