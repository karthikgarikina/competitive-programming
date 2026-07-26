class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int l1 = 1000, l2 = 1000, r1 = -1000, r2 = -1000, r3 = -1000;
        for(auto num : nums){
            if(num > r1){
                r3 = r2, r2 = r1, r1 = num;
            }
            else if(num > r2){
                r3 = r2, r2 = num;
            }
            else if(num > r3) r3 = num;

            if(num < l1){
                l2 = l1, l1 = num;
            }
            else if(num < l2) l2 = num;
        }
        return max(l1 * l2 * r1, r1 * r2 * r3);
    }
};