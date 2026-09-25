class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size(), mini = nums[n - 1];
        long long ans = 0;
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] > mini){
                int need = nums[i] / mini;
                if(nums[i] % mini != 0) need++;
                mini = min(mini, nums[i] / need);
                ans += need - 1;
            }
            else mini = min(mini, nums[i]);
        }
        return ans;
    }
};