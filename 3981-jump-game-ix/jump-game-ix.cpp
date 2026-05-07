class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n),prefixMax(n,0);
        prefixMax[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixMax[i]=max(nums[i],prefixMax[i-1]);
        }
        pair<int,int>mini={nums[n-1],prefixMax[n-1]};
        for(int i=n-1;i>=0;i--){
            if(prefixMax[i]<=mini.first){
                ans[i]=prefixMax[i];
                mini.first=nums[i];
                mini.second=prefixMax[i];
            }
            else{
                ans[i]=max(prefixMax[i],mini.second);
                mini.first=min(mini.first,nums[i]);
                mini.second=max(mini.second,prefixMax[i]);
            }
        }
        return ans;  
    }
};