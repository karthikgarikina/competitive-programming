class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxi = max_element(nums.begin(), nums.end()) - nums.begin();
        int l = min(mini, maxi), r = max(mini, maxi);
        return min( { (r + 1), (n - l), ((l + 1) + (n - r)) } );
    }
};