class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int>Map;
        vector<int>ans=nums;
        int n=nums.size();
        for(int i=0;i<n;i++) Map[nums[i]]=i;
        for(auto i : operations){
            int a=i[0],b=i[1];
            ans[Map[a]]=b;
            Map[b]=Map[a];
            Map.erase(a);
        };
        return ans;
    }
};