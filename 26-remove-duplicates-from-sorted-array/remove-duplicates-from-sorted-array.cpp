class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = 1, n = nums.size();
        while(i < n){
            if(nums[j - 1] != nums[i]) nums[j++] = nums[i];
            i++;
        }
        return j;
    }
};