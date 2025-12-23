class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long  odd=0,even=0,sum=0,ans=0,n=arr.size(),mod=1e9+7;
        for(long long i=0;i<n;i++){
            sum+=arr[i];
            if(sum&1){
                ans+=((i+1)-odd);
                odd++;
            }
            else{
                ans+=(i-even);
                even++;
            }
            ans%=mod;
        }
        return ans;
    }
};