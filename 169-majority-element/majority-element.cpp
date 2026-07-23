class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, assume;
        for(auto i : nums){
            if(count == 0){
                count++;
                assume = i;
            }
            else if(assume == i) count++;
            else count--;
        }
        return assume;
    }
};