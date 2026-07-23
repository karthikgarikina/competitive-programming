class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int bits = log2(n) + 1;
        int ans = (1 << bits);
        if(n < 3) ans--;
        if(n == 2) ans--;
        return ans;
    }
};