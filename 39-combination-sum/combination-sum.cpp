class Solution {
public:
    void helper(vector<int>&nums, int idx, int tar, vector<int>&ds, vector<vector<int>>&ans){
        if(tar==0){
            ans.push_back(ds);
            return;
        }
        if(idx==nums.size()) return;
        if(nums[idx]<=tar){
            ds.push_back(nums[idx]);
            helper(nums,idx,tar-nums[idx],ds,ans);
            ds.pop_back();
        }
        helper(nums,idx+1,tar,ds,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>>ans;
        helper(candidates,0,target,ds,ans);
        return ans;
    }
};