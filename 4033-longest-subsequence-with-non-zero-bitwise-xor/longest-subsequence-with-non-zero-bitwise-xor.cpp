class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size(), Xor = 0;
        bool all_zeros = true;
        for(int &num : nums){
            Xor ^= num;
            if(num != 0) all_zeros = false;
        }

        if(all_zeros) return 0;
        if(Xor == 0) return n - 1;
        return n;
    }
};