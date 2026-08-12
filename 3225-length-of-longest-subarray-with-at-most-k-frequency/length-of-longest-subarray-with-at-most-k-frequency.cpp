class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), st = 0, invalid = 0, ans = 0;
        unordered_map<int,int>freq;

        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
            if( freq[nums[i]] > k ) invalid = 1;
            while(invalid){
                freq[nums[st]]--;
                if( freq[nums[st]] == k ) invalid = 0;
                st++;
            }
            ans = max(ans, (i - st + 1));
        }

        return ans;
    }
};