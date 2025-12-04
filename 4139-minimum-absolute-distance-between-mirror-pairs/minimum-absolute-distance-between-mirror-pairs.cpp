class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>Map;
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            int reversed_num = stoi(s);
            if(Map.find(nums[i])!=Map.end()){
                int idx=Map[nums[i]];
                ans=min(ans,abs(i-idx));
            }
            Map[reversed_num]=i;
        }
        return (ans==INT_MAX)?-1:ans;
    }
};