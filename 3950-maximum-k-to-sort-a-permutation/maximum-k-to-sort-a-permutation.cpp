class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size(), ans = -1;
        for(int i = 0; i < n; i++){
            if(i != nums[i]){
                if(ans == -1) ans = i;
                else ans = (ans & i);
            }
        }
        return (ans == -1) ? 0 : ans;
    }
};