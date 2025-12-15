class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        long long ans=0,cnt=1;
        for(int i=1;i<n;i++){
            if(prices[i-1]==prices[i]+1){
                cnt++;
            }
            else{
                ans+=((cnt*(cnt+1))/2);
                cnt=1;
            }
        }
        ans+=((cnt*(cnt+1))/2);
        return ans;
    }
};

