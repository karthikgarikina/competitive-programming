class Solution {
public:
    int solve(vector<int>& nums) {
        int n = nums.size();
        int inc = -1, dec = -1;

        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
                if(dec == -1) dec = i;
                else {
                    dec = INT_MAX;
                    break;
                }
            }
        }

        if(dec != -1 && nums[n - 1] < nums[0])
            dec = INT_MAX;

        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[i - 1]) {
                if(inc == -1) inc = i;
                else {
                    inc = INT_MAX;
                    break;
                }
            }
        }

        if(inc != -1 && nums[n - 1] > nums[0])
            inc = INT_MAX;

        if(inc == -1) return 0;
        if(dec == -1) return 1;
        if(inc == INT_MAX && dec == INT_MAX) return INT_MAX;
        if(inc == INT_MAX) return dec + 1;
        if(dec == INT_MAX) return inc;

        return min(inc, dec + 1);
    }

    int minOperations(vector<int>& nums) {
        int ans = solve(nums);
        reverse(nums.begin(), nums.end());
        int rev = solve(nums);
        if(rev != INT_MAX)
            ans = min(ans, rev + 1);

        return ans == INT_MAX ? -1 : ans;
    }
};