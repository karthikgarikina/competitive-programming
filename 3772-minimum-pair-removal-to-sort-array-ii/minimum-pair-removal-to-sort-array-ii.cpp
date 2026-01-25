class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        vector<long long>val(nums.begin(),nums.end());
        vector<int>next(n),prev(n);
        for(int i=0;i<n;i++){
            prev[i]=i-1;
            next[i]=(i==n-1)?-1:i+1;
        }
        set<pair<long long,int>>minPair;
        for(int i=0;i<n-1;i++){
            minPair.insert({val[i]+val[i+1],i});
        }
        auto isBad=[&](int i){
            if(prev[i]!=-1 and val[prev[i]]>val[i]) return true;
            if(next[i]!=-1 and val[next[i]]<val[i]) return true;
            return false;
        };
        int bad=0;
        for(int i=0;i<n;i++){
            if(isBad(i)) bad++;
        }
        
        int ans=0;
        while(bad>0){
            auto [sum,i]=*minPair.begin();
            int j=next[i];
            minPair.erase(minPair.begin());
            if(prev[i]!=-1) minPair.erase({val[prev[i]]+val[i],prev[i]});
            if(next[j]!=-1) minPair.erase({val[next[j]]+val[j],j});
            if(isBad(i)) bad--;
            if(isBad(j)) bad--;
            if(prev[i]!=-1 and isBad(prev[i])) bad--;
            if(next[j]!=-1 and isBad(next[j])) bad--;

            val[i]+=val[j];
            next[i]=next[j];
            if(next[j]!=-1) prev[next[j]]=i;

            if(prev[i]!=-1) minPair.insert({val[prev[i]]+val[i],prev[i]});
            if(next[i]!=-1) minPair.insert({val[next[i]]+val[i],i});
            if(isBad(i)) bad++;
            if(prev[i]!=-1 and isBad(prev[i])) bad++;
            if(next[j]!=-1 and isBad(next[j])) bad++;

            ans++;
        }
        return ans;


    }
};