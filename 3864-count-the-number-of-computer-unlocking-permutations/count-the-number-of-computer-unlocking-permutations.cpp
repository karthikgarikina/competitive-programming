class Solution {
public:
    int factorial(int n){
        long long mod=1e9+7,ans=1;
        for(int i=1;i<=n;i++){
            ans=(ans*i)%mod;
        }
        return ans;
    }
    int countPermutations(vector<int>& complexity) {
        int num=complexity[0];
        sort(complexity.begin(),complexity.end());
        if(complexity[0]!=num || complexity[0]==complexity[1]){
            return 0;
        }
        else return factorial(complexity.size()-1);
    }
};