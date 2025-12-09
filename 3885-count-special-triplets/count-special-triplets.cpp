class Solution {
public:
    void find(const vector<int>& arr, long long &ans, int idx) {
        long long mod = 1e9 + 7;
        int left = lower_bound(arr.begin(), arr.end(), idx) - arr.begin();
        int right = arr.end() - upper_bound(arr.begin(), arr.end(), idx);
        ans = (ans + (1LL * left * right) % mod) % mod;
    }

    int specialTriplets(vector<int>& nums) {
        unordered_map<int, vector<int>> Map;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                Map[nums[i] / 2].push_back(i); 
            }
        }

        long long ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (Map.find(nums[i]) != Map.end()) {
                find(Map[nums[i]], ans, i);
            }
        }

        return ans;
    }
};
