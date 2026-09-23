class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), ans = INT_MAX, prefix_sum = 0, pre = -1;
        for(int i = 0; i < n; i++){
            if(prefix_sum + nums[i] > x) break;
            prefix_sum += nums[i];
            if(prefix_sum == x) ans = i + 1;
            pre = i;
        }
        int suffix_sum = 0;
        for(int i = n - 1; i >= 0; i--){
            suffix_sum += nums[i];
            while(pre >= 0 and ( pre >= i || (prefix_sum + suffix_sum) > x) ){
                prefix_sum -= nums[pre--];
            }
            if(prefix_sum + suffix_sum == x) ans = min(ans, (n - i + pre + 1));
            if(prefix_sum == 0 and suffix_sum > x) break;
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};