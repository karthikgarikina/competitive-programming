class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        unordered_map<int, int>Map;
        for(int i = 0; i < len; i++){

            for(int j = 0; j < len; j++){

                if(i == j) continue;
                if(nums[i] + nums[j] == target) return {i, j};
            }
        }
        return {};
    }
};