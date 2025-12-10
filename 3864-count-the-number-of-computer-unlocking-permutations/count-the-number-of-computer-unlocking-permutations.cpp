class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        long long mod=1e9+7,ans=1;
        int n=complexity.size();
        for(int i=1;i<n;i++){
            if(complexity[0]>=complexity[i]) return 0;
            ans=(ans*i)%mod;
        }
        return ans;
    }
};