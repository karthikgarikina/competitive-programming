class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int>ways(k,0);
        int n=energy.size();
        for(int i=0;i<n;i++){
            int idx=i%k;
            ways[idx]+=energy[i];
            if(ways[idx]<0 and (i+k)<n){
                ways[idx]=0;
            }
        }
        int ans=INT_MIN;
        for(auto i : ways) ans=max(ans,i);
        return ans;
        
    }
};