class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, bool>Map;
        for(auto num : nums) Map[num] = true;
        for(int i = k; ; i += k){
            if(!Map.count(i)) return i;
        }
        return -1;
    }
};