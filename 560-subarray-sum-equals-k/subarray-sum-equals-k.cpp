class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>Map;
        Map[0] = 1;
        int runningSum = 0, ans = 0;
        for(auto i : nums){
            runningSum += i;
            int need = runningSum - k;
            if(Map.count(need)) ans += Map[need];
            Map[runningSum]++;
        }
        return ans;
    }
};