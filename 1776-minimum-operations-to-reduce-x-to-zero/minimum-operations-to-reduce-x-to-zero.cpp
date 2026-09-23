class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = INT_MAX;
        int prefix_sum = 0;
        unordered_map<int, int>Prefix;
        for(int i = 0; i < n; i++){
            prefix_sum += nums[i];
            if(prefix_sum > x) break;
            if(prefix_sum == x) ans = i + 1;
            Prefix[prefix_sum] = i + 1;
        }
        int suffix_sum = 0;
        for(int i = n - 1; i >= 0; i--){
            suffix_sum += nums[i];
            if(suffix_sum > x) break;
            if(suffix_sum == x) ans = min(ans, (n - i));
            int rem = x - suffix_sum;
            if(Prefix.count(rem) and Prefix[rem] - 1 < i) ans = min(ans, (n - i + Prefix[rem]));
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};