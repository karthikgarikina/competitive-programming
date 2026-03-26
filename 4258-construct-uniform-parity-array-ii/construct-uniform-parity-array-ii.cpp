class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd=0,even=0,mini=INT_MAX;
        for(auto i : nums1){
            if(i%2!=0) odd++;
            else even++;
            mini=min(mini,i);
        }
        if(odd==0 || even==0) return true;
        if(mini%2!=0) return true;
        return false;
    }
};