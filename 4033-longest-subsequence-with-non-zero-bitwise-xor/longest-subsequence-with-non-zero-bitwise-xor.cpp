class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int freq[32] = {0};
        for(auto i : nums){
            bitset<32>bb(i);
            for(int p = 0; p < 32; p++){
                if(bb[p] == 1) freq[p]++;
            }
        }
        bool allZeros = true, allEven = true;
        for(int i = 0; i < 32; i++){
            if(freq[i] != 0) allZeros = false;
            if(freq[i]&1) allEven = false;
        }

        if(allZeros) return 0;
        if(allEven) return n - 1;
        return n;
    }
};