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


        vector<pair<long long,long long>>dp(4,{INT_MAX,INT_MAX});
        dp[3]={vals[0].first,vals[0].second};


        for(int i=1;i<vals.size();i++){
            dp[0]=dp[1],dp[1]=dp[2],dp[2]=dp[3],dp[3]={INT_MAX,INT_MAX};

            long long newPower=vals[i].second,newKey=vals[i].first;
            long long add=0,idx=2;
            for(int j=2;j>=0;j--){
                long long oldKey=dp[j].first;
                if(oldKey<newKey-2){
                    idx=j;
                    add+=newPower;
                    break;
                }
            }
            long long finalPower=max(newPower,max(add+dp[idx].second,dp[2].second));
            dp[3]={newKey,finalPower};
        }
        return dp[3].second; 
        

    }
};