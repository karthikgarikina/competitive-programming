class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0] + 1;

        int prefix = nums[0], idx = 1;
        while(idx < n){
            if(nums[idx - 1] + 1 == nums[idx]){
                prefix += nums[idx];
            }
            else break;
            idx++; 
        }
        unordered_map<int, bool>Map;
        Map[nums[0]] = true;
        for(int i = idx; i < n; i++) Map[nums[i]] = true;
        while(true){
            if(Map.find(prefix) == Map.end()) return prefix;
            prefix++;
        }
        return prefix;
    }
};