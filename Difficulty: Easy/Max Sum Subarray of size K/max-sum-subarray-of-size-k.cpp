class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n=arr.size(),st=0,sum=0,ans=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(i-st+1==k){
                ans=max(ans,sum);
                sum-=arr[st];
                st++;
            }
        }
        return ans;
    }
};