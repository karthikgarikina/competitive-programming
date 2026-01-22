class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;

        for(auto i : nums){
            int firstUnset=(~i) & (i + 1);
            firstUnset=(firstUnset>>1);
            if(i==2) ans.push_back(-1);
            else ans.push_back(i-(firstUnset));
        }
        return ans;
          
    }
};