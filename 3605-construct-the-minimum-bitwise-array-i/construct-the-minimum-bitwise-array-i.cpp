class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(auto i : nums){
            int firstUnset=(~i) & (i + 1);
            if(firstUnset==1) ans.push_back(-1);
            else if(firstUnset>i) ans.push_back((firstUnset>>1)-1);
            else ans.push_back(i-(firstUnset>>1));
        }
        return ans;
        
    }
};