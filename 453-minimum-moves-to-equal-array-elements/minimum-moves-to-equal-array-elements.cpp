class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0, mini = *min_element(nums.begin(), nums.end());
        for(auto num : nums) ans += (num - mini);
        return ans;
    }
};