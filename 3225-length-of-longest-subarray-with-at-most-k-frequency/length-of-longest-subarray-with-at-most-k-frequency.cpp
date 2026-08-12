class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), st = 0, invalid = 0, ans = 0;
        unordered_map<int,int>Map;

        for(int i = 0; i < n; i++){
            Map[nums[i]]++;
            if(Map[nums[i]] > k) invalid = 1;
            while(invalid){
                Map[nums[st]]--;
                if(Map[nums[st]] == k) invalid = 0;
                st++;
            }
            ans = max(ans, (i - st + 1));
        }
        
        return ans;
    }
};