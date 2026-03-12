class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        int n=arr.size(),ans=0;
        vector<int>prefix(n,0);
        for(int i=0;i<n;i++){
            if(i!=0) prefix[i]+=prefix[i-1];
            int val=prefix[i]+arr[i];
            
            if(val%2==0){
                if(i+k>n) return -1;
                
                prefix[i]+=1;
                if(i+k<n) prefix[i+k]-=1;
                ans++;
            }
        }
        return ans;
    }
};