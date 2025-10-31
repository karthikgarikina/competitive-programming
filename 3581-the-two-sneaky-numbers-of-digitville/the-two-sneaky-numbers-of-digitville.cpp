class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int>Map;
        vector<int>ans;
        for(auto i : nums){
            Map[i]++;
            if(Map[i]==2) ans.push_back(i);
        }
        return ans;
        
    }
};