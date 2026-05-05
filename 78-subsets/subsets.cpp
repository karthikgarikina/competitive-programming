class Solution {
public:
    void findout(vector<int>& nums, int idx, vector<int>&ds, vector<vector<int>>&ans){
        if(idx==nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[idx]);
        findout(nums,idx+1,ds,ans);
        ds.pop_back();
        findout(nums,idx+1,ds,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        findout(nums,0,ds,ans);
        return ans;
    }
};