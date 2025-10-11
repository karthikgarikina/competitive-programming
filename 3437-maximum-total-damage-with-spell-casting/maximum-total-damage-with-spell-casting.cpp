class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long,long long>Map;
        for(auto i : power){
            if(Map.find(i)==Map.end()) Map[i]=i;
            else{
                Map[i]=i+Map[i];
            }
        }
        vector<pair<long long,long long>>vals;
        for(auto i : Map){
            vals.push_back({i.first,i.second});
        }
        sort(vals.begin(),vals.end());

        long long ans=0;
        vector<pair<long long,long long>>dp(4,{INT_MAX,INT_MAX});
        dp[3]={vals[0].first,vals[0].second};
        for(int i=1;i<vals.size();i++){
            long long add=0,idx=2;
            dp[0]=dp[1],dp[1]=dp[2],dp[2]=dp[3];
            dp[3]={INT_MAX,INT_MAX};
            for(int j=3;j>=0;j--){
                if(dp[j].first<vals[i].first-2){
                    idx=j;
                    add+=vals[i].second;
                    break;
                }
            }
            cout<<idx<<"  ";
            // dp[0]=dp[1],dp[1]=dp[2],dp[2]=dp[3];
            dp[3]={vals[i].first,max(vals[i].second,max(add+dp[idx].second,dp[2].second))};
            cout<<dp[3].second<<" ";
             
        }
        return dp[3].second; 
        

    }
};