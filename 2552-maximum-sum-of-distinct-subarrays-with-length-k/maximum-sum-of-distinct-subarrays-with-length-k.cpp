class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,bool>Map;
        long long sum=0,ans=0;
        int n=nums.size(),st=0;
        for(int i=0;i<n;i++){
            while(Map.find(nums[i])!=Map.end() || (i-st+1)>k){
                Map.erase(nums[st]);
                sum-=nums[st];
                st++;
            }
            Map[nums[i]]=true;
            sum+=nums[i];
            if(i-st+1==k){
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};