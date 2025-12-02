class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int>X;
        for(auto i : points){
            X[i[1]]++;
        }
        vector<long long>lines;
        for(auto i : X){
            int cnt=i.second;
            long long total=(1LL*(cnt)*(cnt-1))/2;
            if(total!=0) lines.push_back(total);
        }
        long long mod=1e9+7,sum=0,sumsq=0,inv2=500000004,n=lines.size();
        for(auto l : lines){
            sum=(sum+l)%mod;
            sumsq=(sumsq+(l*l)%mod)%mod;
        }
        long long temp=(((sum*sum)%mod - sumsq +mod)%mod);
        long long ans=(temp*inv2)%mod;
        return ans;
        
        
    }
};