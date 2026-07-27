class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int st = 0, ed = nums.size() - 1;
        while(true){
            int sum = nums[st] + nums[ed];
            if(sum == target) return {st + 1, ed + 1};
            else if(sum < target) st++;
            else ed--;
        }
        return {-1, -1};
    }
};