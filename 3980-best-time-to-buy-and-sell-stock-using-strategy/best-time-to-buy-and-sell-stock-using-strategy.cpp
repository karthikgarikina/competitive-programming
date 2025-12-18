class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        vector<long long>prefixsum(n,0);
        prefixsum[0]=prices[0]*strategy[0];
        for(int i=1;i<n;i++){
            prefixsum[i]=prefixsum[i-1]+(prices[i]*strategy[i]);
        }
        int change=k/2;
        long long sum=0;
        for(int i=change;i<k;i++){
            sum+=prices[i];
        }
        long long ans=(sum+(prefixsum[n-1]-prefixsum[k-1]));
        ans=max(ans,prefixsum[n-1]);
        for(int i=k;i<n;i++){
            sum-=prices[i-change];
            sum+=prices[i];
            long long total=sum+(prefixsum[i-k])+(prefixsum[n-1]-prefixsum[i]);
            ans=max(ans,total);
        }
        return ans;
    }
};