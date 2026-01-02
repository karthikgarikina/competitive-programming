class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size()/2;
        unordered_map<int,int>Map;
        for(auto i : nums) Map[i]++;
        for(auto i : Map){
            if(i.second==n) return i.first;
        }
        return -1;
    }
};