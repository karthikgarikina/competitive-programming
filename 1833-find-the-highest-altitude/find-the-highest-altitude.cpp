class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, cur = 0;
        for(auto i : gain){
            cur += i;
            ans = max(ans,cur);
        }
        return ans;
    }
};