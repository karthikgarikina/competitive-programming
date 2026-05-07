class Solution {
public:
    int INT_MAXX=1e4+1;
    int helper(int idx, vector<int>& coins, int amo, map<pair<int,int>,int>&dp){
        if(idx==coins.size() || amo<0) return INT_MAXX;
        if(amo==0){
            return 0;
        }
        if(dp.find({idx,amo})!=dp.end()) return dp[{idx,amo}];
        int pic=helper(idx,coins,amo-coins[idx],dp);
        int notpic=helper(idx+1,coins,amo,dp);
        return dp[{idx,amo}]=min(pic+1,notpic);
    }
    int coinChange(vector<int>& coins, int amount) {
        map<pair<int,int>,int>dp;
        int ans=helper(0,coins,amount,dp);
        return (ans>=INT_MAXX)?-1:ans;
    }
};