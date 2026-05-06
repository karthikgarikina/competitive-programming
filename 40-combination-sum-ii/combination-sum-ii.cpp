class Solution {
public:
    void helper(vector<int>&nums,int idx, int tar, vector<int>&ds, vector<vector<int>>&ans){
        if(tar==0){
            ans.push_back(ds);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            if(i>idx and nums[i]==nums[i-1]) continue;
            if(nums[i]<=tar){
                ds.push_back(nums[i]);
                helper(nums,i+1,tar-nums[i],ds,ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        helper(candidates,0,target,ds,ans);
        return ans;
    }
};